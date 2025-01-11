#pragma once

#include "sdkconfig.h"
#include "platforms/esp/esp_version.h"

#if CONFIG_IDF_TARGET_ESP32C2
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 0
#define FASTLED_ESP32_HAS_RMT5 0
#elif CONFIG_IDF_TARGET_ESP32C3
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP32C6
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP32S2
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP32S3
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP32H2
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP32P4
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 1
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 1
#elif CONFIG_IDF_TARGET_ESP8266
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 0
#define FASTLED_ESP32_HAS_RMT 0
#define FASTLED_ESP32_HAS_RMT5 0
#elif CONFIG_IDF_TARGET_ESP32 || defined(ARDUINO_ESP32_DEV)
#define FASTLED_ESP32_HAS_CLOCKLESS_SPI 0
#define FASTLED_ESP32_HAS_RMT 1
#define FASTLED_ESP32_HAS_RMT5 0
#else
#warning "Unknown board, assuming support for clockless RMT5 and SPI chipsets. Please file an bug report with FastLED and tell them about your board type."
#endif

// Note that FASTLED_RMT5 is a legacy name,
// so we keep it because "RMT" is specific to ESP32
#if FASTLED_ESP32_HAS_RMT5 && !defined(FASTLED_RMT5)
#define FASTLED_RMT5 1
#else
#define FASTLED_RMT5 0
#endif
