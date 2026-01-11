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
        TEST_ASSERT_EQUAL_INT32(output[i], fpih_32_msb_index(input_n[i]));
    }
}
void fpih_test_fpih_32_lsb_index(void) {
    uint32_t input_n[]      = { 0x00000000, 0x00000010, 0xffffffff, 0x80000000 };
    uint32_t output[]       = { 32, 4, 0, 31 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT32(output[i], fpih_32_lsb_index(input_n[i]));
    }
} 
void fpih_test_fpih_ufpt32_arithmetic_lshift(void) {
    uint32_t input_n[]      = { 0x00000000, 0x88000001, 0xffffffff, 0x80000001 };
    uint32_t input_shift[]  = { 1, 4, 1, 31 };
    uint32_t output[]       = { 0x00000000, 0x80000010, 0xfffffffe, 0x80000000 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_UINT32(output[i], fpih_ufpt32_arithmetic_lshift(input_n[i], input_shift[i]));
    }
}
void fpih_test_fpih_ufpt32_arithmetic_rshift(void) {
    uint32_t input_n[]     = { 0x00000000, 0x80000010, 0xffffffff, 0x80000000 };
    uint32_t input_shift[] = { 1, 4, 1, 31 };
    uint32_t output[]      = { 0x00000000, 0x08000001, 0x7fffffff, 0x00000001 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_UINT32(output[i], fpih_ufpt32_arithmetic_rshift(input_n[i], input_shift[i]));
    }
}
void fpih_test_fpih_fpt32_arithmetic_lshift(void) {
    int32_t input_n[]      = { 0, -8, -1, -1 };
    uint32_t input_shift[]  = { 1, 3, 1, 31 };
    int32_t output[]       = { 0, -64, -2, -2147483648 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT32(output[i], fpih_fpt32_arithmetic_lshift(input_n[i], input_shift[i]));
        TEST_ASSERT_EQUAL_INT32(-output[i], fpih_fpt32_arithmetic_lshift(-input_n[i], input_shift[i]));
    }
} 
void fpih_test_fpih_fpt32_arithmetic_rshift(void) {
    int32_t input_n[]      = { 0, -8, -2, -2147483648 };
    uint32_t input_shift[] = { 1, 3, 1, 31 };
    int32_t output[]       = { 0, -1, -1, -1 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        TEST_ASSERT_EQUAL_INT32(output[i], fpih_fpt32_arithmetic_rshift(input_n[i], input_shift[i]));
        if (input_n[i] != -2147483648)   // todo: a fpt_neg function would remove the need for this corollary 
            TEST_ASSERT_EQUAL_INT32(-output[i], fpih_fpt32_arithmetic_rshift(-input_n[i], input_shift[i]));
    }
}

void fpih_test_float_to_from_fpt32(void) {
    float  input_n[] = { 0.5, 0.2, -15.75, -2.565};
    size_t input_fb[] = { 16,  31, 16, 23 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        float output = fpih_fpt32_to_float(fpih_float_to_fpt32(input_n[i], input_fb[i]), input_fb[i]);
        TEST_ASSERT_EQUAL_FLOAT(output, input_n[i]);
    }
}

void fpih_test_float_to_from_ufpt32(void) {
    float  input_n[] = { 0.5, 0.2, -15.75, -2.565};
    size_t input_fb[] = { 16,  31, 16, 2 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        float output = fpih_ufpt32_to_float(fpih_float_to_ufpt32(input_n[i], input_fb[i]), input_fb[i]);
        TEST_ASSERT_EQUAL_FLOAT(output, input_n[i] < 0.0 ? 0.0 : input_n[i]);
    }
}

void fpih_test_int32_to_from_fpt32(void) {
    int32_t input_n[] = { 400, -1, -15, 43};
    size_t input_fb[] = { 16,  31, 16, 23 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        int output = fpih_fpt32_to_int32(fpih_int32_to_fpt32(input_n[i], input_fb[i]), input_fb[i]);
        TEST_ASSERT_EQUAL_INT32(output, input_n[i]);
    }
}


void fpih_test_uint32_to_from_ufpt32(void) {
    uint32_t input_n[] = { 400, 1, 573, 43};
    size_t input_fb[] = { 16,  31, 16, 23 };

    unsigned int tests_num = sizeof(input_n) / sizeof(*input_n);
    
    for (unsigned int i = 0; i < tests_num; i++) {
        int output = fpih_ufpt32_to_uint32(fpih_uint32_to_ufpt32(input_n[i], input_fb[i]), input_fb[i]);
        TEST_ASSERT_EQUAL_UINT32(output, input_n[i]);
    }
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
    RUN_TEST(fpih_test_fpih_fpt32_arithmetic_lshift);  
    RUN_TEST(fpih_test_fpih_fpt32_arithmetic_rshift);  
    RUN_TEST(fpih_test_float_to_from_fpt32);  
    RUN_TEST(fpih_test_float_to_from_ufpt32);   
    RUN_TEST(fpih_test_int32_to_from_fpt32);  
    RUN_TEST(fpih_test_uint32_to_from_ufpt32); 

    return UNITY_END();
}