/*                   +  -       +  -
                     *  *    *  *  *  *  *       *  *  *  *  *    *  *           
                     *  *    *  *  *  *  *       *  *  *  *  *    *  *           

Master generates this clock for the
communication, which is used by slave.
SCLK (Serial Clock)
                     *  *    *  *  *  *  * +======+ *  *  *  *    *  *           
                     *  *    *  * +--------|| USB||--------+ *    *  *           
                     *  *    *  * | ( )    \\    //    ( ) | *    *  *        voltage divider 5 V -> 3.3 V !!!    
                +---------------o | [o] D13 +====+ D12 [o] |o---------------+ GPI16  MISO (Master In Slave Out)          Master receives data and slave transmits data through this pin.     
                |    *  *    *  * | [ ] 3V3        D11 [o] |o--------------+| GPI15  MOSI (Master Out Slave In)          Master transmits data and slave receives data through this pin.         
                |    *  *    *  * | [ ] REF    ^   D10 [o] |o-------------+|| GPI14  CS (Chip Select)   Master can select slave device through this pin to start communication with it.      
                |    *  *    *  * | [ ] A0    / \  D9  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A1   /   \ D8  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A2   \   / D7  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A3    \ /  D6  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A4  NANO   D5  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A5  =====  D4  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A6  |XXX|  D3  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] A7  =====  D2  [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] 5v   ºººº  GND [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] RST  ºººº  RST [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] GND         RX [ ] | *    *  *    |||    
                |    *  *    *  * | [ ] VIM()()()() TX [ ] | *    *  *    |||    
                |    *  *    *  * | ( )   []()()() ICPS( ) | *    *  *    |||    
                |    *  *    *  * +------------------------+ *    *  *    |||    
                |    *  *    *  *  *  *  *       *  *  *  *  *    *  *    |||    
                |              voltage divider 5 V -> 3.3 V !!!           |||    
                |  +------------------------------------------------------+||    
                | +--------------------------------------------------------+|    
                |+----------------------------------------------------------+    
                ||||           voltage divider 5 V -> 3.3 V !!!                  
                |||| *  *    *  *  *  *  *       *  *  *  *  *    *  *           
                |||| *  *    *  *  *  *  *+-----+*  *  *  *  *    *  *           
                |||| *  *    * /----------| USB |----------\ *    *  *           
                |||| *  *    *|(_)Flsh[o] +-----+ [o]Rst(_) |*    *  *           
                |||| *  *    *|[ ] 3v3              Vin [ ] |*    *  *           
                |||| *  *    *|[ ] GND              GND [ ] |*    *  *           
          GPI01 |||| *  *    *|[ ] TX      NODE     Rst [ ] |*    *  *           
          GPI03 |||| *  *    *|[ ] RX                En [ ] |*    *  *           
H CS      GPI15 |||+---------o|[o] D8       MCU     3v3 [ ] |*    *  *       CS (Chip Select)   Master can select slave device through this pin to start communication with it.      
H MOSI    GPI13 ||+----------o|[o] D7       1.0     GND [ ] |*    *  *       MOSI (Master Out Slave In)          Master transmits data and slave receives data through this pin.      
H MISO    GPI12 |+-----------o|[o] D6   __________  CLK [ ] |*    *  *       MISO (Master In Slave Out)          Master receives data and slave transmits data through this pin.       
HS Clock  GPI14 +------------o|[o] D5  |         |  SD0 [ ] |*    *  *       SCLK (Serial Clock)Master generates this clock for the communication, which is used by slave.   Only master can initiate serial clock.
            GND      *  0----*|[ ] GND |    ESP  |  CMD [ ] |*    *  *           
            3v3      0-------0|[ ] 3v3 |   8266  |  SD1 [ ] |*    *  *       MISO voltage divider 5 V -> 3.3 V !!!     
          GPI02      *  *    *|[ ] D4  |   WiFi  |  SD2 [ ] |*    *  *           
    Flash GPI00      *  *    *|[ ] D3  |         |  SD3 [ ] |*    *  *           
          GPI04      *  *    *|[ ] D2  |---------|  RSV [ ] |*    *  *           
          GPI05      *  *    *|[ ] D1  || __ __ ||  RSV [ ] |*    *  *           
          GPI16      *  *    *|[ ] D0  ||_||_||_||   A0 [ ] |0    *  *           
                     *  *    *|(_)     |_________|      (_) |*    *  *           
                     *  *    *\----------------------------/ *    *  *           
                     +  -       +  -           
                     *  *    *  *  *  *  *       *  *  *  *  *    *  *        
* https://www.electronicwings.com/nodemcu/nodemcu-spi-with-arduino-ide
* https://nodemcu.readthedocs.io/en/master/modules/spi/#spisetmosi
* https://nodemcu.readthedocs.io/en/master/modules/spi/#spigetmiso
* 
Nombre              Alias          Pin (en Arduino Uno o Nano)      Descripcion
VCC             +3.3 … 5 Volt
GND             Ground     Ground
SCLK            CLK/SCK/SCLK      D13       (hardware)       Clock (SPI)
MISO            MISO/SDO/DOUT     D12       (hardware)       Master In Slave Out (SPI)
MOSI            MOSI/SDI/DIN      D11       (hardware)       Master Out Slave In (SPI)
SS              S/CS/SDA/         D10       (hardware, solo en esclavo)  Slave/Chip Select (SPI)
RES             RST/RES/REST      D9        (variable, se fija por software)  Controller Reset
RS              RS/DC             D8        (variable, se fija por software)  Mode: Command/Data
*/  
//I²C  --------------alternativa SPI
//Arduino sketch for NodeMCU Master SPI
//https://www.electronicwings.com/nodemcu/nodemcu-spi-with-arduino-ide
#include<SPI.h>

char buff[]="Hello Slave\n";

void setup() {
 Serial.begin(9600); /* begin serial with 9600 baud */
 SPI.begin();  /* begin SPI */
}

void loop() {
 for(int i=0; i<sizeof buff; i++)  /* transfer buff data per second */
  SPI.transfer(buff[i]);
 delay(1000);  
}




/*

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
  3. Data Mode = SPI MODE0* /
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
*/
