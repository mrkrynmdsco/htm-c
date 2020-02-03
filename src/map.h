
#ifndef HTM_MAP_H
#define HTM_MAP_H

#include "types.h"

typedef struct map {
    uint8 nrow;
    uint8 ncol;
} Map;

extern Map* map_Create(uint8 row, uint8 col);

#endif // HTM_MAP_H
