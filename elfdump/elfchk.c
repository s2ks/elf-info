#include <stdio.h>
#include <stdint.h>

#include <elf.h>

#include "elfchk.h"


extern int get_ident_from_file(FILE *file, char *ident)
{
	int status;

	rewind(file);
	fread(ident, sizeof(*ident), EI_NIDENT, file);

	return ferror(file) || feof(file);
}

extern int get_ident_from_addr(void *addr, char *ident)
{
	//TODO
	return -1;
}

#define CHECK(__cond__) do { valid += __cond__; chk++; } while(0)
extern int is_mag_valid(char *ident)
{
 	const union {
		unsigned char 	magb[4];
		uint32_t	magi;
	} mag = { { ident[EI_MAG0], ident[EI_MAG1], ident[EI_MAG2], ident[EI_MAG3] } },
	  chk = { { ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3 } };

	return mag.magi == chk.magi;
}

extern int is_class_valid(char *ident)
{
	return ident[EI_CLASS] != ELFCLASSNONE;
}

extern int is_version_valid(char *ident)
{
	return ident[EI_VERSION] != EV_NONE;
}

#undef CHECK

extern int is_elf32(char *ident)
{
	return ident[EI_CLASS] == ELFCLASS32;
}

extern int is_elf64(char *ident)
{
	return ident[EI_CLASS] == ELFCLASS64;
}
