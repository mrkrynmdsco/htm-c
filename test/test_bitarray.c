#include "unity.h"
#include "bitarray.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_bitarray_Initialization(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(4096);
    TEST_ASSERT_EQUAL(8, sizeof(BitArray_GetDense(arr)));
    TEST_ASSERT_EQUAL(2, sizeof(BitArray_GetBitCount(arr)));
    TEST_ASSERT_EQUAL(2, sizeof(BitArray_GetByteCount(arr)));
    TEST_ASSERT_EQUAL(4096, BitArray_GetBitCount(arr));
    TEST_ASSERT_EQUAL(512, BitArray_GetByteCount(arr));
    TEST_ASSERT_EQUAL(0, BitArray_GetByte(arr, 0));
    TEST_ASSERT_EQUAL(0, BitArray_GetByte(arr, 511));
}

void test_bitarray_Set_bit_by_valid_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(4096);
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(arr, 0));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(arr, 511));

    BitArray_SetBit(arr, 7);
    TEST_ASSERT_EQUAL(0b10000000, BitArray_GetByte(arr, 0));
    
    BitArray_SetBit(arr, 4088);
    BitArray_SetBit(arr, 4095);
    TEST_ASSERT_EQUAL(0b10000001, BitArray_GetByte(arr, 511));
}

void test_bitarray_Set_bit_by_invalid_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(16);
    TEST_ASSERT_EQUAL(2, BitArray_GetByteCount(arr));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(arr, 0));
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(arr, 1));
    BitArray_SetBit(arr, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b00000000, BitArray_GetByte(arr, 1));
}

void test_bitarray_Reset_bit_by_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(16);
    // set all bits
    BitArray_SetByte(arr, 0, 0xFF);
    BitArray_SetByte(arr, 1, 0xFF);

    BitArray_ResetBit(arr, 7);
    TEST_ASSERT_EQUAL(0b01111111, BitArray_GetByte(arr, 0));

    BitArray_ResetBit(arr, 8);
    BitArray_ResetBit(arr, 15);
    TEST_ASSERT_EQUAL(0b01111110, BitArray_GetByte(arr, 1));
    
    // invalid index
    BitArray_ResetBit(arr, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b01111110, BitArray_GetByte(arr, 1));
}

void test_bitarray_Get_bit_by_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(16);
    TEST_ASSERT_EQUAL(0, BitArray_GetBit(arr, 0));
    TEST_ASSERT_EQUAL(0, BitArray_GetBit(arr, 15));
    BitArray_SetBit(arr, 0);
    BitArray_SetBit(arr, 15);
    TEST_ASSERT_EQUAL(1, BitArray_GetBit(arr, 0));
    TEST_ASSERT_EQUAL(1, BitArray_GetBit(arr, 15));
}
