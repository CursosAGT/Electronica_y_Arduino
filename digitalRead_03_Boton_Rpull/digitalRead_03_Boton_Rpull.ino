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
                                       *  * | [ ]N/C                    SCK/13[0]-----------------------\
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *                 |
                                       *  * | [ ]RST                   MOSI/11[ ]~| *  *                 |
                                       *  * | [ ]3V3    +---+               10[ ]~| *  *                 |
                                       0------[0]5v    -| A |-               9[ ]~| *  *                 |
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *                 |
                                       *  0---[0]GND   -| D |-                    | *  *                 |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                 |
                                       *  * |          -| I |-               6[ ]~| *  *                 |
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                 |
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                 |
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                 |
                                       *  * | [ ]A3                     INT0/2[0]---------------------\  |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               | |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               | |
                                       *  * |             [ ] [ ] [ ]             | *  *               | |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               | |
                                       *  * \________________________/              *  *               | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                                             BOTON           /------------------------/  | pin 2
                                       *  0----0  *  *  *  0--[X]--0  *  *  0  0-ww-0  *                 |         Pull UP
                                                                               10kOhm                    |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                                             BOTON           /------------------------/  |
                                       0-------0  *  *  *  0--[X]--0  *  *  0  0--www--0                 |         Pull Down
                                                                               10kOhm                    |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                          220 Ohm            Led 1              /-----------------------/  pin 13
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


                  Pull Down
                                 _T_
            /-----WWW-----T-----/   \-----\
           |     10 K     |       Touch    |
           |              |                |
           |GND           |Input Pin       | 5V

Resistencia pull down
En la configuración pull down, cuando el circuito está en reposo, una pequeña tension pasa por la resistencia de 10K manteniendo el puerto prácticamente en 0V estado LOW.
Si pulsamos pel boton, dejaremos pasar corriente y tendremos una diferencia de potencial de 5V poniendo el puerto en HIGH.


							Pull Down
                  _T_
            /----/   \----T-------WWW-----\
           |     Touch    |       10 K     |
           |              |                |
           |GND           |Input Pin       | 5V


Resistencia pull up
Por el contrario, en la configuración pull up, cuando el circuito está en reposo, una pequeña tencion pasa por la resistencia de 10K manteniendo el puerto estado HIGH.
Cuando pulsamos el boton se deriva toda la corriente a masa y la caída de tensión es a 0V dejando el puerto en LOW.


*/

int led =13;
int botton = 2;
int Boton_estado;
void setup() {
  Serial.begin(9600);
  pinMode(botton, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {

  int Boton_estado = digitalRead(botton);
  Serial.println(Boton_estado);

  if (Boton_estado == HIGH)
  {
    digitalWrite(led, LOW);
  } else
  {
    digitalWrite(led, HIGH);
  }
}
