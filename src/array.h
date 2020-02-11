#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

struct array {
    void* data;
    dtype_e dtype;
    uint32 nitem;
};

typedef struct array Array;


#endif // ARRAY_H
