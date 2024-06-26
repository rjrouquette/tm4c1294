/**
 * System Registers
 * @author Robert J. Rouquette
 * @date 2022-04-14
 */

#ifndef TM4C_SYS_H
#define TM4C_SYS_H

#include "register.h"

#ifdef __cplusplus
extern "C" {
#endif

REGMAP_32 (STCTRL_MAP, {
    unsigned ENABLE: 1;
    unsigned INTEN: 1;
    unsigned CLK_SRC: 1;
    unsigned : 13;
    unsigned COUNT: 1;
});
#define STCTRL (*(volatile union STCTRL_MAP *)0xE000E010)

REGMAP_32 (STRELOAD_MAP, {
    unsigned RELOAD: 24;
});
#define STRELOAD (*(volatile union STRELOAD_MAP *)0xE000E014)

REGMAP_32 (STCURRENT_MAP, {
    unsigned CURRENT: 24;
});
#define STCURRENT (*(volatile union STCURRENT_MAP *)0xE000E018)

REGMAP_32 (FAULTSTAT_MAP, {
    unsigned IERR: 1;
    unsigned DERR: 1;
    unsigned : 1;
    unsigned MUSTKE: 1;
    unsigned MSTKE: 1;
    unsigned MLSPERR: 1;
    unsigned : 1;
    unsigned MMARV: 1;
    unsigned IBUS: 1;
    unsigned PRECISE: 1;
    unsigned IMPRE: 1;
    unsigned BUSTKE: 1;
    unsigned BSTKE: 1;
    unsigned BLSPERR: 1;
    unsigned : 1;
    unsigned BFARV: 1;
    unsigned UNDEF: 1;
    unsigned INVSTAT: 1;
    unsigned INVPC: 1;
    unsigned NOCP: 1;
    unsigned : 4;
    unsigned UNALIGN: 1;
    unsigned DIV0: 1;
});
#define FAULTSTAT (*(volatile union FAULTSTAT_MAP *)0xE000ED28)

REGMAP_32 (CPAC_MAP, {
    unsigned : 20;
    unsigned CP10: 2;
    unsigned CP11: 2;
});
#define CPAC (*(volatile union CPAC_MAP *)0xE000ED88)

REGMAP_32(FLASHCONF_MAP, {
    unsigned : 16;
    unsigned FPFOFF: 1;
    unsigned FPFON: 1;
    unsigned : 2;
    unsigned CLRTV: 1;
    unsigned : 8;
    unsigned SPFE: 1;
    unsigned FMME: 1;
});
#define FLASHCONF (*(volatile union FLASHCONF_MAP *)0x400FDFC8)

REGMAP_32 (DID0_MAP, {
    unsigned MINOR: 8;
    unsigned MAJOR: 8;
    unsigned CLASS: 8;
    unsigned : 4;
    unsigned VER: 3;
});
#define DID0 (*(const volatile union DID0_MAP *)0x400FE000)

REGMAP_32 (DID1_MAP, {
    unsigned QUAL: 2;
    unsigned ROHS: 1;
    unsigned PKG: 2;
    unsigned TEMP: 3;
    unsigned : 5;
    unsigned PINCOUNT: 3;
    unsigned PARTNO: 8;
    unsigned FAM: 4;
    unsigned VER: 4;
});
#define DID1 (*(const volatile union DID1_MAP *)0x400FE004)

REGMAP_32 (RIS_MAP, {
    unsigned : 1;
    unsigned BORRIS: 1;
    unsigned : 1;
    unsigned MOFRIS: 1;
    unsigned : 2;
    unsigned PLLLRIS: 1;
    unsigned : 1;
    unsigned MOSCPUPRIS: 1;
});
#define SYSRIS (*(volatile union RIS_MAP *)0x400FE050)

REGMAP_32 (MOSCCTL_MAP, {
    unsigned CVAL: 1;
    unsigned MOSCIM: 1;
    unsigned NOXTAL: 1;
    unsigned PWRDN: 1;
    unsigned OSCRNG: 1;
});
#define MOSCCTL (*(volatile union MOSCCTL_MAP *)0x400FE07C)

REGMAP_32 (RSCLKCFG_MAP, {
    unsigned PSYSDIV: 10;
    unsigned OSYSDIV: 10;
    unsigned OSCSRC: 4;
    unsigned PLLSRC: 4;
    unsigned USEPLL: 1;
    unsigned ACG: 1;
    unsigned NEWFREQ: 1;
    unsigned MEMTIMU: 1;
});
#define RSCLKCFG (*(volatile union RSCLKCFG_MAP *)0x400FE0B0)

REGMAP_32 (MEMTIM0_MAP, {
    unsigned FWS: 4;
    unsigned : 1;
    unsigned FBCE: 1;
    unsigned FBCHT: 4;
    unsigned : 6;
    unsigned EWS: 4;
    unsigned : 1;
    unsigned EBCE: 1;
    unsigned EBCHT: 4;
});
#define MEMTIM0 (*(volatile union MEMTIM0_MAP *)0x400FE0C0)

REGMAP_32 (PLLFREQ0_MAP, {
    unsigned MINT: 10;
    unsigned MFRAC: 10;
    unsigned : 3;
    unsigned PLLPWR: 1;
});
#define PLLFREQ0 (*(volatile union PLLFREQ0_MAP *)0x400FE160)

REGMAP_32(PLLFREQ1_MAP, {
    unsigned N: 5;
    unsigned : 3;
    unsigned Q: 5;
});
#define PLLFREQ1 (*(volatile union PLLFREQ1_MAP *)0x400FE164)

REGMAP_32 (PLLSTAT_MAP, {
    unsigned LOCK: 1;
});
#define PLLSTAT (*(volatile union PLLSTAT_MAP *)0x400FE168)

struct UNIQUEID_BLOCK {
    uint32_t WORD[4];
};
#define UNIQUEID (*(volatile struct UNIQUEID_BLOCK *)0x400FEF20)

unsigned RAM_used();
unsigned RAM_size();
unsigned EEPROM_size();
unsigned FLASH_size();
unsigned FLASH_used();

#ifdef __cplusplus
}
#endif

#endif //TM4C_SYS_H
