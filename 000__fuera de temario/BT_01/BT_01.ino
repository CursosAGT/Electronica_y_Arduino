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
                          *  * \______________________/               *  *       
 //bluetooth hc-05
int ledPin = 13; // usamos un pin de salida al LED
int state = 0; // Variable lectrura dato serial
int bandera=0; 
void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop() {
 
        if(Serial.available() > 0){
             state = Serial.read();
        } 
       
      
       if (state == 'A' && bandera==0) {
       
           digitalWrite(ledPin, HIGH);
           bandera = 1;
           state = 0;
       }
      
       if (state == 'A' && bandera==1)
       {
           digitalWrite(ledPin, LOW);
           bandera = 0;
           state = 0;
       }

}
