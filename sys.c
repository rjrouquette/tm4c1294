//
// Created by robert on 12/3/22.
//

#include "eeprom.h"
#include "sys.h"

// .text/code, stored in Flash
extern int _text;
extern int _etext;
// .data, copied into RAM on boot
extern int _data;
extern int _edata;
// .bss, uninitialized variables
extern int _bss;
extern int _ebss;

inline int sectionSize(const int *begin, const int *end) {
    return ((char*) end) - ((char*) begin);
}

unsigned RAM_used() {
    return sectionSize(&_bss, &_ebss) + sectionSize(&_data, &_edata);
}

unsigned RAM_size() {
    unsigned size = *(const uint32_t *) 0x400FDFC4;
    size &= 0xffff;
    size += 1;
    size <<= 8;
    return size;
}

unsigned EEPROM_size() {
    unsigned size = EEPROM.SIZE.WORDCNT;
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

unsigned FLASH_used() {
    return sectionSize(&_data, &_edata) + sectionSize(&_text, &_etext);
}
