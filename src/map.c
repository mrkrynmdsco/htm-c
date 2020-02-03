
#include "map.h"


void map_ctor (Map* self, uint8 row, uint8 col) {
    self->nrow = row;
    self->ncol = col;
    self->data = 0;
    return;
}

Map* map_Create (uint8 row, uint8 col) {
    Map* map_p = (Map*) malloc(sizeof(Map));

    map_ctor(map_p, row, col);

    return map_p;
}
