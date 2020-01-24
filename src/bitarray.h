
#ifndef HTM_BITARRAY_H
#define HTM_BITARRAY_H


#include "types.h"

typedef struct BitArray
{
   uint16 nbits;    // number of bits in the array
   byte*  data;     // pointer to the bit array
} BitArray;

extern BitArray* BitArray_create(uint16 num_bits);
extern void BitArray_destroy(BitArray* array);

extern uint16 BitArray_get(BitArray* array, uint16 index);
extern void BitArray_set(BitArray* array, uint16 index, uint16 value);
extern void BitArray_print(BitArray* array);

#endif // HTM_BITARRAY_H
