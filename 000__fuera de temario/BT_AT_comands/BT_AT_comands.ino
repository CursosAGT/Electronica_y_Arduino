/*                        +  -                                        +  -
                          *  *    *  *  *  *  *      *  *  *  *  *    *  * 		    
                          *  *    *  *  *  *  *      *  *  +-----+    *  *          
                          *  * +----[PWR]------------------| USB |--+ *  *          
                          *  * |                           +-----+  | *  *          
                          *  * |         GND/RST2 [ ][ ]            | *  *          
                          *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *          
                          *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *          
                          *  * |                            AREF[ ] | *  *          
                          *  * |                             GND[ ] | *  *          
                          *  * | [ ]N/C                   SCK/13[ ] | *  *          
                          *  * | [ ]IOREF                MISO/12[ ] | *  *          
                          *  * | [ ]RST                  MOSI/11[0]~| *  *          
                          *  * | [ ]3V3    +---+              10[0]~| *  *          
                          *  * | [ ]5v    -| A |-              9[0]~| *  *          
                          *  * | [0]GND   -| R |-              8[ ] | *  *          
                          *  * | [ ]GND   -| D |-                   | *  *          
                          *  * | [ ]Vin   -| U |-              7[ ] | *  *          
                          *  * |          -| I |-              6[ ]~| *  *          
                          *  * | [0]A0    -| N |-              5[ ]~| *  *          
                          *  * | [ ]A1    -| O |-              4[ ] | *  *          
                          *  * | [ ]A2     +---+          INT1/3[ ]~| *  *          
                          *  * | [ ]A3                    INT0/2[ ] | *  *          
                          *  * | [ ]A4/SDA  RST SCK MISO    TX>1[ ] | *  *          
                          *  * | [ ]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *          
                          *  * |            [ ] [ ] [ ]             | *  *          
                          *  * |  UNO_R3    GND MOSI 5V ____________/ *  *          
                          *  * \______________________/               *  *  */     
#include <SoftwareSerial.h>

SoftwareSerial BT1(10, 11); // RX | TX
void setup()
   { pinMode(8, OUTPUT);        // Al poner en HIGH forzaremos el modo AT
     pinMode(9, OUTPUT);        // cuando se alimente de aqui
     digitalWrite(9, HIGH);
     delay (500) ;              // Espera antes de encender el modulo
     Serial.begin(9600);
     Serial.println("Levantando el modulo HC-06");
     digitalWrite (8, HIGH);    //Enciende el modulo
     Serial.println("Esperando comandos AT:");
     BT1.begin(57600); 
   }

void loop()
   {  if (BT1.available())
            Serial.write(BT1.read());
      if (Serial.available())
            BT1.write(Serial.read());
   }
/*
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}
*/
