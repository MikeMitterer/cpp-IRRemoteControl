//
// Created by Sarah Riedmann on 30.11.21.
//

#include "ir_remote.h"

#include <IRsend.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

IRsend irsend(kIrLedPin);
IRrecv irrecv(kRecvPin, kCaptureBufferSize, kTimeout, true);

decode_results results;
decode_results lastReceivedData;


void initIRSenderAndReceiver(){
    irrecv.enableIRIn();  // Start up the IR receiver.
    irsend.begin();       // Start up the IR sender.
}

void receiveAndRetransmitData(){
    if (irrecv.decode(&results)) {
        lastReceivedData = getReceivedIRData();
        sendIRData(&lastReceivedData);

        irrecv.resume();
    }
}

void receiveIRData(){
    if (irrecv.decode(&results)) {
        lastReceivedData = getReceivedIRData();

        irrecv.resume();
    }
}


decode_results getReceivedIRData(){
    Serial.print(F("Received decoded raw data: "));
    Serial.print(results.value, HEX);
    Serial.print(F(", decoded address: "));
    Serial.print(results.address, HEX);
    Serial.print(F(", decoded command: "));
    Serial.println(results.command, HEX);

    return results;
}

void sendLastReceivedIRData(){
    sendIRData(&lastReceivedData);
}

void sendIRData(decode_results* data){
    // Convert the results into an array suitable for sendRaw().
    // resultToRawArray() allocates the memory we need for the array.
    uint16_t* raw_array = resultToRawArray(data);
    // Find out how many elements are in the array.
    uint16_t length = getCorrectedRawLength(data);

    // Send it out via the IR LED circuit.
    irsend.sendRaw(raw_array, length, kFrequency);

    delete [] raw_array;

    Serial.print(F("Transmitted decoded raw data: "));
    Serial.print(data->value, HEX);
    Serial.print(F(", decoded address: "));
    Serial.print(data->address, HEX);
    Serial.print(F(", decoded command: "));
    Serial.println(data->command, HEX);
}
