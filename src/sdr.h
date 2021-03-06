
#ifndef HTM_SDR_H
#define HTM_SDR_H


#include "types.h"
#include "bitarray.h"

/* SDR Class */
typedef struct sdr {
    uint16 nbits;   // vector size
    real32 sprct;   // sparsity (percentage)
    uint16 wbits;   // vector cardinality (ON-bits count)
    
    uint16 dbyte;   // dense bytes

    uint16 s_pos;   // most recent vacant sparse position
    uint16* sparse; // pointer to an array of ON-bits indices

    uint8 isdense;  // flag to include calculation of dense representation
    uint8* dense;   // pointer to an array of bits of dense representation
}  SDR;

/* SDR Operations */
extern void SDR_ctor (SDR* const self, uint16 n, real32 s, uint8 isdense);
extern SDR* SDR_Create (uint16 n, real32 s, uint8 isdense);
extern void SDR_Destroy (SDR* const self);

extern void SDR_ResetAll (SDR* const self);

extern void SDR_SparseSet (SDR* const self, uint16 i);

extern void SDR_DenseSet (SDR* const self, uint16 i);
extern void SDR_DenseReset (SDR* const self, uint16 i);
extern uint8 SDR_DenseGet (SDR* const self, uint16 i);
extern void SDR_DensePrint (SDR* const self);

#endif // HTM_SDR_H
