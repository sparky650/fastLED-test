#include <Arduino.h>
#include <FastLED.h>

constexpr auto LED_PIN = 4;
constexpr auto NUM_LEDS = 16;
constexpr auto COLOR_ORDER = EOrder::GRB;
#define LED_TYPE WS2811_400

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void loop()
{
  static uint8_t hue = 0;
  for (auto i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(hue + i, 255, 255);
  }
  FastLED.show();
  hue++;
  delay(25);
}