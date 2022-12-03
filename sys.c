//
// Created by robert on 12/3/22.
//

#include "sys.h"

unsigned RAM_size() {
    unsigned size = *(const uint32_t *) 0x400FDFC4;
    size &= 0xffff;
    size += 1;
    size <<= 8;
    return size;
}

unsigned EEPROM_size() {
    unsigned size = *(const uint32_t *) 0x400AF000;
    size &= 0xffff;
    size <<= 2;
    return size;
}

unsigned FLASH_size() {
    unsigned size = *(const uint32_t *) 0x400FDFC0;
    size &= 0xffff;
    size += 1;
    size <<= 11;
    return size;
}
