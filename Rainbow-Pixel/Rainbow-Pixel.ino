#include "Freenove_WS2812_Lib_for_ESP32.h"
#define chn 0
#define led 15
#define pixel 8
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(pixel,led,chn,TYPE_GRB);
void setup() {
  strip.begin();
}

void loop() {
  for(int j=0;j<255;j+=1){
    for(int i=0;i<pixel;i++){
      strip.setLedColorData(i,strip.Wheel((i*265/pixel +j)&255));
    }
    strip.show();
    delay(5);
  }
}
