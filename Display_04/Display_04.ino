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
//LiquidCrystal_I2C lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
unsigned int val ;
int potenciometro =A0;
float volts;

void setup()
{
  Serial.begin(9600);
  pinMode(potenciometro,INPUT);
  // Indicar a la libreria que tenemos conectada una pantalla de 16x2
  lcd.begin(16, 2);
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
   // Actualizar la pantalla completa cada segundo
  lcd.clear();
  // Imprimir encabezado
  lcd.print(" POTENCIOMETRO  ");

  // Realizar la lectura analogica en A0
  val = analogRead(A0);///////entrada de potenciometro
  // Convertir a voltaje
  volts = (val * 5.0) / 1024.0;
  Serial.print  ("valor del pote 10 bits:" +String(val));
  Serial.println("   valor en volts     :" +String(volts));
  // Imprimir valores en la segunda linea
  lcd.setCursor(0, 1);
  lcd.print(val);
  // Imprimir el voltaje en la segunda linea, despues del valor del ADC
  lcd.setCursor(6, 1);
  lcd.print(volts, 1);

  // Esperar un segundo antes de continuar
  delay (1000);
}
