/*                                     +  -                                         +  -          
*/
#include <SoftwareSerial.h>
 
SoftwareSerial ModuloHC05 (10, 11);  			//pin RX, pin TX
 
void setup() 
{
 Serial.begin(38400);        					//Inicializa puerto serie por hard
 ModuloHC05.begin(38400);    					//Inicializa puerto serie por soft
}
 
void loop() 
{
 char dato;
 if (ModuloHC05.available()) 
	 {              							//Llega algo por bluetooth?
	  dato=ModuloHC05.read();                   //Leer lo que llegó
	  Serial.write(dato);                       //Sacarlo a la terminal
	 }
 
 if (Serial.available ()) 
	 {                 							//Llega algo de la terminal?
	  dato=Serial.read();                       //Leer lo que llegó
	  ModuloHC05.write(dato);                   //Sacarlo al módulo
	  Serial.write (dato);                      //Eco en la terminal
	 }
}
