
#include "sdr.h"


void _init_dense (SDR* const self) {
    // calculate number of bytes to be allocated for dense representation
    self->dbyte = self->nbits / CHAR_BITS + (self->nbits % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->dense = (uint8*) calloc(self->dbyte, sizeof(uint8));
}

// Constructor (initialization and allocation)
void SDR_ctor (SDR* const self, uint16 n, real32 s, uint8 isdense) {
    // total number of bit population
    self->nbits = n;
    // sparsity percentage
    self->sprct = s;
    // calculate number of expected ON-bits
    self->wbits = (uint16) (n * s);
    // sparse list position
    self->s_pos = 0;
    // allocate the SDR sparse representation memory blocks (read-only)
    self->sparse = (uint16*) calloc(self->wbits, sizeof(uint16));
    // flag to use dense representation    
    self->isdense = isdense;

    if (self->isdense) {
        _init_dense(self);
    }
    else {
        self->dbyte = 0;
        self->dense = NULL;
    }
    return;
}

void SDR_dtor (SDR* const self) {
    if (self) {
        SDR_ResetAll(self);
        free(self->dense);
        free(self->sparse);
        free(self);
    }
    return;
}

// Dynamic allocation
SDR* SDR_Create (uint16 n, real32 s, uint8 isdense) {
    // allocate the SDR object
    SDR* sdr_p = (SDR*) malloc(sizeof(SDR));
    // contruct the object
    SDR_ctor(sdr_p, n, s, isdense);
    // return the pointer to the object
    return sdr_p;
}

// Reset all bits (without deallocation)
void SDR_ResetAll (SDR* const self) {
    // All dense elements reset to zero
    if (self->dense) {
        for(uint16 i = 0 ; i < sizeof(self->dense) ; i++) {
            self->dense[i] = 0;
        }
    }
    // All sparse elements reset to zero
    if (self->sparse) {
        for(uint16 i=0 ; i<self->wbits ; i++) {
            self->sparse[i] = 0;
        }
    }
    // sparse position
    self->s_pos = 0;

    return;
}

// Destructor (deallocation and destroy)
void SDR_Destroy (SDR* const self) {
    SDR_dtor(self);
    return;
}

// Add index value into the sparse activated list
void SDR_SparseSet (SDR* const self, uint16 i) {
    uint8 idx = 0;
    uint8 addOk = 0;

    // check if valid index is to be added into the set
    if ((0 <= i) && (self->wbits > i)) {
        // check if the index already listed
        for (idx = 0; idx <= self->s_pos; idx++) {
            if (i == self->sparse[idx]) {
                addOk = 0;
                break;
            }
            else {
                addOk = 1;
                break;
            }
        }
    }
    else {
        addOk = 0;
    }

    if (addOk) {
        self->sparse[self->s_pos] = i;
        self->s_pos++;
    }

    return;
}

// Set a bit status by index
void SDR_DenseSet (SDR* const self, uint16 i) {
    if (self->isdense) {
        // check array[index] = (value != 0)
        if (i >= 0 && i < self->nbits) {
            uint16 byte_index = i / CHAR_BITS;
            uint16 bit_index = i % CHAR_BITS;

            byte b = self->dense[byte_index];
            byte mask = 1 << bit_index;
            b |= mask;
            
            self->dense[byte_index] = b;
        }
    }

    return;
}

// Reset a bit status by index
void SDR_DenseReset (SDR* const self, uint16 i) {
    if (self->isdense) {
        // check array[index] = (value != 0)
        if (i >= 0 && i < self->nbits) {
            uint16 byte_index = i / CHAR_BITS;
            uint16 bit_index = i % CHAR_BITS;

            byte b = self->dense[byte_index];
            byte mask = 1 << bit_index;
            b &= ~mask;

            self->dense[byte_index] = b;
        }
    }

    return;
}

// Get a bit status by index
uint8 SDR_DenseGet (SDR* const self, uint16 i) {
    if (self->isdense) {
        uint8 state;
        // return the bit at the given index, or -1 if out of bounds
        if (i < 0 || i >= self->nbits) {
            state = 255;
        }
        else {
            uint16 byte_index = i / CHAR_BITS;
            uint16 bit_index = i % CHAR_BITS;
            state = (self->dense[byte_index] >> bit_index) & 1;
        }

        return state;
    }
    else return 255;
}

// Print out dense representation
void SDR_DensePrint (SDR* const self) {
    uint16 i, n;
    n = self->nbits;
    
    for (i = 0; i < n; ++i) {
        putchar(SDR_DenseGet(self, i) ? '1' : '0');
    }
    return;
}
