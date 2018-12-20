#include <elf.h>

#include "elf_header.h"

enum {
	ELF32,
	ELF64
};

static int _file_read_elf_header(FILE *file, void *dest, size_t size)
{
	rewind(file);
	fread(dest, 1, size, file);

	return feof(file) || ferror(file);
}

extern int file_read_elf_header32(FILE *file, Elf32_Ehdr *header)
{
	return _file_read_elf_header(file, header, sizeof(*header));
}

extern int file_read_elf_header(FILE *file, Elf64_Ehdr *header)
{
	return _file_read_elf_header(file, header, sizeof(*header));
}

extern int dump_elf_header32(Elf32_Ehdr *header)
{
	
}

extern int dump_elf_header(Elf64_Ehdr *header)
{
	
}
