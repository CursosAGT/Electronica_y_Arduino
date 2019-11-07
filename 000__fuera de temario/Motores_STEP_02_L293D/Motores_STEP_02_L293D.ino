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
 
// include Arduino stepper motor library
#include <Stepper.h>
 
// change this to the number of steps on your motor
#define STEPS 20
 
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);
 
const int button =  4; // direction control button is connected to Arduino pin 4
const int pot    = A0; // speed control potentiometer is connected to analog pin 0
 
void setup()
{
  // configure button pin as input with internal pull up enabled
  pinMode(button, INPUT_PULLUP);
}
 
int direction_ = 1, speed_ = 0;
 
void loop()
{
  if ( digitalRead(button) == 0 )  // if button is pressed
    if ( debounce() )  // debounce button signal
    {
      direction_ *= -1;  // reverse direction variable
      while ( debounce() ) ;  // wait for button release
    }
 
  // read analog value from the potentiometer
  int val = analogRead(pot);
 
  // map digital value from [0, 1023] to [5, 100]
  // ===> min speed = 5 and max speed = 100 rpm
  if ( speed_ != map(val, 0, 1023, 5, 100) )
  { // if the speed was changed
    speed_ = map(val, 0, 1023, 5, 100);
    // set the speed of the motor
    stepper.setSpeed(speed_);
  }
 
  // move the stepper motor
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

void loop() 												
{

if ( Serial.available()) 									        //Verifico si el puerto serie esta disponible?
  {
  char dato = Serial.read();                  //Ingreso dato en la variable tipo char desde puerto serial
    if(dato != '\n' )
    { 
  	if(dato >= '0' && dato <= '9') 								      //Si ch es un numero?
  		{
  			velocidad = map(dato, '0', '9', 0, 255); 	//Re-mapea un numero desde un rango a otro '0′ a 0 '9' a 255
  			analogWrite(PinPWM_Motor_1, velocidad); 		//Escribe el valor analogico PWM PinPWM_Motor_I - 5
  			analogWrite(PinPWM_Motor_2, velocidad); 		//Escribe el valor analogico PWM PinPWM_Motor_II - 9
  			Serial.println(velocidad); 							
  		}
  	else if (dato == '+') 						          			//Si el caracter es '+'
  		{
  			Serial.println("Izquierda");
  			digitalWrite(senal_A,LOW); 						      //Escribe el valor senal_A LOW
  			digitalWrite(senal_B,HIGH); 					      //Escribe el valor senal_B HIGH------------->> motor avanza sentido Horario-------Giro hacia
  //			--------------------------------------------                                                                                      la
  			digitalWrite(senal_C,HIGH);       					//Escribe el valor senal_A HIGH------------->> motor avanza sentido AntiHorario---Izquierda
  			digitalWrite(senal_D,LOW); 				      		//Escribe el valor senal_B LOW
  		}
  	else if (dato == '-')     									    	//Si el caracter es –
  		{
  			Serial.println("Derecha");
  			digitalWrite(senal_A,LOW);       						//Escribe el valor senal_A HIGH
  			digitalWrite(senal_B,HIGH); 		      			//Escribe el valor senal_B LOW-------------->> motor avanza sentido AntiHorario--Giro hacia
  //			--------------------------------------------                                                                                     la
  			digitalWrite(senal_C,HIGH); 					      //Escribe el valor senal_A LOW-------------->> motor avanza sentido Horario------Derecha
  			digitalWrite(senal_D,LOW); 			      			//Escribe el valor senal_B HIGH
  		}
    else if (dato == '/')                             //Si el caracter es '+'
      {
        Serial.println("adelante");
        digitalWrite(senal_A,HIGH);                  //Escribe el valor senal_A HIGH
        digitalWrite(senal_B,LOW);                   //Escribe el valor senal_B LOW ------------->> motor avanza sentido Horario-------se mueve
  //      --------------------------------------------                                                                                 hacia
        digitalWrite(senal_C,HIGH);                  //Escribe el valor senal_A HIGH------------->> motor avanza sentido AntiHorario---adelante
        digitalWrite(senal_D,LOW);                   //Escribe el valor senal_B LOW
      }
    else if (dato == '*')                             //Si el caracter es –
      {
        Serial.println("Atraz");
        digitalWrite(senal_A,LOW);                   //Escribe el valor senal_A LOW
        digitalWrite(senal_B,HIGH);                  //Escribe el valor senal_B HIGH-------------->> motor avanza sentido AntiHorario--se mueve
  //      --------------------------------------------                                                                                 hacia
        digitalWrite(senal_C,LOW);                   //Escribe el valor senal_A LOW--------------->> motor avanza sentido Horario------Atras
        digitalWrite(senal_D,HIGH);                  //Escribe el valor senal_B HIGH
      }
     
  	else										                  			//Cualquier otro caracter es omitido
  		{
        Serial.print("Error al ingresar dato. Acepta solo de 0 a 9,  +, -, / y* ");
  			Serial.println(dato);
  		}
  	}
  }
}
