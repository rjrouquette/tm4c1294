/**
* Register Map Macros
 * @author Robert J. Rouquette
 * @date 2022-04-26
 */

#ifndef TM4C_REGISTER_H
#define TM4C_REGISTER_H

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

#endif //TM4C_REGISTER_H
