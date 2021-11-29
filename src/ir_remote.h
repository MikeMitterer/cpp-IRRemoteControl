#pragma once

//
// Created by Sarah Riedmann on 29.11.21.
//

// #ifndef IRREMOTECONTROL_IR_REMOTE_H
// #define IRREMOTECONTROL_IR_REMOTE_H


#include "stdafx.h"

#define IR_RECEIVE_PIN          15  // D15
#define IR_SEND_PIN              4  // D4
#define TONE_PIN                27  // D27 25 & 26 are DAC0 and 1
#define APPLICATION_PIN         16  // RX2 pin
#define TONE_LEDC_CHANNEL        1  // Using channel 1 makes tone() independent of receiving timer -> No need to stop receiving timer.

void initIR();
void sendIRData(uint16_t sAddress, uint8_t sCommand, uint8_t sRepeats);
void sendReceiveDelay();
void receiveIRData();

#if !defined (FLASHEND)
#define FLASHEND 0xFFFF // Dummy value for platforms where FLASHEND is not defined
#endif


// #endif //IRREMOTECONTROL_IR_REMOTE_H
