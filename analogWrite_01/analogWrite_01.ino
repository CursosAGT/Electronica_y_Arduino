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
                                       *  * | [ ]N/C                    SCK/13[ ] | *  *
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *
                                       *  * | [ ]RST                   MOSI/11[0]~|----------------------\
                                       *  * | [ ]3V3    +---+               10[0]~|---------------------\|
                                       0------[0]5v    -| A |-               9[0]~| -------------------\||
                                       *  0---[0]GND   -| R |-               8[ ] | *  *               |||
                                       *  * | [ ]GND   -| D |-                    | *  *               |||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *               |||
                                       *  * |          -| I |-               6[ ]~| *  *               |||
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *               |||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *               |||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *               |||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *               |||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               |||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               |||
                                       *  * |             [ ] [ ] [ ]             | *  *               |||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               |||
                                       *  * \________________________/              *  *               |||
                                                                                                       |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               |||
                                          220 Ohm            Led 1              /---------------------/ || pin 9
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                ||
                                                                                                        ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||
                                          220 Ohm            Led 2              /----------------------/ | pin 10
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |
                                                                                                         |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                          220 Ohm            Led 3              /-----------------------/  pin 11
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *

                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/

void setup() {
pinMode (11,OUTPUT);
pinMode (10,OUTPUT);
pinMode (9,OUTPUT);
}

void loop() {
  digitalWrite (11,LOW);
  delay(100);
  digitalWrite (11,HIGH);
  delay(100);
  digitalWrite (11,LOW);
  delay(100);

  analogWrite (10,0);
  delay(100);
  analogWrite (10,255);
  delay(100);
  analogWrite (10,0);
  delay(100);

  for (int contador = 0; contador <=255; contador++)
    {
    analogWrite (9,contador);
    delay(15);
    }
  }
