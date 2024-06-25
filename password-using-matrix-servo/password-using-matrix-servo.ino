#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ESP32Servo.h>

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
Servo myservo; // Create servo object to control a servo
int servoPin = 19; 
int ledPin = 18; 
char passWord[] = {"1234"}; // Save the correct password

void setup() {
myservo.setPeriodHertz(50); // standard 50 hz servo
 myservo.attach(servoPin, 500, 2500); 
 myservo.write(0); 
 pinMode(ledPin,OUTPUT);
 Wire.begin(SDA, SCL); 
 if (!i2CAddrTest(0x27)) {
 lcd = LiquidCrystal_I2C(0x3F, 16, 2);
 }
 lcd.init(); 
 lcd.backlight(); 
 lcd.setCursor(0,0); 
 lcd.print("Enter Password:");

}
int a =0;
void loop() {
static char keyIn[4]; // Save the input character
 static byte keyInNum = 0; // Save the number of input characters
 char keyPressed = myKeypad.getKey(); // Get the character input
 // Handle the input characters
 if (keyPressed) {
 // Make a prompt tone each time press the key
 digitalWrite(ledPin, HIGH);
 delay(100);
 digitalWrite(ledPin, LOW);
 keyIn[keyInNum++] = keyPressed;
 // Judge the correctness after input
 if(keyInNum == 1){
  for(int i=0;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
   }
 }
 if (keyInNum == 4) {
  a=0;
 bool isRight = true; // Save password is correct or not
 for (int i = 0; i < 4; i++) { // Judge each character of the password is correct or not
 if (keyIn[i] != passWord[i])
 isRight = false; // Mark wrong password if there is any wrong character.
 }
 if (isRight) { // If the input password is right
   lcd.setCursor(0,1);
 lcd.print("passWord right! ");
 myservo.write(90); // Open the switch
 delay(2000); // Delay a period of time
 myservo.write(0); // Close the switch

 }
 else { // If the input password is wrong
 digitalWrite(ledPin, HIGH);// Make a wrong password prompt tone
 delay(1000);
 digitalWrite(ledPin, LOW);
  lcd.setCursor(0,1);
 lcd.print("passWord error! ");
 

 }
 keyInNum = 0; // Reset the number of the input characters to 0
 } else{
  lcd.setCursor(a,1);
  lcd.print("*");
  a++;
 }
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