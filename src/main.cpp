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
#define DECODE_NEC true

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



void setup() {
    Serial.begin(115200);

    // https://github.com/thijse/Arduino-Log
    Log.begin(LOG_LEVEL_NOTICE, &Serial);

    Log.notice("Booting..." CR CR);

    showHWInfo();

    initLEDs(ledArray);
    // initWIFI(ssid, password);

    initIRSenderAndReceiver();

    // initButtons(buttons);

    button1.setClickTicks(10);
    button1.setDebounceTicks(5);
    button1.attachClick([] () {
        blink(LED_ORANGE);
        Log.notice("Button1" CR CR);
        sendLastReceivedIRData();
    });

    button2.setClickTicks(10);
    button2.setDebounceTicks(5);
    button2.attachClick([] () {
        blink(LED_WHITE);
        Log.notice("Button2" CR CR);
    });

    // initOTA();
    // ArduinoOTA.begin();
}

void loop() {
    // ArduinoOTA.handle();

    button1.tick();
    button2.tick();

    blink(LED_GREEN);

    //receiveAndRetransmitData();
    receiveIRData();

    delay(10);
}
