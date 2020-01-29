#include "unity.h"
#include "sdr.h"


SDR* sdr;

void setUp(void)
{
    sdr = sdr_Create(4096, 0.02);
    TEST_ASSERT_EQUAL(0, *(sdr->dense));
}

void tearDown(void)
{
    sdr_Destroy(sdr);
}

void test_sdr_Create_SDR_object(void)
{
    TEST_ASSERT_NOT_NULL(sdr);
    TEST_ASSERT_NOT_NULL(sdr->dense);
    TEST_ASSERT_NOT_NULL(sdr->sparse);
    TEST_ASSERT_EQUAL(32, sizeof(SDR));
    TEST_ASSERT_EQUAL(8, sizeof(sdr));
    TEST_ASSERT_EQUAL(8, sizeof(sdr->dense));
    TEST_ASSERT_EQUAL(8, sizeof(sdr->sparse));
    TEST_ASSERT_EQUAL(4096, sdr->nbits);
    TEST_ASSERT_EQUAL(81, sdr->wbits);
    TEST_ASSERT_EQUAL(512, sdr->dbyte);
    TEST_ASSERT_EQUAL(1, sizeof(sdr->dense[0]));
    TEST_ASSERT_EQUAL(1, sizeof(sdr->dense[511]));
    TEST_ASSERT_EQUAL(2, sizeof(sdr->sparse[0]));
    TEST_ASSERT_EQUAL(2, sizeof(sdr->sparse[80]));
}

void test_sdr_Set_SDR_dense_bit_by_index(void)
{
    sdr_DenseSet(sdr, 7);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[0]);

    sdr_DenseSet(sdr, 8);
    TEST_ASSERT_EQUAL(0b00000001, sdr->dense[1]);

    sdr_DenseSet(sdr, 9);
    TEST_ASSERT_EQUAL(0b00000011, sdr->dense[1]);

    sdr_DenseSet(sdr, 4095);
    TEST_ASSERT_EQUAL(0b10000000, sdr->dense[511]);
}

void test_sdr_Get_SDR_dense_bit_by_index(void)
{
    sdr->dense[0] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 7));

    sdr->dense[1] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 15));

    sdr->dense[511] = 0b10000000;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 4095));

    sdr->dense[511] = 0b00000001;
    TEST_ASSERT_EQUAL(1, sdr_DenseGet(sdr, 4088));
}
