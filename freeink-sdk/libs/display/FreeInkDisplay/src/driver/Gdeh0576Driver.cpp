#include "Gdeh0576Driver.h"

#include <BoardConfig.h>

#if FREEINK_DEVICE_CUSTOM_READER

#include <Arduino.h>
#include <SPI.h>
#include <cstring>
#include <esp_heap_caps.h>
#include <gdeh/GxEPD2_576_GDEH0576T81.h>

namespace freeink {
namespace {

constexpr int SCREEN_WIDTH = 920;
constexpr int SCREEN_HEIGHT = 680;
constexpr size_t FRAME_BYTES = (SCREEN_WIDTH / 8) * SCREEN_HEIGHT;

constexpr int EPD_CS = 13;
constexpr int EPD_DC = 14;
constexpr int EPD_RST = 15;
constexpr int EPD_BUSY = 16;

GxEPD2_576_GDEH0576T81 panel(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY);

// Last frame sent to the display.
uint8_t* previousFrame = nullptr;
bool previousFrameValid = false;

}  // namespace

void Gdeh0576Driver::begin(EpdBus& bus) {
  (void)bus;
  Serial.println("[GDEH0576] Starting initialization");

  const auto& pins = BoardConfig::ACTIVE.display;

  pinMode(EPD_CS, OUTPUT);
  pinMode(EPD_DC, OUTPUT);
  pinMode(EPD_RST, OUTPUT);
  pinMode(EPD_BUSY, INPUT);

  digitalWrite(EPD_CS, HIGH);
  digitalWrite(EPD_DC, HIGH);
  digitalWrite(EPD_RST, HIGH);

  SPI.begin(pins.sclk, -1, pins.mosi, pins.cs);
  panel.selectSPI(SPI, SPISettings(4000000, MSBFIRST, SPI_MODE0));

  Serial.println("[GDEH0576] Initializing panel");
  panel.init(0);
  Serial.println("[GDEH0576] Panel initialized");

  if (!previousFrame) {
    previousFrame = static_cast<uint8_t*>(
        heap_caps_malloc(FRAME_BYTES, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT));
  }

  previousFrameValid = false;

  if (previousFrame) {
    Serial.printf("[GDEH0576] Shadow buffer allocated: %u bytes\n",
                  static_cast<unsigned>(FRAME_BYTES));
  } else {
    Serial.println("[GDEH0576] Shadow allocation failed; using full refresh");
  }
}

void Gdeh0576Driver::display(EpdBus& bus, const uint8_t* fb,
                             const uint8_t* prev, RefreshMode mode,
                             bool turnOff) {
  (void)bus;
  (void)prev;
  if (!fb) return;

  const unsigned long start = millis();
  const bool useFast = mode == RefreshMode::Fast &&
                       previousFrame != nullptr && previousFrameValid;

  if (useFast) {
    // SSD2677 differential update needs the old and new bitmaps.
    panel.writeNative(previousFrame, fb, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                      false, false, false);
    panel.refresh(true);
  } else {
    // Full and Half both use the clean refresh for now.
    panel.writeImage(fb, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                     false, false, false);
    panel.refresh(false);
  }

  if (previousFrame) {
    std::memcpy(previousFrame, fb, FRAME_BYTES);
    previousFrameValid = true;
  }

  if (turnOff) panel.powerOff();

  Serial.printf("[GDEH0576] %s refresh: %lu ms\n",
                useFast ? "FAST" : "FULL", millis() - start);
}

void Gdeh0576Driver::deepSleep(EpdBus& bus) {
  (void)bus;
  previousFrameValid = false;
  panel.hibernate();
}

PanelDriver& gdeh0576Driver() {
  static Gdeh0576Driver driver;
  return driver;
}

}  // namespace freeink

#endif  // FREEINK_DEVICE_CUSTOM_READER
