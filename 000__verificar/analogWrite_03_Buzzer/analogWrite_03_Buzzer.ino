/*                  + -                               + -
                  * *    * * * * *     * * * * *    * * 
                   10 kOhm        Botton       /------------pin 2 Boton
                  * 0-ww-0 * * * 0-[#]-0 * * * 0    * *

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *  _  * * * * *    * * 
                   220 Ohm         / \         /------------pin 11
                  * 0-ww-0 * * * 0( # )0 * * * 0    * * 
                                   \_/
                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 

                  * 0    * * * * *     * * * * *    * * 
   pin GND----------/
                  * 0    * * * * *     * * * * *    * 0 
                    \---------------------------------/ - GND
                  0 *    * * * * *     * * * * *    * * 
   pin 5v---------/
                  0 *    * * * * *     * * * * *    0 * 
                  \---------------------------------/   + 5v

*/
/*
Buzzer Activo: genera un zumbido a frecuencia estable y preestablecida al conectarla a 5v
Buzzer Pasivo: genera un zumbido a frecuencia distintas dependiendo de la señal PWM(modulacion por ancho de pulso) ingresada
*/
int boton=2;
int salida_buzzer=11;
int nivel_buzzer=150;
int pitidos=0;
int contador=0;								 	//contador de las veces que el boton se preciona
int duracion_inicial=200; 					 	//duracion_inicial de zumbidos
int demora_inicial=1000;						//demora_inicial a zumbidoa
int demora=5000;
void setup(){
pinMode(boton,INPUT);
pinMode(salida_buzzer,OUTPUT);
}
void funcion_llamada_a_alarma() 				//funcion_llamada_a_alarma
{
	for(pitidos=0;pitidos<3;pitidos++)
	{
		digitalWrite(salida_buzzer,HIGH);
//		digitalWrite(salida_buzzer,nivel_buzzer);
//		nivel_buzzer 0 nivel_buzzer + 25
		delay(duracion_inicial);
		digitalWrite(salida_buzzer,LOW);
//		digitalWrite(salida_buzzer,0);
		delay(duracion_inicial);
	}
}
void funcion_silencio()//						funcion_silencio entre zumbidos 
{
//	digitalWrite(salida_buzzer,0);
	digitalWrite(salida_buzzer,LOW);
	delay(demora);
}
void funcion_cantidad_de_pulsaciones()//		funcion_cantidad_de_pulsaciones
{
	Serial.print("Boton presionado: ");
	Serial.print(contador);
	Serial.println(" veces");
	while(contador==3)
	{}
}
void loop()
{
	delay(demora_inicial);
	if(digitalRead(boton)==HIGH)
	{
		contador=contador+1;					//cantidad de pulsaciones del boton
		duracion_inicial=duracion_inicial-50;	//decremento de la duracion del pitido
		funcion_silencio(); 					//llamada a funcion_silencio entre alarmas consecutivas
	}
funcion_cantidad_de_pulsaciones(); 				//llamada a funcion_cantidad_de_pulsaciones
funcion_llamada_a_alarma(); 					//llamada a funcion_llamada_a_alarma
}
