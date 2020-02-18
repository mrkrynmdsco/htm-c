#include "unity.h"
#include "bitarray.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_bitarray_Create_and_Destroy(void) {
    BitArray* barry = BitArray_Create(4096);
    TEST_ASSERT_NOT_NULL(barry);
    TEST_ASSERT_NOT_NULL(barry->data);
    BitArray_Destroy(barry);
}

void test_bitarray_Set_bit_by_valid_index(void) {
    BitArray* barry = BitArray_Create(4096);
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(barry, 0));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(barry, 511));

    BitArray_SetBit(barry, 7);
    TEST_ASSERT_EQUAL(0b10000000, BitArray_GetByte(barry, 0));
    
    BitArray_SetBit(barry, 4088);
    BitArray_SetBit(barry, 4095);
    TEST_ASSERT_EQUAL(0b10000001, BitArray_GetByte(barry, 511));
}

void test_bitarray_Set_bit_by_invalid_index(void) {
    BitArray* barry = NULL;
    barry = BitArray_Create(16);
    TEST_ASSERT_EQUAL(2, BitArray_GetByteCount(barry));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(barry, 0));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(barry, 1));
    BitArray_SetBit(barry, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(barry, 1));
}

void test_bitarray_Reset_bit_by_index(void) {
    BitArray* barry = NULL;
    barry = BitArray_Create(16);
    // set all bits
    BitArray_SetByte(barry, 0, 0xFF);
    BitArray_SetByte(barry, 1, 0xFF);

    BitArray_ResetBit(barry, 7);
    TEST_ASSERT_EQUAL(0b01111111, BitArray_GetByte(barry, 0));

    BitArray_ResetBit(barry, 8);
    BitArray_ResetBit(barry, 15);
    TEST_ASSERT_EQUAL(0b01111110, BitArray_GetByte(barry, 1));
    
    // invalid index
    BitArray_ResetBit(barry, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b01111110, BitArray_GetByte(barry, 1));
}

void test_bitarray_Get_bit_by_index(void) {
    BitArray* barry = NULL;
    barry = BitArray_Create(16);
    TEST_ASSERT_EQUAL(0, BitArray_GetBit(barry, 0));
    TEST_ASSERT_EQUAL(0, BitArray_GetBit(barry, 15));
    BitArray_SetBit(barry, 0);
    BitArray_SetBit(barry, 15);
    TEST_ASSERT_EQUAL(1, BitArray_GetBit(barry, 0));
    TEST_ASSERT_EQUAL(1, BitArray_GetBit(barry, 15));
}
