/*                                     +  -                                         +  -
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  +-----+    *  *
                                       *  * +----[PWR]-------------------| USB |--+ *  *
                                       *  * |                            +-----+  | *  *
                                       *  * |         GND/RST2  [ ][ ]            | *  *
                                       *  * |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] | *  *
                                       *  * |          5V/MISO2 [ ][ ]  A4/SDA[ ] | *  *
                                       *  * |                             AREF[ ] | *  *
                                       *  * |                              GND[ ] | *  *
                                       *  * | [ ]N/C                    SCK/13[0] |-------------------------\
                                       *  * | [ ]IOREF                 MISO/12[0] |------------------------\ |
                                       *  * | [ ]RST                   MOSI/11[0]~|-----------------------\|||
                                       *  * | [ ]3V3    +---+               10[0]~|----------------------\||||
                                       0------[0]5v    -| A |-               9[0]~|---------------------\|||||
                                       *  * | [ ]GND   -| R |-               8[0] |--------------------\||||||
                                       *  0---[0]GND   -| D |-                    | *  *                ||||||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                ||||||
                                       *  * |          -| I |-               6[ ]~| *  *                ||||||
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *                ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
                                       *  * \________________________/              *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                                                                                                          ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                                          220 Ohm            Led 3              /------------------------/ ||| pin 10
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                          220 Ohm            Led 4              /-------------------------/ || pin 11
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                          220 Ohm            Led 5              /--------------------------/ | pin 12
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                          220 Ohm            Led 6              /---------------------------/  pin 13
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/

int demora =  100;
int pin =  0;
int bucle = 0;
int estado;

void setup()
{
  for (pin=8;pin<=13; pin++)
  {
    pinMode(pin,OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
    char estado = Serial.read(); // read the incoming byte:
    if (estado!='\n')
    {
      Serial.print("Dato recibido desde pc:");
      Serial.println(estado);
    }
    for (pin=8;pin<=13; pin++)
      {
        digitalWrite (pin,HIGH);
        delay(demora);
        digitalWrite (pin,LOW);
        delay(demora);
      }
     }
    else
    {
    Serial.println("Sin Datos desde pc");
    for (pin=13;pin>=8; pin--)
      {
        digitalWrite (pin,LOW);
        delay(demora);
        digitalWrite (pin,HIGH);
        delay(demora);
      }
    }
 }
/*-------------------------------* /
int incomingByte = 0;

void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() {

if (Serial.available() > 0) {

incomingByte = Serial.read(); // read the incoming byte:

Serial.print(" I received:");

Serial.println(incomingByte);

}

}*/
