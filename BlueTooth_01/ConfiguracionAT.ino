/*
 *     CONEXIONES
 *  Pin 9 Arduino --> RX Bluetooth
 *  Pin 8 Arduino --> TX Bluetooth
 */

/*
 * INTRODUCIR LOS SIGUIENTES COMANDOS (en orden) 
 * 
 * AT+ORGL
 * AT+ROLE=0 
 * AT+POLAR=1,0
 * AT+UART=115200,0,0 El número 115200 depende del modelo de Arduino
 * AT+INIT 
 * 
 */

/*
 *  VELOCIDADES
 *  
 *  ArduinoUNO ---> 115200
 *  Arduino Mini Pro --> 57600
 *  Arduino Diecemila o Duemilanove (con ATmega168) --> 19200
 * 
 */

//Código de la página de Joshua Newell 
// La autoría de los comentarios es de Robotic Arts

#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9

SoftwareSerial mySerial(rxPin, txPin);
char myChar ;

void setup() {
  Serial.begin(9600);   
  Serial.println("AT");

  mySerial.begin(38400);
  mySerial.println("AT");
}

void loop() {
  while (mySerial.available()) {
    myChar = mySerial.read();
    Serial.print(myChar);
  }

  while (Serial.available()) {
    myChar = Serial.read();
    Serial.print(myChar); 
    mySerial.print(myChar);
  }
}
