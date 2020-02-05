
#include "bitarray.h"


void BitArray_ctor (BitArray* const self, uint16 const n) {
    self->nbits = n;
    // calculate number of bytes to be allocated for dense representation
    self->dbyte = self->nbits / CHAR_BITS + (self->nbits % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->dense = (uint8*) calloc(self->dbyte, sizeof(uint8));

    return;
}

void BitArray_dtor (BitArray* const self) {
    BitArray_Reset(self);
    self->nbits = 0;
    self->dbyte = 0;
    self->dense = NULL;
    free(self->dense);
    return;
}

BitArray* BitArray_Create (uint16 const n) {
    // allocate memory
    BitArray* ptr = (BitArray*) malloc(sizeof(BitArray));
    // construct the object
    BitArray_ctor(ptr, n);
    // return the pointer of the object
    return ptr;
}

void BitArray_Reset (BitArray* const self) {
    // reset all bits
    for (uint16 i = 0; i < self->dbyte; i++) {
        self->dense[i] = 0;
    }
    return;
}

void BitArray_Destroy (BitArray* const self) {
    BitArray_dtor(self);
    return;
}

void BitArray_SetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < self->nbits) {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = self->dense[byte_index];
        byte mask = 1 << bit_index;
        b |= mask;
        
        self->dense[byte_index] = b;
    }
    return;
}

void BitArray_ResetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < self->nbits) {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = self->dense[byte_index];
        byte mask = 1 << bit_index;
        b &= ~mask;

        self->dense[byte_index] = b;
    }
    return;
}
