
#include "sdr.h"


// Constructor (initialization and allocation)
SDR* SDR_create (uint16 n, real32 s)
{
    // allocate the SDR object and return a pointer to it
    SDR* sdr_p = (SDR*) malloc(sizeof(SDR));

    // total number of bit population
    sdr_p->nbits = n;

    // sparsity percentage
    sdr_p->sprct = s;

    // calculate number of expected ON-bits
    sdr_p->wbits = (uint16) (n * s);

    // calculate number of bytes to be allocated for dense representation
    sdr_p->dbyte = sdr_p->nbits / CHAR_BITS + (sdr_p->nbits % CHAR_BITS != 0);
    
    // allocate the SDR dense representation memory blocks
    sdr_p->dense = (uint8*) calloc(sdr_p->dbyte, sizeof(uint8));
    
    // allocate the SDR sparse representation memory blocks (read-only)
    sdr_p->sparse = (uint16*) calloc(sdr_p->wbits, sizeof(uint16));

    return sdr_p;
}

// Reset all bits(without deallocation)
void SDR_reset_all (SDR* self)
{
    // All dense elements reset to zero
    for(uint16 i = 0 ; i < sizeof(self->dense) ; i++)
    {
        self->dense[i] = 0;
    }

    // All sparse elements reset to zero
    for(uint16 i=0 ; i<self->wbits ; i++)
    {
        self->sparse[i] = 0;
    }

    return;
}

// Destructor (deallocation and destroy)
void SDR_destroy (SDR* self)
{
    if (self)
    {
        SDR_reset_all(self);
        free(self->dense);
        free(self->sparse);
        free(self);
    }
    return;
}

void SDR_set (SDR* self, uint16 i)
{
    // check array[index] = (value != 0)
    if (i >= 0 && i < self->nbits)
    {
        uint16 byte_index = i / CHAR_BITS;
        uint16 bit_index = i % CHAR_BITS;

        byte b = self->dense[byte_index];
        byte mask = 1 << bit_index;
        // b &= ~mask;
        b |= mask;
        
        self->dense[byte_index] = b;
    }

    return;
}

uint8 SDR_get (SDR* self, uint16 i)
{
    uint8 state;

    // return the bit at the given index, or -1 if out of bounds
    if (i < 0 || i >= self->nbits)
    {
       state = -1;
    }
    else
    {
       uint16 byte_index = i / CHAR_BITS;
       uint16 bit_index = i % CHAR_BITS;
       state = (self->dense[byte_index] >> bit_index) & 1;
    }

    return state;
}
