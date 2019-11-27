/*             +  -                                         +  -
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  *    *  *  *  *  *       *  *  +-----+    *  *
               *  * +----[PWR]-------------------| USB |--+ *  *
               *  * |                            +-----+  | *  *
               *  * |         GND/RST2  [ ][ ]            | *  *
               *  * |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] | *  *
               *  * |          5V/MISO2 [ ][ ]  A4/SDA[ ] | *  *
               *  * |                             AREF[ ] | *  *
               *  * |                              GND[ ] | *  *
               *  * | [ ]N/C                    SCK/13[0] |------------------------\
               *  * | [ ]IOREF                 MISO/12[0] |-----------------------\|
               *  * | [ ]RST                   MOSI/11[0]~|----------------------\||
               *  * | [ ]3V3    +---+               10[0]~|---------------------\|||
               0------[0]5v    -| A |-               9[0]~|--------------------\||||
               *  * | [ ]GND   -| R |-               8[0] |-------------------\|||||
               *  0---[0]GND   -| D |-                    | *  *              ||||||
               *  * | [ ]Vin   -| U |-               7[ ] | *  *              ||||||
               *  * |          -| I |-               6[ ]~| *  *              ||||||
       /------------| [ ]A0    -| N |-               5[ ]~| *  *              ||||||
       |       *  * | [ ]A1    -| O |-               4[ ] | *  *              ||||||
       |       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *              ||||||
       |       *  * | [ ]A3                     INT0/2[ ] | *  *              ||||||
       |       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *              ||||||
       |       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *              ||||||
       |       *  * |             [ ] [ ] [ ]             | *  *              ||||||
       |       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *              ||||||
       |       *  * \________________________/              *  *              ||||||
	   |       *  *    *  *  *  *  *       *  *  *  *  *    *  *			  ||||||
       |           10 kOhm         LDR     *  *  *  *  *    *  *			  ||||||
       |       *  0-ww-0  *  *  0  0--(w)--0  *  *  *  0----0  *			  ||||||
       \-----------------------/pin A0     *  *  *  *  *    *  *			  ||||||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			  ||||||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			  ||||||
                   220 Ohm         Led                 /----pin 8-------------/|||||
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *			   |||||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			   |||||
                   220 Ohm         Led                 /----pin 9--------------/||||
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *			    ||||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			    ||||
                   220 Ohm         Led                 /----pin 10--------------/|||
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *			     |||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			     |||
                   220 Ohm         Led                 /----pin 11---------------/||
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *			      ||
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			      ||
                   220 Ohm         Led                 /----pin 12----------------/|
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *			       |
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			       |
                   220 Ohm         Led                 /----pin 13-----------------/
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  0    *  *  *  *  *       *  *  *  *  *    *  0
                   \-------------------------------------------/ - GND
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
   pin 5v      0  *    *  *  *  *  *       *  *  *  *  *    0  *
                \------------------------------------------/+ 5v
*/
int demora =  500;
int led[] = {8,9,10,11,12,13};
int LDR = A1;
int pin =  0;
int cantidad_led = 0;
int ingresos_LDR_a_ADC =0; //0 a 1024 conversos Analogico digital de 10 bit
int parametros_salida =0; //                  0 a 5 volt en 8 bits 0 a 255

void setup()
 {
  for (pin=0;pin<=5; pin++)
  {
    pinMode(led[pin],OUTPUT);
  }
  Serial.begin(9600);
  pinMode(LDR,INPUT);
}

void loop()
{
  ingresos_LDR_a_ADC = analogRead (LDR);
  //                  tengo 6 leds por lo que el valor de 1024 en 6  = 170.66
  cantidad_led = ingresos_LDR_a_ADC / 171;
  for (pin=0;pin<=5; pin++)
  {
    digitalWrite (led[pin],LOW);
  }


  for (pin=0;pin<=cantidad_led; pin++)
  {
    digitalWrite (led[pin],HIGH);
  }
    Serial.print(" Valor del LDR  : ");
    Serial.println(ingresos_LDR_a_ADC);
    Serial.print(" cantidad leds encendidos  : ");
    Serial.println(cantidad_led);
    Serial.print(" lugar de array  : ");
    Serial.println(pin);
    Serial.print(" pin del board  : ");
    Serial.println(led[pin]);
    Serial.println("--- siguiente toma de datos --- ");

  delay(demora);
}
