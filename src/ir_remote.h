#pragma once

//
// Created by Sarah Riedmann on 30.11.21.
//

// #ifndef IRREMOTECONTROL_IR_REMOTE_NEW_H
// #define IRREMOTECONTROL_IR_REMOTE_NEW_H

#include "stdafx.h"

#include <IRrecv.h>

// The GPIO an IR detector/demodulator is connected to. Recommended: 14 (D5)
// Note: GPIO 16 won't work on the ESP8266 as it does not have interrupts.
const uint16_t kRecvPin = 15;

// GPIO to use to control the IR LED circuit. Recommended: 4 (D2).
const uint16_t kIrLedPin = 2;

// The Serial connection baud rate.
// NOTE: Make sure you set your Serial Monitor to the same speed.
const uint32_t kBaudRate = 115200;

// As this program is a special purpose capture/resender, let's use a larger
// than expected buffer so we can handle very large IR messages.
// i.e. Up to 512 bits.
const uint16_t kCaptureBufferSize = 1024;

// kTimeout is the Nr. of milli-Seconds of no-more-data before we consider a
// message ended.
const uint8_t kTimeout = 50;  // Milli-Seconds

// kFrequency is the modulation frequency all messages will be replayed at.
const uint16_t kFrequency = 38000;  // in Hz. e.g. 38kHz.


void initIRSenderAndReceiver();

void receiveAndSendData();

decode_results getReceivedIRData();

void retransmitData();

void sendIRData(decode_results* data);






// #endif //IRREMOTECONTROL_IR_REMOTE_NEW_H
