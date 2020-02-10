
#include "array.h"


void Array_ctor (Array* const self, dtype_e dt, uint32 i) {
    switch (dt) {
        case UInt8: self->dtype = dt; break;
        default:
            break;
    }

    self->nitem = i;

    return;
}

void* Array_Create (dtype_e dt, uint32 i) {
    UInt8Array* ptr;
    switch (dt) {
    case UInt8:
        ptr = (UInt8Array*) malloc(sizeof(UInt8Array));
        Array_ctor(&ptr->cfg, UInt8, i);
        return ptr;
    
    default:
        break;
    }
    
    
}
