#ifndef __ELF_CHECK_INCLUDE__
#define __ELF_CHECK_INCLUDE__

extern int get_ident_from_file(FILE *file, unsigned char *ident);
//extern int get_ident_from_addr(void *addr, char *ident); //TODO

extern int is_mag_valid(unsigned char *ident);
extern int is_class_valid(unsigned char *ident);
extern int is_version_valid(unsigned char *ident);

extern int is_elf32(unsigned char *ident);
extern int is_elf64(unsigned char *ident);

#endif
