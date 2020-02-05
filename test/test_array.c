#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_Config_Initialization_static(void) {
    ArrayConfig cfg;
    TEST_ASSERT_EQUAL(8, sizeof(cfg));
    TEST_ASSERT_EQUAL(4, sizeof(cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(cfg.dtype));
}

void test_array_UInt8_Initialization_static(void) {
   UInt8_Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}
