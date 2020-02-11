#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_Creation(void) {
    Array x;

    TEST_ASSERT_EQUAL(8, sizeof(void*));
}
