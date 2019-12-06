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

// Incluimos librería
#include <DHT.h>

// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 4
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11

// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);

  // Comenzamos el sensor DHT
  dht.begin();
}
void loop()
{
    // Esperamos 5 segundos entre medidas
  delay(5000);

  // Leemos la humedad relativa
  float humedad = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float temperatura = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  float Fahrenheit = dht.readTemperature(true);

  // Comprobamos si ha habido algún error en la lectura
  if (isnan(humedad) || isnan(temperatura) || isnan(Fahrenheit))
  {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  float indice_calor_f = dht.computeHeatIndex(Fahrenheit, humedad);              // Calcular el índice de calor en Fahrenheit
  float indice_calor_c = dht.computeHeatIndex(temperatura, humedad, false);      // Calcular el índice de calor en grados centígrados
  Serial.println("--------------------------------------------------------------------------------------");
  Serial.println("Hoy hay una temperarura de :" + String(temperatura) + "º Celsius-" + String(Fahrenheit) + "º Fahrenheit.");
  Serial.println("Con :"+ String(humedad) + "% de humedad relativa.") ;
  Serial.println("Indice de calor: "+ String(indice_calor_c)+"º Celsius-: "+ String(indice_calor_f)+ "º Fahrenheit.");
  delay(2000);                                                                  // Intervalo para nueva medicion
}R
