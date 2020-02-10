#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

typedef struct array {
    dtype_e dtype;
    uint32 nitem;
} Array;

typedef struct uint8_a {
    Array cfg;
    uint8* data;
} UInt8Array;

typedef struct uint16_a {
    Array cfg;
    uint16* data;
} UInt16Array;

typedef struct uint32_a {
    Array cfg;
    uint32* data;
} UInt32Array;

typedef struct sint8_a {
    Array cfg;
    sint8* data;
} Int8Array;

typedef struct sint16_a {
    Array cfg;
    sint16* data;
} Int16Array;

typedef struct sint32_a {
    Array cfg;
    sint32* data;
} Int32Array;

typedef struct real32_a {
    Array cfg;
    real32* data;
} Real32Array;

extern void* Array_Create (dtype_e dt, uint32 i);

#endif // ARRAY_H
