//
// Created by robert on 4/23/23.
//

#include "eeprom.h"

static int offset;

void EEPROM_mass_erase() {
    // wait for eeprom ready
    EEPROM_wait();
    // start mass erase
    EEPROM.DBGME = EEPROM_DBGME_KEY;
    // wait for mass erase
    while(EEPROM.DBGME) __asm volatile("nop");
    // wait for eeprom ready
    EEPROM_wait();
    offset = 0;
}

void EEPROM_seek(int _offset) {
    offset = _offset;
}

uint32_t EEPROM_read() {
    EEPROM_wait();
    EEPROM.BLOCK = (offset >> 4) & 0xFFFF;
    EEPROM.OFFSET = offset & 0xF;
    ++offset;
    return EEPROM.RDWR;
}

void EEPROM_write(uint32_t data) {
    EEPROM_wait();
    EEPROM.BLOCK = (offset >> 4) & 0xFFFF;
    EEPROM.OFFSET = offset & 0xF;
    EEPROM.RDWR = data;
    ++offset;
}
