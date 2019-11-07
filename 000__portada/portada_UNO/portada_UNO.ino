/* 
                             +-----+
+----[PWR]-------------------| USB |--+ 
|                            +-----+  | 
|         GND/RST2  [ ][ ]            | 
|       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] | 
|          5V/MISO2 [ ][ ]  A4/SDA[ ] | 
|                             AREF[ ] | 
|                              GND[ ] | 
| [ ]N/C                    SCK/13[ ] | 
| [ ]IOREF                 MISO/12[ ] | 
| [ ]RST                   MOSI/11[ ]~| 
| [ ]3V3    +---+               10[ ]~| 
| [ ]5v    -| A |-               9[ ]~| 
| [ ]GND   -| R |-               8[ ] | 
| [ ]GND   -| D |-                    | 
| [ ]Vin   -| U |-               7[ ] | 
|          -| I |-               6[ ]~| 
| [ ]A0    -| N |-               5[ ]~| 
| [ ]A1    -| O |-               4[ ] | 
| [ ]A2     +---+           INT1/3[ ]~| 
| [ ]A3                     INT0/2[ ] | 
| [ ]A4/SDA  RST SCK MISO     TX>1[ ] | 
| [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] | 
|            [ ] [ ] [ ]              | 
|  UNO_R3    GND MOSI 5V  ____________/ 
 \_______________________/              




       |  |               +  -                                        +  -
       |  |               *  *    *  *  *  *  *      *  *  *  *  *    *  * 		    
       |  |               *  *    *  *  *  *  * +======+ *  *  *  *    *  *          
       |  |               *  *    *  * +--------|| USB||--------+ *    *  *          
       |  |               *  *    *  * | ( )    \\    //    ( ) | *    *  *          
       |  |               *  *    *  * | [ ] D13 +====+ D12 [ ] | *    *  *          
       |  |               *  *    *  * | [ ] 3V3        D11 [ ] | *    *  *          
       |  |               *  *    *  * | [ ] REF    ^   D10 [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A0    / \  D9  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A1   /   \ D8  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A2   \   / D7  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A3    \ /  D6  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A4  NANO   D5  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A5  =====  D4  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A6  |XXX|  D3  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] A7  =====  D2  [ ] | *    *  *          
       |  |               *  *    *  * | [ ] 5v   ºººº  GND [ ] | *    *  *          
       |  |               *  *    *  * | [ ] RST  ºººº  RST [ ] | *    *  *          
       |  |               *  *    *  * | [ ] GND         RX [ ] | *    *  *          
       |  |               *  *    *  * | [ ] VIM()()()() TX [ ] | *    *  *          
       |  |               *  *    *  * | ( )   []()()() ICPS( ) | *    *  *          
       |  |               *  *    *  * +------------------------+ *    *  *          
       |  |               *  *    *  *  *  *  *       *  *  *  *  *    *  * 		 
                          *  *    *  *  *  *  *       *  *  *  *  *    *  * 
                          *  *    *  *  *  *  *       *  *  *  *  *    *  *           
                                               +-----+                                
                          *  *    * /----------| USB |----------\ *    *  *           
                                   |(_)Flsh[o] +-----+ [o]Rst(_) |*    *  *                    
                          *  *    *|[ ] 3v3              Vin [ ] |*    *  *           
                          *  *    *|[ ] GND              GND [ ] |*    *  *           
               GPI01      *  *    *|[ ] TX      NODE     Rst [ ] |*    *  *           
               GPI03      *  *    *|[ ] RX                En [ ] |*    *  *           
               GPI15      *  *    *|[ ] D8       MCU     3v3 [ ] |*    *  *           
               GPI13      *  *    *|[ ] D7       1.0     GND [ ] |*    *  *           
               GPI12      *  *    *|[ ] D6   __________  CLK [ ] |*    *  *  SDCLK    https://nodemcu.readthedocs.io/en/master/modules/spi/#spisetup         
               GPI14      *  *    *|[ ] D5  |         |  SD0 [ ] |*    *  *  SDD0     
                 GND      *  0----*|[ ] GND |    ESP  |  CMD [ ] |*    *  *  SDCMD    
                 3v3      0-------0|[ ] 3v3 |   8266  |  SD1 [ ] |*    *  *  SDD1    
               GPI02      *  *    *|[ ] D4  |   WiFi  |  SD2 [ ] |*    *  *  SDD2     
         Flash GPI00      *  *    *|[ ] D3  |         |  SD3 [ ] |*    *  *  SDD3     
               GPI04      *  *    *|[ ] D2  |---------|  RSV [ ] |*    *  *       
               GPI05      *  *    *|[ ] D1  || __ __ ||  RSV [ ] |*    *  *           
               GPI16      *  *    *|[ ] D0  ||_||_||_||   A0 [ ] |0    *  *          
                          *  *    *|(_)     |_________|      (_) |*    *  *          
                          *  *    *\----------------------------/*    *  *        
                          +  -                                         +  -                      
                          *  *    *  *  *  *  *       *  *  *  *  *    *  * 		              
                                               _____                   +-------+                              
                                       +------(_PWR_)------------------|  USB  |-------+                      
                                       |      |     |                  |       |       |                      
                                       |      |     |                  +-------+       |                      
                                       |      |     |                      A5/SCL [ ]  |                      
                                       |       \___/                       A4/SDA [ ]  |                      
                                       |                                      AREF[ ]  |                      
                                       |                                       GND[ ]  |                      
                                       |  [ ] N/C                          SCK/13 [0]  |---------------------\
                                       |  [ ] IOREF                       MISO/12 [0]  |-------------------\ |
                                       |  [ ] RST                         MOSI/11 [0]~ |------------------\|||
                                       |  [ ] 3V3       +---+                  10 [0]~ |-----------------\||||
                                +------|--[0] 5v       -| A |-                  9 [0]~ |----------------\|||||
                                |      |  [ ] GND      -| R |-                  8 [0]  |---------------\||||||
                                |  +---|--[0] GND      -| D |-                         |                ||||||
                                |  |   |  [ ] Vin      -| U |-                  7 [ ]  |                ||||||
                                |  |   |               -| I |-                  6 [ ]~ |                ||||||
                                |  |   |  [ ] A0       -| N |-                  5 [ ]~ |                ||||||
                                |  |   |  [ ] A1       -| O |-                  4 [ ]  |                ||||||
                                |  |   |  [ ] A2       -|   |-            INT1/ 3 [ ]~ |                ||||||
                                |  |   |  [ ] A3        +---+             INT0/ 2 [ ]  |                ||||||
                                |  |   |  [ ] A4/SDA     RST SCK MISO       TX> 1 [ ]  |                ||||||
                                |  |   |  [ ] A5/SCL     [ ] [ ] [ ]        RX< 0 [ ]  |                ||||||
                                |  |   |                 [ ] [ ] [ ]                   |                ||||||
                                |  |   |  UNO_R3        GND MOSI 5V  _________________/                 ||||||
                                |  |    \___________________________/                                   ||||||
                                |  |                                                                    ||||||
                                |  +------0    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                |                                                                       ||||||
                                +------0  *    *  *  *  *  *       *  *  *  *  *    *  *                ||||||
                                          220 Ohm            Led 1              /----------------------/ ||||| pin 8 
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 |||||
                                                                                                         |||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |||||
                                          220 Ohm            Led 2              /-----------------------/ |||| pin 9 
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  ||||
                                                                                                          ||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  ||||
                                          220 Ohm            Led 3              /------------------------/ ||| pin 10
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                   |||
                                                                                                           |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                   |||
                                          220 Ohm            Led 4              /-------------------------/ || pin 11
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                    ||
                                                                                                            ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                    ||
                                          220 Ohm            Led 5              /--------------------------/ | pin 12
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                     |
                                                                                                             |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                     |
                                          220 Ohm            Led 6              /---------------------------/  pin 13
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                           
                                                                                                                   
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                           
                                                                                                                   
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                           
                                                                                                                   
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0                           
                         pin GND---------/ \------------------------------------------/ - GND                      
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                           
                                                                                                                   
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *                           
                         pin 5v-------/ \------------------------------------------/+ 5v  
