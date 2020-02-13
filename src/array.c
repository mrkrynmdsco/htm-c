
#include "array.h"


// Array attributes...
struct array {
    void* data;     // abstract data pointer
    dtype_e dtype;  // data type
    uint32 nitem;   // data item count
};

void Array_ctor (Array* const self, dtype_e dt, uint32 i) {
    self->data = NULL;  // unallocated data
    self->dtype = dt;
    self->nitem = i;
    // data allocation
    switch (self->dtype) {
        case UInt8: self->data = calloc(self->nitem, sizeof(uint8)); break;
        case UInt16: self->data = calloc(self->nitem, sizeof(uint16)); break;
        case UInt32: self->data = calloc(self->nitem, sizeof(uint32)); break;
        case Int8: self->data = calloc(self->nitem, sizeof(sint8)); break;
        case Int16: self->data = calloc(self->nitem, sizeof(sint16)); break;
        case Int32: self->data = calloc(self->nitem, sizeof(sint32)); break;
        case Real32: self->data = calloc(self->nitem, sizeof(real32)); break;
        default:
            self->dtype = INVALID_TYPE;
            self->nitem = 0;
            break;
    }
    return;
}

void Array_dtor (Array* const self) {
    // reset data
    if (self->data) {
        for (uint32 i=0; i < self->nitem; i++) {
            Array_SetDataByIndex(self, i, 0);
        }
    }
    // reset members
    self->data = NULL;
    self->nitem = 0;
    self->dtype = INVALID_TYPE;
    // free memory allocation
    free(self->data);
    free(self);
    return;
}

Array* Array_Create (dtype_e dt, uint32 i) {
    Array* arrPtr = (Array*) malloc(sizeof(Array));  // allocate object
    Array_ctor(arrPtr, dt, i);  // construct object
    return arrPtr;  // return pointer
}

void Array_Destroy (Array* const self) {
    Array_dtor(self);
    return;
}

void* Array_GetDataPtr (Array const* const self ) {
    return self->data;
}

dtype_e Array_GetDataType (Array const* const self) {
    return self->dtype;
}

uint32 Array_GetItemCount (Array const* const self) {
    return self->nitem;
}

void Array_SetDataByIndex (Array* const self, uint32 i, real32 v) {
    if ((self->data) && (i < self->nitem)) {    
        switch (self->dtype) {
            case UInt8: *(((uint8*)self->data) + i) = (uint8)v; break;
            case UInt16: *(((uint16*)self->data) + i) = (uint16)v; break;
            case UInt32: *(((uint32*)self->data) + i) = (uint32)v; break;
            case Int8: *(((sint8*)self->data) + i) = (sint8)v; break;
            case Int16: *(((sint16*)self->data) + i) = (sint16)v; break;
            case Int32: *(((sint32*)self->data) + i) = (sint32)v; break;
            case Real32: *(((real32*)self->data) + i) = (real32)v; break;
            default: break;
        }
    }
    return;
}

void* Array_GetDataByIndex (Array const* const self, uint32 i) {
    if ((self->data) && (i < self->nitem)) {
        switch (self->dtype) {
            case UInt8: return(((uint8*)self->data) + i);
            case UInt16: return(((uint16*)self->data) + i);
            case UInt32: return(((uint32*)self->data) + i);
            case Int8: return(((sint8*)self->data) + i);
            case Int16: return(((sint16*)self->data) + i);
            case Int32: return(((sint32*)self->data) + i);
            case Real32: return(((real32*)self->data) + i);
            default: break;
        }
    }
    return NULL;
}
