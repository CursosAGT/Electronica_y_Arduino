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
                     +  -                                         +  -           
                     *  *    *  *  *  *  *       *  *  *  *  *    *  *        
									  * https://www.electronicwings.com/nodemcu/nodemcu-spi-with-arduino-ide
									  * https://nodemcu.readthedocs.io/en/master/modules/spi/#spisetmosi
									  * https://nodemcu.readthedocs.io/en/master/modules/spi/#spigetmiso
https://circuits4you.com/2019/01/03/arduino-spi-communication-example/
    SCK − This is the serial clock driven by the master.
    MOSI − This is the master output / slave input driven by the master.
    MISO − This is the master input / slave output driven by the master.
    SS − This is the slave-selection wire.

The following functions are used. You have to include the SPI.h.

    SPI.begin() − Initializes the SPI bus by setting SCK, MOSI, and SS to outputs, pulling SCK and MOSI low, and SS high.
    SPI.setClockDivider(divider) − To set the SPI clock divider relative to the system clock. On AVR based boards, the dividers available are 2, 4, 8, 16, 32, 64 or 128. The default setting is SPI_CLOCK_DIV4, which sets the SPI clock to one-quarter of the frequency of the system clock (5 Mhz for the boards at 20 MHz).
    Divider − It could be (SPI_CLOCK_DIV2, SPI_CLOCK_DIV4, SPI_CLOCK_DIV8, SPI_CLOCK_DIV16, SPI_CLOCK_DIV32, SPI_CLOCK_DIV64, SPI_CLOCK_DIV128).
    SPI.transfer(val) − SPI transfer is based on a simultaneous send and receive: the received data is returned in receivedVal.
    SPI.beginTransaction(SPISettings(speedMaximum, dataOrder, dataMode)) − speedMaximum is the clock, dataOrder(MSBFIRST or LSBFIRST), dataMode(SPI_MODE0, SPI_MODE1, SPI_MODE2, or SPI_MODE3).
We have four modes of operation in SPI as follows −

    Mode 0 (the default) − Clock is normally low (CPOL = 0), and the data is sampled on the transition from low to high (leading edge) (CPHA = 0).
    Mode 1 − Clock is normally low (CPOL = 0), and the data is sampled on the transition from high to low (trailing edge) (CPHA = 1).
    Mode 2 − Clock is normally high (CPOL = 1), and the data is sampled on the transition from high to low (leading edge) (CPHA = 0).
    Mode 3 − Clock is normally high (CPOL = 1), and the data is sampled on the transition from low to high (trailing edge) (CPHA = 1).
    SPI.attachInterrupt(handler) − Function to be called when a slave device receives data from the master.

*/

//Arduino sketch for NodeMCU Master SPI

#include<SPI.h>

char buff[]="Hello Slave\n";

void setup() {
 Serial.begin(9600); /* begin serial with 9600 baud */
 SPI.begin();  /* begin SPI */
}

void loop() {
 for(inti=0; i<sizeof buff; i++)  /* transfer buff data per second */
  SPI.transfer(buff[i]);
 delay(1000);  
}

 
//Arduino Sketch for Arduino Uno slave SPI

#include <SPI.h>

char buff [100];
volatile byte index;
volatile bool receivedone;  /* use reception complete flag */

void setup (void)
{
  Serial.begin (9600);
  SPCR |= bit(SPE);         /* Enable SPI */
  pinMode(MISO, OUTPUT);    /* Make MISO pin as OUTPUT */
  index = 0;
  receivedone = false;
  SPI.attachInterrupt();    /* Attach SPI interrupt */
}

void loop (void)
{
  if (receivedone)          /* Check and print received buffer if any */
  {
    buff[index] = 0;
    Serial.println(buff);
    index = 0;
    receivedone = false;
  }
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
  uint8_t oldsrg = SREG;
  cli();
  char c = SPDR;
  if (index <sizeof buff)
  {
    buff [index++] = c;
    if (c == '\n'){     /* Check for newline character as end of msg */
     receivedone = true;
    }
  }
  SREG = oldsrg;
}

/*
High Level Functions	The high level functions provide a send & receive API for half- and full-duplex mode.
spi.recv()				Receive data from SPI.
spi.send()				Send data via SPI in half-duplex mode.
spi.setup()				Set up the SPI configuration.
spi.set_clock_div()		Set the SPI clock divider.
Low Level Hardware Functions	The low level functions provide a hardware-centric API for application scenarios that need to exercise more complex SPI transactions.
spi.get_miso()			Extract data items from MISO buffer after spi.
spi.set_mosi()			Insert data items into MOSI buffer for spi.
spi.transaction()	
High Level Functions

The high level functions provide a send & receive API for half- and full-duplex mode. Sent and received data items are restricted to 1 - 32 bit length and each data item is surrounded by (H)SPI CS inactive.
spi.recv()
Receive data from SPI.

Syntax
* 	spi.recv(id, size[, default_data])
Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    size number of data items to be read
    default_data default data being sent on MOSI (all-1 if omitted)

Returns	String containing the bytes read from SPI.

Send data via SPI in half-duplex mode. Send & receive data in full-duplex mode.
Syntax
* HALFDUPLEX:  wrote = spi.send(id, data1[, data2[, ..., datan]])
* FULLDUPLEX:  wrote[, rdata1[, ..., rdatan]] = spi.send(id, data1[, data2[, ..., datan]])
Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    data data can be either a string, a table or an integer number.
    Each data item is considered with databits number of bits.

Returns

    wrote number of written bytes
    rdata received data when configured with spi.FULLDUPLEX
    Same data type as corresponding data parameter.

Example

=spi.send(1, 0, 255, 255, 255)
4       255     192     32      0
x = {spi.send(1, 0, 255, 255, 255)}
=x[1]
4
=x[2]
255
=x[3]
192
=x[4]
32
=x[5]
0
=x[6]
nil
=#x
5

_, _, x = spi.send(1, 0, {255, 255, 255})
=x[1]
192
=x[2]
32
=x[3]
0


spi.setup()

Set up the SPI configuration. Refer to Serial Peripheral Interface Bus for details regarding the clock polarity and phase definition.

Calling spi.setup() will route the HSPI signals to the related pins, overriding previous configuration and control by the gpio module. It is possible to revert any pin back to gpio control if its HSPI functionality is not needed, just set the desired gpio.mode() for it. This is recommended especially for the HSPI /CS pin function in case that SPI slave-select is driven from a different pin by gpio.write() - the SPI engine would toggle pin 8 otherwise.
Syntax

spi.setup(id, mode, cpol, cpha, databits, clock_div[, duplex_mode])
Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    mode select master or slave mode
        spi.MASTER
        spi.SLAVE - not supported currently
    cpol clock polarity selection
        spi.CPOL_LOW
        spi.CPOL_HIGH
    cpha clock phase selection
        spi.CPHA_LOW
        spi.CPHA_HIGH
    databits number of bits per data item 1 - 32
    clock_div SPI clock divider, f(SPI) = 80 MHz / clock_div, 1 .. n (0 defaults to divider 8)
    duplex_mode duplex mode
        spi.HALFDUPLEX (default when omitted)
        spi.FULLDUPLEX

Returns

Number: 1
Example

spi.setup(1, spi.MASTER, spi.CPOL_LOW, spi.CPHA_LOW, 8, 8)
-- we won't be using the HSPI /CS line, so disable it again
gpio.mode(8, gpio.INPUT, gpio.PULLUP)

spi.set_clock_div()

Set the SPI clock divider.
Syntax

old_div = spi.set_clock_div(id, clock_div)
Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    clock_div SPI clock divider, f(SPI) = 80 MHz / clock_div, 1 .. n

Returns

Number: Old clock divider
Example

old_div = spi.set_clock_div(1, 84) --drop to slow clock for slow device
spi.send(1, 0x0B, 0xFF)
spi.set_clock_div(1, old_div)

Low Level Hardware Functions

The low level functions provide a hardware-centric API for application scenarios that need to exercise more complex SPI transactions. The programming model is built up around the HW send and receive buffers and SPI transactions are initiated with full control over the hardware features.
spi.get_miso()

Extract data items from MISO buffer after spi.transaction().
Syntax

data1[, data2[, ..., datan]] = spi.get_miso(id, offset, bitlen, num)
string = spi.get_miso(id, num)

Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    offset bit offset into MISO buffer for first data item
    bitlen bit length of a single data item
    num number of data items to retrieve

Returns

num data items or string
See also

spi.transaction()
spi.set_mosi()

Insert data items into MOSI buffer for spi.transaction().
Syntax

spi.set_mosi(id, offset, bitlen, data1[, data2[, ..., datan]])
spi.set_mosi(id, string)

Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    offset bit offset into MOSI buffer for inserting data1 and subsequent items
    bitlen bit length of data1, data2, ...
    data data items where bitlen number of bits are considered for the transaction.
    string send data to be copied into MOSI buffer at offset 0, bit length 8

Returns

nil
See also

spi.transaction()
spi.transaction()

Start an SPI transaction, consisting of up to 5 phases:

    Command
    Address
    MOSI
    Dummy
    MISO

Syntax

spi.transaction(id, cmd_bitlen, cmd_data, addr_bitlen, addr_data, mosi_bitlen, dummy_bitlen, miso_bitlen)
Parameters

    id SPI ID number: 0 for SPI, 1 for HSPI
    cmd_bitlen bit length of the command phase (0 - 16)
    cmd_data data for command phase
    addr_bitlen bit length for address phase (0 - 32)
    addr_data data for command phase
    mosi_bitlen bit length of the MOSI phase (0 - 512)
    dummy_bitlen bit length of the dummy phase (0 - 256)
    miso_bitlen bit length of the MISO phase (0 - 512) for half-duplex.
    Full-duplex mode is activated with a negative value.

Returns

nil
