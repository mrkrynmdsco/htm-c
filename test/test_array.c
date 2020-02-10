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

}

