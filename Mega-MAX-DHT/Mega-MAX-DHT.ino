/*
 * Digital Still monitor 
 * 
 * DHT11 on pin 53
 * 
 *  MAX6675, consecutive 3 pins each from 2 to 51 ? (16 TCs?)
 * 
 * 
 * 
 * 
 */

//Includes
#include <DHT.h>
#include <SoftwareSerial.h>
#include <max6675.h>
//#include <MAX6675_Thermocouple.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>



//Definitions and initializations
//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//DHT11
#define DHTPIN 53
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Serial

using Type = MAX6675*;

//MAX6675 Thermocouples definition
MAX6675 TC[] = { MAX6675( 2,  3,  4), MAX6675( 5,  6,  7), MAX6675(8, 9, 10), 
                 MAX6675(11, 12, 13), MAX6675(14, 15, 16), MAX6675(17, 18, 19), 
                 MAX6675(22, 23, 24), MAX6675(25, 26, 27), MAX6675(28, 29, 30),
                 MAX6675(31, 32, 33), MAX6675(34, 35, 36), MAX6675(37, 38, 39),
                 MAX6675(40, 41, 42), MAX6675(43, 44, 45), MAX6675(46, 47, 48),
                 MAX6675(49, 50, 51)};


//Serial


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("***** RESTART *****");
  dht.begin();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float DHTh = dht.readHumidity();
  float DHTt = dht.readTemperature();
  String str = String("DHT>T:")+String(DHTt)+String("       ")+String("DHT>H:")+String(DHTh);
  Serial.println(str);
  for (int i = 0; i <= 15 ; i++)
  {
    
    float temp=TC[i].readCelsius();
    if (temp >= 0.1 )
    {
      String str = String("TC")+String(i)+String("=")+String(temp);
      Serial.println(str);
//      Serial.println(TC[i].readCelsius());
      delay(250);
    }
  delay(50);  
  }
  Serial.println("--check--");
  
}
