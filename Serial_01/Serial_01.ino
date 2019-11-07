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
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                ||||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                ||||||
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                ||||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *                ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                ||||||
                                       *  * \________________________/              *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                                                                                                          ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                                          220 Ohm            Led 3              /------------------------/ ||| pin 10
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                          220 Ohm            Led 4              /-------------------------/ || pin 11
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                          220 Ohm            Led 5              /--------------------------/ | pin 12
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                          220 Ohm            Led 6              /---------------------------/  pin 13
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v

La funciones más importantes que debemos conocer para manejar el puerto serie son: begin(), read(), write(), print() y available())

begin()           –   establece la velocidad de la UART en baudios para la transmisión serie, también es posible configurar el número de bits de datos, la paridad y los bits de stop, por defecto es 8 bits de datos, sin paridad y un bit de stop. https://www.arduino.cc/en/Serial/Begin
read()            –   lee el primer byte entrante del buffer serie. https://www.arduino.cc/en/Serial/Read
write()           –   escribe datos en binario sobre el puerto serie. El dato es enviado como un byte o serie de bytes.
print()           –   imprime datos al puerto serie como texto ASCII, también permite imprimir en otros formatos. https://www.arduino.cc/en/Serial/Print
available()       –   da el número de bytes (caracteres) disponibles para leer en el puerto serie, son datos que han llegado y se almacenan en el buffer serie que tiene un tamaño de 64 bytes. https://www.arduino.cc/en/Serial/Available
end()             –   deshabilita la comunicación serie permitiendo a los pines RX y TX ser usado como pines digitales. https://www.arduino.cc/en/Serial/End
if(Serial)        –   especifica si el puerto serie está listo. https://www.arduino.cc/en/Serial/IfSerial
find()            –   lee datos del buffer serie hasta encontrar el string buscado. https://www.arduino.cc/en/Serial/Find
parseInt()        –   busca el siguiente entero válido en el stream de datos del puerto serie. https://www.arduino.cc/en/Serial/ParseInt
readBytes()       –   lee datos del buffer serie y lo guarda en una variable buffer. https://www.arduino.cc/en/Serial/ReadBytes
setTimeout()      –   configura el máximo de milisegundos de espera para la lectura del puerto serie. Por defecto es un segundo. https://www.arduino.cc/en/Serial/SetTimeout
readBytesUntil()  –   lee caracteres del buffer serie y los guarda en un array de caracteres, la función termina si el carácter terminados es encontrado o la longitud determinada se a leído o ha alcanzado el timeout. https://www.arduino.cc/en/Serial/ReadBytesUntil
serialEvent()     –   llamado cuando hay datos disponibles. https://www.arduino.cc/en/Reference/SerialEvent
flush()           –   espera hasta la transmisión completa de los datos salientes. https://www.arduino.cc/en/Serial/Flush
peek()            –   devuelve el siguiente carácter del buffer serie pero sin borrarlo de él. https://www.arduino.cc/en/Serial/Peek
readString()      –   lee caracteres del buffer serie y los guarda en un string. La función termina cuando se produce un timeout. https://www.arduino.cc/en/Serial/ReadString

*/

int demora =  150;
int led[] = {8,9,10,11,12,13};
int pin =  0;
void setup()
 {
  for (pin=0;pin<=5; pin++)
  {
    pinMode(led[pin],OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  for (pin=0;pin<=5; pin++)
  {
    digitalWrite (led[pin],HIGH);
    delay(demora);
    digitalWrite (led[pin],LOW);
    delay(demora);
    Serial.print(" lugar de array  : ");
    Serial.println(pin);
    Serial.print(" pin del board  : ");
    Serial.print(led[pin]);
    Serial.println("      ");
  }
}
