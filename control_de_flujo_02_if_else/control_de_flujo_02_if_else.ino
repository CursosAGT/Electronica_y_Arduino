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
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *                ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
                                       *  * \________________________/              *  *                ||||||
                                                                                                        ||||||
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
int pin_unidad = 8;
int pin_1_decena=9;
int pin_2_decena=10;
int pin_3_decena=11;
int pin_4_decena=12;
int pin_5_decena=13;


int unidad=0;
int valor_1_decena=0;

boolean estado = false;
void setup()
{
	pinMode(pin_unidad,OUTPUT);
	pinMode(pin_1_decena,OUTPUT);
	pinMode(pin_2_decena,OUTPUT);
	pinMode(pin_3_decena,OUTPUT);
	pinMode(pin_4_decena,OUTPUT);
	pinMode(pin_5_decena,OUTPUT);
	Serial.begin(9600);
}

void loop()
{
unidad ++;
digitalWrite(pin_unidad,estado);
delay(demora);
//estado = digitalRead(pin_unidad);
digitalWrite(pin_unidad,!estado);
delay(demora);

  if (unidad<10)
	{
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
	}
  else if (unidad>=10 && unidad < 20)
	{
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
	}
  else if (unidad>=20 && unidad < 30)
  {
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
  }
  else if (unidad>=30 && unidad < 40)
  {
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
  }
  else if (unidad>=40 && unidad < 50)
  {
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,LOW);
  }
  else if (unidad>=50 && unidad < 60)
  {
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,HIGH);
  }
  else if (unidad>=60 && unidad < 70)
  {
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,HIGH);
  }
  else if (unidad>=70 && unidad < 80)
  {
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,HIGH);
  }
  else if (unidad>=80 && unidad < 90)
  {
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,HIGH);
  }
  else if (unidad>=90 && unidad < 100)
  {
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,HIGH);
  }
  else if (unidad>=100 && unidad < 100)
  {
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,HIGH);
  }
  else
  {
    digitalWrite(pin_unidad,HIGH);
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,HIGH);
		delay(demora*10);
    digitalWrite(pin_unidad,LOW);
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
		delay(demora*10);
    digitalWrite(pin_unidad,HIGH);
		digitalWrite(pin_1_decena,HIGH);
		digitalWrite(pin_2_decena,HIGH);
		digitalWrite(pin_3_decena,HIGH);
		digitalWrite(pin_4_decena,HIGH);
		digitalWrite(pin_5_decena,HIGH);
		delay(demora*10);
    digitalWrite(pin_unidad,LOW);
		digitalWrite(pin_1_decena,LOW);
		digitalWrite(pin_2_decena,LOW);
		digitalWrite(pin_3_decena,LOW);
		digitalWrite(pin_4_decena,LOW);
		digitalWrite(pin_5_decena,LOW);
		delay(demora*10);
		unidad =0;
  }
  Serial.print("Unidad: ");
  Serial.println(unidad);
  Serial.println(estado);

}
