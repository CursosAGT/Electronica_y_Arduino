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
https://create.arduino.cc/projecthub/ambhatt/bipolar-stepper-motor-library-b9d5e0

Rotate motor 90o clockwise and 90o anticlockwise continuously at 30 RPM

this program will rotate bipolar motor

* with 1.8 deg step angle (200 steps/rev) at 30 RPM to

* 90 deg CW and 90 deg CCW continuously

* created by Ashutosh Bhatt on 22/10/16

*/

#include<bi_polar_Stepper.h>

#define motor_steps 200

bi_polar_Stepper my_step_motor(8, 9, 10, 11);

int rpm = 30;

void setup()

{

// put your setup code here, to run once:

Serial.begin(9600);

Serial.println("bipolar stepper motor library test program");

my_step_motor.set_step_per_rev(motor_steps);

my_step_motor.set_RPM(rpm);

Serial.println("motor rotates 90 deg back and forth");

}

void loop()

{

my_step_motor.rotate_x_deg(90);

delay(2000);

my_step_motor.rotate_x_deg(270);

delay(2000);

}
/*
Note:-If the stepper motor is of higher current and voltage ratings then instead of L293D chip, we can use L298 chip or set of 4 separate Darlington transistors like TIP122, TIP142 etc can be used to drive stepper motors.

The given library and example programs along with above circuit are tested with following stepper motors

1) 2 phase bipolar motor with 5V, 100 RPM (MAX), 200 steps/rev (1.8o step angle)

2) 2 phase bipolar motor with 5V, 60 RPM (MAX), 200 steps/rev (1.8o step angle)*/
