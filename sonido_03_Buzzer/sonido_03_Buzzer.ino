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
Buzzer Activo: genera un zumbido a frecuencia estable y preestablecida al conectarla a 5v
Buzzer Pasivo: genera un zumbido a frecuencia distintas dependiendo de la señal PWM(modulacion por ancho de pulso) ingresada
*/

/* Play Melody
 * -----------
 *
 * Program to play a simple melody
 *
 * Tones are created by quickly pulsing a speaker on and off
 *   using PWM, to create signature frequencies.
 *
 * Each note has a frequency, created by varying the period of
 *  vibration, measured in microseconds. We'll use pulse-width
 *  modulation (PWM) to create that vibration.

 * We calculate the pulse-width to be half the period; we pulse
 *  the speaker HIGH for 'pulse-width' microseconds, then LOW
 *  for 'pulse-width' microseconds.
 *  This pulsing creates a vibration of the desired frequency.
 *
 * (cleft) 2005 D. Cuartielles for K3
 * Refactoring and comments 2006 clay.shirky@nyu.edu
 * See NOTES in comments at end for possible improvements
 */

// TONES  ==========================================
// Start by defining the relationship between
//       note, period, &  frequency.
#define  c     3830    // 261 Hz
#define  d     3400    // 294 Hz
#define  e     3038    // 329 Hz
#define  f     2864    // 349 Hz
#define  g     2550    // 392 Hz
#define  a     2272    // 440 Hz
#define  b     2028    // 493 Hz
#define  C     1912    // 523 Hz
// Define a special note, 'R', to represent a rest
#define  R     0

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerOut = 11;
// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;

void setup()
{
  pinMode(speakerOut, OUTPUT);
  if (DEBUG)
  {
    Serial.begin(9600); // Set serial out if we want debugging
  }
}

// MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[],
//  which sets each note's relative length (higher #, longer note)
int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 };
int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0)
  { // if this isn't a Rest beat, while the tone has played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration)
    {
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    }
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++)
    { // See NOTE on rest_count
      delayMicroseconds(duration);
    }
  }
}

// LET THE WILD RUMPUS BEGIN =============================
void loop() {
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    duration = beat * tempo; // Set up timing

    playTone();
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}
