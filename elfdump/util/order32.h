/* courtesy of https://stackoverflow.com/a/2103095 */

#ifndef __ORDER32_INCLUDE__
#define __ORDER32_INCLUDE__

#include <stdint.h>

#define ORDER_BIG_ENDIAN  	0xAABBCCDDUL
#define ORDER_LITTLE_ENDIAN	0xDDCCBBAAUL

static const union {
	uint8_t 	bytes[4];
	uint32_t 	value;
} order_endianness = { { 0xAA, 0xBB, 0xCC, 0xDD } };

#define ORDER_ENDIANNESS order_endianness.value

#endif
