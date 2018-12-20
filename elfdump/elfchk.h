#ifndef __ELF_CHECK_INCLUDE__
#define __ELF_CHECK_INCLUDE__

extern int get_ident_from_file(FILE *file, char *ident);
//extern int get_ident_from_addr(void *addr, char *ident); //TODO

extern int is_mag_valid(char *ident);
extern int is_class_valid(char *ident);
extern int is_version_valid(char *ident);

extern int is_elf32(char *ident);
extern int is_elf64(char *ident);

#endif
