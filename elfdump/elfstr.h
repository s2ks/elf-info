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

static const char *const e_type[] = {
	[ET_NONE]	= "NONE",
	[ET_REL]	= "REL",
	[ET_EXEC]	= "EXEC",
	[ET_DYN]	= "DYN",
	[ET_CORE]	= "CORE"
};

static const char *const e_machine[] = {
	[EM_NONE]	= "NONE",
	[EM_M32]	= "M32",
	[EM_SPARC]	= "SPARC",
	[EM_386]	= "386",
	[EM_68K]	= "68K",
	[EM_88K]	= "88K",
	[EM_IAMCU]	= "IAMCU",
	[EM_860]	= "860",
	[EM_MIPS]	= "MIPS",
	[EM_S370]	= "S370",
	[EM_MIPS_RS3_LE]	= "MIPS_RS3_LE",

	[EM_PARISC]	= "PARISC",

	[EM_VPP500]	= "VPP500",
	[EM_SPARC32PLUS]	= "SPARC32PLUS",
	[EM_960]	= "960",
	[EM_PPC]	= "PPC",
	[EM_PPC64]	= "PPC64",
	[EM_S390]	= "S390",
	[EM_SPU]	= "SPU",

	[EM_V800]	= "V800",
	[EM_FR20]	= "FR20",
	[EM_RH32]	= "RH32",
	[EM_RCE]	= "RCE",
	[EM_ARM]	= "ARM",
	[EM_FAKE_ALPHA]	= "FAKE_ALPHA",
	[EM_SH]	= "SH",
	[EM_SPARCV9]	= "SPARCV9",
	[EM_TRICORE]	= "TRICORE",
	[EM_ARC]	= "ARC",
	[EM_H8_300]	= "H8_300",
	[EM_H8_300H]	= "H8_300H",
	[EM_H8S]	= "H8S",
	[EM_H8_500]	= "H8_500",
	[EM_IA_64]	= "IA_64",
	[EM_MIPS_X]	= "MIPS_X",
	[EM_COLDFIRE]	= "COLDFIRE",
	[EM_68HC12]	= "68HC12",
	[EM_MMA]	= "MMA",
	[EM_PCP]	= "PCP",
	[EM_NCPU]	= "NCPU",
	[EM_NDR1]	= "NDR1",
	[EM_STARCORE]	= "STARCORE",
	[EM_ME16]	= "ME16",
	[EM_ST100]	= "ST100",
	[EM_TINYJ]	= "TINYJ",
	[EM_X86_64]	= "X86_64",
	[EM_PDSP]	= "PDSP",
	[EM_PDP10]	= "PDP10",
	[EM_PDP11]	= "PDP11",
	[EM_FX66]	= "FX66",
	[EM_ST9PLUS]	= "ST9PLUS",
	[EM_ST7]	= "ST7",
	[EM_68HC16]	= "68HC16",
	[EM_68HC11]	= "68HC11",
	[EM_68HC08]	= "68HC08",
	[EM_68HC05]	= "68HC05",
	[EM_SVX]	= "SVX",
	[EM_ST19]	= "ST19",
	[EM_VAX]	= "VAX",
	[EM_CRIS]	= "CRIS",
	[EM_JAVELIN]	= "JAVELIN",
	[EM_FIREPATH]	= "FIREPATH",
	[EM_ZSP]	= "ZSP",
	[EM_MMIX]	= "MMIX",
	[EM_HUANY]	= "HUANY",
	[EM_PRISM]	= "PRISM",
	[EM_AVR]	= "AVR",
	[EM_FR30]	= "FR30",
	[EM_D10V]	= "D10V",
	[EM_D30V]	= "D30V",
	[EM_V850]	= "V850",
	[EM_M32R]	= "M32R",
	[EM_MN10300]	= "MN10300",
	[EM_MN10200]	= "MN10200",
	[EM_PJ]	= "PJ",
	[EM_OPENRISC]	= "OPENRISC",
	[EM_ARC_COMPACT]	= "ARC_COMPACT",
	[EM_XTENSA]	= "XTENSA",
	[EM_VIDEOCORE]	= "VIDEOCORE",
	[EM_TMM_GPP]	= "TMM_GPP",
	[EM_NS32K]	= "NS32K",
	[EM_TPC]	= "TPC",
	[EM_SNP1K]	= "SNP1K",
	[EM_ST200]	= "ST200",
	[EM_IP2K]	= "IP2K",
	[EM_MAX]	= "MAX",
	[EM_CR]	= "CR",
	[EM_F2MC16]	= "F2MC16",
	[EM_MSP430]	= "MSP430",
	[EM_BLACKFIN]	= "BLACKFIN",
	[EM_SE_C33]	= "SE_C33",
	[EM_SEP]	= "SEP",
	[EM_ARCA]	= "ARCA",
	[EM_UNICORE]	= "UNICORE",
	[EM_EXCESS]	= "EXCESS",
	[EM_DXP]	= "DXP",
	[EM_ALTERA_NIOS2]	= "ALTERA_NIOS2",
	[EM_CRX]	= "CRX",
	[EM_XGATE]	= "XGATE",
	[EM_C166]	= "C166",
	[EM_M16C]	= "M16C",
	[EM_DSPIC30F]	= "DSPIC30F",
	[EM_CE]	= "CE",
	[EM_M32C]	= "M32C",

	[EM_TSK3000]	= "TSK3000",
	[EM_RS08]	= "RS08",
	[EM_SHARC]	= "SHARC",
	[EM_ECOG2]	= "ECOG2",
	[EM_SCORE7]	= "SCORE7",
	[EM_DSP24]	= "DSP24",
	[EM_VIDEOCORE3]	= "VIDEOCORE3",
	[EM_LATTICEMICO32]	= "LATTICEMICO32",
	[EM_SE_C17]	= "SE_C17",
	[EM_TI_C6000]	= "TI_C6000",
	[EM_TI_C2000]	= "TI_C2000",
	[EM_TI_C5500]	= "TI_C5500",
	[EM_TI_ARP32]	= "TI_ARP32",
	[EM_TI_PRU]	= "TI_PRU",

	[EM_MMDSP_PLUS]	= "MMDSP_PLUS",
	[EM_CYPRESS_M8C]	= "CYPRESS_M8C",
	[EM_R32C]	= "R32C",
	[EM_TRIMEDIA]	= "TRIMEDIA",
	[EM_QDSP6]	= "QDSP6",
	[EM_8051]	= "8051",
	[EM_STXP7X]	= "STXP7X",
	[EM_NDS32]	= "NDS32",
	[EM_ECOG1X]	= "ECOG1X",
	[EM_MAXQ30]	= "MAXQ30",
	[EM_XIMO16]	= "XIMO16",
	[EM_MANIK]	= "MANIK",
	[EM_CRAYNV2]	= "CRAYNV2",
	[EM_RX]	= "RX",
	[EM_METAG]	= "METAG",
	[EM_MCST_ELBRUS]	= "MCST_ELBRUS",
	[EM_ECOG16]	= "ECOG16",
	[EM_CR16]	= "CR16",
	[EM_ETPU]	= "ETPU",
	[EM_SLE9X]	= "SLE9X",
	[EM_L10M]	= "L10M",
	[EM_K10M]	= "K10M",

	[EM_AARCH64]	= "AARCH64",

	[EM_AVR32]	= "AVR32",
	[EM_STM8]	= "STM8",
	[EM_TILE64]	= "TILE64",
	[EM_TILEPRO]	= "TILEPRO",
	[EM_MICROBLAZE]	= "MICROBLAZE",
	[EM_CUDA]	= "CUDA",
	[EM_TILEGX]	= "TILEGX",
	[EM_CLOUDSHIELD]	= "CLOUDSHIELD",
	[EM_COREA_1ST]	= "COREA_1ST",
	[EM_COREA_2ND]	= "COREA_2ND",
	[EM_ARC_COMPACT2]	= "ARC_COMPACT2",
	[EM_OPEN8]	= "OPEN8",
	[EM_RL78]	= "RL78",
	[EM_VIDEOCORE5]	= "VIDEOCORE5",
	[EM_78KOR]	= "78KOR",
	[EM_56800EX]	= "56800EX",
	[EM_BA1]	= "BA1",
	[EM_BA2]	= "BA2",
	[EM_XCORE]	= "XCORE",
	[EM_MCHP_PIC]	= "MCHP_PIC",

	[EM_KM32]	= "KM32",
	[EM_KMX32]	= "KMX32",
	[EM_EMX16]	= "EMX16",
	[EM_EMX8]	= "EMX8",
	[EM_KVARC]	= "KVARC",
	[EM_CDP]	= "CDP",
	[EM_COGE]	= "COGE",
	[EM_COOL]	= "COOL",
	[EM_NORC]	= "NORC",
	[EM_CSR_KALIMBA]	= "CSR_KALIMBA",
	[EM_Z80]	= "Z80",
	[EM_VISIUM]	= "VISIUM",
	[EM_FT32]	= "FT32",
	[EM_MOXIE]	= "MOXIE",
	[EM_AMDGPU]	= "AMDGPU",
	[EM_RISCV]	= "RISCV",
	[EM_BPF]	= "BPF"
};

static const char *const e_version[] = {
	[EV_NONE]	= "NONE",
	[EV_CURRENT]	= "CURRENT"
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
