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
                                                                                                  |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                                                                                  |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
                                                                                                  |
                                       *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
 _______________      /-------GND--------\                                                        |
 |   º º     º |-----/                 *  0    *  *  *  *  *      *  *  *  *  *    *  *           |
 | º º º º º º |-----No conectar                                                                  |
 | º º º º º º |-----\                 *  *    *  *  *  *  *      *  *  *  *  *    *  *           |
 | º º º º º º |---\  \--------I/O--Data-------------------------\   /---------------------------/     pin 4
 |___º_º_____º_|    \----5v-VCC--------0  *    0  *  *  *  0--www-0  0  *  *  0    *  *
                                        \-----/              30 ohm a 5 KOhm
                                       *  0    *  *  *  *  *      *  *  *  *  *    *  *
                       pin GND-----------/
                                       *  0    *  *  *  *  *      *  *  *  *  *    *  0
                                          \------------------------------------------/ - GND
                                       0  *    *  *  *  *  *      *  *  *  *  *    *  *
                       pin 5v- -------/
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
//https://programarfacil.com/blog/arduino-blog/sensor-dht11-temperatura-humedad-arduino/
// Modificado por Regata para www.tallerarduino.wordpress.com

#include "DHT.h"  								//Añadimos la libreria con la cual trabaja nuestro sensor
#define DHTPIN 4     							// Indicamos el pin donde conectaremos la patilla data de nuestro sensor

#define DHTTYPE DHT11                           // DHT 11
//#define DHTTYPE DHT22                         // DHT 22  (AM2302)
//#define DHTTYPE DHT21                         // DHT 21 (AM2301)
int humedad = 0;
int temperatura  = 0;

DHT dht(DHTPIN, DHTTYPE);                       //Indica el pin con el que trabajamos y el tipo de sensor
int maxh=0, minh=100, maxt=0, mint=100;         //Variables para ir comprobando maximos y minimos

void setup()
{
  Serial.begin(9600);
  dht.begin();                                  //Iniciamos el sensor
}

void loop()
{
  humedad = dht.readHumidity();                 //lectura de la humedad en la variable float h
  temperatura = dht.readTemperature();              //lectura de la temperatura en la variable float t

  // Comprobamos si lo que devuelve el sensor es valido, si no son numeros algo esta fallando
  if (isnan(temperatura) || isnan(humedad)) // funcion que comprueba si son numeros las variables indicadas
  {
    Serial.println("Error sensor DHT"); //Mostramos mensaje de fallo si no son numeros
  }
  else
  {
    //Mostramos mensaje con valores actuales de humedad y temperatura, asi como maximos y minimos de cada uno de ellos


  }

  delay(2000);
    //Comprobacion de maximos y minimos de humedad y temperatura
    if (maxh<humedad)
    {
      maxh=humedad;
    }
    if (humedad<minh)

    {
      minh=humedad;
    }
    if (maxt<temperatura)
    {
      maxt=temperatura;
    }
    if (temperatura<mint)
    {
      mint=temperatura;
    }
    Serial.println("--------------------------------------------------------------------------------------");
    Serial.println("Hoy hay una temperarura de :" + String(temperatura) + "º Celsius - Temperarura Maxima :" + String(maxt) + "  T.Minima :" + String(mint) + "º Celsius-");
    Serial.println("Con una humedad de :" + String(humedad) + "% relativa.       - Humedad Maxima     :" + String(maxh) + "  H.Minima :" + String(minh) + " % \n") ;

  delay(1000);
}
