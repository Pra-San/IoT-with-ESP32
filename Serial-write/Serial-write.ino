String inputString="";
bool stringComplete = false;
void setup() {
  Serial.begin(115200);
  Serial.println(String("\n ESP32 initialization completed!\n")+String("Enter something")+String("Select \"Newline\" below and press enter.\n"));
}

void loop() {
  if(Serial.available()){
    char inChar = Serial.read();
    inputString+=inChar;
    if(inChar == '\n'){
      stringComplete=true;
    }
  }
  if(stringComplete){
    Serial.printf("inputString: %s \n",inputString);
    inputString="";
    stringComplete=false;
  }
}
