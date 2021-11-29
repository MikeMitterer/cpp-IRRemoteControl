//
// Created by Sarah Riedmann on 29.11.21.
//

#include "ir_remote.h"
#include "gpio.h"

#include <IRremote.hpp>

void initIR() {
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
    // IrSender.begin(IR_TRANSMITTER_PIN, ENABLE_LED_FEEDBACK); // Start the transmitter
}

void sendIRData(uint16_t sAddress, uint8_t sCommand, uint8_t sRepeats) {
    Serial.print(F("Sending: 0x"));
    Serial.print(sAddress, HEX);
    Serial.print(sCommand, HEX);
    Serial.println(sRepeats, HEX);

    // clip repeats at 4
    if (sRepeats > 4) {
        sRepeats = 4;
    }
    // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
}

void sendReceiveDelay() {
    // wait for the receiver state machine to detect the end of a protocol
    delay((RECORD_GAP_MICROS / 1000) + 5);
}


void receiveIRData() {

    if (IrReceiver.decode()) {
        Serial.print(F("Decoded protocol: "));
        Serial.print(getProtocolString(IrReceiver.decodedIRData.protocol));
        Serial.print(F("Decoded raw data: "));
        Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);
        Serial.print(F(", decoded address: "));
        Serial.print(IrReceiver.decodedIRData.address, HEX);
        Serial.print(F(", decoded command: "));
        Serial.println(IrReceiver.decodedIRData.command, HEX);
        IrReceiver.resume();
    }
}
