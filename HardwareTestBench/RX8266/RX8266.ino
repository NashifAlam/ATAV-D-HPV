//This is the receiver module

#include <SoftwareSerial.h>

//static const uint8_t D1 = 5;
//static const uint8_t D2 = 4;
SoftwareSerial myNode(D1, D2); //RX, TX

String temp;

void setup() {
  Serial.begin(115200);  
  myNode.begin(115200);
}

void loop() {
  //git = Serial.read();
  Serial.print("The Number is ");
  temp = Serial.read();
  Serial.print(temp);
  Serial.println("");
  delay(1000);
}
