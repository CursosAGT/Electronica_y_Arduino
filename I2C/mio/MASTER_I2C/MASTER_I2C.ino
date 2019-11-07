//Master Arduino Programming

//I2C MASTER CODE 
//I2C Communication between Two Arduino
//Circuit Digest
//Pramoth.T

#include<Wire.h>                             //Library for I2C Communication functions

 void setup() 
{ 
  delay(5000);                               //Delay for 5 seconds
  Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  Wire.begin();                              //Begins I2C communication at pin (A4,A5)
}
//That’s all, now connect Arduino Uno’s I2C pins (A4 [SDA] and A5 [SCL]) between each board, not forgetting the pull-up (1.2kΩ is fine) resistors for both SDA & SCL.
void loop()
{
    Wire.requestFrom(8,1);                           // request 1 byte from slave arduino (8)
    byte MasterReceive = Wire.read();                // receive a byte from the slave arduino and store in MasterReceive
    int potvalue = analogRead(A0);                   // Reads analog value from POT (0-5V)
    byte MasterSend = map(potvalue,0,1023,0,127);    //Convert digital value (0 to 1023) to (0 to 127)
     
    Wire.beginTransmission(8);                       // start transmit to slave arduino (8)
    Wire.write(MasterSend);                          // sends one byte converted POT value to slave
    Wire.endTransmission();                          // stop transmitting
    Serial.print(">>  Master  <<\n");                     //Prints >> Master << at LCD
    Serial.print("Master send   to     Slave   ");                        //Prints SlaveVal: in LCD
    Serial.println(MasterSend);                        //Prints MasterReceive in LCD received from Slave
    Serial.print("Master Received From Slave   ");    //Prints in Serial Monitor 
    Serial.println(MasterReceive);
    delay(500);                                     
  
}     
 
