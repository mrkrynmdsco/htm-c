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
    
    // Array_Destroy(a);
    // TEST_ASSERT_EQUAL(NULL, Array_GetDataPtr(a));
    // TEST_ASSERT_EQUAL(INVALID_TYPE, Array_GetDataType(a));
    // TEST_ASSERT_EQUAL(0, Array_GetItemCount(a));
}

void test_array_Set_and_Get_data_by_index(void) {
    Array* a = Array_Create(Bit, 4);
    TEST_ASSERT_EQUAL(0, (uint8)(*(uint8*)Array_GetDataByIndex(a, 3)));
    Array_SetDataByIndex(a, 3, 255);
    TEST_ASSERT_EQUAL(255, (uint8)(*(uint8*)Array_GetDataByIndex(a, 3)));
    
    Array* b = Array_Create(UInt8, 4);
    TEST_ASSERT_EQUAL(0, (uint8)(*(uint8*)Array_GetDataByIndex(b, 3)));
    Array_SetDataByIndex(b, 3, 255);
    TEST_ASSERT_EQUAL(255, (uint8)(*(uint8*)Array_GetDataByIndex(b, 3)));

    Array* c = Array_Create(UInt16, 4);
    TEST_ASSERT_EQUAL(0, (uint16)(*(uint16*)Array_GetDataByIndex(c, 3)));
    Array_SetDataByIndex(c, 3, 4096);
    TEST_ASSERT_EQUAL(4096, (uint16)(*(uint16*)Array_GetDataByIndex(c, 3)));

    Array* d = Array_Create(UInt32, 4);
    TEST_ASSERT_EQUAL(0, (uint32)(*(uint32*)Array_GetDataByIndex(d, 3)));
    Array_SetDataByIndex(d, 3, 429496288);
    TEST_ASSERT_EQUAL(429496288, (uint32)(*(uint32*)Array_GetDataByIndex(d, 3)));

    Array* e = Array_Create(Int8, 4);
    TEST_ASSERT_EQUAL(0, (sint8)(*(sint8*)Array_GetDataByIndex(e, 3)));
    Array_SetDataByIndex(e, 3, -1);
    TEST_ASSERT_EQUAL(-1, (sint8)(*(sint8*)Array_GetDataByIndex(e, 3)));

    Array* f = Array_Create(Int16, 4);
    TEST_ASSERT_EQUAL(0, (sint16)(*(sint16*)Array_GetDataByIndex(f, 3)));
    Array_SetDataByIndex(f, 3, -1);
    TEST_ASSERT_EQUAL(-1, (sint16)(*(sint16*)Array_GetDataByIndex(f, 3)));

    Array* g = Array_Create(Int32, 4);
    TEST_ASSERT_EQUAL(0, (sint32)(*(sint32*)Array_GetDataByIndex(g, 3)));
    Array_SetDataByIndex(g, 3, -1);
    TEST_ASSERT_EQUAL(-1, (sint32)(*(sint32*)Array_GetDataByIndex(g, 3)));

    Array* h = Array_Create(Real32, 4);
    TEST_ASSERT_EQUAL(0, (real32)(*(real32*)Array_GetDataByIndex(h, 3)));
    Array_SetDataByIndex(h, 3, -0.000009);
    TEST_ASSERT_EQUAL(-0.000009, (real32)(*(real32*)Array_GetDataByIndex(h, 3)));
}

void test_array_Get_data_by_index_with_invalid_index(void) {
    Array* a = Array_Create(Bit, 4);
    TEST_ASSERT_EQUAL(NULL, (uint8*)Array_GetDataByIndex(a, 4));

    Array* b = Array_Create(UInt8, 4);
    TEST_ASSERT_EQUAL(NULL, (uint8*)Array_GetDataByIndex(b, 4));

    Array* c = Array_Create(UInt16, 4);
    TEST_ASSERT_EQUAL(NULL, (uint16*)Array_GetDataByIndex(c, 4));

    Array* d = Array_Create(UInt32, 4);
    TEST_ASSERT_EQUAL(NULL, (uint32*)Array_GetDataByIndex(d, 4));

    Array* e = Array_Create(Int8, 4);
    TEST_ASSERT_EQUAL(NULL, (sint8*)Array_GetDataByIndex(e, 4));

    Array* f = Array_Create(Int16, 4);
    TEST_ASSERT_EQUAL(NULL, (sint16*)Array_GetDataByIndex(f, 4));

    Array* g = Array_Create(Int32, 4);
    TEST_ASSERT_EQUAL(NULL, (sint32*)Array_GetDataByIndex(g, 4));

    Array* h = Array_Create(Real32, 4);
    TEST_ASSERT_EQUAL(NULL, (real32*)Array_GetDataByIndex(h, 4));
}

void test_array_Different_array_types(void) {
    Array* bit = Array_Create(Bit, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(bit));
    TEST_ASSERT_EQUAL(Bit, Array_GetDataType(bit));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(bit));

    Array* ui8 = Array_Create(UInt8, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(ui8));
    TEST_ASSERT_EQUAL(UInt8, Array_GetDataType(ui8));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(ui8));
    
    Array* ui16 = Array_Create(UInt16, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(ui16));
    TEST_ASSERT_EQUAL(UInt16, Array_GetDataType(ui16));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(ui16));
    
    Array* ui32 = Array_Create(UInt32, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(ui32));
    TEST_ASSERT_EQUAL(UInt32, Array_GetDataType(ui32));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(ui32));
   
    Array* si8 = Array_Create(Int8, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(si8));
    TEST_ASSERT_EQUAL(Int8, Array_GetDataType(si8));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(si8));
    
    Array* si16 = Array_Create(Int16, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(si16));
    TEST_ASSERT_EQUAL(Int16, Array_GetDataType(si16));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(si16));
    
    Array* si32 = Array_Create(Int32, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(si32));
    TEST_ASSERT_EQUAL(Int32, Array_GetDataType(si32));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(si32));
    
    Array* r32 = Array_Create(Real32, 4);
    TEST_ASSERT_NOT_NULL(Array_GetDataPtr(r32));
    TEST_ASSERT_EQUAL(Real32, Array_GetDataType(r32));
    TEST_ASSERT_EQUAL(4, Array_GetItemCount(r32));
    // negative test
    Array* r64 = Array_Create(Real64, 4);
    TEST_ASSERT_NULL(Array_GetDataPtr(r64));
    TEST_ASSERT_EQUAL(INVALID_TYPE, Array_GetDataType(r64));
    TEST_ASSERT_EQUAL(0, Array_GetItemCount(r64));

    Array_Destroy(ui8);
    Array_Destroy(ui16);
    Array_Destroy(ui32);
    Array_Destroy(si8);
    Array_Destroy(si16);
    Array_Destroy(r32);
    Array_Destroy(r64);
}

void test_array_Invalid_data_type(void) {
    // for line coverage
    Array* a = Array_Create(INVALID_TYPE, 4);
    a->data = (void*)0xDEADBEEF;
    a->nitem = 1;
    TEST_ASSERT_EQUAL(0xDEADBEEF, Array_GetDataPtr(a));
    TEST_ASSERT_EQUAL(INVALID_TYPE, Array_GetDataType(a));
    TEST_ASSERT_EQUAL(1, Array_GetItemCount(a));

    Array_SetDataByIndex(a, 0, 1);
    TEST_ASSERT_EQUAL(0xDEADBEEF, Array_GetDataPtr(a));
    TEST_ASSERT_EQUAL(INVALID_TYPE, Array_GetDataType(a));
    TEST_ASSERT_EQUAL(1, Array_GetItemCount(a));

    TEST_ASSERT_EQUAL(NULL, Array_GetDataByIndex(a, 0));

    // for branch coverage
    a->data = NULL;
    a->nitem = 1;
    Array_SetDataByIndex(a, 0, 1);
    TEST_ASSERT_EQUAL(NULL, Array_GetDataPtr(a));
    TEST_ASSERT_EQUAL(1, Array_GetItemCount(a));
    TEST_ASSERT_EQUAL(NULL, Array_GetDataByIndex(a, 0));

    // for branch coverage
    a->data = (void*)0xDEADBEEF;
    a->nitem = 0;
    Array_SetDataByIndex(a, 0, 1);
    TEST_ASSERT_EQUAL(0xDEADBEEF, Array_GetDataPtr(a));
    TEST_ASSERT_EQUAL(0, Array_GetItemCount(a));
    TEST_ASSERT_EQUAL(NULL, Array_GetDataByIndex(a, 0));
}
