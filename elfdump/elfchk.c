#include <stdio.h>
#include <stdint.h>

#include <elf.h>

#include "elf/elf_header.h"

#include "elfchk.h"

extern int is_mag_valid(Elf_Header *header)
{
 	const union {
		unsigned char 	bytes[4];
		uint32_t	mag;
	} ident = { { header->ident[EI_MAG0], header->ident[EI_MAG1], header->ident[EI_MAG2], header->ident[EI_MAG3] } },
	  check = { { ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3 } };

	return ident.mag == check.mag;
}

extern int is_class_valid(Elf_Header *header)
{
	return header->ident[EI_CLASS] != ELFCLASSNONE;
}

extern int is_version_valid(Elf_Header *header)
{
	return header->ident[EI_VERSION] != EV_NONE;
}

extern int is_elf32(Elf_Header *header)
{
	return header->ident[EI_CLASS] == ELFCLASS32;
}

extern int is_elf64(Elf_Header *header)
{
	return header->ident[EI_CLASS] == ELFCLASS64;
}
