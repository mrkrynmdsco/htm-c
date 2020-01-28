#include "unity.h"
#include "sdr.h"


SDR* sdr = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sdr_Creation(void)
{
    sdr = SDR_create(4096, 0.02);

    TEST_ASSERT_NOT_NULL(sdr);
    TEST_ASSERT_NOT_NULL(sdr->dense);
    TEST_ASSERT_EQUAL(sdr->nbits, 4096);
    TEST_ASSERT_EQUAL(sdr->dbyte, 512);
    TEST_ASSERT_EQUAL(sizeof(sdr->dense[0]), 1);
}
