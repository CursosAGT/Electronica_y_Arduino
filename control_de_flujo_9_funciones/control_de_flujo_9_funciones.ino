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
                                       *  * | [ ]IOREF                 MISO/12[0] |-----------------------\
                                       *  * | [ ]RST                   MOSI/11[0]~|----------------------\|
                                       *  * | [ ]3V3    +---+               10[0]~|---------------------\||
                                       0------[0]5v    -| A |-               9[0]~| -------------\      |||
                                       *  * | [ ]GND   -| R |-               8[ ] | *  *          |     |||
                                       *  0---[0]GND   -| D |-                    | *  *          |     |||
                                       *  * | [ ]Vin   -| U |-               7[ ] | *  *          |     |||
                                       *  * |          -| I |-               6[0]~|--------------------\|||
                                       *  * | [ ]A0    -| N |-               5[0]~|-------------------\||||
                                       *  * | [ ]A1    -| O |-               4[ ] | *  *          |   |||||
                                       *  * | [ ]A2     +---+           INT1/3[0]~| -----------------\|||||
                                       *  * | [ ]A3                     INT0/2[ ] | *  *          |  ||||||
                                       *  * | [ ]A4/SDA   RST SCK MISO    TX>1[ ] | *  *          |  ||||||
                                       *  * | [ ]A5/SCL   [ ] [ ] [ ]     RX<0[ ] | *  *          |  ||||||
                                       *  * |             [ ] [ ] [ ]             | *  *          |  ||||||
                                       *  * |  UNO_R3     GND MOSI 5V ____________/ *  *          |  ||||||
                                       *  * \________________________/              *  *          |  ||||||
                                                                                                  |  ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *   Boton  |  ||||||
                                         10 kOhm             Boton                                |  |||||| pin 9
                                       *  0-ww-0  *  *  0  0--[#]--0  *  *  *  0----0  *          |  ||||||
                                                         \---------------------------------------/   ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *             ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *             ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *             ||||||
                                       *  *    *  *  *  *  *       *  *  *  *  /-------------------/ |||||| pin 6 LED Azul  RGB
                                       *  *    *  *  *  *  *     /-0  *  *  *  0    *  *              |||||
                                          220 Ohm          Led  / RGB           /--------------------/ |||| pin 5 LED Verde RGB
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *               ||||
                                       *  *    *  *  *  *  *    \  *  *  *  *   /---------------------/ ||| pin 3 LED Rojo RGB
                                       *  *    *  *  *  *  *     \-0  *  *  *  0    *  *                |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                |||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                |||
                                          220 Ohm            Led 1              /----------------------/ || pin 12 LED Rojo
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                 ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 ||
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                 ||
                                          220 Ohm            Led 2              /-----------------------/ | pin 11 LED Verde
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *                  |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  |
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *                  |
                                          220 Ohm            Led 3              /------------------------/  pin 10 LED Azul
                                       *  0-ww-0  *  *  *  0--|>|--0  *  *  *  0    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       *  0    *  *  *  *  *       *  *  *  *  *    *  0
                         pin GND---------/ \------------------------------------------/ - GND
                                       *  *    *  *  *  *  *       *  *  *  *  *    *  *
                                       0  *    *  *  *  *  *       *  *  *  *  *    0  *
                         pin 5v-------/ \------------------------------------------/+ 5v
*/
//————————————————–
//Declara puertos de entradas y salidas y variables
//————————————————–
int ledRojo_RGB = 3; 	//Declara Pin LED Rojo
int ledVerde_RGB= 5; 	//Declara Pin LED Verde
int ledAzul_RGB= 6; 	//Declara Pin LED Azul
int ledRojo = 11; 		//Declara Pin LED Rojo
int ledVerde= 10; 		//Declara Pin LED Verde
int ledAzul= 9;  		  //Declara Pin LED Azul
int botonPin = 2;  		//Declara Pin Boton
int contador = 0;

//————————————
//Funcion principal
//————————————
void setup() //                  Se ejecuta cada vez que el Arduino se inicia
{
pinMode(ledRojo_RGB,OUTPUT);  	//El RGB Rojo como una salida
pinMode(ledVerde_RGB,OUTPUT); 	//El RGB Verde como una salida
pinMode(ledAzul_RGB,OUTPUT);	  //El RGB Azul como una salida
pinMode(ledRojo,OUTPUT);  		  //El LED Rojo como una salida
pinMode(ledVerde,OUTPUT);  		  //El LED Verde como una salida
pinMode(ledAzul,OUTPUT);    		//El LED Azul como una salida
pinMode(botonPin, INPUT); 	  	//El botos de cambio de color_RGB
}
//————————————
//Funcion ciclicla
//————————————
void loop() //                  Esta funcion se mantiene ejecutando
{           //                   cuando este energizado el Arduino
  if (digitalRead(botonPin) == LOW)
  {

//                  Llamado a la función color_RGB que recibe
//                  1er posicion: Intensidad Rojo
//                  2da posición: Intensidad Verde
//                  3ra posición: Intensidad Azul
    if (contador == 0)
      {
      color_RGB(255,0,0);     			//Rojo
      contador = 1;
      }
    else if (contador == 1)
      {
      color_RGB(0,255,0);     			//Verde
      contador = 2;
      }
    else if (contador == 2)
      {
      color_RGB(0,0,255);     			//Azul
      contador = 3;
      }
    else if (contador == 3)
      {
      color_RGB(255,255,255); 			//Blanco
      contador = 4;
      }
    else if (contador == 4)
      {
      color_RGB(255,0,255);   			//Magenta
      contador = 5;
      }
    else if (contador == 5)
      {
      color_RGB(255,128,0);  			//Naranaja
      contador = 0;
      }
  delay(100);
  }
}
//————————————
//Funcion color_RGB
//————————————
void color_RGB(int Rojo, int Azul,int Verde)
  {
    analogWrite(ledRojo_RGB, 255-Rojo);		//Escritura de PWM del color_RGB Rojo
    analogWrite(ledVerde_RGB, 255-Verde);	//Escritura de PWM del color_RGB Verde
    analogWrite(ledAzul_RGB, 255-Azul); 	//Escritura de PWM del color_RGB Azul
    digitalWrite(ledRojo, Rojo);			//Escritura de PWM del color Rojo
    digitalWrite(ledVerde, Verde);		  	//Escritura de PWM del color verde
    digitalWrite(ledAzul, Azul);			//Escritura de PWM del color Azul
  }
