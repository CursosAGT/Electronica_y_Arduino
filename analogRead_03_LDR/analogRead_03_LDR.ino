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
               *  0    *  *  *  *  *       *  *  *  *  *    0  *
                   \---------------------------------------/ - GND
               *  *    *  *  *  *  *       *  *  *  *  *    *  *
   pin 5v      0  *    *  *  *  *  *       *  *  *  *  *    *  0
                \---------------------------------------------/   + 5v
*/
int demora =  200;
int LDR = A0;
int pin =  0;
int cantidad_led = 0;
int parametros_salida =0;     //0 a 5 volt en 8 bits 0 a 255
int pinLed1 = 9; 	            //Declara Pin LED
int pinLed2 = 10; 	          //Declara Pin LED
int pinLed3 = 11; 	          //Declara Pin LED
int ingresos_LDR_a_ADC =0;    //0 a 1024 conversos Analogico digital de 10 bit

void setup()
{
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  Serial.begin(9600);         //Configurar el puerto serial
  pinMode(LDR, INPUT);
}

void loop()
{
  // Apagar todos los leds siempre que se inicia el ciclo
	digitalWrite(pinLed1, LOW);
	digitalWrite(pinLed2, LOW);
	digitalWrite(pinLed3, LOW);

	ingresos_LDR_a_ADC= analogRead(LDR);	// Guardamos el valor leido del ADC en una variable El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional con respecto a la luz percibida por el LDR
	Serial.print(" Valor del LDR  : ");
	Serial.println(ingresos_LDR_a_ADC);   // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino

  if(ingresos_LDR_a_ADC <= 400)  		    // Encender los leds apropiados de acuerdo al valor de ADC
  {
	  digitalWrite(pinLed1, HIGH);
	  delay(demora);
	  digitalWrite(pinLed1, LOW);
  }
  else if(ingresos_LDR_a_ADC > 400)
  {
		digitalWrite(pinLed1, HIGH);
  }
  if (ingresos_LDR_a_ADC > 600)
  {
		digitalWrite(pinLed2, HIGH);
  }
  if (ingresos_LDR_a_ADC > 800)
  {
		digitalWrite(pinLed3, HIGH);
  }
  delay(demora);  // Esperar unos milisegundos antes de actualizar
}
/////////////////////////////////////////////
