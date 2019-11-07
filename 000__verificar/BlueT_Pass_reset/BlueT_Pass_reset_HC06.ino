
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

/* Hacer la conexion a la protoboard (no poner el modulo Bluethoot aun)
Abrir el programa con la configuración
Cambiar el nombre para renombrar nuestro módulo
Poner clave que desea use este modulo
Cargar el programa a la placa arduino

Una vez cargado se dispone de 15 segundos para pinchar el módulo Bluetooth a la protoboard, y automaticamente despues se verá parpadear distinto durante un segundo el led de la plaquita Bluetooth, lo que indicará que está trabajando y cambiando el nombre.

A continuación el led volverá a parpadear constantemente intermitente (estado de espera a activacion)

para HC-05 ver
https://www.youtube.com/watch?v=kfv_uRfHDRU
https://www.youtube.com/watch?v=j-cUDfmtq5g
https://www.youtube.com/watch?v=XXtf1XtQC_0
*
para HC-06 ver
http://dinastiatecnologica.com/producto/modulo-bluetooth-hc-06/

 */



char nombre[10] = "poner_nombre"; //El nuevo nombre del modulo
char password[10] = "poner_clave"; //El nuevo password.
char baud = '4'; //4 = 9600 baud

void setup()
{
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(15000); //Esperar 15 segundos para conectar el modulo

  Serial.print("AT"); //Iniciar la configuracion
  delay(1000);

  Serial.print("AT+NAME"); Serial.print(nombre); //Cambiar el nombre
  delay(1000);

  Serial.print("AT+PIN"); Serial.print(password); //Cambiar contrasena
  delay(1000);

  Serial.print("AT+BAUD"); Serial.print(baud); //Cambiar baudios
  delay(1000);

  digitalWrite(13, HIGH);
}

void loop(){}
