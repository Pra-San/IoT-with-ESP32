#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT 8
#define pin 2
#define chn 0
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, pin, chn, TYPE_GRB);
u8 m_color[5][3]={{128,128,128},{0,255,0},{0,0,255},{255,255,255},{0,0,0}};
int val = 255;
void setup() {
  strip.begin();
  strip.setBrightness(255);
}

void loop() {
  for(int i=0;i<5;i++){
    for(int j=0; j< LEDS_COUNT ; j++ ){
      strip.setLedColorData(j,m_color[i][0],m_color[i][1],m_color[i][2]);
      strip.show();
      delay(1000);
    }
    delay(500);
  }
}
