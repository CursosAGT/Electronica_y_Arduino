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
//
//	                            * *    * * * * *     * * * * *    * *
//
//	                            * *    * * * * *     * * * * *    * *
//    pin_N <----Habilita-------------\       _________       /------------------------> VCC_IN_motor_Y
//                              * *    0 * 1=|    º    |=16* 0    * *
//    pin_N <-----------Data_IN_A_1---\      |         |      /---------Data_IN_B_1----> pin_N
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
//    pin_N <-----------Data_IN_A_2---/      |         |      \---------Data_IN_B_2----> pin_N
//                              * *    0 * 8=|̣̣_________|=9 * 0    * *
// VCC_IN_motor_X <-------------------/                       \---------Habilita_B-----> Pin_N
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
//   pin_N <----Habilita_A----1=|    º    |=16---VCC_IN_motor_Y-> pin_N
//   pin_N <---Data_IN_A_1----2=|         |=15---Data_IN_B_1----> pin_N
// motor_1 <--OUT_Motor_X1----3=|    L    |=14---OUT_Motor_Y1---> motor_2----\
// Pin GND <-----------GND----4=|    2    |=13---GND------------> Pin GND    ___
// Pin GND <-----------GND----5=|    9    |=12---GND------------> Pin GND    --- Capacitor
// motor_1 <--OUT_Motor_X2----6=|    3    |=11---OUT_Motor_Y2---> motor_2----/
//   pin_N <---Data_IN_A_2----7=|    D    |=10---Data_IN_B_2----> Pin_N
//          VCC_IN_motor_X----8=|̣̣_________|=9----Habilita_B-----> Pin_N
//
//				               + -                               + -
//				               * *    * * * * *     * * * * *    * *
//				                10 kOhm   boton_Horario          /--------------pin 5
//				               * 0-ww-0 * * * 0-(w)-0 * * 0 0----0 *
//				                10 kOhm   boton_AntiHorario      /--------------pin 6
//                             * 0-ww-0 * * * 0-(w)-0 * * 0 0----0 *
//
// _____________               * *    * * * * *     * * * * *    * *
// |_____º_____|
// |     _     |               * *    * * * * *     * * * * *    * *
// |    |=|    |          /-------------------------\       /------------pin 2
// |    |=|    |----GRD--/     * *    * * * * *     0 * * * 0    * *
// |    |=|    |----4.8v_a_6v--Vcc->----------------\       /------------pin
// |  (=(0)=)  |----Signal     * *    * * * * *     0 * * * 0    * *
// |    |=|    |          \-------------------------\       /------------pin 3
// |̣̣____|=|____|               * *    * * * * *     0 * * * 0    * *
//      |=|
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
// _____________
// |_____º_____|
// |     _     |
// |    |=|    |
// |    |=|    |----GRD------------>
// |    |=|    |----4.8v_a_6v--Vcc->
// |  (=(0)=)  |----Signal--------->
// |    |=|    |
// |̣̣____|=|____|
//      |=|
//


#include <Servo.h>
Servo servo;
int angulo = 90;//Normal
int Motor_Adelante = 2;
int Motor_Atras = 3;
int boton_Horario = 5;
int boton_AntiHorario = 6;
int boton = 0;
int demora_servo = 15;
int demora = 150;
void setup() {
  servo.attach(8);
  servo.write(angulo);
  pinMode(boton_Horario, INPUT);
  pinMode(boton_AntiHorario, INPUT);
  pinMode(Motor_Adelante, OUTPUT);
  pinMode(Motor_Atras, OUTPUT);
}
void loop()
{
  digitalWrite(Motor_Adelante, LOW);
  digitalWrite(Motor_Atras, HIGH);
  delay(demora*4);
  digitalWrite(Motor_Adelante, LOW);
  digitalWrite(Motor_Atras, LOW);
  delay(demora_servo);
  digitalWrite(Motor_Adelante, HIGH);
  digitalWrite(Motor_Atras, LOW);
  delay(demora*4);
  digitalWrite(Motor_Adelante, LOW);
  digitalWrite(Motor_Atras, LOW);
	if (digitalRead(boton_Horario) == LOW)
	{
		if ( angulo < 180)
		{
			for(angulo = 90; angulo < 180; angulo++)      // ida de 0 a 180 grados
			{
				servo.write(angulo);
				delay(demora_servo);
			}
			delay(demora);
			for(angulo = 180; angulo > 90; angulo--)
			{
				servo.write(angulo);
				delay(demora_servo);
			}
		}
		delay(demora);
	}
	if (digitalRead(boton_AntiHorario) == LOW)
	{
		if ( angulo > 10)
		{
			for(angulo = 90; angulo > 10; angulo--)       // vuelta de 180 a 0 grados
			{
				servo.write(angulo);
				delay(demora_servo);
			}
			delay(demora);
			for(angulo = 10; angulo < 90; angulo++)
			{
				servo.write(angulo);
				delay(demora_servo);
			}
		}
		delay(demora);
	}
}
