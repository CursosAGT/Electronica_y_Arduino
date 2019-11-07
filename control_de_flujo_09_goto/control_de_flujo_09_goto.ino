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
                                       *  * | [ ]N/C                    SCK/13[0] |--------------------------\
                                       *  * | [ ]IOREF                 MISO/12[0] |-------------------------\|
                                       *  * | [ ]RST                   MOSI/11[0]~|------------------------\||
                                       *  * | [ ]3V3    +---+               10[0]~|-----------------------\|||
                                       0------[0]5v    -| A |-               9[0]~|----------------------\||||
                                       *  * | [ ]GND   -| R |-               8[0] |---------------------\|||||
                                       *  0---[0]GND   -| D |-                    | *  *                ||||||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                ||||||
                                       *  * |          -| I |-               6[ ]~| *  *                ||||||
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[0] |-----------\         ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *      |         ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *      |         ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *      |         ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *      |         ||||||
                                       *  * \________________________/              *  *      |         ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *      |         ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *      |         ||||||
                                       *  *    *  *  *  /-------------------------------------/         ||||||
                                       *  0-ww-0  0  *  0  0--[#]--0  *  *  *  0-ww-0  *  220 Ohms      ||||||
                                          1 kOhms           Boton 1                                     ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
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
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
                                    x == y         "x" es igual a "y"
                                    x != y        "x" NO es igual a "y"
                                    x <  y        "x" es menor a "y"
                                    x >  y        "x" es mayor a "y"
                                    x <= y        "x" es menor o igual a "y"
                  x >= y        "x" es mayor o igual a "y"
                  x == y && y==z    and  "x" es igual a "y" E "y" es igual a "z"
                  x == y || y==z    or  "x" es igual a "y" O "y" es igual a "z"



goto

The use of goto is discouraged in C programming, and some authors of C programming books claim that the goto statement is never necessary, but used judiciously, it can simplify certain programs.
The reason that many programmers frown upon the use of goto is that with the unrestrained use of goto statements, it is easy to create a program with undefined program flow, which can never be debugged.
With that said, there are instances where a goto statement can come in handy, and simplify coding. One of these situations is to break out of deeply nested for loops, or if logic blocks, on a certain condition.

*/


int boton = 2;
int demora =  50;
int pin =  0;
int bucle = 0;
int estado;
void setup()
{
  for (pin=8;pin<=13; pin++)
  {
    pinMode(pin,OUTPUT);
  }
  pinMode(boton,INPUT);
    Serial.begin(9600);
}

void loop()
{
  estado = digitalRead(boton);
  do
  {
    for (pin=8;pin<=13; pin++)
    {
      digitalWrite (pin,HIGH);
      delay(demora);
      digitalWrite (pin,LOW);
      delay(demora);
    }
    estado = digitalRead(boton);
      Serial.print("Dentro del do... while  ");
      Serial.println(estado);
  } while (estado != 1 );
  goto rutina;

rutina:
  {
    for (bucle=0;bucle<=1; bucle++)
    {
      for (pin=8;pin<=13; pin++)
      {
        digitalWrite (pin,HIGH);
        delay(demora);
      }
      for (pin=8;pin<=13; pin++)
      {
        digitalWrite (pin,LOW);
        delay(demora);
      }
    }
    Serial.print("fuera del while  ");
    Serial.println(estado);
  }
}
