//
// Created by Mike Mitterer on 16.01.18.
//

#include <ArduinoLog.h>
#include "stdafx.h"

/**
 * Basis für dieses Sample kommt von:
 *      https://diyprojects.io/arduinoota-esp32-wi-fi-ota-wireless-update-arduino-ide/
 */
void initOTA() {
    // Port defaults to 8266
    // ArduinoOTA.setPort(8266);

    // Hostname defaults to esp8266-[ChipID]
    ArduinoOTA.setHostname("Demo OTA ESP32");

    // No authentication by default
    // ArduinoOTA.setPassword((const char *)"123");

    ArduinoOTA.onStart([]() {
        Log.notice("Start" CR);
    });

    ArduinoOTA.onEnd([]() {
        Log.notice("\nEnd" CR);
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Log.notice("Progress: %u%%\r" CR, (progress / (total / 100)) );
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Log.notice("Error [%u]: " CR, error);

        if (error == OTA_AUTH_ERROR) Log.error("Auth Failed" CR);
        else if (error == OTA_BEGIN_ERROR) Log.error("Begin Failed" CR);
        else if (error == OTA_CONNECT_ERROR) Log.error("Connect Failed" CR);
        else if (error == OTA_RECEIVE_ERROR) Log.error("Receive Failed" CR);
        else if (error == OTA_END_ERROR) Log.error("End Failed" CR);
    });


}
