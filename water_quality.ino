/*

This is example for SHT3X-DIS Digital Humidity & Temperature Sensors Arduino Library
ClosedCube SHT31-D [Digital I2C] Humidity and Temperature Sensor Breakout

Initial Date: 06-Oct-2015
Last Updated: 12-Oct-2016

Hardware connections for Arduino Uno:
VDD to 3.3V DC
SDA to A4
SCL to A5
GND to common ground

MIT License

*/

#include <Wire.h>
#include "ClosedCube_SHT31D.h"
#include "Adafruit_TCS34725.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <math.h>

const char* ssid = "JuliusLieblingsPC";
const char* password = "mainLAAN";

String tobesend;
uint8_t did_send = 0;

ClosedCube_SHT31D sht3xd;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);
uint16_t r, g, b, c;
float water_conduct;
float temperature;
uint8_t water_polluted;
uint8_t buffer_cntr = 0;
uint8_t buffer[5];

void setup()
{
	Wire.begin();
	Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
    
  while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  

    if (tcs.begin()) {
    Serial.println("Found TCS34725");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

	Serial.println("ClosedCube SHT3X-D Periodic Mode Example");
	Serial.println("supports SHT30-D, SHT31-D and SHT35-D");

	sht3xd.begin(0x44); // I2C address: 0x44 or 0x45

	Serial.print("Serial #");
	Serial.println(sht3xd.readSerialNumber());

	if (sht3xd.periodicStart(SHT3XD_REPEATABILITY_HIGH, SHT3XD_FREQUENCY_10HZ) != SHT3XD_NO_ERROR)
		Serial.println("[ERROR] Cannot start periodic mode");
  pinMode(D0, OUTPUT);
  analogWrite(D0, 10);   
  pinMode(A0, INPUT);
}
uint8_t decide_water_quality(){
  uint16_t water_conduct_threshold = 180;
  // float temperature_threshold = 30.;


  if(water_conduct < water_conduct_threshold){
    water_polluted = 1;
    }
  // if(temperature > temperature_threshold){
  //   water_polluted = 1;
  return water_polluted;
}
void pushNotification(uint8_t water_quality_bad){
  if (water_quality_bad && (did_send==0))
    {
      Serial.print("1");
      did_send = 1;
      sendMessage("&text=The+water+is+polluted.+Drink+only+after+cleaning.");
    }
  if (!water_quality_bad && (did_send==1))
  {
      sendMessage("&text=The+water+is+clean+again.");
      did_send = 0;

  }
}

void sendMessage(String sendText){
      Serial.print("connecting to ");
      Serial.println("whatsapp");
      WiFiClient client;
      HTTPClient http; //Declare an object of class HTTPClient
      //Specify request destination
      tobesend = "http://api.callmebot.com/whatsapp.php?";
      tobesend = tobesend + "phone=+4917672503958";
      tobesend = tobesend + sendText;
      tobesend = tobesend + "&apikey=809671";
      http.begin(client,tobesend); 
      int httpCode = http.GET(); //Send the request
      if (httpCode > 0) 
          { 
           //Check the returning code
           String payload = http.getString(); //Get the request response payload
           Serial.println(payload); //Print the response payload
          }
      http.end(); //Close connection
}

void loop()
{
	printResult("Periodic Mode", sht3xd.periodicFetchData());
  water_conduct = analogRead(A0);
	delay(250);
  tcs.getRawData(&r, &g, &b, &c);
    Serial.print("W: "); Serial.print(water_conduct, DEC); Serial.print(" ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  // Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");

  buffer[buffer_cntr] = decide_water_quality();
  buffer_cntr++;
  if(buffer_cntr == 5){
    buffer_cntr = 0;
  }
  uint8_t sum;
  for(int i = 0; i<5; i++){
    sum = sum + buffer[i];
  }
  if(sum == 5){
      Serial.println("DANGER!!!");
  pushNotification(sum);
  Serial.println(" ");
}}


void printResult(String text, SHT31D result) {
	if (result.error == SHT3XD_NO_ERROR) {
    Serial.println("");
		Serial.print(": T=");
		Serial.print(result.t);
		Serial.print("C, RH=");
		Serial.print(result.rh);
		Serial.println("%");
	} else {
		Serial.print(text);
		Serial.print(": [ERROR] Code #");
		Serial.println(result.error);
	}
}

