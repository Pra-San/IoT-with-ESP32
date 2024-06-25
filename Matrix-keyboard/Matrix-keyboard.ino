#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define SDA 13 
#define SCL 14 
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Keypad.h>
char keys[4][4] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};
byte rowPins[4] = {4, 27, 26, 25}; 
byte colPins[4] = {15, 21, 22, 23}; 
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
Wire.begin(SDA, SCL); 
 if (!i2CAddrTest(0x27)) {
 lcd = LiquidCrystal_I2C(0x3F, 16, 2);
 }
 lcd.init(); 
 lcd.backlight(); 
 lcd.setCursor(0,0); 
 lcd.print("Keyboard Input:");
}
int a=0;
void loop() {
 char keyPressed = myKeypad.getKey();
 if(a>16){
   for(int i=0;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
   }
   a=0;
 }
 if (keyPressed) {
 lcd.setCursor(a,1);
 lcd.print(keyPressed);
 a++;
 }
}
bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}