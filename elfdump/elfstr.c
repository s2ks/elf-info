#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include <elf.h>

#include "elfstr.h"
#include "util/bench.h"

extern const char *get_section_type_unsafe(uint32_t type)
{
	if(type < SHT_NUM)
		return (const char *) sh_types_str[type];
	else
		return (const char *) NULL;
}

extern const char *get_sym_vis_unsafe(uint8_t st_other)
{
        unsigned int vis = ELF64_ST_VISIBILITY(st_other);

        if(vis < sizeof(sym_vis_str) / sizeof(sym_vis_str[0]))
                return (const char *) sym_vis_str[vis];
        else
                return (const char *) NULL;
}

extern const char *get_sym_bind_unsafe(uint8_t st_info)
{
        unsigned int bind = ELF64_ST_BIND(st_info);

        if(bind < STB_NUM)
                return (const char *) sym_bind_str[bind];
        else
                return (const char *) NULL;
}

extern const char *get_sym_type_unsafe(uint8_t st_info)
{
        unsigned int type = ELF64_ST_TYPE(st_info);

        if(type < STT_NUM)
                return (const char *) sym_type_str[type];
        else
                return (const char *) NULL;
}



extern const char *get_section_type(uint32_t type)
{
	switch(type) {
		case SHT_NULL:
			return (const char *) sh_types_str[type];
		case SHT_PROGBITS:
			return (const char *) sh_types_str[type];
		case SHT_SYMTAB:
			return (const char *) sh_types_str[type];
		case SHT_STRTAB:
			return (const char *) sh_types_str[type];
		case SHT_RELA:
			return (const char *) sh_types_str[type];
		case SHT_HASH:
			return (const char *) sh_types_str[type];
		case SHT_DYNAMIC:
			return (const char *) sh_types_str[type];
		case SHT_NOTE:
			return (const char *) sh_types_str[type];
		case SHT_NOBITS:
			return (const char *) sh_types_str[type];
		case SHT_REL:
			return (const char *) sh_types_str[type];
		case SHT_SHLIB:
			return (const char *) sh_types_str[type];
		case SHT_DYNSYM:
			return (const char *) sh_types_str[type];
		case SHT_INIT_ARRAY:
			return (const char *) sh_types_str[type];
		case SHT_FINI_ARRAY:
			return (const char *) sh_types_str[type];
		case SHT_PREINIT_ARRAY:
			return (const char *) sh_types_str[type];
		case SHT_GROUP:
			return (const char *) sh_types_str[type];
		case SHT_SYMTAB_SHNDX:
			return (const char *) sh_types_str[type];
		default:
			//break; /* TODO */
			return (const char *) NULL;
	};

	/* TODO processor specific */
}

extern size_t section_flags_alocsz(uint64_t flags)
{
	size_t flagc = 0;

	while(flags) {
		flagc += flags & 1;
		flags >>= 1;
	}

	return flagc * sizeof(void *);
}

extern const char **get_section_flags(uint64_t flags, const char **buf)
{
	int i = 0, x;

	const int flagc = sizeof(sh_flags) / sizeof(sh_flags[0]);

	while(flags) {
		buf[i] = NULL;

		for(x = 0; x < flagc && buf[i] == NULL; x++)
			buf[i] = (const char *) sh_flags_str[flags & sh_flags[x]];

		if(buf[i]) {
			flags &= ~sh_flags[x];
			i++;
		} else {
			break;
		}

	}

	return buf;
}
