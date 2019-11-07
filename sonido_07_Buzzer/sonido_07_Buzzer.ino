/*                                     +  -                                         +  -
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  +-----+    *  *
                                       *  * +----[PWR]-------------------| USB |--+ *  *
                                       *  * |                            +-----+  | *  *
                                       *  * |         GND/RST2  [ ][ ]            | *  *
                                       *  * |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] | *  *
                                       *  * |          5V/MISO2 [ ][ ]  A4/SDA[ ] | *  *
                                       *  * |                             AREF[ ] | *  *
                                       *  * |                              GND[ ] | *  *
                                       *  * | [ ]N/C                    SCK/13[ ] | *  *
                                       *  * | [ ]IOREF                 MISO/12[ ] | *  *
                                       *  * | [ ]RST                   MOSI/11[0]~|----------------------\
                                       *  * | [ ]3V3    +---+               10[ ]~| *  *                 |
                                       0------[0]5v    -| A |-               9[ ]~| *  *                 |
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *                 |
                                       *  0---[0]GND   -| D |-                    | *  *                 |
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *                 |
                                       *  * |          -| I |-               6[ ]~| *  *                 |
                                       *  * | [ ]A0    -| N |-               5[ ]~| *  *                 |
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *                 |
                                       *  * | [ ]A2     +---+           INT1/3[ ]~| *  *                 |
                                       *  * | [ ]A3                     INT0/2[ ] | *  *                 |
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *                 |
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *                 |
                                       *  * |             [ ] [ ] [ ]             | *  *                 |
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *                 |
                                       *  * \________________________/              *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 |
                                       *  *    *  *  *  *  *  ___   *  *  *  *  *    *  *                |
                                          220 Ohm            /   \               /-----------------------/  pin 11
                                       *  0-ww-0  *  *  *  0( ( ) )0  *  *  *  0    *  *
                                       *  *    *  *  *  *  * \___/ *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/
// Pin connected to buzzer
int buzzer = 11;

void setup()
{
    // Defines the Buzzer pin as output
    pinMode(buzzer,OUTPUT);
}

void loop()
{
    // Sounds the buzzer at the frequency relative to the note C in Hz
    tone(buzzer,261);
    // Waits some time to turn off
    delay(200);
    //Turns the buzzer off
    noTone(buzzer);
    // Sounds the buzzer at the frequency relative to the note D in Hz
    tone(buzzer,293);
    delay(200);
    noTone(buzzer);
    // Sounds the buzzer at the frequency relative to the note E in Hz
    tone(buzzer,329);
    delay(200);
    noTone(buzzer);
    // Sounds the buzzer at the frequency relative to the note F in Hz
    tone(buzzer,349);
    delay(200);
    noTone(buzzer);
    // Sounds the buzzer at the frequency relative to the note G in Hz
    tone(buzzer,392);
    delay(200);
    noTone(buzzer);
}
