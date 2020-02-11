#include "unity.h"
#include "bitarray.h"

#define BITARRAY_OBJ_SIZE   16
#define BITARRAY_PTR_SIZE   8

void setUp(void) {
}

void tearDown(void) {
}

void test_bitarray_Initialization(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(4096);
    TEST_ASSERT_EQUAL(BITARRAY_PTR_SIZE, sizeof(arr));
    TEST_ASSERT_EQUAL(BITARRAY_OBJ_SIZE, sizeof(*arr));
    TEST_ASSERT_EQUAL(8, sizeof(arr->dense));
    TEST_ASSERT_EQUAL(2, sizeof(arr->nbits));
    TEST_ASSERT_EQUAL(2, sizeof(arr->dbyte));
    TEST_ASSERT_EQUAL(4096, arr->nbits);
    TEST_ASSERT_EQUAL(512, arr->dbyte);
    TEST_ASSERT_EQUAL(0, arr->dense[0]);
    TEST_ASSERT_EQUAL(0, arr->dense[511]);
}

void test_bitarray_Set_bit_by_valid_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(4096);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[0]);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[511]);

    BitArray_SetBit(arr, 7);
    TEST_ASSERT_EQUAL(0b10000000, arr->dense[0]);
    
    BitArray_SetBit(arr, 4088);
    BitArray_SetBit(arr, 4095);
    TEST_ASSERT_EQUAL(0b10000001, arr->dense[511]);
}

void test_bitarray_Set_bit_by_invalid_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(16);
    TEST_ASSERT_EQUAL(2, arr->dbyte);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[0]);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[1]);
    BitArray_SetBit(arr, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[1]);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[2]); // this element is no longer part of the struct
}

void test_bitarray_Reset_bit_by_index(void) {
    BitArray* arr = NULL;
    arr = BitArray_Create(16);
    // set all bits
    arr->dense[0] = 0xFF;
    arr->dense[1] = 0xFF;

    BitArray_ResetBit(arr, 7);
    TEST_ASSERT_EQUAL(0b01111111, arr->dense[0]);

    BitArray_ResetBit(arr, 8);
    BitArray_ResetBit(arr, 15);
    TEST_ASSERT_EQUAL(0b01111110, arr->dense[1]);
    
    // invalid index
    BitArray_ResetBit(arr, 16); // supposed to be 0~15 only
    TEST_ASSERT_EQUAL(0b01111110, arr->dense[1]);
    TEST_ASSERT_EQUAL(0b00000000, arr->dense[2]); // this element is no longer part of the struct
}
