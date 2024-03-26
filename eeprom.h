/**
 * EEPROM Register Mapping
 * @author Robert J. Rouquette
 * @date 2023-04-23
 */

#ifndef GPSDO_EEPROM_H
#define GPSDO_EEPROM_H

#include "register.h"

#define EEPROM_DBGME_KEY (0xE37B0001)

PAGE_MAP(EEPROM_MAP, {
    // offset 0x000
    // EEPROM size information
    REGMAP_32(, {
        unsigned WORDCNT: 16;
        unsigned BLKCNT: 11;
    }) SIZE;

    // offset 0x004
    // EEPROM current block
    uint32_t BLOCK;

    // offset 0x008
    // EEPROM current offset
    uint32_t OFFSET;

    // padding
    char _reserved_0[0x004];

    // offset 0x010
    // EEPROM data register for reads and writes
    uint32_t RDWR;

    // offset 0x014
    // EEPROM data register for reads and writes (increments offset)
    uint32_t RDWRINC;

    // offset 0x018
    // EEPROM current offset
    REGMAP_32(, {
            unsigned WORKING: 1;
            unsigned : 1;
            unsigned WKERASE: 1;
            unsigned WKCOPY: 1;
            unsigned NOPERM: 1;
            unsigned WKBUSY: 1;
    }) DONE;

    // offset 0x01C
    // EEPROM current offset
    REGMAP_32(, {
            unsigned : 2;
            unsigned PRETRY: 1;
            unsigned ERETRY: 1;
    }) SUPP;

    // offset 0x020
    // EEPROM block unlock register
    uint32_t UNLOCK;

    // padding
    char _reserved_1[0x00C];

    // offset 0x030
    // EEPROM block protection
    REGMAP_32(, {
            unsigned PROT: 3;
            unsigned ACC: 1;
    }) PROT;

    // offset 0x034
    // EEPROM password registers
    uint32_t PASS0;
    uint32_t PASS1;
    uint32_t PASS2;

    // offset 0x040
    // EEPROM interrupt register
    REGMAP_32(, {
            unsigned INT: 1;
    }) INT;

    // padding
    char _reserved_2[0x00C];

    // offset 0x050
    // EEPROM block hide registers
    uint32_t HIDE0;
    uint32_t HIDE1;
    uint32_t HIDE2;

    // padding
    char _reserved_3[0x024];

    // offset 0x080
    // EEPROM debug mass erase
    uint32_t DBGME;

    // padding
    char _reserved_4[0xF3C];

    // offset 0xFC0
    // EEPROM peripheral properties
    REGMAP_32(, {
            unsigned SIZE: 16;
    }) PP;

    // padding
    char _reserved_5[0x03C];
})

#define EEPROM (*(volatile struct EEPROM_MAP *)0x400AF000)

REGMAP_32 (RCGCEEPROM_MAP, {
    unsigned EN_EEPROM: 1;
});
#define RCGCEEPROM (*(volatile union RCGCEEPROM_MAP *)0x400FE658)

/**
 * Wait for EEPROM to complete current operation
 */;
void EEPROM_wait();

void EEPROM_mass_erase();

/**
 * Seek to absolute word offset for next read or write
 * @param offset absolute word offset
 */
void EEPROM_seek(int offset);

uint32_t EEPROM_read();

void EEPROM_write(uint32_t data);

#endif //GPSDO_EEPROM_H
