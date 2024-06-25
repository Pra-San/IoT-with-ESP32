#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define SDA 13 
#define SCL 14 


#define trigPin 4 
#define echoPin 15 
#define MAX_DISTANCE 700 // Maximum sensor distance is rated at 400-500cm.
//timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
float timeOut = MAX_DISTANCE * 60;
int soundVelocity = 340; // define sound speed=340m/s
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
 pinMode(echoPin,INPUT); 

}

void loop() {
 delay(100); 
  lcd.setCursor(0,1);
  lcd.print(getSonar());
}

float getSonar() {
 unsigned long pingTime;
 float distance;
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 pingTime = pulseIn(echoPin, HIGH, timeOut);
 distance = (float)pingTime * soundVelocity / 2 / 10000;
 return distance; 
}
bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
