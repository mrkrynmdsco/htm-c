#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_Initialization_static(void) {
    UInt8Array* aPtr = (UInt8Array*) Array_Create(UInt8, 4);
    TEST_ASSERT_EQUAL(UInt8, aPtr->cfg.dtype);
    TEST_ASSERT_EQUAL(4, aPtr->cfg.nitem);
    TEST_ASSERT_EQUAL(1, sizeof(aPtr->data[0]));

    Real32Array* bPtr = (Real32Array*) Array_Create(Real32, 8);
    TEST_ASSERT_EQUAL(Real32, bPtr->cfg.dtype);
    TEST_ASSERT_EQUAL(8, bPtr->cfg.nitem);
    TEST_ASSERT_EQUAL(4, sizeof(bPtr->data[0]));
}
