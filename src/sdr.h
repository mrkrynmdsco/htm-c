
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

extern SDR* sdr_Create (uint16 n, real32 s);
extern void sdr_Destroy (SDR* self);

extern void sdr_Reset (SDR* self, uint16 i);
extern void sdr_ResetAll (SDR* self);

extern void sdr_DenseSet (SDR* self, uint16 i);
extern uint8 sdr_DenseGet (SDR* self, uint16 i);

#endif // HTM_SDR_H
