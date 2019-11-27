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
              +-------------------------------[0]A0    -| N |-               5[ ]~| *  *                ||||||
              |                        *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
              |                        *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
              |                        *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
              |                        *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
              |                        *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
              |                        *  * |             [ ] [ ] [ ]             | *  *                ||||||
              |                        *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
              |                        *  * \________________________/              *  *                ||||||
              |                        *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
              |                        *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
              |                         330 /  10 kOhm            LDR                                   ||||||
              |                        *  0-ww-0  *  *  0  0--(W)--*  *  *  *  0----0  *                ||||||
              +-----------------------------------------/    pin A0                                     ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8 	unidad
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                                                                                         |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9	1ª Decena
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                                                                                                          ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                                          220 Ohm            Led 3              /------------------------/ ||| pin 10	2ª Decena
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                                                                                                           |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                          220 Ohm            Led 4              /-------------------------/ || pin 11	3ª Decena
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                                                                                                            ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                          220 Ohm            Led 5              /--------------------------/ | pin 12	4ª Decena
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                                                                                                             |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                          220 Ohm            Led 6              /---------------------------/  pin 13	5ª Decena
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *


                                    x == y 				"x" es igual a "y"
                                    x != y 				"x" NO es igual a "y"
                                    x <  y 				"x" es menor a "y"
                                    x >  y 				"x" es mayor a "y"
                                    x <= y 				"x" es menor o igual a "y"
									x >= y 				"x" es mayor o igual a "y"
									x == y && y==z		and  "x" es igual a "y" E "y" es igual a "z"
									x == y &= y==z		and_eq
									x == y &  y==z		bitand
									x == y |  y==z		bitor
									x == y !  y==z		not
									x == y != y==z		not_eq
									x == y || y==z		or  "x" es igual a "y" O "y" es igual a "z"
									x == y |= y==z		or_eq
									x == y ^  y==z		xor
									x == y ^= y==z		xor_eq

https://playground.arduino.cc/ArduinoNotebookTraduccion/Flowcontrol/
*/


int demora =  25;
int pin_ok = 8;
int pin_1=9;
int pin_2=10;
int pin_3=11;
int pin_4=12;
int pin_5=13;
const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 600;    // sensor maximum, discovered through experiment

int unidad=0;
int valor_1=0;

boolean estado = false;
void setup()
{

	pinMode(pin_ok,OUTPUT);
	pinMode(pin_1,OUTPUT);
	pinMode(pin_2,OUTPUT);
	pinMode(pin_3,OUTPUT);
	pinMode(pin_4,OUTPUT);
	pinMode(pin_5,OUTPUT);
	Serial.begin(9600);
}

void loop()
{
  unidad ++;
  digitalWrite(pin_ok,estado);
  delay(demora);
  //estado = digitalRead(pin_ok);
  digitalWrite(pin_ok,!estado);
  delay(demora);
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);  // map the sensor range to a range of four options:

  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("oscuridad");
      digitalWrite(pin_1,HIGH);
      digitalWrite(pin_2,LOW);
      digitalWrite(pin_3,LOW);
      digitalWrite(pin_4,LOW);
      digitalWrite(pin_5,LOW);
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("penumbra");
      digitalWrite(pin_1,LOW);
      digitalWrite(pin_2,HIGH);
      digitalWrite(pin_3,LOW);
      digitalWrite(pin_4,LOW);
      digitalWrite(pin_5,LOW);
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("luz media");
      digitalWrite(pin_1,LOW);
      digitalWrite(pin_2,LOW);
      digitalWrite(pin_3,HIGH);
      digitalWrite(pin_4,LOW);
      digitalWrite(pin_5,LOW);
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("luminoso");
      digitalWrite(pin_1,LOW);
      digitalWrite(pin_2,LOW);
      digitalWrite(pin_3,LOW);
      digitalWrite(pin_4,HIGH);
      digitalWrite(pin_5,LOW);
      break;
  }
  delay(demora);        // delay in between reads for stability

}
