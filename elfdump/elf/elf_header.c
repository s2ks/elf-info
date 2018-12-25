#include <stddef.h>
#include <stdio.h>

#include <elf.h>

#include "elf_header.h"
#include "elfchk.h"
#include "elfstr.h"

extern int get_ident_from_file(FILE *file, Elf_Header *header)
{
	rewind(file);
	fread(header->ident, sizeof(*header->ident), sizeof(header->ident), file);

	return ferror(file) || feof(file);
}

extern int read_elf_header_from_file(FILE *file, Elf_Header *header)
{
	rewind(file);
	if(is_elf64(header))
		fread(header, 1, sizeof(header->h64), file);
	else
		fread(header, 1, sizeof(header->h32), file);

	return ferror(file) || feof(file);
}

#define EHDR(_member) (header->ident[EI_CLASS] == ELFCLASS64 ? header->h64._member : header->h32._member)
extern int dump_elf_header(Elf_Header *header)
{
	printf("MAG0:		%x\n", 		header->ident[EI_MAG0]);
	printf("MAG1:		%c\n", 		header->ident[EI_MAG1]);
	printf("MAG2:		%c\n", 		header->ident[EI_MAG2]);
	printf("MAG3:		%c\n\n", 	header->ident[EI_MAG3]);

	printf("CLASS:		%s\n", 		ei_class[header->ident[EI_CLASS]]);
	printf("DATA:		%s\n", 		ei_data[header->ident[EI_DATA]]);
	printf("VERSION:	%s (%x)\n", 	e_version[header->ident[EI_VERSION]], header->ident[EI_VERSION]);
	printf("OSABI:		%s\n", 		ei_osabi[header->ident[EI_OSABI]]);
	printf("ABIVERSION:	%x\n\n", 	header->ident[EI_ABIVERSION]);

	printf("TYPE:		%s\n", 		e_type[EHDR(e_type)]);
	printf("MACHINE:	%s\n", 		e_machine[EHDR(e_machine)]);
	printf("VERSION:	%s (%x)\n\n", 	e_version[EHDR(e_version)], EHDR(e_version));

	printf("ENTRY:		0x%lx\n", 	EHDR(e_entry));
	printf("PHOFF:		0x%lx\n",	EHDR(e_phoff));
	printf("SHOFF:		0x%lx\n",	EHDR(e_shoff));
	printf("FLAGS:		0x%x\n",	EHDR(e_flags));
	printf("EHSIZE:		0x%x\n",	EHDR(e_ehsize));
	printf("PHENTSIZE:	0x%x\n",	EHDR(e_phentsize));
	printf("PHNUM:		0x%x\n",	EHDR(e_phnum));
	printf("SHENTSIZE:	0x%x\n",	EHDR(e_shentsize));
	printf("SHNUM:		0x%x\n",	EHDR(e_shnum));
	printf("SHSTRNDX:	0x%x\n\n",	EHDR(e_shstrndx));

	return 0;
}
#undef EHDR
