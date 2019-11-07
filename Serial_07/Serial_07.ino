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
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *
                                       *  * |             [ ] [ ] [ ]             | *  *
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *
                                       *  * \________________________/              *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/

char caracter_ingresado;
String cadena_ingresada;
boolean caracter_retorno = false;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (caracter_retorno)
  {    											//cadena_ingresada //Los datos ingresados se encuentran en esta variable
    cadena_ingresada = "";  					//Limpiar el String
    caracter_retorno = false;  					//Limpiar la bandera
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    caracter_ingresado = Serial.read(); 		//Leer un byte del puerto serial
    cadena_ingresada += caracter_ingresado;  	//Agregar el char anterior al string
    if (caracter_ingresado == '\n')
    {  											//Si se detecta un fin de linea
      caracter_retorno = true;  				//Se indica al programa que el usuario termino de ingresar la informacion
      Serial.print (cadena_ingresada);
    }
  }
}
