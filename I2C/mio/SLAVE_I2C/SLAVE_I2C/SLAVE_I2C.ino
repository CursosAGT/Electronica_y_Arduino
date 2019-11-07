//Slave Arduino Programming

//I2C SLAVE CODE
//I2C Communication between Two Arduino
//CircuitDigest
//Pramoth.T

#include<Wire.h>                          //Library for I2C Communication functions
byte SlaveReceived = 0;

void setup() 
{
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 

void loop(void) 
{
  
  Serial.print(">>  Slave  <<\n");                      //Prints >> Slave << at LCD

    Serial.print("Slave Received From Master   ");    //Prints in Serial Monitor 
    Serial.println(SlaveReceived);
  
  
  delay(500);

  
}

void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master
{
   SlaveReceived = Wire.read();                    //Used to read value received from master and store in variable SlaveReceived
}
//That’s all, now connect Arduino Uno’s I2C pins (A4 [SDA] and A5 [SCL]) between each board, not forgetting the pull-up (1.2kΩ is fine) resistors for both SDA & SCL.
void requestEvent()                                //This Function is called when Master wants value from slave
{
  int potvalue = analogRead(A0);                   // Reads analog value from POT (0-5V)
  byte SlaveSend = map(potvalue,0,1023,0,127);    // Convert potvalue digital value (0 to 1023) to (0 to 127)
  Wire.write(SlaveSend);                          // sends one byte converted POT value to master
    Serial.print("Slave send   to     Master   ");                        //Prints SlaveVal: in LCD
    Serial.println(SlaveSend);                        //Prints SlaveReceived in LCD received from master
}
