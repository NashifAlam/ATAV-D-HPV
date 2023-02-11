/*unsigned long i = 10;

void setup() {
  Serial.begin(9600);  
  Serial1.begin(9600);
}

void loop() {

  Serial.print("Number ");
  Serial.print(i);
  Serial.println("");
  Serial1.write(i);
  delay(1000);
}*/
HardwareSerial &hSerial = Serial2; //can be Serial2 as well, just use proper pins
 String temp;

String readString;


void setup() 
{
  Serial.begin(115200);//open serial via USB to PC on default port
  hSerial.begin(115200);//open the other serial port
 
}

void loop()
{

  //expect a string like wer,qwe rty,123 456,hyre kjhg,
  //or like hello world,who are you?,bye!,
  
  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      //do stuff
      hSerial.write(readString); //prints string to serial port out
      readString=""; //clears variable for new input      
     }  
    else {     
      readString += c; //makes the string readString
    }
  }
}

 /*
{  
  if (Serial.available()) //check incoming on default serial (USB) from PC
      { 
        temp = Serial.read();
        while(temp > 13)
          hSerial.write(temp);   // read it from UBS and send it to hSerial 
      }

  if (hSerial.available()) //check incoming on other serial from the other board
      { 
        hSerial.write(Serial.read());   //read it from hSerial and send it to  UBS
      }*/
    //delay(1000);

