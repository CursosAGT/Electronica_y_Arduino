/*                                 + -                               + -
                                   * *    * * * * *     * * * * *    * * 
      
                                   * *    * * * * *       * * * * *    * * 
            
                                   * *    * * * * *       * * * * *    * * 
                                                   ---V----            /--------------------\  Entrada VCC CD4069 5v
                                   * *    0 * * * o|01 14|o * * * 0----0 *                   | +
                                                   |     |                                  ===  Cap 100 uf Electrolitico
                                   * *    * * * 0 o|02 13|o * * * *    * 0                   | -
                                                   |     |                \-----------------/                                                                        C
                                   * *    0 * * * o|03 12|o * * * 0    * *                                                                                           D       
                                                   |     |                                                                                                           4
                                   * *    * * * * o|04 11|o * * * 0    * *                                                                                           0
                                                   |     |                                                                                                           6 
                                   * *    0 * * * o|05 10|o * * * *    * *                                                                                           9   
    /------------------------------------/         |     |  
   /                               * *    * * 0 * o|06 09|o * * * 0    * *            
  / ------------------------- ---------------/     |     |         \-------------------------------------\
 / /                               * 0----0 * * 0 o|07 08|o 0 * * *    * *                                \ 
 | |                                  GND          -------   \-------------------------------------------\ \
 | |                               * *    * * * * *       * * * * *    * *                                | \
 | |                                                                                                      | |
 | |                               * *    * * * * *       * * * * *    * *                                | |
 | |                                                                                                      | |
 | |                               * *    * * * * *       * * * * *    * *                                | |
P| |                                                                                                      | |P
i| |                               * *    * * * * *       * * * * *    * *                                | |i
n| |  Entrada In1-2(PWM)-----------------\         ---V----        /--\Entrada VCC L293D 5v               | |n
 | |  velocidad de motor I         * *    0 * * * o|01 16|o * * * 0    0 *                                | |>---------------------Pin 7
8| |  PinPWM_Motor_1 = 5                           |     |                            /------------------/  |7
 | \-------------------------\     * *    * * * 0 o|02 15|o * * * *    * *           /                      |
 |Señal B sentido Motor I     \----------------/   |     |  \-----------------------/  Señal D sentido      |                                                     L
 | Pin 8                           * *    0 * * * o|03 14|o * * * 0    * *             Motor II Pin 3       |                                                     2
 |                         /-------------/         |     |         \-------------\                          |                                                     9
 |    Salida  1 -----|----/        * 0----0 * * * o|04 13|o * * * 0--\ * *        \-----|----Salida  1      |                                                     3
 |    Motor I       === Cap           GND          |     |            >--\GND      Cap ===   Motor II       |                                                     D 
 |    Salida  2 -----|----\        * 0----0 * * * o|05 12|o * * * 0--/ * 0        /-----|----Salida  2      |    
 \                         \-------------\         |     |         /-------------/                          |
  \                                * *    0 * * * o|06 11|o * * * 0    * *                                  /
   \------------------------\                      |     |                                                 / 
                             \     * *    0 * * * o|07 10|o * * * 0    * *                                /            
      Señal A sentido Motor I \-----------/        |     |         \-------------------------------------/Señal C sentido Motor II
      Pin 7                        * *    * * * 0 o|08 09|o 0 * * *    * *                    
                              /----------------/   -------  \-----------------------\
      Entrada VCC alimenta   /                                                       \ Entrada In3-4(PWM) Recordar q Arduino puede solo 40 ma x puerto
      motores (4,5 a 36V)   /      * *    * * * * *       * * * * *    * *            \ velocidad de motor II
                                                                                       \ PinPWM_Motor_2 = 
                                   * *    * * * * *       * * * * *    * * 
                    pin GND----------/
                                   * 0    * * * * *       * * * * *    * 0 
                                     \---------------------------------/ - GND
                                   0 *    * * * * *       * * * * *    * * 
                    pin 5v---------/
                                   0 *    * * * * *       * * * * *    0 * 
                                   \---------------------------------/   + 5v

     

Control de velocidad y direccion de Motor CC
*/

const int PinPWM_Motor_1 = 5;                     // PWM se conecta al pin 1 del puente-H
const int PinPWM_Motor_2 = 9;                     // PWM se conecta al pin 9 del puente-H
const int senal_A = 7;                            // Entrada 2 del puente-H
const int senal_C = 8;                            // Entrada 10 del puente-H

int velocidad = 255;
void setup()                                      //Inicializa y prepara los valores
{
  Serial.begin(9600);                             //Abre el puerto serie a 9600 bps
  pinMode(senal_A, OUTPUT);                       //Configura senal_A como salida
  pinMode(senal_C, OUTPUT);                       //Configura senal_A como salida
  Serial.println("VELOCIDAD: (0-9) ");            //Instrucciones en la consola puerto serie
  Serial.println("Adelante: / o - Atraz: *");    // de 0 a 9 y - o + 
  Serial.println("GIRO: + Izquierda o - Derecha");    // de 0 a 9 y - o + 
}

void loop()                         
{
if ( Serial.available())                          //Verifico si el puerto serie esta disponible?
  {
  char dato = Serial.read();                  //Ingreso dato en la variable tipo char desde puerto serial
    if(dato != '\n' )
    { 
    if(dato >= '0' && dato <= '9')                      //Si ch es un numero?
      {
        velocidad = map(dato, '0', '9', 0, 255);  //Re-mapea un numero desde un rango a otro '0′ a 0 '9' a 255
        analogWrite(PinPWM_Motor_1, velocidad);     //Escribe el valor analogico PWM PinPWM_Motor_I - 5
        analogWrite(PinPWM_Motor_2, velocidad);     //Escribe el valor analogico PWM PinPWM_Motor_II - 9
        Serial.println(velocidad);              
      }
    else if (dato == '+')                             //Si el caracter es '+'
      {
        Serial.println("Izquierda");
//                                                                                                                                                                       /Escribe el valor senal_B LOW
        digitalWrite(senal_A,HIGH);                 //Escribe el valor senal_A HIGH------------->> motor avanza sentido Horario-------Giro hacia                        /
//        --------------------------------------------                                                                                      la------CD4069---> invierte< 
        digitalWrite(senal_C,LOW);                  //Escribe el valor senal_C LOW-------------->> motor avanza sentido AntiHorario----Izquierda                         \
//                                                                                                                                                                       \Escribe el valor senal_D HIGH
      }
    else if (dato == '-')                             //Si el caracter es –
      {
        Serial.println("Derecha");
//                                                                                                                                                                       /Escribe el valor senal_B HIGH
        digitalWrite(senal_A,LOW);                  //Escribe el valor senal_A LOW-------------->> motor avanza sentido AntiHorario--Giro hacia                         /
//        --------------------------------------------                                                                                     la------CD4069---> invierte< 
        digitalWrite(senal_C,HIGH);                 //Escribe el valor senal_C HIGH------------->> motor avanza sentido Horario------Derecha                            \
//                                                                                                                                                                       \Escribe el valor senal_D LOW
      }
    else if (dato == '/')                             //Si el caracter es '+'
      {
        Serial.println("adelante");
//                                                                                                                                                                       /Escribe el valor senal_B LOW
        digitalWrite(senal_A,HIGH);                  //Escribe el valor senal_A HIGH------------->> motor avanza sentido Horario-------se mueve                         /
//        --------------------------------------------                                                                                 hacia--------CD4069---> invierte< 
        digitalWrite(senal_C,HIGH);                  //Escribe el valor senal_C HIGH------------->> motor avanza sentido Horario-------adelante                         \ 
//                                                                                                                                                                       \Escribe el valor senal_D LOW
      }
    else if (dato == '*')                             //Si el caracter es –
      {
        Serial.println("Atraz");
//                                                                                                                                                                       /Escribe el valor senal_B HIGH
        digitalWrite(senal_A,LOW);                   //Escribe el valor senal_A LOW-------------->> motor avanza sentido Horario-------se mueve                         /
//        --------------------------------------------                                                                                 hacia--------CD4069---> invierte< 
        digitalWrite(senal_C,LOW);                   //Escribe el valor senal_C LOW-------------->> motor avanza sentido Horario-------atras                            \ 
//                                                                                                                                                                       \Escribe el valor senal_D HIGH      
      }
     
    else                                            //Cualquier otro caracter es omitido
      {
        Serial.print("Error al ingresar dato. Acepta solo de 0 a 9,  +, -, / y* ");
        Serial.println(dato);
      }
    }
  }
}
