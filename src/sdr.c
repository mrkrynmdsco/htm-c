
#include "sdr.h"


void _init_dense (SDR* const self)
{
    // calculate number of bytes to be allocated for dense representation
    self->dbyte = self->nbits / CHAR_BITS + (self->nbits % CHAR_BITS != 0);
    // allocate the SDR dense representation memory blocks
    self->dense = (uint8*) calloc(self->dbyte, sizeof(uint8));
}

// Constructor (initialization and allocation)
SDR* sdr_Create (uint16 n, real32 s, uint8 isdense)
{
    // allocate the SDR object and return a pointer to it
    SDR* sdr_p = (SDR*) malloc(sizeof(SDR));

    // total number of bit population
    sdr_p->nbits = n;

    // sparsity percentage
    sdr_p->sprct = s;

    // calculate number of expected ON-bits
    sdr_p->wbits = (uint16) (n * s);

    // sparse position
    sdr_p->s_pos = 0;
    
    // allocate the SDR sparse representation memory blocks (read-only)
    sdr_p->sparse = (uint16*) calloc(sdr_p->wbits, sizeof(uint16));
    
    sdr_p->isdense = isdense;

    if (sdr_p->isdense)
    {
        _init_dense(sdr_p);
    }
    else
    {
        sdr_p->dbyte = 0;
        sdr_p->dense = NULL;
    }
    
    return sdr_p;
}

// Reset all bits(without deallocation)
void sdr_ResetAll (SDR* const self)
{
    // All dense elements reset to zero
    if (self->dense)
    {
        for(uint16 i = 0 ; i < sizeof(self->dense) ; i++)
        {
            self->dense[i] = 0;
        }
    }

    // All sparse elements reset to zero
    if (self->sparse)
    {
        for(uint16 i=0 ; i<self->wbits ; i++)
        {
            self->sparse[i] = 0;
        }
    }

    // sparse position
    self->s_pos = 0;

    return;
}

// Destructor (deallocation and destroy)
void sdr_Destroy (SDR* const self)
{
    if (self)
    {
        sdr_ResetAll(self);
        free(self->dense);
        free(self->sparse);
        free(self);
    }
    return;
}

void sdr_SparseSet (SDR* const self, uint16 i)
{
    uint8 idx = 0;
    uint8 addOk = 0;

    // check if valid index is to be added into the set
    if ((0 <= i) && (self->wbits > i))
    {
        // check if the index already listed
        for (idx = 0; idx <= self->s_pos; idx++)
        {
            if (i == self->sparse[idx])
            {
                addOk = 0;
                break;
            }
            else
            {
                addOk = 1;
                break;
            }
        }
    }
    else
    {
        addOk = 0;
    }

    if (addOk)
    {
        self->sparse[self->s_pos] = i;
        self->s_pos++;
    }

    return;
}

void sdr_DenseSet (SDR* const self, uint16 i)
{
    if (self->isdense)
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
    }

    return;
}

uint8 sdr_DenseGet (SDR* const self, uint16 i)
{
    if (self->isdense)
    {
        uint8 state;
        // return the bit at the given index, or -1 if out of bounds
        if (i < 0 || i >= self->nbits)
        {
            state = 255;
        }
        else
        {
            uint16 byte_index = i / CHAR_BITS;
            uint16 bit_index = i % CHAR_BITS;
            state = (self->dense[byte_index] >> bit_index) & 1;
        }

        return state;
    }
    else return 255;
}
