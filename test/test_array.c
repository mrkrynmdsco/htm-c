#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_UInt8_Initialization_static(void) {
    UInt8Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_UInt16_Initialization_static(void) {
    UInt16Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_UInt32_Initialization_static(void) {
    UInt32Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_Int8_Initialization_static(void) {
    Int8Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_Int16_Initialization_static(void) {
    Int16Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_Int32_Initialization_static(void) {
    Int32Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}

void test_array_Real32_Initialization_static(void) {
    Real32Array arr;
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.data));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.nitem));
    TEST_ASSERT_EQUAL(4, sizeof(arr.cfg.dtype));
}
