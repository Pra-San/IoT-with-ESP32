const byte leds[]={15,2,4};
const byte chns[]={0,1,2};

int red,green,blue;
void setup() {
  for(int i=0;i<3;i++){
    ledcSetup(chns[i],1000,8);
    ledcAttachPin(leds[i],chns[i]);
  }
}

void loop() {
  red = random(0,256);
  blue = random(0,256);
  green = random(0,256);
  ledcWrite(chns[0],255-red);
  ledcWrite(chns[1],255-green);
  ledcWrite(chns[2],255-blue);
  delay(200);
}
