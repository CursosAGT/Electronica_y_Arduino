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
                                       *  * | [ ]N/C                    SCK/13[0]-----------------------\
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *                 |
                                       *  * | [ ]RST                   MOSI/11[ ]~| *  *                 |
                                       *  * | [ ]3V3    +---+               10[ ]~| *  *                 |
                                       0------[0]5v    -| A |-               9[ ]~| *  *                 |
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *                 |
                                       *  0---[0]GND   -| D |-                    | *  *                 |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                 |
                                       *  * |          -| I |-               6[ ]~| *  *                 |
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                 |
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                 |
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                 |
                                       *  * | [ ]A3                     INT0/2[0]---------------------\  |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *               | |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *               | |
                                       *  * |             [ ] [ ] [ ]             | *  *               | |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *               | |
                                       *  * \________________________/              *  *               | |
                                                                                                       | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               | |
                                                             BOTON              /---------------------/  | pin 2
                                       *  0----0  *  *  *  0--[X]--0  *  *  *  0    *  *                 |
                                                                                                         |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                                                                                         |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                                                                                         |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                          220 Ohm            Led 1              /-----------------------/  pin 13
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *

                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *

                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v

*/
//El propósito de este ejemplo, es demostrar un efecto que es conocido como “debounce” o “rebote”.

int demora =  500;
int led = 13;
int Ingreso_digital = 2;
int contador = 0;
int Boton_estado;
unsigned long tiempo0 = 0;
unsigned long tiempo1 = 0;
bool primeraVez = false;

void setup() {
	pinMode(led,OUTPUT);
	Serial.begin(9600);
	pinMode(Ingreso_digital,INPUT_PULLUP);  //Declarar el pin 2 como entrada con pull-up
}
void loop()
{
	Boton_estado = digitalRead(Ingreso_digital);
	if(Boton_estado == 0)
	{
		if(!primeraVez)
		{
			primeraVez = true;
			tiempo0 = millis();
			digitalWrite (led,HIGH);
		}
		else
		{
			tiempo1 = millis();
			if((tiempo1-tiempo0)>200)
			{  //Si el tiempo supera los 200ms entonces activamos las instrucciones correspondientes
				primeraVez = false;
				contador++;
				Serial.print("Boton presionado: ");
				Serial.print(contador);
				Serial.println(" veces");
			}
		}
	}
	else
	{
		contador=0;
		Serial.println("Boton no presionado: ");
	}
delay(demora);
}
