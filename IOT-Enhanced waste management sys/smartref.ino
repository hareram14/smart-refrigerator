#include "DHT.h"
#define DPIN 4        //Pin to connect DHT sensor (GPIO number) D2
#define DTYPE DHT11
#define sensorDigital 2
#define LED 3
#define buzzer 4
#define sensorAnalog A0
#define Sober 120   // Define max value that we consider sober
#define Drunk 400   // Define min value that we consider drunk

#define MQ3pin 0   // Define DHT 11 or DHT22 sensor type
float sensorValue;
DHT dht(DPIN,DTYPE);


#include <ESP8266WiFi.h>

const char *ssid =  "Your wifi Network name";     // replace with your wifi ssid and wpa2 key
const char *pass =  "Network password";

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
}
 
void loop() 
{      
  delay(2000);
  
  float tc = dht.readTemperature(false);  //Read temperature in C
  float tf = dht.readTemperature(true);   //Read Temperature in F
  float hu = dht.readHumidity();         //Read Humidity
  sensorValue = analogRead(MQ3pin);
  
  Serial.print(tc);
  Serial.print(',');
  Serial.print(hu);
  Serial.print(',');
  Serial.print(sensorValue);
  Serial.print("\n");
}

/*
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(sensorDigital, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.begin(9600); // sets the serial port to 9600
	Serial.println("MQ3 warming up!");
	delay(2000); // allow the MQ3 to warm up
}
void loop() {
  delay(2000);
  
  float tc = dht.readTemperature(false);  //Read temperature in C
  float tf = dht.readTemperature(true);   //Read Temperature in F
  float hu = dht.readHumidity();         //Read Humidity
  sensorValue = analogRead(MQ3pin);
  
  Serial.print(tc);
  Serial.print(',');
  Serial.print(hu);
  Serial.print(',');
  Serial.print(sensorValue);
  Serial.print("\n");
  

}
*/