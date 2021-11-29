#pragma once

//
// Created by Mike Mitterer on 2.4.2020
//
// cmake-Template für config.h
//

#include <string>

// the configured options and settings for HelloWorld
const std::string Project_NAME          = "IRRemoteControl";
const std::string Project_VERSION       = "0.1";
const std::string Project_VERSION_MAJOR = "0";
const std::string Project_VERSION_MINOR = "1";

// Password compiled into source
// Set in .config/passwords.cmake (or via ENV-VAR)
//
// Mehr zu "const char* const": https://stackoverflow.com/a/24558597/504184
//
const char* const Project_SSID     = "";
const char* const Project_PASSWORD = "";

// Setup-Version (EEPROM)
const uint8_t Project_Config_VERSION = 1;


