#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

/* Array Class */
typedef struct array {
    void* data;     // abstract data pointer
    dtype_e dtype;  // data type
    uint32 nitem;   // data item count
} Array;

/* Array Operations */
extern void Array_ctor (Array* const self, dtype_e dt, uint32 i);
extern void Array_dtor (Array* const self);

extern Array* Array_Create (dtype_e dt, uint32 i);
extern void Array_Reset (Array* const self);
extern void Array_Destroy (Array* const self);

extern void* Array_GetDataPtr (Array const* const self );
extern dtype_e Array_GetDataType (Array const* const self);
extern uint32 Array_GetItemCount (Array const* const self);

extern void Array_SetDataByIndex (Array* const self, uint32 i, real32 v);
extern void* Array_GetDataByIndex (Array const* const self, uint32 i);


#endif // ARRAY_H
