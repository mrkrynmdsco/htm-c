
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "bitarray.h"


BitArray* BitArray_create (uint16 num_bits)
{
   // allocate memory for a BitArray and return a pointer to it
    BitArray* array = (BitArray*) malloc(sizeof(BitArray));
    uint16 bytes_required = num_bits / CHAR_BITS + (num_bits % CHAR_BITS != 0);

    array->nbits = num_bits;
    array->data = (uint8*) calloc(bytes_required, sizeof(uint8));

    return array;
}

void BitArray_destroy (BitArray* array)
{
    // deallocate memory for a BitArray
    free(array->data);
    free(array);
    return;
}

uint16 BitArray_get (BitArray* array, uint16 index)
{
    // return the bit at the given index, or -1 if out of bounds
    if (index < 0 || index >= array->nbits)
    {
       return -1;
    }
    else
    {
       uint16 byte_index = index / CHAR_BITS;
       uint16 bit_index = index % CHAR_BITS;
       return (array->data[byte_index] >> bit_index) & 1;
    }
}

void BitArray_set (BitArray* array, uint16 index, uint16 value)
{
    // check array[index] = (value != 0)
    if (index >= 0 || index < array->nbits)
    {
        uint16 byte_index = index / CHAR_BITS;
        uint16 bit_index = index % CHAR_BITS;
        byte b = array->data[byte_index];
        byte mask = 1 << bit_index;
        b &= ~mask;
        
        if (value)
        {
            b |= mask;
        }

        array->data[byte_index] = b;
    }
    return;
}

void BitArray_print (BitArray* array)
{
    uint16 i, n;
    n = array->nbits;
    
    for (i = 0; i < n; ++i)
    {
        putchar(BitArray_get(array, i) ? '1' : '0');
    }
    return;
}
