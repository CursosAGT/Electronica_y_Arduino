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
void setup()
{
	pinMode(led,OUTPUT);
	Serial.begin(9600);
	pinMode(Ingreso_digital,INPUT);
}
void loop()
{
	Boton_estado = digitalRead(Ingreso_digital);
	if(Boton_estado == 0)
	{
		contador++;
		Serial.print("Boton presionado: ");
		Serial.print(contador);
		Serial.println(" veces");
	}
	else
	{
		contador=0;
		Serial.print("Boton aun no presionado: ");
	}
delay(demora);
}
/*
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
*/
