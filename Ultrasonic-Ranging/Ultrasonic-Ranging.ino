#include <LiquidCrystal_I2C.h>
#include <UltrasonicSensor.h>
#include <Wire.h>
#define SDA 13 //Define SDA pins
#define SCL 14 //Define SCL pins

UltrasonicSensor ultrasonic(4, 15);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Wire.begin(SDA, SCL); 
 if (!i2CAddrTest(0x27)) {
 lcd = LiquidCrystal_I2C(0x3F, 16, 2);
 }
 lcd.init(); 
 lcd.backlight(); 
 lcd.setCursor(0,0); 
 lcd.print("Distance in CM: ");
 int temperature = 22;
 ultrasonic.setTemperature(temperature);


}

void loop() { 
  delay(100); 
  lcd.setCursor(0,1);
  for(int i=0;i<16;i++){
    lcd.print(" ");
  }
  lcd.setCursor(0,1);
  int distance = ultrasonic.distanceInCentimeters();
  lcd.print(distance);
}


bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
