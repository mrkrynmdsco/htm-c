
#include "bitarray.h"


void BitArray_ctor (BitArray* const self, uint16 const n) {
    // calculate number of bytes to be allocated for bit array
    self->dbytes = n / CHAR_BITS + (n % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->darray = Array_Create(Bit, self->dbytes);

    return;
}

void BitArray_dtor (BitArray* const self) {
    BitArray_Reset(self);
    self->dbytes = 0;
    self->darray = NULL;
    free(self->darray);
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
    if (Array_GetDataPtr(self->darray)) {
        Array_Reset(self->darray);
    }
    return;
}

void BitArray_Destroy (BitArray* const self) {
    BitArray_dtor(self);
    return;
}

uint8* BitArray_GetDense (BitArray const* const self) {
    return (uint8*)Array_GetDataPtr(self->darray);
}

uint16 BitArray_GetBitCount (BitArray const* const self) {
    return (uint16)Array_GetItemCount(self->darray);
}

uint16 BitArray_GetByteCount (BitArray const* const self) {
    return (uint16)self->dbytes;
}

void BitArray_SetByte (BitArray * const self, uint16 i, uint8 v) {
    if (i < self->dbytes) {
        Array_SetDataByIndex(self->darray, i, v);
    } else {
        // Invalid index
    }
    
    return;
}

uint8 BitArray_GetByte (BitArray const* const self, uint16 i) {
    if (i < self->dbytes) {
        return (uint8)(*(uint8*)(Array_GetDataByIndex(self->darray, i)));
    }
    return -1;   
}

void BitArray_SetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < (uint16)Array_GetItemCount(self->darray)) {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = (byte)(*(uint8*)(Array_GetDataByIndex(self->darray, byte_index)));
        byte mask = 1 << bit_index;
        b |= mask;        
        Array_SetDataByIndex(self->darray, byte_index, b);
    }
    return;
}

void BitArray_ResetBit (BitArray* const self, uint16 const i) {
    if (i >= 0 && i < (uint16)Array_GetItemCount(self->darray)) {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = (byte)(*(uint8*)(Array_GetDataByIndex(self->darray, byte_index)));
        byte mask = 1 << bit_index;
        b &= ~mask;
        Array_SetDataByIndex(self->darray, byte_index, b);
    }
    return;
}

uint8 BitArray_GetBit (BitArray* const self, uint16 const i) {
    uint8 v = 0xFF;
    if (i >= 0 && i < (uint16)Array_GetItemCount(self->darray)) {
        uint16 bit_index = i % CHAR_BITS;

        byte b = (byte)(*(uint8*)(Array_GetDataByIndex(self->darray, (i/CHAR_BITS))));
        byte mask = 1 << bit_index;
        mask &= b;
        v = mask >> bit_index;
    }
    return v;
}
