
 // original library source:
// www.ladyada.net/learn/sensors/thermocouple
 /*
 * Arduino code to read temperature using MAX6675 chip and k-type thermocouple
 * and display on LCD1602 I2C Display
 * 
 * Watch video instruction for this code: https://youtu.be/BlhpktgPdKs
 * 
 * Download this code from Robojax.com
 *  
 * updated by Ahmad Shamshiri for Robojax.com on Saturday November 24, 2018 
 * in Ajax, Ontario, Canada
 * 
 
 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "max6675.h"// this file is part of the library. See video for details

// start of settings for LCD1602 with I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>// this file is part of the library. See video for details
// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// end of settings for LCD1602 with I2C

int soPin1 = 11;// SO=Serial Out
int csPin1 = 10;// CS = chip select CS pin
int sckPin1 = 9;// SCK = Serial Clock pin

int soPin2 = 7;// SO=Serial Out
int csPin2 = 6;// CS = chip select CS pin
int sckPin2 = 5;// SCK = Serial Clock pin

int soPin3 = 14;// SO=Serial Out
int csPin3 = 15;// CS = chip select CS pin
int sckPin3 = 16;// SCK = Serial Clock pin

int soPin4 = 22;// SO=Serial Out
int csPin4 = 23;// CS = chip select CS pin
int sckPin4 = 24;// SCK = Serial Clock pin

float temp1=0.0;
float temp2=0.0;
float temp3=0.0;
float temp4=0.0;

MAX6675 thermocouple1(sckPin1, csPin1, soPin1);
MAX6675 thermocouple2(sckPin2, csPin2, soPin2);
MAX6675 thermocouple3(sckPin3, csPin3, soPin3);
MAX6675 thermocouple4(sckPin4, csPin4, soPin4);

int dt=500;

void setup() {
  // Robojax.com MAX6675 video with LCD1602 20181124
  lcd.init();// initializ the LCD1602
  lcd.backlight();// turn the backlight ON for the LCD
    //  lcd.print("Robojax MAX6675");
    //  lcd.setCursor(0,1);
    //  lcd.print("Thermocouple");  
          
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  //Serial.println("Robojax MAX6675"); 
    
 delay(3000);// give time to user to read the display at the beginning
 // Robojax.com MAX6675 video with LCD1602 20181124
}

void loop() {
  // basic readout test, just print the current temp
  // Robojax.com MAX6675 video with LCD1602 20181124

temp1=thermocouple1.readCelsius();
temp2=thermocouple2.readCelsius();
temp3=thermocouple3.readCelsius();
temp4=thermocouple4.readCelsius();
  
   Serial.print("C1 = "); 
   Serial.println(temp1);
   Serial.print("C2 = "); 
   Serial.println(temp2);
   delay(dt);
   Serial.print("C3 = "); 
   Serial.println(temp3);
   Serial.print("C4 = "); 
   Serial.println(temp4);
   Serial.println("-------------");
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFahrenheit());

  lcd.clear();// clear previous values from screen 
      lcd.setCursor(0,0);// set cursor at character 0, line 0       
      lcd.print(temp1); 
      lcd.setCursor(5,0);// set cursor at character 9, line 1
      lcd.print((char)223); 
      lcd.setCursor(6,0);// set cursor at character 9, line 1
      lcd.print("C");    
       
      lcd.setCursor(7,0);// set cursor at character 9, line 1
      lcd.print("  ");       
      lcd.setCursor(9,0);// set cursor at character 9, line 1
      lcd.print(temp2);
      lcd.setCursor(14,0);// set cursor at character 9, line 1      
      lcd.print((char)223); 
      lcd.setCursor(15,0);// set cursor at character 9, line 1
      lcd.print("C"); 
       
      lcd.setCursor(0,1);// set cursor at character 0, line 0       
      lcd.print(temp3); 
      lcd.setCursor(5,1);// set cursor at character 9, line 1
      lcd.print((char)223); 
      lcd.setCursor(6,1);// set cursor at character 9, line 1
      lcd.print("C");    
              
      lcd.setCursor(7,1);// set cursor at character 9, line 1
      lcd.print("  ");       
      lcd.setCursor(9,1);// set cursor at character 9, line 1
      lcd.print(temp4);
      lcd.setCursor(14,1);// set cursor at character 9, line 1      
      lcd.print((char)223); 
      lcd.setCursor(15,1);// set cursor at character 9, line 1
      lcd.print("C");       
 // Robojax.com MAX6675 video with LCD1602 20181124            
   delay(dt);
}
