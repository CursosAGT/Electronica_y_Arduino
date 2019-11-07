/*                        +  -                                        +  -
                          *  *    *  *  *  *  *      *  *  *  *  *    *  *
                          *  *    *  *  *  *  *      *  *  +-----+    *  *
                          *  * +----[PWR]------------------| USB |--+ *  *
                          *  * |                           +-----+  | *  *
                          *  * |         GND/RST2 [ ][ ]            | *  *
                          *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *
                          *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *
                          *  * |                            AREF[ ] | *  *
                          *  * |                             GND[ ] | *  *
                          *  * | [ ]N/C                   SCK/13[ ] | *  *
                          *  * | [ ]IOREF                MISO/12[ ] | *  *
                          *  * | [ ]RST                  MOSI/11[ ]~| *  *
                          *  * | [ ]3V3    +---+              10[ ]~| *  *
                          0------[0]5v    -| A |-              9[ ]~| *  *
                          *  * | [ ]GND   -| R |-              8[ ] | *  *
                          *  0---[0]GND   -| D |-                   | *  *
                          *  * | [ ]Vin   -| U |-              7[ ] | *  *
                          *  * |          -| I |-              6[ ]~| *  *
                          *  * | [ ]A0    -| N |-              5[ ]~| *  *
                          *  * | [ ]A1    -| O |-              4[ ] | *  *
                          *  * | [ ]A2     +---+          INT1/3[ ]~| *  *
                          *  * | [ ]A3                    INT0/2[ ] | *  *
        -------------------------[0]A4/SDA  RST SCK MISO    TX>1[ ] | *  *
       /  -----------------------[0]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *
       |  /               *  * |            [ ] [ ] [ ]             | *  *
       |  |               *  * |  UNO_R3    GND MOSI 5V ____________/ *  *
       |  |               *  * \______________________/               *  *
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  *
       |  \                           ̣̣________________________________
       |   ----------------------0---/ SCL                            \
       \             pin A5          |                                 |
        -------------------------0---| SDA                             |
 pin A4                              |                 I2C            ----|]
                          0------0---| Vcc 5v                         ----|]
                                     |                                 |
                          *  0---0---| GND                             |
                                     \_****************_______________/
                          *  *    *  * |||||||||||||||| *  *  *  *    *  *
                          *  *    *  * |||||||||||||||| *  *  *  *    *  *
						  *  *    *  * ||||||||||||||||__________________________________________________
						  *  *    *  | ****************                                                 |
                          *  *    *  |  /-----------------------------------------------------------\   |
						  *  *    *  |  |                                                            |  |
                          *  *    *  |  |                                                            |  |
						  *  *    *  |  |                                                            |  |
                          *  *    *  |  |                     2 x 16                                 |  |
						  *  *    *  |  |                                                            |  |
                          *  *    *  |  |                                                            |  |
						  *  *    *  |  |                                                            |  |
                          *  *    *  |  \-----------------------------------------------------------/   |
						  *  *    *  |__________________________________________________________________|
                          *  *    *  *  *  *  *      *  *  *  *  *    *  *
                          *  *    *  *  *  *  *      *  *  *  *  *    *  *
					      *  0    *  *  *  *  *       *  *  *  *  *    *  0
		    pin GND---------/ \------------------------------------------/ - GND
			              *  *    *  *  *  *  *       *  *  *  *  *    *  *
					      0  *    *  *  *  *  *       *  *  *  *  *    0  *
		    pin 5v-------/ \------------------------------------------/+ 5v


Adaptador LCD a I2C   |   Arduino Uno, Nano, Mini.   |   Arduino Mega , DUE   |   Arduino Leonardo    |
          GND         |           GND                |         GND            |           GND         |
          VCC         |           5 volts            |         5 volts        |           5 volts     |
          SDA         |           pin A4             |         pin 20         |           pin 2       |
          SCL         |           pin A5             |         pin 21         |           pin 3       |

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.init();//lcd.begin();
  lcd.setBacklight(HIGH);

  lcd.home ();                   // inicio
  lcd.print("UTN 2019");
  lcd.setCursor ( 0, 1 );        // paso a la seginda linea
  lcd.print("Elec.& arduino");
}

void loop()
{
  delay(5000);
  bool blinking = true;
  lcd.cursor();

  while (1) {
    if (blinking) {
      lcd.clear();
      lcd.print("cursor estatico");
      lcd.noBlink();
      blinking = false;
    } else {
      lcd.clear();
      lcd.print("Cursor blinking");
      lcd.blink();
      blinking = true;
    }
    delay(4000);
  }
}
