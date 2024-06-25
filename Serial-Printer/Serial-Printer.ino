void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 initialization completed!");
}

void loop() {
  Serial.printf("Running time: %.lf s\n",millis()/1000.0f);
  delay(1000);
}
