#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

typedef struct array_cfg {
    uint32 nitem;
    dtype_e dtype;
} ArrayConfig;

typedef struct uint8_array
{
    ArrayConfig cfg;
    uint8* data;
} UInt8_Array;


#endif // ARRAY_H
