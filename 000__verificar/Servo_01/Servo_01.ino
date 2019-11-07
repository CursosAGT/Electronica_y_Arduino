

/*		               + -                               + -
				                     * *    * * * * *     * * * * *    * *
				                      220 Ohm   boton_Horario          /--------------pin 13 
				                     * 0-ww-0 * * * 0-(w)-0 * * 0 0----0 *
				                      220 Ohm   boton_AntiHorario      /--------------pin 12
                             * 0-ww-0 * * * 0-(w)-0 * * 0 0----0 *

 _____________               * *    * * * * *     * * * * *    * * 
 |_____º_____|
 |     _     |               * *    * * * * *     * * * * *    * * 
 |    |=|    |            /----------------------\         /------------pin GND
 |    |=|    |-Marron-GRD/   * *    * * * * *     0 * * * 0    * *
 |    |=|    |-Rojo-4.8v_a_6v--Vcc->-------------\         /------------pin Vcc 5V
 |  (=(0)=)  |-Amarillo-Signal *    * * * * *     0 * * * 0    * *
 |    |=|    |          \------------------------\         /------------pin 9
 |̣̣____|=|____|               * *    * * * * *     0 * * * 0    * *
      |=|
      				               * *    * * * * *     * * * * *    * * 
  
	       			               * 0    * * * * *     * * * * *    * * 
      				pin GND----------/
			      	               * 0    * * * * *     * * * * *    * 0 
				                       \---------------------------------/ - GND
		      		               0 *    * * * * *     * * * * *    * * 
				     pin 5v---------/
				                     0 *    * * * * *     * * * * *    0 * 
				                     \---------------------------------/   + 5v
				
 _____________
 |_____º_____|
 |     _     |
 |    |=|    |
 |    |=|    |--negro o marrón----GRD------------>
 |    |=|    |--rojo--4.8v_a_6v---Vcc------------>
 |  (=(0)=)  |--amarillo o blanco-Signal---------> pin 9
 |    |=|    |
 |̣̣____|=|____|
      |=|


Tienen 3 hilos de conexión, 5V    (rojo),
                            GND   (negro o marrón) 
                            Datos (amarillo o blanco). 

#include <Servo.h>
Servo servoMotor;
 
void setup()
{
  Serial.begin(9600);
  servoMotor.attach(9);
}
 
void loop() 
{
  servoMotor.write(0);
  Serial.println("Desplazamos a la posición 0º") ;
  delay(1000);
  
  servoMotor.write(90);
  Serial.println("Desplazamos a la posición 90º") ;
  delay(1000);
  
  servoMotor.write(180);
  Serial.println("Desplazamos a la posición 180º") ;
  delay(1000);

 
  servoMotor.write(90);
  Serial.println("Desplazamos a la posición 90º") ;
  delay(100);
//https://programarfacil.com
//Serial.println(String(distancia) + " mayor igual al limite minimo de 50 cm y menor al limite maximo de 150 cm.") ;
}


*/
#include <Servo.h>
 
Servo myservo;  // crea el objeto servo
 
int pos = 0;    // posicion del servo
 
void setup() {
   myservo.attach(9);  // vincula el servo al pin digital 9
}
 
void loop() {
   //varia la posicion de 0 a 180, con esperas de 15ms
   for (pos = 0; pos <= 180; pos += 1) 
   {
      myservo.write(pos);              
      delay(15);                       
   }
 
   //varia la posicion de 0 a 180, con esperas de 15ms
   for (pos = 180; pos >= 0; pos -= 1) 
   {
      myservo.write(pos);              
      delay(15);                       
   }
}
