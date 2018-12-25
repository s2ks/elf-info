#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <unistd.h>
#include <elf.h>
#include <fcntl.h>

#include "elfstr.h"
#include "elfchk.h"

#include "elf/elf_header.h"
#include "util/order32.h"

#ifdef BENCH
#define TIME_BENCH 1
#endif

#define error_if(__cond, __label) do { if(__cond) goto __label; } while(0)

static int fd;

static Elf64_Ehdr *ehdr; /* ELF header */
static Elf64_Phdr *phdr; /* Program header table */
static Elf64_Shdr *shdr; /* Section header table */

struct string_tables {
	char *shstr; 	/* section header string table */
	char *dynstr; 	/* dynamic symbol string table */
};

static char *objname;

static struct string_tables *strtabs;

static void string_tables_free(void *ptr)
{
	struct string_tables *st = (struct string_tables *) ptr;

	free(st->shstr);
	free(st->dynstr);

	free(st);
}

static void *get_string_tables(void)
{
	Elf64_Shdr *strtab;
	struct string_tables *st = malloc(sizeof(*st));

	assert(st != NULL);

	strtab = shdr + ehdr->e_shstrndx;

	lseek(fd, strtab->sh_offset, SEEK_SET);
	st->shstr = malloc(strtab->sh_size);
	assert(st->shstr != NULL);

	read(fd, st->shstr, strtab->sh_size);

	return st;
}

static void *get_program_header_table(void)
{
	Elf64_Phdr *tmp;

	/* if the file has no program header table e_phoff will be 0 */
	assert(ehdr->e_phoff != 0);
	assert(ehdr->e_phentsize == sizeof(*tmp));

	tmp = malloc(ehdr->e_phnum * sizeof(*tmp));
	assert(tmp != NULL);

	lseek(fd, ehdr->e_phoff, SEEK_SET);

	for(int i = 0; i < ehdr->e_phnum; i++)
		read(fd, tmp + i, sizeof(*tmp));

	return tmp;
}

static void *get_section_header_table(void)
{
	Elf64_Shdr *tmp;

	/* if the file has no section header table e_shoff will be 0 */
	assert(ehdr->e_shoff != 0);
	assert(ehdr->e_shentsize == sizeof(*tmp));

	tmp = malloc(ehdr->e_shnum * sizeof(*tmp));
	assert(tmp != NULL);

	lseek(fd, ehdr->e_shoff, SEEK_SET);

	for(int i = 0; i < ehdr->e_shnum; i++)
		read(fd, tmp + i, sizeof(*tmp));

	return tmp;

}

/* dump sections with DYNSYM type */
static void dump_dynsym(void)
{
	Elf64_Shdr 	**shdr_dynsym 	= NULL;
	Elf64_Shdr	*shdr_strtab	= NULL;
	Elf64_Sym	*symtab		= NULL;

	char		*strtab		= NULL;
	uint64_t 	sec_count 	= 0;
	uint64_t	sym_count;

	/* look for dynsym section(s) */
	for(uint64_t i = 0; i < ehdr->e_shnum; i++) {
		if(shdr[i].sh_type == SHT_DYNSYM) {
			shdr_dynsym = realloc(shdr_dynsym, ++sec_count * sizeof(*shdr_dynsym));
			assert(shdr_dynsym);
			shdr_dynsym[sec_count - 1] = shdr + i;
		}
	}

	printf("%lu %s found.\n\n", sec_count, sec_count == 1 ? "section" : "sections");

	if(sec_count == 0) {
		assert(shdr_dynsym 	== NULL);
		assert(shdr_strtab 	== NULL);
		assert(symtab 		== NULL);
		assert(strtab 		== NULL);
		return; /* nothing to free */
	}

	/* print symbol info */
	for(uint64_t i = 0; i < sec_count; i++) {
		/* read string table */
		/* For type SHT_SYMTAB and SHT_DYNSYM sh_link is
		 * the section header index for the associated string table. */
		shdr_strtab = shdr + shdr_dynsym[i]->sh_link;
		strtab = malloc(shdr_strtab->sh_size);
		assert(strtab != NULL);

		lseek(fd, shdr_strtab->sh_offset, SEEK_SET);
		read(fd, strtab, shdr_strtab->sh_size);

		/* read symbol table */
		sym_count = shdr_dynsym[i]->sh_size / shdr_dynsym[i]->sh_entsize;
		symtab = malloc(shdr_dynsym[i]->sh_size);
		assert(symtab != NULL);

		lseek(fd, shdr_dynsym[i]->sh_offset, SEEK_SET);
		read(fd, symtab, shdr_dynsym[i]->sh_size);

		printf("%s contains %lu %s\n",
				shdr_dynsym[i]->sh_name + strtabs->shstr,
				sym_count, sym_count == 1 ? "entry" : "entries");
		printf("%6s: %-12s%-12s%-12s%-12s%-12s%s\n",
				"NUM", "VAL (16)", "SIZE (10)", "BIND", "TYPE", "VIS", "NAME");

		for(uint64_t x = 0; x < sym_count; x++) {
			printf("%6lu: ", x);
			printf("%-12lx", symtab[x].st_value);
			printf("%-12lu", symtab[x].st_size);
			printf("%-12s", get_sym_bind_unsafe(symtab[x].st_info));
			printf("%-12s", get_sym_type_unsafe(symtab[x].st_info));
			printf("%-12s", get_sym_vis_unsafe(symtab[x].st_other));
			printf("%s\n", strtab + symtab[x].st_name);
		}

		putchar('\n');

		free(strtab);
		free(symtab);
	}

	free(shdr_dynsym);
}

/* dump .dynamic section
 * TODO support for multiple dynsym sections
 * TODO split .dynamic section dump and .dynsym section dump */
static void dump_dynamic(void)
{
	Elf64_Shdr *shdr_dynamic= NULL;
	Elf64_Shdr *shdr_dynsym	= NULL;
	Elf64_Dyn  *dynamic 	= NULL;
	Elf64_Sym  *symtab	= NULL;

	size_t 	size;
	char 	*strtab;
	int 	count = 0;

	/* look for .dynamic section */
	for(int i = 0; i < ehdr->e_shnum; i++) {
		if(shdr[i].sh_type == SHT_DYNAMIC) {
			shdr_dynamic = shdr + i;
			count++;
		}
	}

	assert(count == 1);
	count = 0;

	/* look for .dynsym section */
	for(int i = 0; i < ehdr->e_shnum; i++) {
		if(shdr[i].sh_type == SHT_DYNSYM) {
			printf("%s has SHT_DYNSYM type\n", strtabs->shstr + shdr[i].sh_name);
			shdr_dynsym = shdr + i;
			count++;
		}

	}

	assert(count == 1);

	/* TODO what if the file does not have a .dynamic section? */
	assert(shdr_dynamic != NULL);

	dynamic = malloc(shdr_dynamic->sh_size);
	assert(dynamic != NULL);

	lseek(fd, shdr_dynamic->sh_offset, SEEK_SET);
	read(fd, dynamic, shdr_dynamic->sh_size);

	/* get string table size */
	for(int i = 0; dynamic[i].d_tag != DT_NULL; i++) {
		if(dynamic[i].d_tag == DT_STRSZ) {
			size = dynamic[i].d_un.d_val;

			break;
		}
	}

	assert(size > 0);
	strtab = malloc(size);
	assert(strtab != NULL);

	/* read string table */
	for(int i = 0; dynamic[i].d_tag != DT_NULL; i++) {
		if(dynamic[i].d_tag == DT_STRTAB) {
			lseek(fd, dynamic[i].d_un.d_val, SEEK_SET);
			read(fd, strtab, size);

			break;
		}
	}

	/* get symbol count */
	count = shdr_dynsym->sh_size / shdr_dynsym->sh_entsize;
	printf("dynsym count %u\n\n", count);

	/* read symbol table */
	symtab = malloc(shdr_dynsym->sh_size);
	assert(symtab != NULL);

	lseek(fd, shdr_dynsym->sh_offset, SEEK_SET);
	read(fd, symtab, shdr_dynsym->sh_size);

	/* print dynsym names */
	for(int i = 0; i < count; i++) {
		printf("symbol %d: %s\n", i, symtab[i].st_name + strtab);
	}

	free(dynamic);
	free(symtab);
	free(strtab);

}

/* print all section names */
static void dump_sections(void)
{
	printf("%s has %u section %s\n\n",
			objname, ehdr->e_shnum, ehdr->e_shnum == 1 ? "header" : "headers");

	printf("%6s: %-12s%-12s%-12s%-14s%s\n",
			"NUM", "TYPE", "OFFSET (16)", "SIZE (10)", "ENTSIZE (10)", "NAME");
	for(unsigned int i = 0; i < ehdr->e_shnum; i++) {
		printf("%6u: ", i);
		printf("%-12s", get_section_type_unsafe(shdr[i].sh_type));
		printf("%-12lx", shdr[i].sh_offset);
		printf("%-12lu", shdr[i].sh_size);
		printf("%-14lu", shdr[i].sh_entsize);
		printf("%s\n", strtabs->shstr + shdr[i].sh_name);
	}
}

int main(int argc, char **argv)
{
	int error;
	FILE *file;
	char *filename = argv[argc - 1];

	Elf_Header elf_header;

	file = fopen(filename, "r");
	error_if(!file, error);

	error = get_ident_from_file(file, &elf_header);
	error_if(error, read_error);

	if(!is_mag_valid(&elf_header)) {
		fprintf(stderr, "ERROR %s is not an ELF file\n", filename);
		exit(-1);
	}

	if(!is_class_valid(&elf_header)) {
		fprintf(stderr, "ERROR: %s - invalid architecture\n", filename);
		exit(-1);
	}

	error = read_elf_header_from_file(file, &elf_header);
	error_if(error, read_error);

	dump_elf_header(&elf_header);

	goto exit;

read_error:
	fprintf(stderr, "error reading %s\n", filename);
	if(feof(file))
		fprintf(stderr, "end of file reached\n");

error:
	perror(filename);

exit:
	fclose(file);
	return errno;
}
