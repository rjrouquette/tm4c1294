//
// Created by robert on 5/15/22.
//

#include "emac.h"

void EMAC_MII_Write(volatile struct EMAC_MAP *emac, uint8_t address, uint16_t value) {
    // wait for MII to be ready
    while(emac->MIIADDR.MIB);
    emac->MIIDATA.DATA = value;
    emac->MIIADDR.MII = address;
    emac->MIIADDR.MIW = 1;
    emac->MIIADDR.MIB = 1;
}

uint16_t EMAC_MII_Read(volatile struct EMAC_MAP *emac, uint8_t address) {
    // wait for MII to be ready
    while(emac->MIIADDR.MIB);
    emac->MIIADDR.MII = address;
    emac->MIIADDR.MIW = 0;
    emac->MIIADDR.MIB = 1;
    // wait for MII to be ready
    while(emac->MIIADDR.MIB);
    // return value
    return emac->MIIDATA.DATA;
}

void EMAC_getMac(const volatile struct EMAC_MACADDR *macAddr, uint8_t *macBytes) {
    // get high bytes
    macBytes[5] = (macAddr->HI.ADDR >> 8) & 0xFF;
    macBytes[4] = (macAddr->HI.ADDR >> 0) & 0xFF;
    // get low bytes
    macBytes[3] = (macAddr->LO >> 24) & 0xFF;
    macBytes[2] = (macAddr->LO >> 16) & 0xFF;
    macBytes[1] = (macAddr->LO >> 8) & 0xFF;
    macBytes[0] = (macAddr->LO >> 0) & 0xFF;
}

void EMAC_setMac(volatile struct EMAC_MACADDR *macAddr, const uint8_t *macBytes) {
    uint32_t temp;
    // set high bytes
    temp = macBytes[5]; temp <<= 8;
    temp |= macBytes[4];
    macAddr->HI.ADDR = temp;
    // set low bytes
    temp = macBytes[3]; temp <<= 8;
    temp |= macBytes[2]; temp <<= 8;
    temp |= macBytes[1]; temp <<= 8;
    temp |= macBytes[0];
    macAddr->LO = temp;
}
