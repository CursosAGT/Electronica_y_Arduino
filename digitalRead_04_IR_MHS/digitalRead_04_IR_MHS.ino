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
                                       *  * | [ ]3V3    +---+               10[ ]~| *  *                 |
                                       0------[0]5v    -| A |-               9[ ]~| *  *                 |
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *                 |
                                       *  0---[0]GND   -| D |-                    | *  *                 |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                 |
                                       *  * |          -| I |-               6[ ]~| *  *                 |
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                 |
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                 |
                                       *  * | [ ]A2     +---+           INT1/3[ ]~|-------------------\  |
                                       *  * | [ ]A3                     INT0/2[ ] | *  *               | |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               | |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               | |
                                       *  * |             [ ] [ ] [ ]             | *  *               | |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               | |
                                       *  * \________________________/              *  *               | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                       *  *   __ -------------------  *  *  *  *    0  *               | |
                                             C__|             vcc ----0------------/   *               | |
                                       *  *   __   MHS  IR    gnd ----0----------------0               | |
                                             C__|             data----0--------------------------------/ | PIN 3
                                       *  *    * -------------------  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                          220 Ohm            Led 3              /-----------------------/  pin 11
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
int demora =  500;
int led = 13;
int IR_Modulo = 3;
boolean estado;

void setup()
 {

  {
    pinMode(led,OUTPUT);
  }
  Serial.begin(9600);
  pinMode(IR_Modulo,INPUT);
}

void loop()
{
  estado = digitalRead (IR_Modulo);//          cambiar            !digitalRead (IR_Modulo);
  digitalWrite (led,estado);
    Serial.print("Obstaculo  : ");
    Serial.println(estado);
  delay(demora);

  if (estado == LOW)
  {
      Serial.println("Se encontro un obstaculo");
  }

}
