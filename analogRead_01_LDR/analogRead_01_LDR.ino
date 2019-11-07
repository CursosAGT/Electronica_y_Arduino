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
                                       0------[0]5v    -| A |-               9[0]~| -------------------\
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *                |
                                       *  0---[0]GND   -| D |-                    | *  *                |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                |
                                       *  * |          -| I |-               6[ ]~| *  *                |
               -------------------------------[0]A0    -| N |-               5[ ]~| *  *                |
              /                        *  * | [ ]A1    -| O |-               4[ ] | *  *                |
              |                        *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                |
              |                        *  * | [ ]A3                     INT0/2[ ] | *  *                |
              |                        *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                |
              |                        *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                |
              |                        *  * |             [ ] [ ] [ ]             | *  *                |
              |                        *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                |
              |                        *  * \________________________/              *  *                |
              |                                                                                         |
              |                        *  *    *  *  *  *  *       *  *  *  *  *    *  *                |
              |                           220 Ohm            Led 1              /----------------------/   pin 9
              |                        *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *
              |                        *  *    *  *  *  *  *       *  *  *  *  *    *  *
              |                            10 kOhm            LDR
              |                        *  0-ww-0  *  *  0  0--(W)--*  *  *  *  0----0  *
              \-----------------------------------------/    pin A0
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/
int demora =  500;
int led = 9;
int Ingreso_Analogico = A0;
int pin =  0;
int nivel_luz_led = 0;
int Ingreso_Analogico_a_ADC =0; //0 a 1024 conversos Analogico digital de 10 bit
int parametros_salida =0;       // 0 a 5 volt en 8 bits 0 a 255

void setup()
 {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  pinMode(Ingreso_Analogico,INPUT);
}

void loop()
{
  Ingreso_Analogico_a_ADC = analogRead (Ingreso_Analogico);
  nivel_luz_led = 255-(Ingreso_Analogico_a_ADC / 4);// 4 = 1024 / 256
  analogWrite (led,nivel_luz_led);
  Serial.print(" Valor del Ingreso Analogico  : ");
  Serial.println(Ingreso_Analogico_a_ADC);

  Serial.println("--- siguiente toma de datos --- ");

  delay(demora);
}
