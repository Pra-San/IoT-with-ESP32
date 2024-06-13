#define PIN_LED 2
#define PIN_BUTTON 13
void setup() {
 pinMode(PIN_LED, OUTPUT);
 pinMode(PIN_BUTTON, INPUT);
}
void loop() {
 if (digitalRead(PIN_BUTTON) == LOW) {
 delay(20);
 if (digitalRead(PIN_BUTTON) == LOW) {
 reverseGPIO(PIN_LED);
 }
 while (digitalRead(PIN_BUTTON) == LOW);
 delay(20);
 while (digitalRead(PIN_BUTTON) == LOW);
 }
}
void reverseGPIO(int pin) {
 digitalWrite(pin, ! digitalRead(pin));
}
