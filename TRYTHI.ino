#include <FastLED.h>

const int LED_BUILTIN = 2;
const int DATA_PIN = 22;
const int LED_COUNT = 98;
const int BRIGHTNESS = 64;

CRGB leds[LED_COUNT];

void setLights() {
  for (int i = 0; i < LED_COUNT; ++i) {
    leds[i] = CRGB::White;
  }

  FastLED.show();
}

void setup()
{
  // Give the LED chain time to warm up
  delay(3000);

  // Just in case this is needed, set the pin up
  pinMode(DATA_PIN, OUTPUT);

  // Set up the leds
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, LED_COUNT);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setTemperature(Tungsten40W);
  setLights();

  // Serial debugger
  Serial.begin(115200);
  Serial.println("Setup done");
}

void loop()
{
  FastLED.show();
  FastLED.delay(2000);
}
