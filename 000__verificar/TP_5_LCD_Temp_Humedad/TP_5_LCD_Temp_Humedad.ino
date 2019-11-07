#include <DHT11.h>
#include <Wire.h>
#include <LCD.h>
// Codigo para usar un LCD 16x2 con Arduino
#include <LiquidCrystal_I2C.h>
 
//Pines en el PCF8574(dir, en,rw,rs,d4,d5,d6,d7,bl, blpol)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int sensorPin= A0;;
int pin=2;
DHT11 dht11(pin);

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
      lcd.setCursor(0,1);
      lcd.print("sensor simple");
      //Esperamos  Recordad que solo lee una vez por segundo
      delay(1000);  
      //Y lo borramos  
      lcd.clear();  
      int err;
      float temp, hum;
      if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
            Serial.print("Temperatura: ");
            Serial.print(temp);
            Serial.print(" Humedad: ");
            Serial.print(hum);
            Serial.println();
            
            int value = analogRead(sensorPin);
            float millivolts = (value / 1023.0) * 5000;
            float celsius = millivolts / 10; 
            Serial.print(celsius);
            Serial.println(" C");
            //escribimos un texto linea 1 
            lcd.setCursor(2,0);
            lcd.print(temp);
            lcd.setCursor(8,0);
            lcd.print("- C");
            //escribimos un texto linea 2            
            lcd.setCursor(2,1);
            lcd.print(hum);
            lcd.setCursor(8,1);
            lcd.print("Humedad");
          }
       else
          {
            Serial.println();
            Serial.print("Error Num :");
            Serial.print(err);
            Serial.println();
            
            //escribimos un texto linea 1 
            lcd.setCursor(2,0);
            lcd.print("Error en la toma");
            //escribimos un texto linea 2            
            lcd.setCursor(2,1);
            lcd.print("Error ");
            lcd.setCursor(8,1);
            lcd.print("de temp y Hum.");
          }
        //Esperamos  Recordad que solo lee una vez por segundo
        delay(1000);  
        //Y lo borramos  
       lcd.clear();  
    }

