//Imports
#include "Sensors.h"

/*
//Definations

//Initialisations
bool B_v1[7]; 
    //B_v1[0-3] - tyre temperature/Brake temperature
    //B_v1[4-7] - tyre pressure/Brake wear
bool B_persist[3][7];
    //For persistent values
int ValueBin = 0, flag = 0;
int change[3]; 
*/

int forReturn = 0, iterator = 0, BinaryMultiplier =0, power =0, flag =0;
//int sensorPanel[8] = {0,0,0,0,0,0,0,0};
//Data simulation 

//I can't think 
//https://theiotprojects.com/esp8266-data-logger-upload-data-on-webserver/
//https://www.youtube.com/watch?v=61floBUAiTY&list=RD61floBUAiTY&start_radio=1
//https://forum.qt.io/topic/109799/how-to-send-the-data-from-qt-app-to-arduino-by-serial-communication/3
//Function Declarations  
//int binaryConv(bool B_v1);          //Takes the boolean values of integers covert them into a string and output a decimal equivalent
int checkTyre();  //Check tyre pressure and Temperature 
int checkBrakes();
int checkToggles();

/*FIXMEIf car tyre temp is taken using if condition directly 
using integers instead of boolean*/

//This is fucking bonkers
//Can't fucking do this shit anymore 
//Hier 1 Accept data function
//Hier 2 Function to compare data
//Hier Done
      //3 Function to aggregate binary data
      //4 Funtion to convert binary to integer
      //5 Function to send binary data 


//Setup and Looping 
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(" [");
  Serial.print(checkTyre());
  Serial.print(",");
  Serial.print(checkBrakes());
  Serial.print(",");
  Serial.print(checkToggles());
  Serial.print("]");
  Serial.println(" ");
  delay(1000);
}

//Function Definations 
  
int checkTyre()  //Check tyre pressure and Temperature 
{

    for(iterator =0, forReturn = 0, BinaryMultiplier = 10000000, power = 7; iterator <8; ++iterator, --power) //Defines the values of sensor to an array
    {
		flag = readSensorDataTyre(iterator);
		forReturn +=  (flag * (pow(2,power)));
		//cout<<"Sensor data:"<<readSensorDataTyre(iterator)<<"  flag:"<<flag<<"  Power:"<<pow(2,power)<<"  forReturn:"<<forReturn<<"\n";;
    }
    return forReturn;
}
    
int checkBrakes()
{

    for(iterator =0, forReturn = 0, BinaryMultiplier = 10000000, power = 7; iterator <8; ++iterator, --power) //Defines the values of sensor to an array
    {
		flag = readSensorDataBrake(iterator);
		forReturn +=  (flag * (pow(2,power)));
		//cout<<"Sensor data:"<<readSensorDataTyre(iterator)<<"  flag:"<<flag<<"  Power:"<<pow(2,power)<<"  forReturn:"<<forReturn<<"\n";;
    }
    return forReturn;
}
int checkToggles()
{


    for(iterator =0, forReturn = 0, BinaryMultiplier = 10000000, power = 7; iterator <8; ++iterator, --power) //Defines the values of sensor to an array
    {
		flag = readSensorDataToggles(iterator);
		forReturn +=  (flag * (pow(2,power)));
		//cout<<"Sensor data:"<<readSensorDataTyre(iterator)<<"  flag:"<<flag<<"  Power:"<<pow(2,power)<<"  forReturn:"<<forReturn<<"\n";;
    }
    return forReturn;
}