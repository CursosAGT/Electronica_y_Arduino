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
*/ //http://beetlecraft.blogspot.com/2016/06/tutorial-dht11-sensor-de-temperatura-y.html

#include "DHT.h" // Libreria DHT de Adafruit
DHT sensor(4, DHT11); // Configruacion de la libreria para usar en el pin 2 el sensor DHT11

void setup() {
  sensor.begin();     // Inicializacion de la libreria DHT
  Serial.begin(9600); // Comunicacion serial a 9600 bps
}

void loop() {
  float humedad = sensor.readHumidity();        // Lectura de la humedad en porcentaje
  float temperatura = sensor.readTemperature(); // Lectura de la temperatura en grados Celsius

  if (isnan(humedad) || isnan(temperatura)) // Determina si los valores son ilegales
  {
    Serial.println("Error de medicion");
    return;
  }

  // Calculo del indice de calor usando la temperatura y humedad leidos
  float indice_calor = sensor.computeHeatIndex(temperatura, humedad, false);
  Serial.println("--------------------------------------------------------------------------------------");
  Serial.println("Hoy hay una temperarura de :" + String(temperatura, 1) + " grados centigrados.");
  Serial.println("Con :"+ String(humedad, 1) + "% de humedad relativa.") ;
  Serial.println("Indice de calor: "+ String(indice_calor));
  delay(2000); // Intervalo para nueva medicion
}
