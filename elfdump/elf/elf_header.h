#ifndef __ELF_HEADER_INCLUDE__
#define __ELF_HEADER_INCLUDE__

#include <stdio.h>
#include <elf.h>

typedef union {
	unsigned char 	ident[EI_NIDENT];
	Elf32_Ehdr	h32;
	Elf64_Ehdr	h64;
} Elf_Header;

extern int get_ident_from_file(FILE *file, Elf_Header *header);

extern int read_elf_header_from_file(FILE *file, Elf_Header *header);
//extern int addr_read_elf_header(void *addr, Elf64_Ehdr *header);

extern int dump_elf_header(Elf_Header *header);

#endif
