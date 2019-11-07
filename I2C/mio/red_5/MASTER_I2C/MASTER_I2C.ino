#include <Wire.h>


#define Kit_cant_max 6                     							// Numero de Kits (esclavos) esperados sobre bus
#define kit_inicio 2				                    		 	// Inicio de kit de sensores (master = 1)									eliminar en version alfa ya definido
#define kit_cant_sen_kit 5                     						// Numero de sensores (bytes) esperados de cada kit
#define demora_entre_kit 2500           		          			// Demora entre lecturas de kits
int kit_sensor[kit_cant_sen_kit];									// Array de sensores por cada kit

void setup()
{
  Serial.begin(9600);				                     			// Inicio serial. si no va a haber comunicacion desde BAires se debe ----- eliminar en version alfa ya definido  
/*  Serial.println("MASTER");
  Serial.print("Kit_cantidad_maxima: ");
  Serial.println(Kit_cant_max);
  Serial.print("kit_cant_sensores_en cada kit: ");
  Serial.println(kit_cant_sen_kit);
  Serial.println("*********MASTER*********");
*/  
  Wire.begin();                            							// Inicio I2C
}

void loop()
{//                            /-------------------------------------"2". eliminar en version alfa 
    for (int kit_ubic = kit_inicio; kit_ubic <= Kit_cant_max; kit_ubic++) 
    {
      Wire.requestFrom(kit_ubic, kit_cant_sen_kit);                 // lectura de cada kit
/*
      Serial.print("kit_ubic: ");                      				// confirmacion por serie. eliminar en version alfa 
      Serial.println(kit_ubic);                     				// confirmacion por serie. eliminar en version alfa 
      Serial.print("kit_cant_sen_kit: ");                      		// confirmacion por serie. eliminar en version alfa 
      Serial.println(kit_cant_sen_kit);                     		// confirmacion por serie. eliminar en version alfa 
*/      
    	if(Wire.available() == kit_cant_sen_kit) 
    	{
    			for (int sensor = 0; sensor < kit_cant_sen_kit; sensor++)
    			{
    				kit_sensor[sensor] = Wire.read();                      	// lectura de cada sensor de cada kit
    			}
          Serial.println("********MASTER*********"); 
    			Serial.print("Alerta_Kit: ");                      	// confirmacion por serie. eliminar en version alfa 
    			Serial.println(kit_sensor[0]);                     		// confirmacion por serie. eliminar en version alfa 
    			Serial.print("Data_sensor 1: ");                      	// confirmacion por serie. eliminar en version alfa 
    			Serial.println(kit_sensor[1]);                     		// confirmacion por serie. eliminar en version alfa 
    			Serial.print("Data_sensor 2: ");                      	// confirmacion por serie. eliminar en version alfa 
    			Serial.println(kit_sensor[2]);                     		// confirmacion por serie. eliminar en version alfa 
    			Serial.print("Data_sensor 3: ");                      	// confirmacion por serie. eliminar en version alfa 
    			Serial.println(kit_sensor[3]);                     		// confirmacion por serie. eliminar en version alfa 
    			Serial.print("Data_sensor 4: ");                      	// confirmacion por serie. eliminar en version alfa 
    			Serial.println(kit_sensor[4]);                     		// confirmacion por serie. eliminar en version alfa 
    /*
    			for (int j = 0; j < kit_cant_sen_kit; j++)
    			{
    				Serial.println(kit_sensor[j]);                       	// print nodes data   
    			}
    */
    		     
    		}
    }
    delay(demora_entre_kit);
    Serial.println("**************************************************************"); 
}
