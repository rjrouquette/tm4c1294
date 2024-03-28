//
// Created by robert on 4/26/22.
//

#ifndef GPSDO_REGISTER_H
#define GPSDO_REGISTER_H

#ifdef __cplusplus
extern "C" {
#else
#define static_assert _Static_assert
#endif

#include <stdint.h>

#define REGMAP_32(type, fields) union type { struct fields; uint32_t raw; }

#define PAGE_MAP(type, fields) struct type fields; static_assert(sizeof(struct type) == 4096, "PERIPHERAL_MAP must be 4096 bytes");

#ifdef __cplusplus
}
#endif

#endif //GPSDO_REGISTER_H
