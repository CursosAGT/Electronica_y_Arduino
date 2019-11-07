#include <DHT11.h>

#include <Wire.h>
#include <LCD.h>
// Codigo para usar un LCD 16x2 con Arduino
#include <LiquidCrystal_I2C.h>
 
//Pines en el PCF8574(dir, en,rw,rs,d4,d5,d6,d7,bl, blpol)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int sensorPin= A0;;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}
void loop()
{
  int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.print(celsius);
  Serial.println(" C");
  //escribimos un texto  
  lcd.setCursor(2,0);
  lcd.print(celsius);
  lcd.setCursor(8,0);
  lcd.print("- C");

  lcd.setCursor(2,1);
  lcd.print(celsius);
  lcd.setCursor(8,1);
  lcd.print("Humedad");
  //Esperamos  
  delay(1000);  
  //Y lo borramos  
  lcd.clear();  
}


