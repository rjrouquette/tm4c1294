//
// Created by robert on 4/23/23.
//

#include "eeprom.h"

static int offset_;

void EEPROM_wait() {
    while (EEPROM.DONE.WORKING) {}
}

void EEPROM_mass_erase() {
    // wait for eeprom ready
    EEPROM_wait();
    // start mass erase
    EEPROM.DBGME = EEPROM_DBGME_KEY;
    // wait for mass erase
    while (EEPROM.DBGME)
        __asm volatile("nop");
    // wait for eeprom ready
    EEPROM_wait();
    offset_ = 0;
}

void EEPROM_seek(const int offset) {
    offset_ = offset;
}

uint32_t EEPROM_read() {
    EEPROM_wait();
    EEPROM.BLOCK = (offset_ >> 4) & 0xFFFF;
    EEPROM.OFFSET = offset_ & 0xF;
    ++offset_;
    return EEPROM.RDWR;
}

void EEPROM_write(const uint32_t data) {
    EEPROM_wait();
    EEPROM.BLOCK = (offset_ >> 4) & 0xFFFF;
    EEPROM.OFFSET = offset_ & 0xF;
    EEPROM.RDWR = data;
    ++offset_;
}
