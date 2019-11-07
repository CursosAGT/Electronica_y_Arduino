/*Tutorial Arduino -I2C
 * 
 * 
 * 
 * Código del slave.
Autor:Toni Ruiz Sastre 
www.electroensaimada.com
*/
/*

#include <Wire.h>

unsigned char result=0;
unsigned char ingreso;
unsigned int valor_puerto;
//#declare int howMany;
int cont;
//int pin[]=(A0,A1,A2,A3,A4,A5,);
void setup()
{
    Wire.begin(0xF5);               // Address 0xf5
    Wire.onRequest(requestEvent);   // Activamos evento de peticion
    Wire.onReceive(receiveEvent);   //Activamos evento de lectura.
    Serial.begin(9600);             //Iniciamos el Serial
    pinMode (13,OUTPUT);
}
void loop()
{
  digitalWrite(13,HIGH);
  delay(100);
  
}

//Evento de peticion se activa cuando un master nos pide que le enviemos algun dato
void requestEvent()
{
  Wire.write(result); // Enviamos el resultado del calculo
}

//Evento de recepcion
void receiveEvent(int howMany)
{
  while( Wire.available()) //Leemos hasta que no haya datos. Teoricamente son 2.
  {
  ingreso = Wire.read(); //Leemos los dos bytes
  if (ingreso = "I")
    {
    for (int cont = 14; cont <=18 ; cont ++)
      {
        valor_puerto = analogRead(cont);
        Serial.print("Puerto # =");
        Serial.println(cont);
        Wire.write(cont); 
        Serial.println(valor_puerto);
        Wire.write(valor_puerto);
        Wire.write(" Hola ");   
      }
      Serial.println("T");//terminar
      Wire.write("T");
    }
  }
}
*/
#include <Wire.h>
unsigned char ingreso;
unsigned int valor_puerto;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);  // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
    for (int cont = 14; cont <=18 ; cont ++)
      {
        valor_puerto = analogRead(cont);
        Serial.print("Puerto # =");
//        Serial.println(cont);
//        Wire.write(cont); 
        Serial.println(valor_puerto);
        Wire.write(valor_puerto);
//        Wire.write("Hola");
      }
 // Wire.write(" Hola "); //  Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master

}
