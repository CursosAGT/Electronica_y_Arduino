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
La librería LiquidCrystal_I2C dispone de métodos similares (algunos idénticos) a los de la librería oficial.

    LiquidCrystal_I2C() – Constructor de la clase, configura el hardware.
    init() – Prepara el LCD para su uso.
    clear() – Borra todos los caracteres de la pantalla LCD.
    setCursor(col, row) – Permite mover el cursor a la posición indicada en sus parámetros.
    print() – Imprime una variable o literal en la pantalla
    scrollDisplayLeft() y scrollDisplayRight() – Recorre el contenido de la pantalla a la izquierda o a la derecha
    backlight() y noBacklight() – Métodos para encender / apagar la iluminación de fondo
    createChar(num, data) –  Crear un carácter definido por el usuario en la memoria del controlador de pantalla
    */

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

//#define I2C_ADDR    0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte up[8] = {
B00100,
B01110,
B10101,
B00100,
B00100,
B00100,
B00100,
B00100,
};
byte down[8] = {
B00100,
B00100,
B00100,
B00100,
B00100,
B10101,
B01110,
B00100,
};
byte left[8] = {
B00000,
B00110,
B01100,
B11111,
B11111,
B01100,
B00110,
B00000,
};
byte right[8] = {
B00000,
B01100,
B00110,
B11111,
B11111,
B00110,
B01100,
B00000,
};
byte linea[8] = {
B00000,
B00000,
B00000,
B11111,
B11111,
B00000,
B00000,
B00000,
};
byte barra[8] = {
B00000,
B00100,
B00100,
B00100,
B00100,
B00100,
B00100,
B00000,
};
byte cara[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000,
};
byte cuerpo[8] = {
B01110,
B01110,
B00100,
B11111,
B00100,
B01010,
B10001,
B00000,
};

void setup() {
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2

  lcd.begin();
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();

  //creamos los nuevos caracteres
  lcd.createChar (0,up);
  lcd.createChar (1,down);
  lcd.createChar (2,left);
  lcd.createChar (3,right);
  lcd.createChar (4,linea);
  lcd.createChar (5,barra);
  lcd.createChar (6,cara);
  lcd.createChar (7,cuerpo);
 // Escribimos el texto en el LCD
  lcd.setCursor(0, 0);
  lcd.print("UTN Ej iconos");
  lcd.setCursor(0, 1);
  lcd.write (byte (7));
  lcd.print(" ");
  lcd.write (byte (6));
  lcd.write (byte (5));
  lcd.write (byte (4));
  lcd.write (byte (3));
  lcd.write (byte (1));
  lcd.print(" ");
  lcd.write (byte (0));
  lcd.print(" ");
  lcd.write (byte (2));
  lcd.write (byte (4));
  lcd.write (byte (5));
  lcd.write (byte (6));
  lcd.print(" ");
  lcd.write (byte (7));



}

void loop () {}
