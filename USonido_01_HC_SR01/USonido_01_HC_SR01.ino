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
                                       *  * | [ ]N/C                    SCK/13[0] |-------------------------\
                                       *  * | [ ]IOREF                 MISO/12[0] |------------------------\ |
                                       *  * | [ ]RST                   MOSI/11[0]~|-----------------------\|||
                                       *  * | [ ]3V3    +---+               10[0]~|----------------------\||||
                                       0------[0]5v    -| A |-               9[0]~|---------------------\|||||
                                       *  * | [ ]GND   -| R |-               8[0] |--------------------\||||||
                                       *  0---[0]GND   -| D |-                    | *  *                ||||||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                ||||||
                                       *  * |          -| I |-               6[ ]~| *  *                ||||||
                /                      *  * | [0]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *                ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
                                       *  * \________________________/              *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                       ________        *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                      |  ___  |        *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                      | // \\ |            GND *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                      | \\_// |-----------0    *  *  *  *  *       *  *  *  *  *    *  *                /|||||
                      |       |--------------Echo------------------------------------------------------/ |||||          Pin 2 Echo
                      |  ___  |--------------Echo-------------------------------------------------------/ ||||          Pin 3 Trig
                      | // \\ |--------0 5 Vcc *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                      | \\_// |        *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                      |̣̣_______|        *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
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
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v

 _________
 |  ___  |
 | /   \ |
 | \___/ |----GRD---->
 |       |----Echo--->--pin 2
 |  ___  |----Trig--->--pin 3
 | /   \ |----5v-Vcc->
 | \___/ |
 |̣̣_______|

*/
#define echoPin 2
#define trigPin 3
//#define led 2
int demora =  500;
int pin_led_1 = 13;
int pin_led_2 = 12;
int pin_led_3 = 11;
int pin_led_4 = 10;
  int Limite_min = 50 ;                   // Medida en vacío del sensor
  int Limite_max = 150 ;
void setup()
{
  pinMode(pin_led_1, OUTPUT);
  pinMode(pin_led_2, OUTPUT);
  pinMode(pin_led_3, OUTPUT);
  pinMode(pin_led_4, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop()
{
  digitalWrite ( pin_led_1 , HIGH) ;
  long duracion, distancia ;
	digitalWrite(trigPin, LOW);           	// Nos aseguramos de que el trigger está desactivado
	delayMicroseconds(2);                 	// Para asegurarnos de que el trigger esta LOW
	digitalWrite(trigPin, HIGH);          	// Activamos el pulso de salida
	delayMicroseconds(10);                	// Esperamos 10µs. El pulso sigue active este tiempo
	digitalWrite(trigPin, LOW);           	// Cortamos el pulso y a esperar el echo
	duracion = pulseIn(echoPin, HIGH) ;
	distancia = duracion / 2 / 29.1  ;
//	Serial.println(String(distancia) + " cm.") ;
	if ( distancia < Limite_min)
	{
		 digitalWrite ( pin_led_2 , HIGH) ;
		 digitalWrite ( pin_led_3 , LOW) ;
		 digitalWrite ( pin_led_4 , LOW) ;
     Serial.println(String(distancia) + " menor al limite minimo de 50 cm.") ;
	}
	else if ( distancia >= Limite_min && distancia < Limite_max)
	{
		 digitalWrite ( pin_led_2 , LOW) ;
		 digitalWrite ( pin_led_3 , HIGH) ;
		 digitalWrite ( pin_led_4 , LOW) ;
     Serial.println(String(distancia) + " mayor igual al limite minimo de 50 cm y menor al limite maximo de 150 cm.") ;
	}
	else if ( distancia > Limite_max)
	{
		 digitalWrite ( pin_led_2 , LOW) ;
		 digitalWrite ( pin_led_3 , LOW) ;
		 digitalWrite ( pin_led_4 , HIGH) ;
     Serial.println(String(distancia) + " mayor al limite maximo de 150 cm.") ;
  }
	delay (demora);
}
