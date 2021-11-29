#pragma once

//
// Created by Mike Mitterer on 19.02.21.
//

void blink(uint8_t led);

void initWIFI(const std::string& ssid,const std::string& password, uint8_t maxReTries = 10, bool restartOnError = false);
void initLEDs(const std::vector<uint8_t>& leds);
void initButtons(const std::vector<uint8_t>& buttons);

void showHWInfo();
