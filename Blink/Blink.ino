#define led 2
#define eled 15

void setup(){
  pinMode(led,OUTPUT);
  pinMode(eled,OUTPUT);
}

void loop(){
  digitalWrite(led,LOW);
  digitalWrite(eled,HIGH);
  delay(500);
  digitalWrite(led,HIGH);
  digitalWrite(eled,LOW);
  delay(500);
}