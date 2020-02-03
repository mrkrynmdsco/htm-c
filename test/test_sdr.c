#include "unity.h"
#include "sdr.h"


SDR* sdr;

void setUp(void) {
    sdr = sdr_Create(4096, 0.02, TRUE);
    TEST_ASSERT_EQUAL(1, sdr->isdense);
    TEST_ASSERT_EQUAL(0, *(sdr->dense));
    TEST_ASSERT_EQUAL(0, *(sdr->sparse));
}

void tearDown(void) {
    sdr_ResetAll(sdr);
    TEST_ASSERT_EQUAL(0, sdr->s_pos);
}

void test_sdr_Create_SDR_object(void) {
    TEST_ASSERT_NOT_NULL(sdr);
    TEST_ASSERT_NOT_NULL(sdr->dense);
    TEST_ASSERT_NOT_NULL(sdr->sparse);
    TEST_ASSERT_EQUAL(40, sizeof(SDR));
    TEST_ASSERT_EQUAL(8, sizeof(sdr));
    TEST_ASSERT_EQUAL(2, sizeof(sdr->s_pos));
    TEST_ASSERT_EQUAL(8, sizeof(sdr->sparse));
    TEST_ASSERT_EQUAL(8, sizeof(sdr->dense));
    TEST_ASSERT_EQUAL(4096, sdr->nbits);
    TEST_ASSERT_EQUAL(81, sdr->wbits);
    TEST_ASSERT_EQUAL(0, sdr->s_pos);
    TEST_ASSERT_EQUAL(512, sdr->dbyte);
    TEST_ASSERT_EQUAL(1, sizeof(sdr->dense[0]));
    TEST_ASSERT_EQUAL(1, sizeof(sdr->dense[511]));
    TEST_ASSERT_EQUAL(2, sizeof(sdr->sparse[0]));
    TEST_ASSERT_EQUAL(2, sizeof(sdr->sparse[80]));
}

void test_sdr_Set_SDR_sparse_add_index(void) {
    TEST_ASSERT_EQUAL(0, *(sdr->sparse));

    // adding invalid index
    sdr_SparseSet(sdr, 81);
    TEST_ASSERT_EQUAL(0, sdr->sparse[0]);
    TEST_ASSERT_EQUAL(0, sdr->s_pos);
    // adding valid index
    sdr_SparseSet(sdr, 1);
    TEST_ASSERT_EQUAL(1, sdr->sparse[0]);
    TEST_ASSERT_EQUAL(1, sdr->s_pos);
    // adding index value = 0
    sdr_SparseSet(sdr, 0);
    TEST_ASSERT_EQUAL(0, sdr->sparse[1]);
    TEST_ASSERT_EQUAL(2, sdr->s_pos);
    // adding existing index value
    sdr_SparseSet(sdr, 1);
    TEST_ASSERT_EQUAL(0, sdr->sparse[2]);
    TEST_ASSERT_EQUAL(2, sdr->s_pos);
    // adding new valid index value
    sdr_SparseSet(sdr, 80);
    TEST_ASSERT_EQUAL(80, sdr->sparse[2]);
    TEST_ASSERT_EQUAL(3, sdr->s_pos);
    // adding new valid index value
    sdr_SparseSet(sdr, 15);
    TEST_ASSERT_EQUAL(15, sdr->sparse[3]);
    TEST_ASSERT_EQUAL(4, sdr->s_pos);
    // adding existing index value
    sdr_SparseSet(sdr, 1);
    TEST_ASSERT_EQUAL(0, sdr->sparse[4]);
    TEST_ASSERT_EQUAL(4, sdr->s_pos);

    // verify all contents of te sparse index list
    TEST_ASSERT_EQUAL(1, sdr->sparse[0]);
    TEST_ASSERT_EQUAL(0, sdr->sparse[1]);
    TEST_ASSERT_EQUAL(80, sdr->sparse[2]);
    TEST_ASSERT_EQUAL(15, sdr->sparse[3]);
    TEST_ASSERT_EQUAL(4, sdr->s_pos);
}

void test_sdr_Set_SDR_dense_bit_by_index(void) {
    sdr_DenseSet(sdr, 7);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[0]);

    sdr_DenseSet(sdr, 8);
    TEST_ASSERT_EQUAL(0b00000001, sdr->dense[1]);

    sdr_DenseSet(sdr, 9);
    TEST_ASSERT_EQUAL(0b00000011, sdr->dense[1]);

    sdr_DenseSet(sdr, 4095);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[511]);
}

void test_sdr_Reset_SDR_dense_bit_by_index(void) {
    sdr_DenseSet(sdr, 7);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[0]);
    sdr_DenseReset(sdr, 7);
    TEST_ASSERT_EQUAL(0b00000000, sdr->dense[0]);

    sdr_DenseSet(sdr, 8);
    TEST_ASSERT_EQUAL(0b00000001, sdr->dense[1]);
    sdr_DenseReset(sdr, 8);
    TEST_ASSERT_EQUAL(0b00000000, sdr->dense[1]);

    sdr_DenseSet(sdr, 9);
    TEST_ASSERT_EQUAL(0b00000010, sdr->dense[1]);
    sdr_DenseReset(sdr, 9);
    TEST_ASSERT_EQUAL(0b00000000, sdr->dense[1]);

    sdr_DenseSet(sdr, 4095);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[511]);
    sdr_DenseReset(sdr, 4095);
    TEST_ASSERT_EQUAL(0b00000000, sdr->dense[511]);
}

void test_sdr_Get_SDR_dense_bit_by_index(void) {
    sdr->dense[0] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 7));

    sdr->dense[1] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 15));
    
    sdr->dense[511] = 0b00000001;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 4088));

    sdr->dense[511] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 4095));
    // invalid index
    TEST_ASSERT_EQUAL(255, sdr_DenseGet(sdr, 4096));
}

/*
void test_sdr_Print_SDR_dense(void) {
    sdr->dense[0] = 0xFF;
    sdr->dense[2] = 0xFF;
    sdr->dense[4] = 0xFF;
    sdr->dense[6] = 0xFF;
    sdr->dense[8] = 0xFF;
    sdr_DensePrint(sdr);
}
*/
