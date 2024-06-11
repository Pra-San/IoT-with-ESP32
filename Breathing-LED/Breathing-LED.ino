byte leds[]={15,2,0,4,5,18,19,21,13,12};
#define chn 0
void setup() {
  int n=sizeof(leds);
  ledcSetup(chn,1000,8);
  for(int i = 0;i<n;i++){
    ledcAttach(leds[i],chn)
  }

}


void loop() {
  int n =sizeof(leds);
  for(int i = 0;i<n;i++){
    for(int j=n-1;j>=0;j--){
      ledcWrite(leds[j],i);
      delay(50);

    }
    
    delay(50);
  }
}
