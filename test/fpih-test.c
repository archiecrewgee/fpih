#include "stdbool.h"
#include "stdio.h"

#include "unity.h"
#include "fpih.h"

void setUp(void) {}
void tearDown(void) {}



void fpih_test_sanity_test(void) {
    printf("sanity test running\n");
    TEST_ASSERT_EQUAL_INT(1, true);
}

int main(void) {
    printf("hola amigos\n");

    UNITY_BEGIN();
    RUN_TEST(fpih_test_sanity_test);
    return UNITY_END();
}