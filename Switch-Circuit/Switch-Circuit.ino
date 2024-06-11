
#define led 15
#define button 13

void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  if(digitalRead(button)==LOW) digitalWrite(led,HIGH);
  else digitalWrite(led,LOW);

}
