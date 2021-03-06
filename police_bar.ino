#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(64);
}

void loop() { 
  Strobe(127, 127, 127, 800, 50, 1000);
}

void Strobe(int red, int green, int blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    for(int i=0; i<28; i++)
    {
      strip.setPixelColor(i,255,0,0);
      strip.show();
    }
    delay(5);
    setAll(0,0,0);
    for(int i = 32; i<60; i++)
    {
      strip.setPixelColor(i,0,0,255);
      strip.show();
    }
    delay(5);
    setAll(0,0,0);
    for(int i =28; i<32;i++)
    {
      strip.setPixelColor(i,127,127,127);
      strip.show();
    }
    
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

