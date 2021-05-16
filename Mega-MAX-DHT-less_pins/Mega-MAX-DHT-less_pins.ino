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
//#include <max6675.h>
#include <MAX6675_Thermocouple.h>
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

//using Type = MAX6675_Thermocouple*;
#define CK_PIN 2
#define SO_PIN 3
//MAX6675 thermocoupleA(CK_PIN, CS_PIN_A, SO_PIN);
//MAX6675 Thermocouples definition
MAX6675_Thermocouple TC[] = { MAX6675_Thermocouple(CK_PIN, 4, SO_PIN), MAX6675_Thermocouple( CK_PIN, 5, SO_PIN), MAX6675_Thermocouple(CK_PIN, 6, SO_PIN), 
                 MAX6675_Thermocouple(CK_PIN, 7, SO_PIN), MAX6675_Thermocouple( CK_PIN, 8, SO_PIN)
};

//Serial


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("***** RESTART *****");
  dht.begin();
  delay(2000);
  for (int i = 2; i <= 8 ; i++)
  {
    digitalWrite(i, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float DHTh = dht.readHumidity();
  float DHTt = dht.readTemperature();
  String str = String("DHT>T:")+String(DHTt)+String("       ")+String("DHT>H:")+String(DHTh);
  Serial.println(str);
  
  for (int i = 0; i <= sizeof(TC) ; i++)
  {
    
    float temp=TC[i].readCelsius();
    if (temp >= 0.1 )
    {
      String str = String("TC")+String(i)+String("=")+String(temp);
      Serial.println(str);
//      Serial.println(TC[i].readCelsius());
      //delay(50);
    }
  }
  delay(50);  
  Serial.println("--check--");
  
}
