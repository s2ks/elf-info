#ifndef __ELF_HEADER_INCLUDE__
#define __ELF_HEADER_INCLUDE__

#include <elf.h>

extern int file_read_elf_header32(FILE *file, Elf32_Ehdr *header);
extern int file_read_elf_header(FILE *file, Elf64_Ehdr *header);
//extern int addr_read_elf_header32(void *addr, Elf32_Ehdr *header);
//extern int addr_read_elf_header(void *addr, Elf64_Ehdr *header);

extern int dump_elf_header32(Elf32_Ehdr *header);
extern int dump_elf_header(Elf64_Ehdr *header);

#endif
