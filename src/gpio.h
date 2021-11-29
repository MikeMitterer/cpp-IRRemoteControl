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

    const uint8_t IR_RECEIVER_PIN = GPIO_NUM_7;
    const uint8_t IR_TRANSMITTER_PIN = GPIO_NUM_8;
#else
    const uint8_t LED_WHITE = 19;
    const uint8_t LED_BLUE = 18;
    const uint8_t LED_GREEN = 5;
    const uint8_t LED_YELLOW = 17;
    const uint8_t LED_ORANGE = 16;
    const uint8_t LED_RED = 4;

    const uint8_t IR_RECEIVER_PIN = 7;
    const uint8_t IR_TRANSMITTER_PIN = 8;
#endif

const std::vector<uint8_t> ledArray = {
        LED_WHITE,
        LED_BLUE,
        LED_GREEN,
        LED_YELLOW,
        LED_ORANGE,
        LED_RED
};

const uint8_t BUTTON_1 = GPIO_NUM_13;
const uint8_t BUTTON_2 = GPIO_NUM_14;
// const uint8_t BUTTON_3 = GPIO_NUM_27;
// const uint8_t BUTTON_4 = GPIO_NUM_26;

const std::vector<uint8_t> buttons = {
        BUTTON_1,
        BUTTON_2,
        // BUTTON_3,
        // BUTTON_4,
};

// Reminder...
//#ifdef BOARD_LOLIN32PRO
//const gpio_num_t pinInternalLED = GPIO_NUM_5;
//#else
//const gpio_num_t pinInternalLED = GPIO_NUM_2;
//#endif

#ifndef UNIT_TEST
    extern OneButton button1;
    extern OneButton button2;
#endif

