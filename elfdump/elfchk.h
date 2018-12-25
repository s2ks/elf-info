#ifndef __ELF_CHECK_INCLUDE__
#define __ELF_CHECK_INCLUDE__

#include "elf/elf_header.h"

extern int is_mag_valid(Elf_Header *header);
extern int is_class_valid(Elf_Header *header);
extern int is_version_valid(Elf_Header *header);

extern int is_elf32(Elf_Header *header);
extern int is_elf64(Elf_Header *header);

#endif
