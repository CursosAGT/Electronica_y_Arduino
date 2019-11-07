//                              + -                               + -
//	                            * *    * * * * *     * * * * *    * *
// 
//	                            * *    * * * * *     * * * * *    * *
// 
//	                            * *    * * * * *     * * * * *    * *
//    pin_9 <----Habilita-------------\       _________       /------------------------> VCC_IN_motor_Y
//                              * *    0 * 1=|    º    |=16* 0    * *
//    pin_8 <-----------Data_IN_A_1---\      |         |      /---------Data_IN_B_1----> pin_5
//                              * *    0 * 2=|         |=15* 0    * *
// Motor_X1 <-------------------------\      |         |      /------------------------> Motor_Y1
// OUT_Motor_X1                 * *    0 * 3=|    L    |=14* 0    * *                    OUT_Motor_Y1
//                  _/----------------/      |         |      \--------------\_
//                 /1\          * *    * 0 4=|    2    |=13* 0    * *        /1\
//                |=0=|       GND/------<|   |         |     | GND          |=0=| 
//                 \3/          0 *    * 0 5=|    9    |=12* 0----0 *        \3/  
//                   \----------------\      |         |      /--------------/
// OUT_Motor_X2                 * *    0 * 6=|    3    |=11* 0    * *                    OUT_Motor_Y2
// Motor_X2 <-------------------------/      |         |      \------------------------> Motor_Y2
//                              * *    0 * 7=|    D    |=10* 0    * *
//    pin_7 <-----------Data_IN_A_2---/      |         |      \---------Data_IN_B_2----> pin_4
//                              * *    0 * 8=|̣̣_________|=9 * 0    * *
// VCC_IN_motor_X <-------------------/                       \---------Habilita_B-----> Pin_3
//				               * *    * * * * *     * * * * *    * * 
//
//				               * 0    * * * * *     * * * * *    * * 
//				pin GND----------/
//				               * 0    * * * * *     * * * * *    * 0 
//				                 \---------------------------------/ - GND
//				               0 *    * * * * *     * * * * *    * * 
//				pin 5v---------/
//				               0 *    * * * * *     * * * * *    0 * 
//				               \---------------------------------/   + 5v
//				
//                              ___________
//   pin_9 <----Habilita_A----1=|    º    |=16---VCC_IN_motor_Y
//   pin_8 <---Data_IN_A_1----2=|         |=15---Data_IN_B_1----> pin_5 
// motor_1 <--OUT_Motor_X1----3=|    L    |=14---OUT_Motor_Y1---> motor_2----\
// Pin GND <-----------GND----4=|    2    |=13---GND------------> Pin GND    ___
// Pin GND <-----------GND----5=|    9    |=12---GND------------> Pin GND    --- Capacitor
// motor_1 <--OUT_Motor_X2----6=|    3    |=11---OUT_Motor_Y2---> motor_2----/
//   pin_7 <---Data_IN_A_2----7=|    D    |=10---Data_IN_B_2----> Pin_4
//          VCC_IN_motor_X----8=|̣̣_________|=9----Habilita_B-----> Pin_3

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()
{
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop()
{
	directionControl();
	delay(1000);
	speedControl();
	delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl()
{
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
	analogWrite(enB, 255);

	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl()
{
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++)
	{
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i)
	{
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
