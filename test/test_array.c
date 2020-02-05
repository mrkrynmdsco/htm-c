#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_Initialization_static(void) {
    Array arr;
    TEST_ASSERT_EQUAL(1, sizeof(arr.dtype));
}
