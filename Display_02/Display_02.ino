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
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin();
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "UTN 2019" en la primera linea
  lcd.print("UTN 2019");
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir Elec.& arduino en la segunda linea
  lcd.print("Elec.& arduino");
  // Esperar un segundo
  delay(1000);
}

void loop()
{
  // EN EL CICLO PRINCIPAL SOLAMENTE RECORREMOS EL MENSAJE DE UN LADO A OTRO
  // Variable para conteo de ciclos
  int i;

  // Desplazar la pantalla a la derecha 2 veces
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayRight();
    delay (1000);
  }

  // Desplazar la pantalla a la izquierda 2 veces
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayLeft();
    delay (1000);
  }
}
