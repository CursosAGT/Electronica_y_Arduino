/*                                     +  -                                        +  -
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *      *  *  +-----+    *  *
                                       *  * +----[PWR]------------------| USB |--+ *  *
                                       *  * |                           +-----+  | *  *
                                       *  * |         GND/RST2 [ ][ ]            | *  *
                                       *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *
                                       *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *
                                       *  * |                            AREF[ ] | *  *
                                       *  * |                             GND[ ] | *  *
                                       *  * | [ ]N/C                   SCK/13[ ] | *  *
                                       *  * | [ ]IOREF                MISO/12[ ] | *  *
                                       *  * | [ ]RST                  MOSI/11[ ]~| *  *
                                       *  * | [ ]3V3    +---+              10[ ]~| *  *
                                       0------[0]5v    -| A |-              9[ ]~| *  *
                                       *  * | [ ]GND   -| R |-              8[ ] | *  *
                                       *  0---[0]GND   -| D |-                   | *  *
                                       *  * | [ ]Vin   -| U |-              7[ ] | *  *
                                       *  * |          -| I |-              6[ ]~| *  *
                                       *  * | [ ]A0    -| N |-              5[ ]~| *  *
                                       *  * | [ ]A1    -| O |-              4[0]-----------------\
                                       *  * | [ ]A2     +---+          INT1/3[ ]~| *  *           |
                                       *  * | [ ]A3                    INT0/2[ ] | *  *           |
                                       *  * | [ ]A4/SDA  RST SCK MISO    TX>1[ ] | *  *           |
                                       *  * | [ ]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *           |
                                       *  * |            [ ] [ ] [ ]             | *  *           |
                                       *  * |  UNO_R3    GND MOSI 5V ____________/ *  *           |
                                       *  * \______________________/               *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
 _______________      /-------GND--------\     *  *  *  *  *      *  *  *  *  *    *  *           |
 |   º º     º |-----/                 *  0    *  *  *  *  *      *  *  *  *  *    *  *           |
 | º º º º º º |-----No conectar               *  *  *  *  *      *  *  *  *  *    *  *           |
 | º º º º º º |-----\                 *  *    *  *  *  *  *  +---0----/-------------------------/    Pul up pin 4
 | º º º º º º |---\  \--------I/O--Data---------------------/        /
 |___º_º_____º_|    \----5v-VCC--------0  *    0  *  *  *  0--www-0  0  *  *  *    *  *
                                        \-----/              30 ohm a 5 KOhm
                                       *  0    *  *  *  *  *      *  *  *  *  *    *  *
                       pin GND-----------/     *  *  *  *  *      *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *      *  *  *  *  *    *  0
                                          \------------------------------------------/ - GND
                                       0  *    *  *  *  *  *      *  *  *  *  *    *  *
                       pin 5v- -------/   *    *  *  *  *  *      *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *      *  *  *  *  *    0  *
                                        \-----------------------------------------/   + 5v

*-*-*-*-***-*-*-*-*-*-*-*-*-*-*-*-*-*-*	DHT11    O  DHT22	*-*-*-*-***-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 _______________
 |   º º     º |-----GND
 | º º º º º º |-----No conectar
 | º º º º º º |-----Data I/O
 | º º º º º º |-----3,5v a 5v VCC
 |___º_º_____º_|
______________________
| _______________    |
| |   º º     º |--	 |
| | º º º º º º |--	 |____	GND
| | º º º º º º |--	 |____	3,5v a 5v VCC
| | º º º º º º |--	 |____	Data I/O
| |___º_º_____º_|    |
|____________________|
*-*-*-*-***-*-*-*-*-*-*-*-*-*-*-*-*-*-*	DHT11    O  DHT22	*-*-*-*-***-*-*-*-*-*-*-*-*-*-*-*-*-*-*
    La resistencia pull-up de 5 kΩ es la recomendada para un cable de longitud de hasta 20 metros. Si conectas un cable mayor al DHT11, la resistencia pull-up deberá ser proporcional.
    Ojo si alimentas el DHT11 con 3,5 V. En este caso, el cable de alimentación no debe ser mayor de 20 cm debido a que las caídas de tensión pueden provocar mal funcionamiento.
    Se recomienda tomar medidas cada 5 segundos. Si se utiliza un periodo menor puede ocasionar que los datos no sean precisos.
 //http://beetlecraft.blogspot.com/2016/06/tutorial-dht11-sensor-de-temperatura-y.html


 Temperatura
             Rango       de 0ºC a 50ºC
             Precisión       a 25ºC ± 2ºC
             Resolución       1ºC (8-bit)
 Humedad
             Rango           de 20% RH a 90% RH
 Precisión
             Rango           de 0ºC y 50ºC ± 5% RH
             Resolución       1% RH

       0011 0101  +   0000 0000   +   0001 1000    +   0000 0000    =   0100 1101
    8-bit Humedad + 8-bit Humedad + 8-bit Temperat + 8-bit Temperat = 8-bit Paridad

    La resistencia pull-up de 5 kΩ es la recomendada para un cable de longitud de hasta 20 metros. Si conectas un cable mayor al DHT11, la resistencia pull-up deberá ser proporcional.
    Ojo si alimentas el DHT11 con 3,5 V. En este caso, el cable de alimentación no debe ser mayor de 20 cm debido a que las caídas de tensión pueden provocar mal funcionamiento.
    Se recomienda tomar medidas cada 5 segundos. Si se utiliza un periodo menor puede ocasionar que los datos no sean precisos.
*/

#include <DHT11.h>

int pin=4;
DHT11 dht11(pin);
int Error;
float temperatura, humedad;
void setup()
{
  Serial.begin(9600);
  while (!Serial) {}; // Espera por coneccion serial en Leonardo (only).
}
void loop()
{
  if((Error=dht11.read(humedad, temperatura))==0)
  {
    Serial.println("Hoy hay una temperarura de :" + String(temperatura) + " grados centigrados.") ;
    Serial.println("Con :"+ String(humedad) + "% de humedad relativa.") ;
  }
  else
  {
    Serial.println("Error No :"+ String(Error) + " (buscar en libreria DHT11.") ;
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}
