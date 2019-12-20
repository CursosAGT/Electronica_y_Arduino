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
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[0] |---------\
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[0] |-------\ |
                                       *  * |             [ ] [ ] [ ]             | *  *  | |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *  | |
                                       *  * \________________________/              *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
+--------------------------+           *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
|   ___                    |----State  *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
|  [    +------+  +------+ |----RXD a TXD de Arduino--------------------------------------|-/   (pin 1)
|   ]   |      |  |      | |----TXD a RXD de Arduino-------------------------------------/      (pin 0)
|  [    |      |  |      | |----GND-------0    *  *  *  *  *       *  *  *  *  *    *  *
|   ]   +------+  +------+ |----Vcc-5v-0  *    *  *  *  *  *       *  *  *  *  *    *  *
|  [                       |-----      *  *    *  *  *  *  *       *  *  *  *  *    *  *
+--------------------------+           *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/
char valor;
int ledpin = 13;

void setup()
{

  pinMode(ledpin, OUTPUT);  // declaramos un led de testigo
  Serial.begin(9600);       // Inicializamos el puerto serial para comunicaciones
}

void loop()
{

  if(Serial.available())          // hay datos disponibles?
    valor = Serial.read();        // leemos el valor y lo colocamos en la variable valor
    Serial.println(valor);        // imprimimos el valor en el monitor serial
  if(valor == 'A')                // si recibimos una 'A'
     digitalWrite(ledpin, HIGH);  // prendemos el led
  else if(valor == 'b')           // si recibimos una 'B'
    digitalWrite(ledpin, LOW);    // apagamos el led
  delay(100);                    // delay 100ms para releer
}
