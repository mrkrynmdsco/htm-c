#include "unity.h"
#include "array.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_array_Creation_and_Getters_and_Destroy(void) {
    Array* a = Array_Create(Real32, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(a));
    TEST_ASSERT_EQUAL(Real32, Array_GetDataType(a));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(a));
    TEST_ASSERT_EQUAL(4, sizeof(*(real32*)(Array_GetDataPtr(a))));
    Array_Destroy(a);
    // TEST_ASSERT_EQUAL(NULL, Array_GetDataPtr(a));
    // TEST_ASSERT_EQUAL(INVALID_TYPE, Array_GetDataType(a));
    // TEST_ASSERT_EQUAL(0, Array_GetItemCount(a));
}

void test_array_Set_and_Get_data_by_index(void) {
    Array* a = Array_Create(UInt8, 4);
    TEST_ASSERT_EQUAL(0, (uint8)(*(((uint8*)Array_GetDataPtr(a) + 3))));
    Array_SetDataByIndex(a, 3, 255);
    TEST_ASSERT_EQUAL(255, (uint8)(*(((uint8*)Array_GetDataPtr(a) + 3))));
    TEST_ASSERT_EQUAL(255, (uint8)(*(uint8*)Array_GetDataByIndex(a, 3)));
}
