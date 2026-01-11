#include "stdbool.h"
#include "stdio.h"

#include "unity.h"
#include "fpih.h"

void setUp(void) {}
void tearDown(void) {}

void fpih_test_sanity_test(void) {
    TEST_ASSERT_EQUAL_INT(1, true);
}


void fpih_test_fpih_32_logical_lshift(void) {
    uint32_t input_n[]     = { 0x00000000, 0x00000001, 0xffffffff, 0x00000001 };
    uint32_t input_shift[] = { 1, 4, 1, 31 };
    uint32_t output[]      = { 0x00000000, 0x00000010, 0xfffffffe, 0x80000000 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT(output[i], fpih_32_logical_lshift(input_n[i], input_shift[i]));
    }
} 

void fpih_test_fpih_32_logical_rshift(void) {
    uint32_t input_n[]      = { 0x00000000, 0x00000010, 0xffffffff, 0x80000000 };
    uint32_t input_shift[]  = { 1, 4, 1, 31 };
    uint32_t output[]       = { 0x00000000, 0x00000001, 0x7fffffff, 0x00000001 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT(output[i], fpih_32_logical_rshift(input_n[i], input_shift[i]));
    }
} 

void fpih_test_fpih_32_msb_index(void) {
    uint32_t input_n[]      = { 0x00000000, 0x00000010, 0xffffffff, 0x80000000 };
    uint32_t output[]       = { 32, 4, 31, 31 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT(output[i], fpih_32_msb_index(input_n[i]));
    }
}
void fpih_test_fpih_32_lsb_index(void) {
    uint32_t input_n[]      = { 0x00000000, 0x00000010, 0xffffffff, 0x80000000 };
    uint32_t output[]       = { 32, 4, 0, 31 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT(output[i], fpih_32_lsb_index(input_n[i]));
    }
} 
void fpih_test_fpih_ufpt32_arithmetic_lshift(void) {
}
void fpih_test_fpih_ufpt32_arithmetic_rshift(void) {
}
void fpih_test_fpih_fpt32_lshift(void) {
} 
void fpih_test_fpih_fpt32_rshift(void) {
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(fpih_test_sanity_test);
    
    RUN_TEST(fpih_test_fpih_32_logical_lshift);
    RUN_TEST(fpih_test_fpih_32_logical_rshift);  
    RUN_TEST(fpih_test_fpih_32_msb_index); 
    RUN_TEST(fpih_test_fpih_32_lsb_index);  
    RUN_TEST(fpih_test_fpih_ufpt32_arithmetic_lshift); 
    RUN_TEST(fpih_test_fpih_ufpt32_arithmetic_rshift); 
    RUN_TEST(fpih_test_fpih_fpt32_lshift);  
    RUN_TEST(fpih_test_fpih_fpt32_rshift); 

    return UNITY_END();
}