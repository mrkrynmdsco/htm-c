
#include "bitarray.h"


// BitArray attributes...
struct bit_array {
    uint8* dense;   // pointer to bit array represented in byte
    uint16 nbits;   // total bit count
    uint16 dbyte;   // total bytes count
    // plus 4-bytes padding
};

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

uint8* BitArray_GetDense (BitArray const* const self) {
    return self->dense;
}

uint16 BitArray_GetBitCount (BitArray const* const self) {
    return self->nbits;
}

uint16 BitArray_GetByteCount (BitArray const* const self) {
    return self->dbyte;
}

void BitArray_SetByte (BitArray * const self, uint16 i, uint8 v) {
    if (i < self->dbyte) {
        self->dense[i] = v;
    }
    else {
        // Invalid index
    }
    
    return;
}

uint8 BitArray_GetByte (BitArray const* const self, uint16 i) {
    if (i < self->dbyte) {
        return self->dense[i];
    }
    else {
        // Invalid index
    }    
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

uint8 BitArray_GetBit (BitArray* const self, uint16 const i) {
    uint8 v = 0xFF;
    if (i >= 0 && i < self->nbits) {
        uint16 bit_index = i % CHAR_BITS;

        byte b = self->dense[(i/CHAR_BITS)];
        byte mask = 1 << bit_index;
        mask &= b;
        v = mask >> bit_index;
    }
    return v;
}
