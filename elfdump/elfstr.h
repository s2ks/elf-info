#ifndef __ELFSTR_H__
#define __ELFSTR_H__

#include <stdint.h>

static const char *const sh_types_str[] = {
	[SHT_NULL] 		= "NULL",
	[SHT_PROGBITS] 		= "PROGBITS",
	[SHT_SYMTAB]		= "SYMTAB",
	[SHT_STRTAB]		= "STRTAB",
	[SHT_RELA]		= "RELA",
	[SHT_HASH]		= "HASH",
	[SHT_DYNAMIC]		= "DYNAMIC",
	[SHT_NOTE]		= "NOTE",
	[SHT_NOBITS]		= "NOBITS",
	[SHT_REL]		= "REL",
	[SHT_SHLIB]		= "SHLIB",
	[SHT_DYNSYM]		= "DYNSYM",
	[SHT_INIT_ARRAY]	= "INIT_ARRAY",
	[SHT_FINI_ARRAY]	= "FINI_ARRAY",
	[SHT_PREINIT_ARRAY] 	= "PREINIT_ARRAY",
	[SHT_GROUP]		= "GROUP",
	[SHT_SYMTAB_SHNDX] 	= "SYMTAB_SHNDX",
};

#define SHF_SZ (sizeof(void *) * (sizeof(uint64_t) * 8))

static const char *const sh_flags_str[] = {
	[0]			= NULL,
	[SHF_WRITE]		= "WRITE",
	[SHF_ALLOC]		= "ALLOC",
	[SHF_EXECINSTR] 	= "EXECINSTR",
	[SHF_STRINGS]		= "STRINGS",
	[SHF_INFO_LINK]		= "INFO_LINK",
	[SHF_LINK_ORDER]	= "LINK_ORDER",
	[SHF_OS_NONCONFORMING] 	= "OS_NONCONFORMING",
	[SHF_GROUP]		= "GROUP",
	[SHF_TLS]		= "TLS",
	[SHF_COMPRESSED]	= "COMPRESSED"
};

static const uint64_t sh_flags[] = {
        SHF_WRITE,
        SHF_ALLOC,
        SHF_EXECINSTR,
        SHF_MERGE,
        SHF_STRINGS,
        SHF_INFO_LINK,
        SHF_LINK_ORDER,
        SHF_OS_NONCONFORMING,
        SHF_GROUP,
        SHF_TLS,
        SHF_COMPRESSED
};

static const char *const sym_vis_str[] = {
	[STV_DEFAULT]	= "DEFAULT",
	[STV_INTERNAL]	= "INTERNAL",
	[STV_HIDDEN]	= "HIDDEN",
	[STV_PROTECTED]	= "PROTECTED",
};
static const char *const sym_bind_str[] = {
	[STB_LOCAL]	= "LOCAL",
	[STB_GLOBAL]	= "GLOBAL",
	[STB_WEAK]	= "WEAK",
};

static const char *const sym_type_str[] = {
	[STT_NOTYPE]	= "NOTYPE",
	[STT_OBJECT]	= "OBJECT",
	[STT_FUNC]	= "FUNC",
	[STT_SECTION]	= "SECTION",
	[STT_FILE]	= "FILE",
	[STT_COMMON]	= "COMMON",
	[STT_TLS]	= "TLS",
};

static const char *const ei_class[] = {
	[ELFCLASSNONE]	= "NONE",
	[ELFCLASS32]	= "32",
	[ELFCLASS64]	= "64"
};

static const char *const ei_data[] = {
	[ELFDATANONE]	= "NONE",
	[ELFDATA2LSB]	= "LITTLE ENDIAN",
	[ELFDATA2MSB]	= "BIG ENDIAN"
};

static const char *const ei_osabi[] = {
	[ELFOSABI_SYSV] 	= "SYSV",
	[ELFOSABI_HPUX]		= "HPUX",
	[ELFOSABI_NETBSD] 	= "NETBSD",
	[ELFOSABI_LINUX] 	= "LINUX",
	[ELFOSABI_SOLARIS] 	= "SOLARIS",
	[ELFOSABI_IRIX] 	= "IRIX",
	[ELFOSABI_FREEBSD] 	= "FREEBSD",
	[ELFOSABI_TRU64]	= "TRUE64",
	[ELFOSABI_ARM]		= "ARM",
	[ELFOSABI_STANDALONE]	= "STANDALONE"
};

extern const char *get_section_type_unsafe(uint32_t type);
extern const char *get_section_type(uint32_t type);

extern const char **get_section_flags(uint64_t flags, const char **buf);
extern size_t section_flags_alocsz(uint64_t flags);

extern const char *get_sym_vis_unsafe(uint8_t other);
extern const char *get_sym_vis(uint8_t other);

extern const char *get_sym_bind_unsafe(uint8_t info);
extern const char *get_sym_bind(uint8_t info);

extern const char *get_sym_type_unsafe(uint8_t info);
extern const char *get_sym_type(uint8_t info);

#endif
