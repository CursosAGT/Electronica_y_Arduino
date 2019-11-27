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
                |                                                                                       ||||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                |                         220 Ohm            Led 1              /----------------------/ ||||| pin 8
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                |                                                                                        |||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                |                         220 Ohm            Led 2              /-----------------------/ |||| pin 9
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                |                                                                                         ||||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                |                         220 Ohm            Led 3              /------------------------/ ||| pin 10
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                |                                                                                          |||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                |                         220 Ohm            Led 4              /-------------------------/ || pin 11
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                |                                                                                           ||
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                |                         220 Ohm            Led 5              /--------------------------/ | pin 12
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                |                                                                                            |
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                |                         220 Ohm            Led 6              /---------------------------/  pin 13
                |                      *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                |
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |
                |                      *  *    *  *  *  *  *       *  *  *  *  *    *  *
                |                         1 kOhms           Boton 1
                |                      *  0-ww-0  0  *  0  0--[#]--0  *  *  *  0-ww-0  *  220 Ohms
                \--------------------------------/      |                                                     pin A0
                     PULL              *  *    *  *  *  |  *       *  *  *  *  *    *  *
                     DOWN                 1 kOhms       |   Boton 2
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0-ww-0  *  390 Ohms
                                                     |
                                       *  *    *  *  |  *  *       *  *  *  *  *    *  *
                                          1 kOhms    |      Boton 3
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0-ww-0  *  680 Ohms
                                                        |
                                       *  *    *  *  *  |  *       *  *  *  *  *    *  *
                                          1 kOhms       |   Boton 4
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0-ww-0  *  2k2 Ohms
                                                     |
                                       *  *    *  *  |  *  *       *  *  *  *  *    *  *
                                          1 kOhms    |      Boton 5
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0-ww-0  *  4k7 Ohms
                                                        |
                                       *  *    *  *  *  |  *       *  *  *  *  *    *  *
                                          1 kOhms       |   Boton 6
                                       *  0-ww-0  *  0  0  0--[#]--0  *  *  *  0-ww-0  *  6k2 Ohms

									   *  0    *  *  *  *  *       *  *  *  *  *    *  0
										   \-------------------------------------------/ - GND
									   *  *    *  *  *  *  *       *  *  *  *  *    *  *
						   pin 5v      0  *    *  *  *  *  *       *  *  *  *  *    0  *
										\------------------------------------------/+ 5v


AnalogButton_Combos
Version 0.1

Connection more then one button to a single analog pin. Utilizing
software debounce to prevent registering multiple button press
while allow for 2 button combos to be registered.

The Circuit:
 Most other analog buttons circuits call for the resistors to be
 lined up in series from ground. The analog pin and each button
 connect off one of the resistors. My cuicuit requires that the
 resistors tie in from +5 to the buttons. The buttons all connect
 to the analog pin which is tied to ground threw a 1k resistor as
 seen in the diagram below.

        Analog pin 0
           |
Ground--1K--|--------|--------|-------|-------|-------|
            |        |        |       |       |       |
          btn1     btn2     btn3    btn4    btn5    btn6
            |        |        |       |       |       |
        220 Ohm  390 Ohm  680 Ohm   2.2K    4.7K     6k2
            |--------|--------|-------|-------|-- ----|+5V

Created By: Michael Pilcher
February 24, 2010

*/
int j = 1; // integer used in scanning the array designating column number
//2-dimensional array for asigning the buttons and there high and low values
int Button[21][3] = {{1, 837, 838},	// button 1	//   			 <-------------------      Reemplazar este valor por el que resulte de la muestra 1
                    {2, 737, 738},	// button 2	//   			 <-------------------      Reemplazar este valor por el que resulte de la muestra 2
                    {3, 610, 611},	// button 3	//   			 <-------------------      Reemplazar este valor por el que resulte de la muestra 3
                    {4, 318, 319},	// button 4	//   			 <-------------------      Reemplazar este valor por el que resulte de la muestra 4
                    {5, 178, 179},	// button 5	//   			 <-------------------      Reemplazar este valor por el que resulte de la muestra 5
                    {6, 91, 92}, 	// button 6	//				 <-------------------      Reemplazar este valor por el que resulte de la muestra 6
                    {7, 896, 897},	// button 1 + button 2	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 7
                    {8, 877, 878},	// button 1 + button 3	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 8
                    {9, 851, 852},	// button 1 + button 4	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 9
                    {10, 844, 845},	// button 1 + button 5	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 10
                    {11, 840, 841},	// button 1 + button 6	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 11
                    {12, 821, 822},	// button 2 + button 3	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 12
                    {13, 769, 770},	// button 2 + button 4	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 13
                    {14, 753, 754},	// button 2 + button 5	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 14
                    {15, 745, 746},	// button 2 + button 6	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 15
                    {16, 674, 675},	// button 3 + button 4	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 16
                    {17, 643, 644},	// button 3 + button 5	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 17
                    {18, 627, 627},	// button 3 + button 6	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 18
                    {19, 408, 409},	// button 4 + button 5	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 19
                    {20, 363, 364},	// button 4 + button 6	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 20
                    {21, 243, 243};	// button 5 + button 6	//   <-------------------      Reemplazar este valor por el que resulte de la muestra 21
				}
int analogpin = 5;			// analog pin to read the buttons
int label = 0;				// for reporting the button label
int counter = 0;			// how many times we have seen new value
long time = 0;				// the last time the output pin was sampled
int debounce_count = 50;	// number of millis/samples to consider before declaring a debounced input
int current_state = 0;		// the debounced input value
int ButtonVal;

void setup()
{ Serial.begin(9600); }

void loop()
{							// If we have gone on to the next millisecond
 if (millis() != time)
 {							// check analog pin for the button value and save it to ButtonVal
   ButtonVal = analogRead(analogpin);
   if(ButtonVal == current_state && counter >0)
   {     counter--;   }
   if(ButtonVal != current_state)
   {     counter++;   }
							// If ButtonVal has shown the same value for long enough let's switch it
   if (counter >= debounce_count)
   {
     counter = 0;
     current_state = ButtonVal;
							//Checks which button or button combo has been pressed
     if (ButtonVal > 0)     {       ButtonCheck();     }
   }
   time = millis();
 }
}

void ButtonCheck()
{							// loop for scanning the button array.
 for(int i = 0; i <= 21; i++)
 {							// checks the ButtonVal against the high and low vales in the array
   if(ButtonVal >= Button[i][j] && ButtonVal <= Button[i][j+1])
   {							// stores the button number to a variable
     label = Button[i][0];
     Action();
   }
 }
}

void Action()
{
		if(label == 1)
		 {   Serial.println("Boton 1"); }
		if(label == 2)
		 {   Serial.println("Boton 2"); }
		if(label == 3)
		 {   Serial.println("Boton 3"); }
		if(label == 4)
		 {   Serial.println("Boton 4"); }
		if(label == 5)
		 {   Serial.println("Boton 5"); }
		if(label == 6)
		 {   Serial.println("Boton 6"); }
		if(label == 7)
		 {   Serial.println("Botones 1 y 2"); }
		if(label == 8)
		 {   Serial.println("Botones 1 y 3"); }
		if(label == 9)
		 {   Serial.println("Botones 1 y 4"); }
		if(label == 10)
		 {   Serial.println("Botones 1 y 5"); }
		if(label == 11)
		 {   Serial.println("Botones 1 y 6"); }
		if(label == 12)
		 {   Serial.println("Botones 2 y 3"); }
		if(label == 13)
		 {   Serial.println("Botones 2 y 4"); }
		if(label == 14)
		 {   Serial.println("Botones 2 y 5"); }
		if(label == 15)
		 {   Serial.println("Botones 2 y 6"); }
		if(label == 16)
		 {   Serial.println("Botones 3 y 4"); }
		if(label == 17)
		 {   Serial.println("Botones 3 y 5"); }
		if(label == 18)
		 {   Serial.println("Botones 3 y 6"); }
		if(label == 19)
		 {   Serial.println("Botones 4 y 5"); }
		if(label == 20)
		 {   Serial.println("Botones 4 y 6"); }
		if(label == 21)
		 {   Serial.println("Botones 5 y 6"); }
		Serial.println("Boton =:");
		Serial.println(label);
		delay(200);
}
