#ifndef BITARRAY_H
#define BITARRAY_H

#include "types.h"
#include "array.h"

/* BitArray Class */
typedef struct bitarray {
    uint8* data;    // pointer to bit array data
    uint16 nbits;   // total bit count
    uint16 nbyte;   // total byte count
} BitArray;

// BitArray Operations
extern void BitArray_ctor (BitArray* const self, uint16 const n);
extern void BitArray_dtor (BitArray* const self);

extern BitArray* BitArray_Create (uint16 const n);
extern void BitArray_Reset (BitArray* const self);
extern void BitArray_Destroy (BitArray* const self);

extern uint8* BitArray_GetDataPtr (BitArray const* const self);
extern uint16 BitArray_GetBitCount (BitArray const* const self);
extern uint16 BitArray_GetByteCount (BitArray const* const self);

extern void BitArray_SetByte (BitArray * const self, uint16 i, uint8 v);
extern uint8 BitArray_GetByte (BitArray const* const self, uint16 i);

extern void BitArray_SetBit (BitArray* const self, uint16 const i);
extern void BitArray_ResetBit (BitArray* const self, uint16 const i);
extern uint8 BitArray_GetBit (BitArray* const self, uint16 const i);

#endif // BITARRAY_H
