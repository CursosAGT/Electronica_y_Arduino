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
                                       *  * | [ ]RST                   MOSI/11[ ] | *  *
                                       *  * | [ ]3V3    +---+               10[ ] | *  *
                                       0------[0]5v    -| A |-               9[ ] | *  *
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *
                                       *  0---[0]GND   -| D |-                    | *  *
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *
                                       *  * |          -| I |-               6[ ]~| *  *
                                       *  * | [0]A0    -| N |-               5[ ]~| *  *
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *
                                       *  * | [ ]A3                     INT0/2[ ] | *  *
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *
                                       *  * |             [ ] [ ] [ ]             | *  *
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *
                                       *  * \________________________/              *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/
#define DEBUG 1/// poner 0

String leido = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Introduce una cadena de texto: ");
  while (Serial.available() == 0) {
    //No hago nada
  }

  do {
    char caracter_leido;
    delay(5);
    caracter_leido = Serial.read();
#if DEBUG
    Serial.print("Caracter leido: ");
    Serial.print(caracter_leido);
    Serial.print(" --> ");
    Serial.println(caracter_leido, DEC);
    Serial.print("Caracteres en buffer: ");
    Serial.println(Serial.available());
    Serial.println();
#endif
    leido += caracter_leido;
  }  while (Serial.available() > 0);

  Serial.println("He leido la cadena: \"" + leido + "\"");
}

void loop() {

  //no hago nada

}
