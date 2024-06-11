byte leds[]={15,2,0,4,5,18,19,21,13,12};
void setup() {
  int n=sizeof(leds);
  for(int i = 0;i<n;i++){
    pinMode(leds[i],OUTPUT);
  }

}

void loop() {
  int n =sizeof(leds);
  for(int i = 0;i<n;i++){
    digitalWrite(leds[i],HIGH);
    delay(50);
  }
  for(int i = 0;i<n;i++){
    digitalWrite(leds[i],LOW);
    delay(50);
  }
}
