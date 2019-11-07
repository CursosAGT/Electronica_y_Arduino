/*                        +  -                                        +  -
                          *  *    *  *  *  *  *      *  *  *  *  *    *  * 		    
                          *  *    *  *  *  *  *      *  *  +-----+    *  *          
                          *  * +----[PWR]------------------| USB |--+ *  *          
                          *  * |                           +-----+  | *  *          
                          *  * |         GND/RST2 [ ][ ]            | *  *          
                          *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *          
                          *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *          
                          *  * |                            AREF[ ] | *  *          
                          *  * |                             GND[ ] | *  *          
                          *  * | [ ]N/C                   SCK/13[ ] | *  *          
                          *  * | [ ]IOREF                MISO/12[ ] | *  *          
                          *  * | [ ]RST                  MOSI/11[ ]~| *  *          
                          *  * | [ ]3V3    +---+              10[ ]~| *  *          
                          0------[0]5v    -| A |-              9[ ]~| *  *          
                          *  * | [ ]GND   -| R |-              8[ ] | *  *          
                          *  0---[0]GND   -| D |-                   | *  *          
                          *  * | [ ]Vin   -| U |-              7[ ] | *  *          
                          *  * |          -| I |-              6[ ]~| *  *          
                Pull Up   *  * | [ ]A0    -| N |-              5[ ]~| *  *          
        /----0----WWWW----0  * | [ ]A1    -| O |-              4[ ] | *  *          
       |                  *  * | [ ]A2     +---+          INT1/3[ ]~| *  *          
       |                  *  * | [ ]A3                    INT0/2[ ] | *  *          
       +-------------------------[0]A4/SDA  RST SCK MISO    TX>1[ ] | *  *          
       |   ----------------------[0]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *          
       |  /               *  * |            [ ] [ ] [ ]             | *  *          
       |  +-----0-WWWW----0  * |  UNO_R3    GND MOSI 5V ____________/ *  *          
       |  |     Pull Up   *  * \______________________/               *  *          
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  * 	
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               +  -                                        +  -
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  * 		    
       |  |               *  *    *  *  *  *  *      *  *  +-----+    *  *          
       |  |               *  * +----[PWR]------------------| USB |--+ *  *          
       |  |               *  * |                           +-----+  | *  *          
       |  |               *  * |         GND/RST2 [ ][ ]            | *  *          
       |  |               *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *          
       |  |               *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *          
       |  |               *  * |                            AREF[ ] | *  *          
       |  |               *  * |                             GND[ ] | *  *          
       |  |               *  * | [ ]N/C                   SCK/13[ ] | *  *          
       |  |               *  * | [ ]IOREF                MISO/12[ ] | *  *          
       |  |               *  * | [ ]RST                  MOSI/11[ ]~| *  *          
       |  |               *  * | [ ]3V3    +---+              10[ ]~| *  *          
       |  |               0------[0]5v    -| A |-              9[ ]~| *  *          
       |  |               *  * | [ ]GND   -| R |-              8[ ] | *  *          
       |  |               *  0---[0]GND   -| D |-                   | *  *          
       |  |               *  * | [ ]Vin   -| U |-              7[ ] | *  *          
       |  |               *  * |          -| I |-              6[ ]~| *  *          
       |  |               *  * | [ ]A0    -| N |-              5[ ]~| *  *          
       |  |               *  * | [ ]A1    -| O |-              4[ ] | *  *          
       |  |               *  * | [ ]A2     +---+          INT1/3[ ]~| *  *          
       |  |               *  * | [ ]A3                    INT0/2[ ] | *  *          
       +-------------------------[0]A4/SDA  RST SCK MISO    TX>1[ ] | *  *          
       |  +----------------------[0]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *          
       |  |               *  * |            [ ] [ ] [ ]             | *  *          
       |  |               *  * |  UNO_R3    GND MOSI 5V ____________/ *  *          
       |  |               *  * \______________________/               *  *          
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  * 	
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               
       |  |               +  -                                        +  -
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  * 		    
       |  |               *  *    *  *  *  *  *      *  *  +-----+    *  *          
       |  |               *  * +----[PWR]------------------| USB |--+ *  *          
       |  |               *  * |                           +-----+  | *  *          
       |  |               *  * |         GND/RST2 [ ][ ]            | *  *          
       |  |               *  * |       MOSI2/SCK2 [ ][ ]  A5/SCL[ ] | *  *          
       |  |               *  * |          5V/MISO2[ ][ ]  A4/SDA[ ] | *  *          
       |  |               *  * |                            AREF[ ] | *  *          
       |  |               *  * |                             GND[ ] | *  *          
       |  |               *  * | [ ]N/C                   SCK/13[ ] | *  *          
       |  |               *  * | [ ]IOREF                MISO/12[ ] | *  *          
       |  |               *  * | [ ]RST                  MOSI/11[ ]~| *  *          
       |  |               *  * | [ ]3V3    +---+              10[ ]~| *  *          
       |  |               0------[0]5v    -| A |-              9[ ]~| *  *          
       |  |               *  * | [ ]GND   -| R |-              8[ ] | *  *          
       |  |               *  0---[0]GND   -| D |-                   | *  *          
       |  |               *  * | [ ]Vin   -| U |-              7[ ] | *  *          
       |  |               *  * |          -| I |-              6[ ]~| *  *          
       |  |               *  * | [ ]A0    -| N |-              5[ ]~| *  *          
       |  |               *  * | [ ]A1    -| O |-              4[ ] | *  *          
       |  |               *  * | [ ]A2     +---+          INT1/3[ ]~| *  *          
       \  |               *  * | [ ]A3                    INT0/2[ ] | *  *          
        -------------------------[0]A4/SDA  RST SCK MISO    TX>1[ ] | *  *          
           \---------------------[0]A5/SCL  [ ] [ ] [ ]     RX<0[ ] | *  *          
                          *  * |            [ ] [ ] [ ]             | *  *          
                          *  * |  UNO_R3    GND MOSI 5V ____________/ *  *          
                          *  * \______________________/               *  *          
                          *  *    *  *  *  *  *      *  *  *  *  *    *  * 	
*/  
#include <Wire.h>

#define kit_direccion 5  								   // Kit Numero
#define kit_cant_sen_kit 5								 // Cantidad de sensores por kit

byte kit_sensor[kit_cant_sen_kit];

void setup()
{

  Serial.begin(9600);  
/*  
  Serial.println("kit");
  Serial.print("kit_direccion: ");
  Serial.println(kit_direccion);
  Serial.print("kit_cant_sen_kit: ");
  Serial.println(kit_cant_sen_kit);
*/  
  Serial.println("********SLAVE*********");

  Wire.begin(kit_direccion);  								// levanto I2C
  Wire.onRequest(pool_datos);								  // Escucha al Master
}

void loop()
{ 
  delay(250);																	// demora para que levane i2c
/*																				// activar en version alfa cuando esten definidas las librerias y la posicion de cada sensor
	for (int sensor = 0; sensor < kit_cant_sen_kit; sensor++)
	{
		if (sensor <=13)
		{
			kit_sensor[sensor] = digitalRead(sensor);                      		// lectura de cada sensor digital de cada kit	
		//     pasar por cada libreria de cada sensor digital*********************************************************
		// select case una vez definido cada sensor								ojo, dht11 usa el byte para humedad y temperatura---- son 2 lecturas
		}
		else
		{
			kit_sensor[sensor] = analogRead(sensor)/4;                      	// lectura de cada sensor analogico de cada kit
		//     pasar por cada libreria de cada sensor analogico*********************************************************
		}
	}
 */
  kit_sensor[0] = kit_direccion; 							//  Reemplazar en alfa por estado de sensores (binario)
  kit_sensor[1] = analogRead(A0)/4;							//	A0 lectura del sensor (paso de 10 a 8 bits). eliminar en version alfa 
  kit_sensor[2] = analogRead(A1)/4;							//	A1 lectura del sensor (paso de 10 a 8 bits). eliminar en version alfa 
  kit_sensor[3] = analogRead(A2)/4;							//	A2 lectura del sensor (paso de 10 a 8 bits). eliminar en version alfa 
  kit_sensor[4] = analogRead(A3)/4;							//	A3 lectura del sensor (paso de 10 a 8 bits). eliminar en version alfa 

//  kit_sensor[5] = analogRead(A2)/4;							//	A5 Usado por i2c
//  kit_sensor[6] = analogRead(A3)/4;							//	A6 Usado por i2c
/*
    for (int i=0; i<=largoLectura; i++){
      char letraActual=lectura.charAt(i);
      if (isDigit(letraActual)==false){
        Serial.println("Ingreso fallido");
        modo=0;
        loop();
        break;
      }

*/
}

void pool_datos()
{
  Wire.write(kit_sensor,kit_cant_sen_kit);      			// escritura de cada kit  
  Serial.print("Data_sensor 1: ");                      	// confirmacion por serie. eliminar en version alfa 
  Serial.println(kit_sensor[1]);                     		// confirmacion por serie. eliminar en version alfa 
  Serial.print("Data_sensor 2: ");                      	// confirmacion por serie. eliminar en version alfa 
  Serial.println(kit_sensor[2]);                     		// confirmacion por serie. eliminar en version alfa 
  Serial.print("Data_sensor 3: ");                      	// confirmacion por serie. eliminar en version alfa 
  Serial.println(kit_sensor[3]);                     		// confirmacion por serie. eliminar en version alfa 
  Serial.print("Data_sensor 4: ");                      	// confirmacion por serie. eliminar en version alfa 
  Serial.println(kit_sensor[4]);                     		// confirmacion por serie. eliminar en version alfa   
  Serial.println("********SLAVE*********");
}
