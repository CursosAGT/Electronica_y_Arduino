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
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                 |
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                 |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                 |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                 |
                                       *  * |             [ ] [ ] [ ]             | *  *                 |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                 |
                                       *  * \________________________/              *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *  ___   *  *  *  *  *    *  *                |
                                          220 Ohm            /   \               /-----------------------/  pin 11
                                       *  0-ww-0  *  *  *  0( ( ) )0  *  *  *  0    *  *
                                       *  *    *  *  *  *  * \___/ *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
Buzzer Activo: genera un zumbido a frecuencia estable y preestablecida al conectarla a 5v
Buzzer Pasivo: genera un zumbido a frecuencia distintas dependiendo de la señal PWM(modulacion por ancho de pulso) ingresada

 Piezo

 This example shows how to run a Piezo Buzzer on pin 9
 using the analogWrite() function.

 It beeps 3 times fast at startup, waits a second then beeps continuously
 at a slower pace

 */

void setup()  {
  // declare pin 9 to be an output:
  pinMode(11, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
}

void loop()  {
  beep(200);
}

void beep(unsigned char delayms){
  analogWrite(9, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms
}
