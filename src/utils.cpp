//
// Created by Mike Mitterer on 19.02.21.
//
#include "stdafx.h"
#include "utils.h"
#include "gpio.h"

#include <cstdint>
#include <Esp.h>
#include <ArduinoLog.h>

/**
 * initialize LED digital pin as an output.
 */
void initLEDs(const std::vector<uint8_t>& leds) {
    for (auto const& led : leds) {
        pinMode(led, OUTPUT);
        delay(300);
        blink(led);
    }
}

void initButtons(const std::vector<uint8_t>& buttons){
    // initialize Buttons digital pin as an input.
    for (auto const& button : buttons) {
        // pinMode(button, INPUT_PULLDOWN);
        pinMode(button, INPUT);
    }
}

void blink(uint8_t led) {
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(led, HIGH);

    Log.trace("Blink" CR);

    // wait
    delay(100);

    // turn the LED off by making the voltage LOW
    digitalWrite(led, LOW);

    // wait
    delay(100);
}

void initWIFI(const std::string& ssid, const std::string& password, uint8_t maxReTries, bool restartOnError) {
    uint8_t retry = 0;

    Log.notice("Initializing WIFI..." CR);

    WiFiClass::mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFiClass::status() != WL_CONNECTED && retry < maxReTries) {
        Log.notice(".");
        blink(LED_BLUE);
        retry++;
        delay(500);
    }

    if(retry < maxReTries) {
        Log.notice("\nWIFI initialized!" CR CR);

        Log.notice("MAC-Address: %s" CR,  WiFi.macAddress().c_str());
        Log.notice("Local IP: %s" CR, WiFi.localIP().toString().c_str());

        digitalWrite(LED_BLUE, HIGH);
    }
    else {
        digitalWrite(LED_RED, HIGH);
        Log.error("\nWIFI - initialization failed!" CR CR);

        if(restartOnError) {
            Log.notice("Restarting in 500ms..." CR);
            delay(500);
            ESP.restart();
        }
    }
}

/**
 * Zeigt die HW-Info an
 */
void showHWInfo() {
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    Log.notice(CR "--- Hardware info ---" CR);

    Log.notice("%d cores Wifi %s%s" CR, chip_info.cores, (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                  (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    //get chip id
    auto chipId = String( (uint32_t) ESP.getEfuseMac(), HEX);
    Log.notice("Chip id: %s" CR, chipId.c_str());

    Log.notice("Silicon revision: %d" CR, chip_info.revision);
    Log.notice("Chip model: %s" CR, ESP.getChipModel());

    Log.notice("Flash: %dMB %s" CR, spi_flash_get_chip_size() / (1024*1024),
                  (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embeded" : "external");

    Log.notice("Heap: free[ %lk ] / max[ %lk ]" CR, ESP.getFreeHeap() / 1024, ESP.getHeapSize() / 1024);

    Log.notice("PSRAM: free[ %lk ] / max[ %lk ]" CR, ESP.getFreePsram() / 1024, ESP.getPsramSize() / 1024);

    Log.notice("SDK version: %s" CR, ESP.getSdkVersion());

    Log.notice("Sketch Space: free[ %lk ] / used[ %lk ]" CR CR,
               ESP.getFreeSketchSpace() / 1024, ESP.getSketchSize() / 1024
               );
}



