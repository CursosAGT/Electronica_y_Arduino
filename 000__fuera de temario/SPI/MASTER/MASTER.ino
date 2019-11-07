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
                |   +----0----WWWW----0   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                                                                   
                +--------0----WWWW----0   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *
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
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *          
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *          
                |   |                 *   *    *  *  *  *  *       *  *  *  *  *    *  *          

   /*                        +  -                                        +  -
                          *  *    *  *  *  *  *      *  *  *  *  *    *  *           
                                               |----|                                
                          *  *    * /----------| USB|----------\ *    *  *           
                                   |  (_)  [o] |____| [o]    (_)|                    
                          *  *    *| o 3v3  |          |  Vin o |*    *  *           
                                   |        Flash     Rst       |                    
                          *  *    *| o GND                GND o |*    *  *           
                                   |           N                |                    
               GPI01      *  *    *| o TX       O         Rst o |*    *  *           
                                   |             D              |                    
               GPI03      *  *    *| o RX         E        En o |*    *  *           
                                   |            M               |                    
               GPI15      *  *    *| o D8        C        3v3 o |*    *  *           
                                   |              U             |                    
               GPI13      *  *    0| o D7                 GND o |*    *  *           
                                   |            1.0             |                    
               GPI12      *  *    0| o D6   ___________   CLK o |*    *  *  SDCLK             
     /---------------------------/ |       |           |        |                    https://nodemcu.readthedocs.io/en/master/modules/spi/#spisetup
    |          GPI14      *  *    0| o D5  |           |  SD0 o |*    *  *  SDD0     
    | /--------------------------/ |       |           |        |                    
    ||           GND      *  0----0| o GND |    ESP    |  CMD o |*    *  *  SDCMD    
    ||                             |       |           |        |                    
    ||           3v3      0  *    0| o 3v3 |   8266    |  SD1 o |*    *  *  SDD1    
    ||                     \-----/ |       |           |        |                    
    ||         GPI02      *  *    0| o D4  |   WiFi    |  SD2 o |*    *  *  SDD2     
    ||                             |       |           |        |                    
    ||   Flash GPI00      *  *    0| o D3  |           |  SD3 o |*    *  *  SDD3     
    ||                             |       |           |        |                    
    ||         GPI04      *  *    0| o D2  |-----------|  RSV o |*    *  *       
    ||                             |       |[X]     | ||        |                    
    ||         GPI05      *  *    0| o D1  || __ __ | ||  RSV o |*    *  *           
    ||/--------------------------/ |       || || || | ||        |                    
    |||        GPI16      *  *    0| o D0  || || || | ||   A0 o |0    *  *           
    ||| /------------------------/ |       ||_||_||_|_||        | \------------\AnalogRead  
    ||||                  *  *    *| (_)   |___________|    (_) |*    *  *      |    
    ||||                           \----------------------------/               |    
    ||||                  *  *    *  *  *  *  *      *  *  *  *  *    *  *      |   
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
#include <SPI.h>// SPI   --------------alternativa I²C

#define CS 15                 //define chip select line for manual control           
//https://github.com/deeplyembeddedWP/SPI_Comm_NodeMCU_ArduinoUNO
void setup() 
{
	pinMode(CS,OUTPUT);         //configure the line as output
	Serial.begin(115200);       //Set UART baud rate
	digitalWrite(CS,HIGH);      //Initialize the CS line to HIGH
	SPI.begin();                //Initialize the SPI module--> configures the MOSI, MISO and CLOCK lines

	/*Configure the SPI bus as follows
  1. SPI bus speed = 1 MHz
  2. Data Out = From MSB bit ---> To LSB bit
  3. Data Mode = SPI MODE0*/
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));      

}

void loop() 
{
	byte spi_dat;

	digitalWrite(CS,LOW);           //Pull CS Line Low
	SPI.transfer(0x02);             //Send a byte (0x02) to the slave i.e. Arduino UNO 
	digitalWrite(CS,HIGH);          //Pull CS Line High

	delayMicroseconds(10);          //Give some time for the slave to process/do something with the recived data

	digitalWrite(CS,LOW);           //Pull CS Line Low
	spi_dat = SPI.transfer(0x00);   //Recieve the processed data byte from the slave
	digitalWrite(CS,HIGH);          //Pull CS Line High
	Serial.println("Processed Data Recieved from Slave is: "); 
	Serial.print(spi_dat);          //UART - Print the data recieved from the slave
	Serial.println("\r\n");
	delay(1000);                     //Delay of 1s
}
