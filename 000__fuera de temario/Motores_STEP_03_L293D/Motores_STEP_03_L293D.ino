/*                            + -                               + -
                             * *    * * * * *     * * * * *    * * 

                             * *    * * * * *       * * * * *    * * 
      
                             * *    * * * * *       * * * * *    * * 
Entrada In1-2(PWM)-----------------\         ---V----        /------------Entrada VCC L293D 5v
velocidad de motor I         * *    0 * * * o|01 16|o * * * 0   * * 
PinPWM_Motor_1 = 5                           |     | 
                             * *    * * * 0 o|02 15|o * * * *    * *           
Señal B sentido Motor I \----------------/   |     |  \-----------------------/Señal D sentido Motor II
Pin 4                        * *    0 * * * o|03 14|o * * * 0    * *                   Pin 3            
                     /-------------/         |     |         \-------------\
Salida  1 -----|----/        * 0----0 * * * o|04 13|o * * * 0--\ * *        \-----|----Salida  1  
Motor I       === Cap           GND          |     |            >--\GND      Cap ===   Motor II
Salida  2 -----|----\        * 0----0 * * * o|05 12|o * * * 0--/ * 0        /-----|----Salida  2
                     \-------------\         |     |         /-------------/
                             * *    0 * * * o|06 11|o * * * 0    * * 
                                             |     | 
                             * *    0 * * * o|07 10|o * * * 0    * *            
Señal A sentido Motor I \-----------/        |     |         \----------------/Señal C sentido Motor II
Pin 7                        * *    * * * 0 o|08 09|o 0 * * 0    * *                    Pin 8
                        /----------------/   -------  \-----------------------\
Entrada VCC alimenta   /                                                       \ Entrada In3-4(PWM) Recordar q Arduino puede solo 40 ma x puerto
motores (4,5 a 36V)   /      * *    * * * * *       * * * * *    * *            \ velocidad de motor II
                                                                                 \ PinPWM_Motor_2 = 9
                                                                                 
                             * *    * * * * *       * * * * *    * * 
              pin GND----------/
                             * 0    * * * * *       * * * * *    * 0 
                               \---------------------------------/ - GND
                             0 *    * * * * *       * * * * *    * * 
              pin 5v---------/
                             0 *    * * * * *       * * * * *    0 * 
                             \---------------------------------/   + 5v

     

Control de step motors
*/

#include <Stepper.h>

const int senal_1 = 8;                            // Entrada 2 del puente-H
const int senal_2 = 3;                            // Entrada 10 del puente-H
const int senal_3 = 4;                            // Entrada 7 del puente-H
const int senal_4 = 7;                            // Entrada 15 del puente-H 
Stepper myStepper(250, senal_1,senal_2,senal_3,senal_4);           
const int Pin_Motor_1 = 5;                     // Habilita al pin 1 del puente-H
const int Pin_Motor_2 = 9;                     // Habilita al pin 9 del puente-H
void setup() {
  myStepper.setSpeed(60);
  pinMode(Pin_Motor_1, OUTPUT);     //Habilita Pin_Motor_I - 5
  pinMode(Pin_Motor_2, OUTPUT);     //Habilita Pin_Motor_II - 9
}

void loop() {
  digitalWrite(Pin_Motor_1, HIGH);     //Habilita Pin_Motor_I - 5
  digitalWrite(Pin_Motor_2, HIGH);     //Habilita Pin_Motor_II - 9
  myStepper.step(10);
}
