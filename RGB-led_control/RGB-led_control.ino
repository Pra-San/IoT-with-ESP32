const byte ledPins[] = {15, 2, 4}; 
const byte chns[] = {0, 1, 2}; 
void setup() {
 for (int i = 0; i < 3; i++) {
 ledcSetup(chns[i], 1000, 8);
 ledcAttachPin(ledPins[i], chns[i]);
 }
}
void loop() {
 for (int i = 0; i < 256; i++) {
 setColor(wheel(i));
 delay(20);
 }
 }
void setColor(long rgb) {
 ledcWrite(chns[0], 255 - (rgb >> 16) & 0xFF);
 ledcWrite(chns[1], 255 - (rgb >> 8) & 0xFF);
 ledcWrite(chns[2], 255 - (rgb >> 0) & 0xFF);
}
long wheel(int pos) {
 long WheelPos = pos % 0xff;
 if (WheelPos < 85) {
 return ((255 - WheelPos * 3) << 16) | ((WheelPos * 3) << 8);
 } else if (WheelPos < 170) {
 WheelPos -= 85;
 return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
 } else {
 WheelPos -= 170;
 return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
 }
}