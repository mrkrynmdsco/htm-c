
#include "bitarray.h"


void BitArray_ctor (BitArray* self, uint16 n) {
    self->nbits = n;
    // calculate number of bytes to be allocated for dense representation
    self->dbyte = self->nbits / CHAR_BITS + (self->nbits % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->dense = (uint8*) calloc(self->dbyte, sizeof(uint8));

    return;
}
