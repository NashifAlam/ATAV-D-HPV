
void setup() {
  Serial.begin(115200);
  Serial.println("Initialised");
}

void loop() {
  if (Serial.available()) 
  { 
    String command = Serial.readStringUntil('\n'); 
    Serial.println("String Values");
    Serial.println(command);
  }
}
