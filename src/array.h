#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

// Array class
typedef struct array Array;
// Array operations
extern void Array_ctor (Array* const self, dtype_e dt, uint32 i);
extern void Array_dtor (Array* const self);

extern Array* Array_Create (dtype_e dt, uint32 i);
extern void Array_Destroy (Array* const self);

extern void* Array_GetDataPtr (Array const* const self );
extern dtype_e Array_GetDataType (Array const* const self);
extern uint32 Array_GetItemCount (Array const* const self);

extern void Array_SetDataByIndex (Array* const self, uint32 i, real32 v);
extern void* Array_GetDataByIndex (Array* const self, uint32 i);


#endif // ARRAY_H
