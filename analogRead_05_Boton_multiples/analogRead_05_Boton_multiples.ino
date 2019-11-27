/*                 + -                               + -

 *
        Analog pin 5
            |
Ground--1K--|--------|--------|-------|-------|
            |        |        |       |       |
           btn1     btn2     btn3    btn4    btn5
            |        |        |       |       |
         220 Ohm  390 Ohm  680 Ohm   2.2K    4.7K
            |--------|--------|-------|-------|-- +5V

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
                /---------------------------| [0]A0    -| N |-               5[ ]~| *  *                ||||||
                |                      *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                |                      *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                |                      *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
                |                      *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
                |                      *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
                |                      *  * |             [ ] [ ] [ ]             | *  *                ||||||
                |                      *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
                |                      *  * \________________________/              *  *                ||||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                |                         220 Ohm            Led 1              /----------------------/ ||||| pin 8
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                |                         220 Ohm            Led 2              /-----------------------/ |||| pin 9
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                |                         220 Ohm            Led 3              /------------------------/ ||| pin 10
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                |                         220 Ohm            Led 4              /-------------------------/ || pin 11
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                |                         220 Ohm            Led 5              /--------------------------/ | pin 12
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                |                         220 Ohm            Led 6              /---------------------------/  pin 13
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |                         1 kOhms           Boton 1
                |                      *  0-ww-0  0  *  0  0--[#]--0  *  *  *  0----0  *
                \--------------------------------/      |                                                    pin A0
                     PULL              *  *    *  *  *  |  *       *  *  *  *  *    *  *
                     DOWN                 1 kOhms       |   Boton 2
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0----0  *
                                                     |
                                       *  *    *  *  |  *  *       *  *  *  *  *    *  *
                                          1 kOhms    |      Boton 3
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0----0  *
                                                        |
                                       *  *    *  *  *  |  *       *  *  *  *  *    *  *
                                          1 kOhms       |   Boton 4
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0----0  *
                                                     |
                                       *  *    *  *  |  *  *       *  *  *  *  *    *  *
                                          1 kOhms    |      Boton 5
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0----0  *
                                                        |
                                       *  *    *  *  *  |  *       *  *  *  *  *    *  *
                                          1 kOhms       |   Boton 6
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0----0  *
									   *  0    *  *  *  *  *       *  *  *  *  *    *  0
										   \-------------------------------------------/ - GND
									   *  *    *  *  *  *  *       *  *  *  *  *    *  *
						   pin 5v      0  *    *  *  *  *  *       *  *  *  *  *    0  *
										\------------------------------------------/+ 5v

*/

int demora =  500;
int leds[]={8,9,10,11,12,13};
int pin =  0;
int Ingreso_Analogico = A0
void setup()
{
  for (pin=0;pin<=5; pin++)
  {
    pinMode(leds[pin],OUTPUT);
  }
  Serial.begin(9600);
  pinMode(Ingreso_Analogico,INPUT);
}

void loop()
{
	int Ingreso_Analogico = analogRead(A0);
	Serial.printf("Ingreso Analogico", Ingreso_Analogico);
	if (Ingreso_Analogico > 100)
	{
		if (Ingreso_Analogico > 700 && Ingreso_Analogico < 750)//        <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 1");
			Serial.println(leds[0]);
		}
		else if (Ingreso_Analogico > 600 && Ingreso_Analogico < 650)//   <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 2");
			Serial.println(leds[1]);
		}
		else if (Ingreso_Analogico > 500 && Ingreso_Analogico < 550)//   <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 3");
			Serial.println(leds[2]);
		}
		else if (Ingreso_Analogico > 400 && Ingreso_Analogico < 450)//   <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 3");
			Serial.println(leds[3]);
		}
		else if (Ingreso_Analogico > 300 && Ingreso_Analogico < 350)//   <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 3");
			Serial.println(leds[4]);
		}
		else if (Ingreso_Analogico > 200 && Ingreso_Analogico < 250)//   <-------------------      Reemplazar este valor por el que resulte de la muestra
		{
			Serial.println("Selecciono el boton 4");
			Serial.println(leds[5]);
		}
	delay(demora);
	}
}
