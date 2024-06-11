#define led 15
#define button 13
void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  if(digitalRead(button)==LOW){
    delay(20);
    if(digitalRead(button)==LOW){
      digitalWrite(led,!digitalRead(led));
    }
    // while(digitalRead(led)==LOW);
    // delay(20);
    // while(digitalRead(led)=LOW);
  }
  
}
