/**
 * Hello-World ESP32.
 * Blinkt eine LED und ermöglicht ein OAT update
 *
 * Wenn das OAT funktioniere soll muss im platformio.ini der Upload-Port gesetzt sein!
 *
 * Mehr:
 *      https://diyprojects.io/arduinoota-esp32-wi-fi-ota-wireless-update-arduino-ide/
 *
 * OTA mit platformio:
 *      http://docs.platformio.org/en/latest/platforms/espressif8266.html#over-the-air-ota-update
 *      
 */
#include "stdafx.h"


#include "config.h"
#include "ota.h"
#include "gpio.h"
#include "utils.h"
#include "ir_remote.h"

#include <Esp.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoLog.h>


const std::string ssid{ Project_SSID };
const std::string password{  Project_PASSWORD };

uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 1;

#ifndef ESP32
    static_assert(false);
#endif

// #ifndef SEND_PWM_BY_TIMER
//     static_assert(false);
// #endif

void setup() {
    Serial.begin(115200);

    // https://github.com/thijse/Arduino-Log
    Log.begin(LOG_LEVEL_NOTICE, &Serial);

    Log.notice("Booting..." CR CR);

    showHWInfo();

    initLEDs(ledArray);
    initWIFI(ssid, password);
    initIR();
    
    button1.attachClick([] () {
        blink(LED_ORANGE);
    });

    initOTA();
    ArduinoOTA.begin();
    
    // IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
    // IrSender.begin(IR_TRANSMITTER_PIN, ENABLE_LED_FEEDBACK); // Start the transmitter
    //
    // Serial.print(F("Ready to receive IR signals of protocols: "));
    // printActiveIRProtocols(&Serial);


}

void loop() {
    ArduinoOTA.handle();
    button1.tick();

    blink(LED_GREEN);

    // sendIRData(sAddress, sCommand, sRepeats);

    // sendReceiveDelay();

    receiveIRData();

    // Prepare data for next loop
    // sAddress += 0x0101;
    // sCommand += 0x11;
    // sRepeats++;

    delay(1);
}


