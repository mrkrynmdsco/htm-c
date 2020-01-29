#include "unity.h"
#include "bitarray.h"


BitArray* p_array = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bitarray_Creation(void)
{
    p_array = BitArray_create(16);

    TEST_ASSERT_NOT_NULL(p_array);
    TEST_ASSERT_NOT_NULL(p_array->data);
    TEST_ASSERT_EQUAL(p_array->nbits, 16);
    TEST_ASSERT_EQUAL(sizeof(p_array->data[0]), 1);

    BitArray_destroy(p_array);
}
