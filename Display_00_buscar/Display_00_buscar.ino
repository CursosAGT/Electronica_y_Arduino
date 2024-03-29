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
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
void setup()
   {
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

       lcd.home ();                   // go home
       lcd.print("UTN 2019");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("Elec.& arduino");
   }
void loop()
   {}
