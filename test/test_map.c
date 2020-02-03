#include "unity.h"
#include "map.h"

Map* map;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_map_Create(void)
{
    map = map_Create(4, 4);
    TEST_ASSERT_EQUAL(4, map->nrow);
    TEST_ASSERT_EQUAL(4, map->ncol);
    TEST_ASSERT_EQUAL(2, sizeof(map->data));
}
