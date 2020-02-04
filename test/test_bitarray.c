#include "unity.h"

#include "bitarray.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bitarray_Initialization_static(void)
{
    BitArray arr;
    BitArray_ctor(&arr, 4096);
    TEST_ASSERT_EQUAL(16, sizeof(arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr.dense));
    TEST_ASSERT_EQUAL(2, sizeof(arr.nbits));
    TEST_ASSERT_EQUAL(2, sizeof(arr.dbyte));
    TEST_ASSERT_EQUAL(4096, arr.nbits);
    TEST_ASSERT_EQUAL(512, arr.dbyte);
}
