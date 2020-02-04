
#include "map.h"


void Map_ctor (Map* self, uint8 row, uint8 col) {
    self->nrow = row;
    self->ncol = col;
    return;
}

Map* Map_Create (uint8 row, uint8 col) {
    // allocate the Map object
    Map* map_p = (Map*) malloc(sizeof(Map));
    // construct the object
    Map_ctor(map_p, row, col);
    // return the pointer to the object
    return map_p;
}
