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
    * 
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
#include <SPI.h>
//https://github.com/deeplyembeddedWP/SPI_Comm_NodeMCU_ArduinoUNO
volatile boolean process_it;                    //Flag for checking if the data is recieved from Master i.e. ESP8266
byte a;                                         //Byte to store the processed data

void setup (void)
{
	Serial.begin (115200);                        //Set UART baug rate to 115200
	SPCR |= bit (SPE);                            //Configure ATMEGA328P/Arduino in slave mode
	pinMode(MISO, OUTPUT);                        //Configure MISO as output, SlaveOut
	process_it = false;                           //Initialize flag to FALSE
	SPI.attachInterrupt();                        //Enable interrupts for SPI--> You can do that like this too /*SPCR |= bit (SPIE)*/

}  


// SPI interrupt routine
ISR (SPI_STC_vect)
{
	byte c = SPDR;                                //Grab the data byte from the SPI Data Register (SPDR)
	a = c;                                        //Put the byte into a temporary variable for processing
	SPDR = c*2;                                   //process the data byte and put it back into the SPDR for the Master to read it
	process_it = true;                            //Set the Flag  as TRUE

}  


void loop (void)
{
	if (process_it)                               //Check if the data has been processed 
	{
		Serial.println("Recieved\r\n");             //UART - Notify if recived a byte from master
		process_it = false;                         //Set the Flag to False
	}  
} 
