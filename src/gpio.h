#pragma once

#ifndef UNIT_TEST
    #include <OneButton.h>
#endif

#include <vector>

//
// Created by Mike Mitterer on 19.02.21.
//

#ifndef UNIT_TEST
    const uint8_t LED_WHITE = GPIO_NUM_19;
    const uint8_t LED_BLUE = GPIO_NUM_18;
    const uint8_t LED_GREEN = GPIO_NUM_5;
    const uint8_t LED_YELLOW = GPIO_NUM_17;
    const uint8_t LED_ORANGE = GPIO_NUM_16;
    const uint8_t LED_RED = GPIO_NUM_4;
#else
    const uint8_t LED_WHITE = 19;
    const uint8_t LED_BLUE = 18;
    const uint8_t LED_GREEN = 5;
    const uint8_t LED_YELLOW = 17;
    const uint8_t LED_ORANGE = 16;
    const uint8_t LED_RED = 4;
#endif

const std::vector<uint8_t> ledArray = {
        LED_WHITE,
        LED_BLUE,
        LED_GREEN,
        LED_YELLOW,
        LED_ORANGE,
        LED_RED
};

// Reminder...
//#ifdef BOARD_LOLIN32PRO
//const gpio_num_t pinInternalLED = GPIO_NUM_5;
//#else
//const gpio_num_t pinInternalLED = GPIO_NUM_2;
//#endif

#ifndef UNIT_TEST
    extern OneButton button1;
#endif

