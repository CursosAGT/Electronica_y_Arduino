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


                                    x == y 				"x" es igual a "y"
                                    x != y 				"x" NO es igual a "y"
                                    x <  y 				"x" es menor a "y"
                                    x >  y 				"x" es mayor a "y"
                                    x <= y 				"x" es menor o igual a "y"
									x >= y 				"x" es mayor o igual a "y"
									x == y && y==z		and  "x" es igual a "y" E "y" es igual a "z"
									x == y || y==z		or  "x" es igual a "y" O "y" es igual a "z"

if (!x) { // if x is not true
x = !y;
while

*  Un bucle del tipo while es un bucle de ejecución continua mientras se cumpla la expresión colocada entre paréntesis en la cabecera del bucle.
*  La variable de prueba tendrá que cambiar para salir del bucle.
*  La situación podrá cambiar a expensas de una expresión dentro el código del bucle o también por el cambio de un valor en una entrada de un sensor.

while (unaVariable ?? valor)
{
ejecutarSentencias;
}
*/
int boton = 2;
int demora =  50;
int pin =  0;
int estado;
void setup()
{
  for (pin=8;pin<=13; pin++)
  {
    pinMode(pin,OUTPUT);
  }
  pinMode(boton,INPUT);
  Serial.begin(9600);   //Inicio la comunicación serie a 9600 baudios
}

void loop()
{
  estado = digitalRead(boton);
  while (estado == 1 )
    {
      for (pin=8;pin<=13; pin++)
      {
        digitalWrite (pin,HIGH);
        delay(demora);
        digitalWrite (pin,LOW);
        delay(demora);
      }
      estado = digitalRead(boton);
      Serial.print("Dentro del while  ");
      Serial.println(estado);
    }
  Serial.print("fuera del while  ");
  Serial.println(estado);
}
