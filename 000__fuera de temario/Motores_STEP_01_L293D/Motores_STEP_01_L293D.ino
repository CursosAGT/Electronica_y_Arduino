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

/*
 * Bipolar stepper motor speed and direction control with Arduino.
 * Full step control.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 */
 /*
// include Arduino stepper motor library
#include <Stepper.h>
 
// change this to the number of steps on your motor
#define STEPS 20
 
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 3, 4, 7, 8);

const int PinPWM_Motor_1 = 5;                     // PWM se conecta al pin 1 del puente-H
const int PinPWM_Motor_2 = 9;                     // PWM se conecta al pin 9 del puente-H
const int senal_A = 7;                            // Entrada 2 del puente-H
const int senal_B = 4;                            // Entrada 7 del puente-H
const int senal_C = 8;                            // Entrada 10 del puente-H
const int senal_D = 3;                            // Entrada 15 del puente-H 
int velocidad = 55;
boolean salida= true;
int delayTime = 50;
int direction_ = 1, speed_ = 0;

void setup()
{
  Serial.begin(9600);                             //Abre el puerto serie a 9600 bps
  pinMode(senal_A, OUTPUT);                       //Configura senal_A como salida
  pinMode(senal_B, OUTPUT);                       //Configura senal_B como salida
  pinMode(senal_C, OUTPUT);                       //Configura senal_A como salida
  pinMode(senal_D, OUTPUT);                       //Configura senal_B como salida
Serial.println (salida);
delay(5000);
}
 

 
void loop()
{

direction_ *= -1;  // reverse direction variable
stepper.setSpeed(velocidad);
stepper.step(direction_);
 
}
const int PinPWM_Motor_1 = 5;     								// PWM se conecta al pin 1 del puente-H
const int PinPWM_Motor_2 = 9;			      					// PWM se conecta al pin 9 del puente-H
const int senal_A = 7;									      	  // Entrada 2 del puente-H
const int senal_B = 4;      										  // Entrada 7 del puente-H
const int senal_C = 8;			      							  // Entrada 10 del puente-H
const int senal_D = 3;										        // Entrada 15 del puente-H
int velocidad = 255;
boolean salida= true;

void setup() 												              //Inicializa y prepara los valores
{
	Serial.begin(9600); 				      					    //Abre el puerto serie a 9600 bps
	pinMode(senal_A, OUTPUT);        								//Configura senal_A como salida
	pinMode(senal_B, OUTPUT); 			      					//Configura senal_B como salida
	pinMode(senal_C, OUTPUT); 						      		//Configura senal_A como salida
	pinMode(senal_D, OUTPUT); 						      		//Configura senal_B como salida
Serial.println (salida);
delay(5000);

    Serial.println("VELOCIDAD: (0-9) ");            //Instrucciones en la consola puerto serie
    Serial.println("Adelante: / o - Atraz: *");    // de 0 a 9 y - o + 
    Serial.println("GIRO: + Izquierda o - Derecha");    // de 0 a 9 y - o + 

}
*/
const int Pin_Motor_1 = 5;                     // Habilita al pin 1 del puente-H
const int Pin_Motor_2 = 9;                     // Habilita al pin 9 del puente-H
const int senal_1 = 8;                            // Entrada 2 del puente-H
const int senal_2 = 7;                            // Entrada 10 del puente-H
const int senal_3 = 4;                            // Entrada 7 del puente-H
const int senal_4 = 3;                            // Entrada 15 del puente-H 
int delayTime = 40;
 
void setup()
{
  pinMode(senal_1, OUTPUT);
  pinMode(senal_2, OUTPUT);
  pinMode(senal_3, OUTPUT);
  pinMode(senal_4, OUTPUT);
  pinMode(Pin_Motor_1, OUTPUT);     //Habilita Pin_Motor_I - 5
  pinMode(Pin_Motor_2, OUTPUT);     //Habilita Pin_Motor_II - 9
}
 
void loop() 
{
  digitalWrite(Pin_Motor_1, HIGH);     //Habilita Pin_Motor_I - 5
  digitalWrite(Pin_Motor_2, HIGH);     //Habilita Pin_Motor_II - 9
  digitalWrite(senal_4, HIGH);
  digitalWrite(senal_3, LOW);
  digitalWrite(senal_2, LOW);
  digitalWrite(senal_1, LOW);
  delay(delayTime);
  digitalWrite(senal_4, LOW);
  digitalWrite(senal_3, HIGH);
  digitalWrite(senal_2, LOW);
  digitalWrite(senal_1, LOW);
  delay(delayTime);
  digitalWrite(senal_4, LOW);
  digitalWrite(senal_3, LOW);
  digitalWrite(senal_2, HIGH);
  digitalWrite(senal_1, LOW);
  delay(delayTime);
  digitalWrite(senal_4, LOW);
  digitalWrite(senal_3, LOW);
  digitalWrite(senal_2, LOW);
  digitalWrite(senal_1, HIGH);
  delay(delayTime);
}
