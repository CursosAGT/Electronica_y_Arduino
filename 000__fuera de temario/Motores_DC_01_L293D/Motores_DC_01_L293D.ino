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
                                       *  * | [ ]IOREF                 MISO/12[0] |-----------------------\
                                       *  * | [ ]RST                   MOSI/11[0]~|----------------------\|
                                       *  * | [ ]3V3    +---+               10[0]~|---------------------\||
                                       0------[0]5v    -| A |-               9[0]~| -------------\      |||
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *          |     |||
                                       *  0---[0]GND   -| D |-                    | *  *          |     |||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *          |     |||
                                       *  * |          -| I |-               6[0]~|--------------------\|||
                                       *  * | [ ]A0    -| N |-               5[0]~|-------------------\||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *          |   |||||
                                       *  * | [ ]A2     +---+           INT1/3[0]~| -----------------\|||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *          |  ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *          |  ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *          |  ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *          |  ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *          |  ||||||
                                       *  * \________________________/              *  *          |  ||||||       
                                                                                                  |  ||||||       
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *   Boton  |  ||||||       
                                         10 kOhm             Boton                                |  |||||| pin 9 
                                       *  0-ww-0  *  *  0  0--[#]--0  *  *  *  0----0  *          |  ||||||        
                                                         \---------------------------------------/   ||||||        
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *             ||||||        
                                          220 Ohm            Led 1              /-------------------/ ||||| pin 3 LED Rojo 
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *              |||||        
                                                                                                      |||||        
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *              |||||        
                                          220 Ohm            Led 2              /--------------------/ |||| pin 5 LED Verde
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *               ||||        
                                                                                                       ||||        
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *               ||||        
                                          220 Ohm            Led 3              /---------------------/ ||| pin 6 LED Azul 
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                |||        
                                                                                                        |||        
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                |||        
                                                                               /----------------------/ ||| pin 10 LED Azul  RGB
                                       *  *    *  *  *  *  *   |---0  *  *  *  0    *  *                 ||        
                                                               |                                         ||        
                                       *  *    *  *  *  *  *   |   *  *  *  *  *    *  *                 ||        
                                          220 Ohm          Led | RGB           /-----------------------/ || pin 11 LED Verde RGB
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  |        
                                                               |                                          |        
                                       *  *    *  *  *  *  *   |   *  *  *  *  *    *  *                  |        
                                                               |                /------------------------/   pin 12 LED Rojo RGB
                                       *  *    *  *  *  *  *   |---0  *  *  *  0    *  *                           
                                                                                                                   
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  * 
          Entrada In1-2(PWM)---------------------\         ---V----            /------------Entrada VCC L293D 5v PIN
          velocidad de motor I         *  *    *  0  *  *  o|01 16|o  *  *  *  0----0  * 
          PinPWM = 5                                        |     | 
                                       *  *    0  *  *  *  o|02 15|o  *  *  *  *    *  *            
          Señal B sentido Motor I /-----------/             |     |  
          Pin 7------------------/     *  *    *  0  *  *  o|03 14|o  *  *  *  *    *  *            
                                   /-------------/          |     |        
          Salida  1 -----|--------/    *  0----0  *  *  *  o|04 13|o  *  *  *  0--\ * *    
          Motor I       === Cap           GND               |     |                >--\GND 
          Salida  2 -----|--------\    *  0----0  *  *  *  o|05 12|o  *  *  *  0--/ * 0    
                                   \-------------\          |     |  
                                       *  *    *  0  *  *  o|06 11|o  *  *  *  *    *  *            
                                                            |     | 
          Señal A sentido Motor I      *  *    0  *  *  *  o|07 10|o  *  *  *  *    *  *            
          Pin 4 ------------------------------/             |     |  
                                       *  *    *  0  *  *  o|08 09|o  *  *  *  *    *  *            
          Entrada VCC alimenta    /--------------/          -------  
          motores (4,5 a 36V)    /                              
          FEM-------------------/      *  *    *  *  *  *  *       *  *  *  *  *    *  *                          
                                                                                                                  
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                           
                                                                                                                   
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0                           
                         pin GND---------/ \------------------------------------------/ - GND                      
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                           
                                                                                                                   
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *                           
                         pin 5v-------/ \------------------------------------------/+ 5v                           
                                                                                                                    


     
/*https://alonsodub.wordpress.com/2012/06/08/control-de-motor-cc-velocidad-y-direccion/
Control de velocidad y direccion de Motor CC

El motor de corriente continua (DC) es un dispositivo sencillo con dos cables conectados a los cepillos (contactos) que controlan el campo magnético de las bobinas que impulsa un núcleo metálico (inducido).
La dirección de rotación puede ser invertida por la inversión de la polaridad de la tensión en los contactos.
Los motores de corriente continua están disponibles en diferentes tamaños, pero aún el más pequeño (por ejemplo, motores de vibración usado en los teléfonos celulares) para el trabajo con Arduino se requiere un transistor o de otro tipo de control externo para proporcionar la corriente adecuada.
MEl integrado L293D incluye cuatro circuitos para manejar cargas de potencia media, en especial pequeños motores y cargas inductivas, con la capacidad de controlar corriente hasta 600 mA en cada circuito y una tensión entre 4,5 V a 36 V.
El integrado permite formar, entonces, dos puentes H completos, con los que se puede realizar el manejo de dos motores. En este caso el manejo será bidireccional, con frenado rápido y con posibilidad de implementar fácilmente el control de velocidad.

*	Basicamente es un doble puente en H que funciona utilizando transistores para conmutar
*	Se pueden controlar hasta 2 motores DC.
*	Proporciona 1A a los motores (en total) 
*	permite cambiar el sentido de giro.
Un punto a tomar en cuenta es el PWM (pulse-width modulation) es una técnica en la que se modifica el ciclo de trabajo de una señal periódica (unasenoidal o una cuadrada),
*  para controlar la cantidad de energía que se envía a una carga, la mayoría de los controladores sólo atacan el ajuste de velocidad y no consideran el torque el cual puede permitir el acelerar/desacelerar 
* a mayor precision. Normalmente entre mas grande y/o pesado sea un motor posee mayor torque. Una vez implementado y entendido la parte fisica podemos abordar la parte logica o software.


 '0' a '9' para la velocidad tomando a '0' apagado, '9' maxima velocidad
 '+' y '–' para asignar la direccion

*/

const int PinPWM = 5;										   // PWM se conecta al pin 1 del puente-H
const int senal_A = 7;										 // Señal A del puente-H
const int senal_B = 4;										 // Señal B del puente-H

void setup() 											        	//Inicializa y prepara los valores
{
	Serial.begin(9600); 									    //Abre el puerto serie a 9600 bps
	pinMode(senal_A, OUTPUT); 								//Configura senal_A como salida
	pinMode(senal_B, OUTPUT); 								//Configura senal_B como salida
	Serial.println("VELOCIDAD (0-9) "); 			//Instrucciones en la consola puerto serie
	Serial.println("SENTIDO + Horario o - Antiorario");    // de 0 a 9 y - o +
  
}
void loop() 												
{
if ( Serial.available()) 									  //Verifico si el puerto serie esta disponible?
	{
	char dato = Serial.read(); 								  //Ingreso dato en la variable tipo char desde puerto serial
  if(dato != '\n' )
  { 
	if(dato >= '0' && dato <= '9') 								//Si ch es un numero?
		{
			int velocidad = map (dato , '0', '9', 0, 255); 		//Re-mapea un numero desde un rango a otro '0′ a 0 '9' a 255
			analogWrite(PinPWM, velocidad); 			//Escribe el valor analogico PWM PinPWM - 5
			Serial.println(velocidad); 							
		}
	else if (dato == '+') 									    //Si el caracter es '+'
		{
			Serial.println("+");
			digitalWrite(senal_A,LOW);
			digitalWrite(senal_B,HIGH);
			digitalWrite(senal_A,LOW); 						//Escribe el valor senal_A high--\                                 /
			digitalWrite(senal_B,HIGH); 					//Escribe el valor senal_B Low---->--------->> motor avanza sentido Horario
		}
	else if (dato == '-')									    	//Si el caracter es –
		{
			Serial.println("-");
			digitalWrite(senal_A,HIGH); 					//Escribe el valor senal_A high--\                                  /
			digitalWrite(senal_B,LOW); 						//Escribe el valor senal_B Low---->--------->> motor avanza sentido Anti-Horario
		}
	else													            //Cualquier otro caracter es omitido
		{
			Serial.print("Unexpected character ");
			Serial.println(dato);
		}
	}
}
}
