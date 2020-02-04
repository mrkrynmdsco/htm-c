#include "unity.h"
#include "map.h"

Map* map;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_map_Initializing_a_Map(void)
{
    map = Map_Create(4, 4);
    TEST_ASSERT_EQUAL(4, map->nrow);
    TEST_ASSERT_EQUAL(4, map->ncol);
    TEST_ASSERT_EQUAL(1, sizeof(map->nrow));
    TEST_ASSERT_EQUAL(1, sizeof(map->ncol));
}
