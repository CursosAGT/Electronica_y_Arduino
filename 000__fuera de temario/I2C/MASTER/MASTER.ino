/*                                     +  -                                         +  -                      
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  * 		              
                                               _____                   +-------+                              
                                       +------(_PWR_)------------------|  USB  |-------+                      
                                       |      |     |                  |       |       |                      
                                       |      |     |                  +-------+       |                      
                                       |      |     |                      A5/SCL [ ]  |                      
                                       |       \___/                       A4/SDA [ ]  |                      
                                       |                                      AREF[ ]  |                      
                                       |                                       GND[ ]  |                      
                                       |  [ ] N/C                          SCK/13 [ ]  |
                                       |  [ ] IOREF                       MISO/12 [ ]  |
                                       |  [ ] RST                         MOSI/11 [ ]~ |
                                       |  [ ] 3V3       +---+                  10 [ ]~ |
                                +------|--[0] 5v       -| A |-                  9 [ ]~ |
                                |      |  [ ] GND      -| R |-                  8 [ ]  |
                                |  +---|--[0] GND      -| D |-                         |
                                |  |   |  [ ] Vin      -| U |-                  7 [ ]  |
                                |  |   |               -| I |-                  6 [ ]~ |
                                |  |   |  [ ] A0       -| N |-                  5 [ ]~ |
                                |  |   |  [ ] A1       -| O |-                  4 [ ]  |
                                |  |   |  [ ] A2       -|   |-            INT1/ 3 [ ]~ |
                                |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |
   ________     +-------------------------[0] A4/SDA     RST SCK MISO       TX> 1 [ ]  |
  / V E R  \    |   +---------------------[0] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |
  \________/    |   |           |  |   |                 [ ] [ ] [ ]                   |
                |   |           |  |   |  UNO_R3        GND MOSI 5V  _________________/ 
                |   |           |  |    \___________________________/                   
                |   |           |  |                                                    


                                |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |
   ________         +---------------------[0] A4/SDA     RST SCK MISO       TX> 1 [ ]  |
  / V E R  \    +-------------------------[0] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |
  \________/    |   |           |  |   |                 [ ] [ ] [ ]                   |
                |   |           |  |   |  UNO_R3        GND MOSI 5V  _________________/ 
                |   |           |  |    \___________________________/                   
                |   |           |  |                                                    
  

                |   |           |  +------0    *  *  *  *  *       *  *  *  *  *    *  *
                |   |           |                                                       
                |   |           +------0  *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   +----0----WWWW----0   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                +--------0----WWWW----0   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                          _____                   +-------+                              
                |   |                  +------(_PWR_)------------------|  USB  |-------+                      
                |   |                  |      |     |                  |       |       |                      
                |   |                  |      |     |                  +-------+       |                      
                |   |                  |      |     |                      A5/SCL [ ]  |                      
                |   |                  |       \___/                       A4/SDA [ ]  |                      
                |   |                  |                                      AREF[ ]  |                      
                |   |                  |                                       GND[ ]  |                      
                |   |                  |  [ ] N/C                          SCK/13 [ ]  |
                |   |                  |  [ ] IOREF                       MISO/12 [ ]  |
                |   |                  |  [ ] RST                         MOSI/11 [ ]~ |
                |   |                  |  [ ] 3V3       +---+                  10 [ ]~ |
                |   |           +------|--[0] 5v       -| A |-                  9 [ ]~ |
                |   |           |      |  [ ] GND      -| R |-                  8 [ ]  |
                |   |           |  +---|--[0] GND      -| D |-                         |
                |   |           |  |   |  [ ] Vin      -| U |-                  7 [ ]  |
                |   |           |  |   |               -| I |-                  6 [ ]~ |
                |   |           |  |   |  [ ] A0       -| N |-                  5 [ ]~ |
                |   |           |  |   |  [ ] A1       -| O |-                  4 [ ]  |
                |   |           |  |   |  [ ] A2       -|   |-            INT1/ 3 [ ]~ |
                |   |           |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |
                +-------------------------[0] A4/SDA     RST SCK MISO       TX> 1 [ ]  |
                |   +---------------------[0] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |
                |   |           |  |   |                 [ ] [ ] [ ]                   |
                |   |           |  |   |  UNO_R3        GND MOSI 5V  _________________/ 
                |   |           |  |    \___________________________/                   
                |   |           |  |                                                    
                |   |           |  +------0    *  *  *  *  *       *  *  *  *  *    *  *
                |   |           |                                                       
                |   |           +------0  *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                          _____                   +-------+                              
                |   |                  +------(_PWR_)------------------|  USB  |-------+                      
                |   |                  |      |     |                  |       |       |                      
                |   |                  |      |     |                  +-------+       |                      
                |   |                  |      |     |                      A5/SCL [ ]  |                      
                |   |                  |       \___/                       A4/SDA [ ]  |                      
                |   |                  |                                      AREF[ ]  |                      
                |   |                  |                                       GND[ ]  |                      
                |   |                  |  [ ] N/C                          SCK/13 [ ]  |
                |   |                  |  [ ] IOREF                       MISO/12 [ ]  |
                |   |                  |  [ ] RST                         MOSI/11 [ ]~ |
                |   |                  |  [ ] 3V3       +---+                  10 [ ]~ |
                |   |           +------|--[0] 5v       -| A |-                  9 [ ]~ |
                |   |           |      |  [ ] GND      -| R |-                  8 [ ]  |
                |   |           |  +---|--[0] GND      -| D |-                         |
                |   |           |  |   |  [ ] Vin      -| U |-                  7 [ ]  |
                |   |           |  |   |               -| I |-                  6 [ ]~ |
                |   |           |  |   |  [ ] A0       -| N |-                  5 [ ]~ |
                |   |           |  |   |  [ ] A1       -| O |-                  4 [ ]  |
                |   |           |  |   |  [ ] A2       -|   |-            INT1/ 3 [ ]~ |
                |   |           |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |
                +-------------------------[0] A4/SDA     RST SCK MISO       TX> 1 [ ]  |
                |   +---------------------[0] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |
                |   |           |  |   |                 [ ] [ ] [ ]                   |
                |   |           |  |   |  UNO_R3        GND MOSI 5V  _________________/ 
                |   |           |  |    \___________________________/                   
                |   |           |  |                                                    
                |   |           |  +------0    *  *  *  *  *       *  *  *  *  *    *  *
                |   |           |                                                       
                |   |           +------0  *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                          _____                   +-------+                              
                |   |                  +------(_PWR_)------------------|  USB  |-------+                      
                |   |                  |      |     |                  |       |       |                      
                |   |                  |      |     |                  +-------+       |                      
                |   |                  |      |     |                      A5/SCL [ ]  |                      
                |   |                  |       \___/                       A4/SDA [ ]  |                      
                |   |                  |                                      AREF[ ]  |                      
                |   |                  |                                       GND[ ]  |                      
                |   |                  |  [ ] N/C                          SCK/13 [ ]  |
                |   |                  |  [ ] IOREF                       MISO/12 [ ]  |
                |   |                  |  [ ] RST                         MOSI/11 [ ]~ |
                |   |                  |  [ ] 3V3       +---+                  10 [ ]~ |
                |   |           +------|--[0] 5v       -| A |-                  9 [ ]~ |
                |   |           |      |  [ ] GND      -| R |-                  8 [ ]  |
                |   |           |  +---|--[0] GND      -| D |-                         |
                |   |           |  |   |  [ ] Vin      -| U |-                  7 [ ]  |
                |   |           |  |   |               -| I |-                  6 [ ]~ |
                |   |           |  |   |  [ ] A0       -| N |-                  5 [ ]~ |
                |   |           |  |   |  [ ] A1       -| O |-                  4 [ ]  |
                |   |           |  |   |  [ ] A2       -|   |-            INT1/ 3 [ ]~ |
                |   |           |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |
                +-------------------------[0] A4/SDA     RST SCK MISO       TX> 1 [ ]  |
                |   +---------------------[0] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |
                |   |           |  |   |                 [ ] [ ] [ ]                   |
                |   |           |  |   |  UNO_R3        GND MOSI 5V  _________________/ 
                |   |           |  |    \___________________________/                   
                |   |           |  |                                                    
                |   |           |  +------0    *  *  *  *  *       *  *  *  *  *    *  *
                |   |           |                                                       
                |   |           +------0  *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                V   V                 *   *    *  *  *  *  *       *  *  *  *  *    *  *   
                * 
I²C  --------------alternativa SPI


-*-*-*-*-*-*-
i2c.address()	Setup I²C address and read/write mode for the next transfer.
		Syntax
		i2c.address(id, device_addr, direction)
		Parameters
			• id always 0 
			• device_addr 7-bit device address, remember that in I²C device_addr represents the upper 7 bits followed by a single direction bit 
			• direction i2c.TRANSMITTER for writing mode , i2c. RECEIVER for reading mode 
		Returns			true if ack received, false if no ack received.
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
i2c.write()		Write data to I²C bus. Data items can be multiple numbers, strings or Lua tables.
		Syntax
		i2c.write(id, data1[, data2[, ..., datan]])
		Parameters
			• id always 0 
			• data data can be numbers, string or Lua table. 
		Returns			number number of bytes written
		Example
		i2c.write(0, "hello", "world")
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
i2c.read()		Read data for variable number of bytes.
		Read data for variable number of bytes.
		Syntax
		i2c.read(id, len)
		Parameters
			• id always 0 
			• len number of data bytes 
		Returns			string of received data
		Example
		id  = 0
		sda = 1
		scl = 2

		-- initialize i2c, set pin1 as sda, set pin2 as scl
		i2c.setup(id, sda, scl, i2c.SLOW)

		-- user defined function: read from reg_addr content of dev_addr
		function read_reg(dev_addr, reg_addr)
			i2c.start(id)
			i2c.address(id, dev_addr, i2c.TRANSMITTER)
			i2c.write(id, reg_addr)
			i2c.stop(id)
			i2c.start(id)
			i2c.address(id, dev_addr, i2c.RECEIVER)
			c = i2c.read(id, 1)
			i2c.stop(id)
			return c
		end

		-- get content of register 0xAA of device 0x77
		reg = read_reg(0x77, 0xAA)
		print(string.byte(reg))
-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
i2c.setup()		Initialize the I²C module.
* 
		Initialize the I²C module.
		Syntax
		i2c.setup(id, pinSDA, pinSCL, speed)
		Parameters
			• id always 0 
			• pinSDA 1~12, IO index 
			• pinSCL 1~12, IO index 
			• speed only i2c.SLOW supported 
		Returns			speed the selected speed
-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
i2c.start()		Send an I²C start condition.
		Syntax
		i2c.start(id)
		Parameters
		id always 0
		Returns			nil
-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
i2c.stop()		Send an I²C stop condition.
		Syntax
		i2c.stop(id)
		Parameters
		id always 0
		Returns			nil

*/  
#include <Wire.h>// I²C  --------------alternativa SPI


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
