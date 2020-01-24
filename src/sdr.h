
#ifndef HTM_SDR_H
#define HTM_SDR_H


#include "types.h"

typedef struct SDR
{
    uint16 nbits;   // vector size
    real32 sprct;   // sparsity (percentage)
    uint16 wbits;   // vector cardinality (ON-bits count)
    uint16* data;   // pointer to an array of ON-bits indices
} SDR;

// typedef struct sdr SDR;

extern SDR* SDR__create(uint16 n, real32 s);
extern void SDR__destroy(SDR* obj);

extern void SDR__init(SDR* self, uint16 n, real32 s);
extern void SDR__reset(SDR* self);

#endif // HTM_SDR_H
