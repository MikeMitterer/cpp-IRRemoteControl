#include <unity.h>

#include "gpio.h"
#include "calc/mysquare.h"

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_led_builtin_pin_number() {
    TEST_ASSERT_EQUAL(LED_RED, 4);
}

void testSquareFunction() {
   TEST_ASSERT_EQUAL(my_square(0), 0);
   TEST_ASSERT_EQUAL(my_square(2), 4);

   TEST_ASSERT_NOT_EQUAL(my_square(3), 4);
}

/**
 * Unit-Test für dieses Project
 *
 * Usage:
 *      pio test -e native --verbose
 */
int main(int argc, char **argv) {
    UNITY_BEGIN();
        RUN_TEST(test_led_builtin_pin_number);
        RUN_TEST(testSquareFunction);
    UNITY_END();

    return 0;
}


