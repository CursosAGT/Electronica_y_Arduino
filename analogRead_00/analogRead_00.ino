/*             +  -                 +  -
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
               *  * | [ ]RST                   MOSI/11[ ]~| *  *
               *  * | [ ]3V3    +---+               10[ ]~| *  *
               0------[0]5v    -| A |-               9[0]~|--------------------\
               *  * | [ ]GND   -| R |-               8[ ] | *  *               |
               *  0---[0]GND   -| D |-                    | *  *               |
               *  * | [ ]Vin   -| U |-               7[ ] | *  *               |
               *  * |          -| I |-               6[ ]~| *  *               |
       /------------| [ ]A0    -| N |-               5[ ]~| *  *               |
       |       *  * | [ ]A1    -| O |-               4[ ] | *  *               |
       |       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *               |
       |       *  * | [ ]A3                     INT0/2[ ] | *  *               |
       |       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               |
       |       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               |
       |       *  * |             [ ] [ ] [ ]             | *  *               |
       |       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               |
       |       *  * \________________________/              *  *               |
	   |       *  *    *  *  *  *  *       *  *  *  *  *    *  *			   |
       |           10 kOhm         LDR     *  *  *  *  *    *  *			   |
       |       *  0-ww-0  *  *  0  0--(w)--0  *  *  *  0----0  *			   |
       \-----------------------/pin A0     *  *  *  *  *    *  *			   |
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			   |
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			   |
               *  *    *  *  *  *  *       *  *  *  *  *    *  *			   |
                   220 Ohm         Led                 /----pin 9--------------/
               *  0-ww-0  *  *  * 0--(L)---0  *  *  *  0    *  *
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
               *  0    *  *  *  *  *       *  *  *  *  *    0  *
                   \---------------------------------------/ - GND
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
   pin 5v      0  *    *  *  *  *  *       *  *  *  *  *    *  0
                \---------------------------------------------/   + 5v
*/
int demora =  500;
int ingresos_LDR_a_ADC = 0;
int LDR = A1;


void setup()
 {
  Serial.begin(9600);
  pinMode(LDR,INPUT);
}

void loop()
{
  ingresos_LDR_a_ADC = analogRead (LDR);
  Serial.println(ingresos_LDR_a_ADC);
  delay(demora);
}