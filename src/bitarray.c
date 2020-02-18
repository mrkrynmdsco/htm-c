
#include "bitarray.h"


void BitArray_ctor (BitArray* const self, uint16 const n) {
    // validate number of bits
    self->nbits = n;
    // calculate number of bytes to be allocated for bit array
    self->nbyte = self->nbits / CHAR_BITS + (self->nbits % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->data = (uint8*) calloc(self->nbyte, sizeof(uint8));

    return;
}

void BitArray_dtor (BitArray* const self) {
    BitArray_Reset(self);
    self->nbits = 0;
    self->nbyte = 0;
    self->data = NULL;
    free(self->data);
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
    // reset data
    if (self->data) {
        for (uint16 i = 0; i < self->nbyte; i++) {
            self->data[i] = 0x00;
        }
    }
    return;
}

void BitArray_Destroy (BitArray* const self) {
    BitArray_dtor(self);
    return;
}

uint8* BitArray_GetDataPtr (BitArray const* const self) {
    return (uint8*)(self->data);
}

uint16 BitArray_GetBitCount (BitArray const* const self) {
    return (uint16)(self->nbits);
}

uint16 BitArray_GetByteCount (BitArray const* const self) {
    return (uint16)(self->nbyte);
}

void BitArray_SetByte (BitArray * const self, uint16 i, uint8 v) {
    if ((self->data) && (i < self->nbyte)) {
        self->data[i] = v;
    }    
    return;
}

uint8 BitArray_GetByte (BitArray const* const self, uint16 i) {
    if ((self->data) && (i < self->nbyte)) {
        return (uint8)(self->data[i]);
    }
    return -1;   
}

void __setBitVal__(uint8* a, uint16 const i, uint8 v) {
    uint16 byte_index = i / CHAR_BITS;
    uint16 bit_index = i % CHAR_BITS;

    byte b = (byte)(a[byte_index]);
    byte mask = 1 << bit_index;
    b &= ~mask;
    if (v) b |= mask;

    a[byte_index] = b;
}

void BitArray_SetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < self->nbits) {
        __setBitVal__(self->data, i, 1);
    }
    return;
}

void BitArray_ResetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < self->nbits) {
        __setBitVal__(self->data, i, 0);
    }
    return;
}

uint8 BitArray_GetBit (BitArray* const self, uint16 const i) {
    uint8 v = 0xFF;
    if (i >= 0 && i < self->nbits) {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = (byte)(self->data[byte_index]);
        byte mask = 1 << bit_index;
        mask &= b;
        v = mask >> bit_index;
    }
    return v;
}
