#ifndef BITARRAY_H
#define BITARRAY_H

#include "types.h"

typedef struct bit_array {
    uint8* dense;
    uint16 nbits;
    uint16 dbyte;
    // plus 4-bytes padding
} BitArray;

extern void BitArray_ctor (BitArray* const self, uint16 const n);
extern void BitArray_dtor (BitArray* const self);

extern BitArray* BitArray_Create (uint16 const n);
extern void BitArray_Reset (BitArray* const self);
extern void BitArray_Destroy (BitArray* const self);

extern void BitArray_SetBit (BitArray* const self, uint16 const i);
extern void BitArray_ResetBit (BitArray* const self, uint16 const i);

#endif // BITARRAY_H
