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
                                       *  * | [ ]N/C                    SCK/13[ ] | *  *
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *
                                       *  * | [ ]RST                   MOSI/11[ ] | *  *
                                       *  * | [ ]3V3    +---+               10[ ] | *  *
                                       0------[0]5v    -| A |-               9[ ] | *  *
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *
                                       *  0---[0]GND   -| D |-                    | *  *
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *
                                       *  * |          -| I |-               6[ ]~| *  *
                                       *  * | [0]A0    -| N |-               5[ ]~| *  *
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *
                                       *  * | [ ]A3                     INT0/2[ ] | *  *
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[0] |---------\
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[0] |-------\ |
                                       *  * |             [ ] [ ] [ ]             | *  *  | |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *  | |
                                       *  * \________________________/              *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
+--------------------------+           *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
|   ___                    |----State  *  *    *  *  *  *  *       *  *  *  *  *    *  *  | |
|  [    +------+  +------+ |----RXD a TXD de Arduino--------------------------------------|-/   (pin 1)
|   ]   |      |  |      | |----TXD a RXD de Arduino-------------------------------------/      (pin 0)
|  [    |      |  |      | |----GND-------0    *  *  *  *  *       *  *  *  *  *    *  *
|   ]   +------+  +------+ |----Vcc-5v-0  *    *  *  *  *  *       *  *  *  *  *    *  *
|  [                       |-----      *  *    *  *  *  *  *       *  *  *  *  *    *  *
+--------------------------+           *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
* https://www.prometec.net/bt-hc06/
*/
#include <SoftwareSerial.h>
SoftwareSerial BT1(4,2); // RX, TX
void setup()
   {
       Serial.begin(9600);
       Serial.println("Enter AT commands:");
       BT1.begin(9600);
   }

void loop()
   {
       if (BT1.available())
           {
				Serial.write(BT1.read());
			}
       if (Serial.available())
			{
				String S = GetLine();
				BT1.print(S);
				Serial.println("---> " + S);
			}
}

String GetLine()
   {
	   String S = "" ;
       if (Serial.available())
			{
			char c = Serial.read(); ;
			while ( c != '\n')            //Hasta que el caracter sea intro
				{     S = S + c ;
					delay(25) ;
					c = Serial.read();
				}
			return( S + '\n') ;
		}
   }
