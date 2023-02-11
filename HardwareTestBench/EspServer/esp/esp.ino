

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "ⁿ¹⁴⁵⁸¹"
#define STAPSK  "mnbvcxz1"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;


String command;


#define LED 2       //On board LED
#define DHTTYPE DHT11 // DHT 11
//uint8_t DHTPin = 5;
//DHT dht(DHTPin, DHTTYPE);


int Brakes, Tyres, Toggles;

ESP8266WebServer server(80);


const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html>
<head>
  <title>Logger</title>
  <h1 style="text-align:center; color:green;">Telemetry Data for High Performance Vehicle</h1>
  <h3 style="text-align:center;">ESP8266 Data Logger</h3>
  <style>
  canvas{
    -moz-user-select: none;
    -webkit-user-select: none;
    -ms-user-select: none;
  }
  /* Data Table Styling*/ 
  #dataTable {
    font-family: "Trebuchet MS", Arial, Helvetica, sans-serif;
    border-collapse: collapse;
    width: 100%;
    text-align: center;
  }
  #dataTable td, #dataTable th {
    border: 1px solid #ddd;
    padding: 8px;
  }
  #dataTable tr:nth-child(even){background-color: #f2f2f2;}
  #dataTable tr:hover {background-color: #ddd;}
  #dataTable th {
    padding-top: 12px;
    padding-bottom: 12px;
    text-align: center;
    background-color: #050505;
    color: white;
  }
  </style>
</head>
<body>
<div>
  <table id="dataTable">
    <tr><th>Time</th><th>Tyres</th></tr>
  </table>
</div>
<br>
<br>  
<script>


var TyreData = [];
var timeStamp = [];

// Call a function repetatively with 5 Second interval
setInterval(function() { getData(); }, 5000); //5000mSeconds update rate
function getData() 
{
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() 
      {
          if (this.readyState == 4 && this.status == 200) 
          {
              //Push the data in array
              var time = new Date().toLocaleTimeString();
              var txt = this.responseText;
              var obj = JSON.parse(txt); 
              TyreData.push(obj.Tyres);
              timeStamp.push(time);

              //Update Data Table
              var table = document.getElementById("dataTable");
              var row = table.insertRow(1); //Add after headings
              var cell1 = row.insertCell(0);
              var cell2 = row.insertCell(1);

              cell1.innerHTML = time;
              cell2.innerHTML = obj.Tyres;
          }
      };
  xhttp.open("GET", "readData", true); //Handle readData server on ESP8266
  xhttp.send();
}
</script>
</body>
</html>
)=====";


void handleRoot()
{
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}


void readData()
{
    String data = "{\"Tyres\":\""+ String(command) +"\"}";
    digitalWrite(LED,!digitalRead(LED)); 
    server.send(200, "text/plane", data); 
    delay(2000);
    if (Serial.available()) 
      { 
        command = Serial.readStringUntil('\n'); 
        Serial.println("Message broadcast:");
        Serial.println(command);
      }
    Serial.println(command);
    Serial.println(command);
    Serial.println(command);
}


void setup(void) 
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("esp8266")) 
    {
      Serial.println("MDNS responder started");
    }

    server.on("/", handleRoot);     
    server.on("/readData", readData); 
    server.begin();
    Serial.println("HTTP server started");
}


void loop(void) {
      server.handleClient();
      MDNS.update();
}
