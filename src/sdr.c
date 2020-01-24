
#include "sdr.h"


// Constructor (without allocation)
void SDR__init (SDR* self, uint16 n, real32 s)
{
    self->nbits = n;
    self->sprct = s;
    self->wbits = (uint16) (n * s);

    return;
}

// Allocation and Initialization
SDR* SDR__create (uint16 n, real32 s)
{
    // allocate the SDR object
    SDR* sdr_p = (SDR*) malloc(sizeof(SDR));
    SDR__init(sdr_p, n, s);
    // allocate the SDR data memory blocks
    sdr_p->data = (uint16*) calloc(sdr_p->wbits, sizeof(uint16));
    
    return sdr_p;
}

// Destructor (without deallocation)
void SDR__reset (SDR* self)
{
    // All elements reset to zero
    for(uint16 i=0 ; i<self->wbits ; i++)
    {
        self->data[i] = 0;
    }
    return;
}

// Deallocation and Destroy
void SDR__destroy (SDR* obj)
{
    if (obj)
    {
        SDR__reset(obj);
        free(obj->data);
        free(obj);
    }
    return;
}