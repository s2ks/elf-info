/* courtesy of https://stackoverflow.com/a/2103095 */

#ifndef __ORDER32_INCLUDE__
#define __ORDER32_INCLUDE__

#include <stdint.h>

#define ORDER_BIG_ENDIAN  	0x12345678UL
#define ORDER_LITTLE_ENDIAN	0x87654321UL

static const union {
	uint8_t 	bytes[4];
	uint32_t 	value;
} order_endianness = { { 0x12, 0x34, 0x56, 0x78 } };

#define ORDER_ENDIANNESS order_endianness.value

#endif
