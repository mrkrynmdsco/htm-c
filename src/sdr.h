
#ifndef HTM_SDR_H
#define HTM_SDR_H


#include "types.h"

typedef struct SDR
{
    uint16 nbits;   // vector size
    real32 sprct;   // sparsity (percentage)
    uint16 wbits;   // vector cardinality (ON-bits count)
    
    uint16 dbyte;   // dense bytes

    uint8* dense;   // pointer to an array of bits of dense representation
    uint16* sparse; // pointer to an array of ON-bits indices
    

} SDR;

extern SDR* SDR_create (uint16 n, real32 s);
extern void SDR_destroy (SDR* self);

extern void SDR_set (SDR* self, uint16 i);
extern void SDR_reset (SDR* self, uint16 i);

extern uint8 SDR_get (SDR* self, uint16 i);
extern void SDR_reset_all (SDR* self);

#endif // HTM_SDR_H
