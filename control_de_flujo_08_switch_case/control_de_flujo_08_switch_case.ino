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
                                       *  * | [ ]N/C                    SCK/13[0] |--------------------------\
                                       *  * | [ ]IOREF                 MISO/12[0] |-------------------------\|
                                       *  * | [ ]RST                   MOSI/11[0]~|------------------------\||
                                       *  * | [ ]3V3    +---+               10[0]~|-----------------------\|||
                                       0------[0]5v    -| A |-               9[0]~|----------------------\||||
                                       *  * | [ ]GND   -| R |-               8[0] |---------------------\|||||
                                       *  0---[0]GND   -| D |-                    | *  *                ||||||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                ||||||
                                       *  * |          -| I |-               6[ ]~| *  *                ||||||
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[0] |-----------\         ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *      |         ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *      |         ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *      |         ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *      |         ||||||
                                       *  * \________________________/              *  *      |         ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *      |         ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *      |         ||||||
                                       *  *    *  *  *  /-------------------------------------/         ||||||
                                       *  0-ww-0  0  *  0  0--[#]--0  *  *  *  0-ww-0  *  220 Ohms      ||||||
                                          1 kOhms           Boton 1                                     ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
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
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
                                    x == y         "x" es igual a "y"
                                    x != y        "x" NO es igual a "y"
                                    x <  y        "x" es menor a "y"
                                    x >  y        "x" es mayor a "y"
                                    x <= y        "x" es menor o igual a "y"
                  x >= y        "x" es mayor o igual a "y"
                  x == y && y==z    and  "x" es igual a "y" E "y" es igual a "z"
                  x == y || y==z    or  "x" es igual a "y" O "y" es igual a "z"


if (!x) { // if x is not true
x = !y;
switch...case

Like if statements, switch case controls the flow of programs by allowing programmers to specify different code that should be executed in various conditions. In particular, a switch statement compares the value of a variable to the values specified in case statements. When a case statement is found whose value matches that of the variable, the code in that case statement is run.

The break keyword exits the switch statement, and is typically used at the end of each case. Without a break statement, the switch statement will continue executing the following expressions ("falling-through") until a break, or the end of the switch statement is reached.


*/
int boton = 2;
int pin =  0;
int leds[]={8,9,10,11,12,13};
int demora =  250;
int estado =  0;
void setup() {
  for (pin=0;pin<=5; pin++)
  {
    pinMode(leds[pin],OUTPUT);
  }
  pinMode(boton,INPUT);
  Serial.begin(9600);
}
void loop()
{
	digitalWrite (leds[pin],HIGH);
	delay(demora);
	digitalWrite (leds[pin],LOW);
	delay(demora);
	estado = digitalRead(boton);
    if (estado == 1 )
    {
		  pin = pin + 1;
  		if (pin > 5)
  		{
  			pin = 0;
  		}
    }

  	switch (pin)
  	{
  	  case 5:
    		demora = 300;
    		break;
  	  case 4:
  	  	demora = 25;
  		  break;
  	  case 3:
    		demora = 40;
    		break;
  	  case 2:
  		  demora = 200;
  		  break;
  	  case 1:
  		  demora = 10;
  		  break;
  	  case 0:
  	  	demora = 150;
  		  break;
  	  default:
  		  demora = 1000;
    		break;
  	}
  Serial.print("estado : ");
  Serial.println(estado);
  Serial.print("pin    : ");
  Serial.println(pin);
  Serial.print("demora : ");
  Serial.println(demora);

}

