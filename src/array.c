
#include "array.h"


void Array_ctor (Array* const self, dtype_e dt, uint32 i) {
    self->dtype = dt;
    self->nitem = i;
    return;
}

void* Array_Create (dtype_e dt, uint32 i) {
    switch (dt) {
        case UInt8: {
            UInt8Array* ptr;
            ptr = (UInt8Array*) malloc(sizeof(UInt8Array));
            Array_ctor(&ptr->cfg, UInt8, i);
            ptr->data = (uint8*) calloc(ptr->cfg.nitem, sizeof(uint8));
            return ptr;
        }
        case UInt16: {
            UInt16Array* ptr;
            ptr = (UInt16Array*) malloc(sizeof(UInt16Array));
            Array_ctor(&ptr->cfg, UInt16, i);
            ptr->data = (uint16*) calloc(ptr->cfg.nitem, sizeof(uint16));
            return ptr;
        }
        case UInt32: {
            UInt32Array* ptr;
            ptr = (UInt32Array*) malloc(sizeof(UInt32Array));
            Array_ctor(&ptr->cfg, UInt32, i);
            ptr->data = (uint32*) calloc(ptr->cfg.nitem, sizeof(uint32));
            return ptr;
        }
        case Int8: {
            Int8Array* ptr;
            ptr = (Int8Array*) malloc(sizeof(Int8Array));
            Array_ctor(&ptr->cfg, Int8, i);
            ptr->data = (sint8*) calloc(ptr->cfg.nitem, sizeof(sint8));
            return ptr;
        }
        case Int16: {
            Int16Array* ptr;
            ptr = (Int16Array*) malloc(sizeof(Int16Array));
            Array_ctor(&ptr->cfg, Int16, i);
            ptr->data = (sint16*) calloc(ptr->cfg.nitem, sizeof(sint16));
            return ptr;
        }
        case Int32: {
            Int32Array* ptr;
            ptr = (Int32Array*) malloc(sizeof(Int32Array));
            Array_ctor(&ptr->cfg, Int32, i);
            ptr->data = (sint32*) calloc(ptr->cfg.nitem, sizeof(sint32));
            return ptr;
        }
        case Real32: {
            Real32Array* ptr;
            ptr = (Real32Array*) malloc(sizeof(Real32Array));
            Array_ctor(&ptr->cfg, Real32, i);
            ptr->data = (real32*) calloc(ptr->cfg.nitem, sizeof(real32));
            return ptr;
        }
        default:
            break;
    }
    
    
}
