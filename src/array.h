#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

typedef struct array {
    uint32 nitem;
    dtype_e dtype;
    void* data;
} Array;

// struct array_cfg {
//     uint32 nitem;
//     dtype_e dtype;
// };

// typedef struct uint8_array {
//     struct array_cfg cfg;
//     uint8* data;
// } UInt8Array;

// typedef struct uint16_array {
//     struct array_cfg cfg;
//     uint16* data;
// } UInt16Array;

// typedef struct uint32_array {
//     struct array_cfg cfg;
//     uint32* data;
// } UInt32Array;

// typedef struct sint8_array {
//     struct array_cfg cfg;
//     sint8* data;
// } Int8Array;

// typedef struct sint16_array {
//     struct array_cfg cfg;
//     sint16* data;
// } Int16Array;

// typedef struct sint32_array {
//     struct array_cfg cfg;
//     sint32* data;
// } Int32Array;

// typedef struct real32_array {
//     struct array_cfg cfg;
//     real32* data;
// } Real32Array;


#endif // ARRAY_H
