#ifndef BITARRAY_H
#define BITARRAY_H

#include "types.h"

typedef struct bitarray {
    uint8* dense;
    uint16 nbits;
    uint16 dbyte;
    // plus 4-bytes padding
} BitArray;

extern void BitArray_ctor (BitArray* self, uint16 n);

#endif // BITARRAY_H
