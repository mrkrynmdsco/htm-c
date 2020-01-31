
#ifndef HTM_SDR_H
#define HTM_SDR_H


#include "types.h"

typedef struct SDR
{
    uint16 nbits;   // vector size
    real32 sprct;   // sparsity (percentage)
    uint16 wbits;   // vector cardinality (ON-bits count)
    
    uint16 dbyte;   // dense bytes

    uint16 s_pos;   // most recent vacant sparse position
    uint16* sparse; // pointer to an array of ON-bits indices

    uint8 isdense;  // flag to include calculation of dense representation
    uint8* dense;   // pointer to an array of bits of dense representation
} SDR;

extern SDR* sdr_Create (uint16 n, real32 s, uint8 isdense);
extern void sdr_Destroy (SDR* const self);

extern void sdr_Reset (SDR* const self, uint16 i);
extern void sdr_ResetAll (SDR* const self);

extern void sdr_SparseSet (SDR* const self, uint16 i);

extern void sdr_DenseSet (SDR* const self, uint16 i);
extern uint8 sdr_DenseGet (SDR* const self, uint16 i);

#endif // HTM_SDR_H
