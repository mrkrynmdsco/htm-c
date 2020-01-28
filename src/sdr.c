
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
    sdr_p->dbyte = sdr_p->nbits / CHAR_BIT + (sdr_p->nbits % CHAR_BIT != 0);
    
    // allocate the SDR dense representation memory blocks
    sdr_p->dense = (uint8*) calloc(sdr_p->dbyte, sizeof(uint8));
    
    // allocate the SDR sparse representation memory blocks
    sdr_p->sparse = (uint16*) calloc(sdr_p->wbits, sizeof(uint16));

    return sdr_p;
}

// Reset (without deallocation)
void SDR_reset (SDR* self)
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
void SDR_destroy (SDR* obj)
{
    if (obj)
    {
        SDR_reset(obj);
        free(obj->dense);
        free(obj->sparse);
        free(obj);
    }
    return;
}