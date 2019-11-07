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
                                       *  * | [ ]N/C                    SCK/13[0] |--------------------\
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *               |
                                       *  * | [ ]RST                   MOSI/11[ ]~| *  *               |
                                       *  * | [ ]3V3    +---+               10[ ]~| *  *               |
                                       0------[0]5v    -| A |-               9[ ]~| *  *               |
                                       *  0---[0]GND   -| R |-               8[ ] | *  *               |
                                       *  * | [ ]GND   -| D |-                    | *  *               |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *               |
                                       *  * |          -| I |-               6[ ]~| *  *               |
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *               |
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *               |
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *               |
                                       *  * | [ ]A3                     INT0/2[ ] | *  *               |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               |
                                       *  * |             [ ] [ ] [ ]             | *  *               |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               |
                                       *  * \________________________/              *  *               |
                                                                                                       |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               |
                                          220 Ohm            Led 1              /---------------------/ pin 13
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/


int demora =  250;
int pin =  13;
void setup()
{
	pinMode(13,OUTPUT);
}

void loop()
{
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
	digitalWrite(pin,HIGH);
	delay(demora);
	digitalWrite(pin,LOW);
	delay(demora);
}
