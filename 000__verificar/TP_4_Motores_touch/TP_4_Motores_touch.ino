#include <Servo.h>

Servo servo;
int angulo = 90;//Normal
int motorAdelante = 2;
int motorAtras = 3;
int botonIzq = 5;
int botonDer = 6;



int boton = 0;



void setup() {
  servo.attach(8);
  servo.write(angulo);
  pinMode(botonIzq, INPUT);
  pinMode(botonDer, INPUT);
  pinMode(motorAdelante, OUTPUT);
  pinMode(motorAtras, OUTPUT);
}
void loop()
{
  digitalWrite(motorAdelante, LOW);
  digitalWrite(motorAtras, HIGH);
  delay(500);
  digitalWrite(motorAdelante, LOW);
  digitalWrite(motorAtras, LOW);
  delay(10); 
  digitalWrite(motorAdelante, HIGH);
  digitalWrite(motorAtras, LOW);
  delay(500);
  digitalWrite(motorAdelante, LOW);
  digitalWrite(motorAtras, LOW);
  if (digitalRead(botonIzq) == LOW)
  {
   if ( angulo < 180)
      {
    // scan from 0 to 180 degrees
      for(angulo = 90; angulo < 180; angulo++)  
      {                                  
        servo.write(angulo);               
        delay(15);                   
      } 
      delay(100);
      for(angulo = 180; angulo > 90; angulo--)   
      {                                  
        servo.write(angulo);          
        delay(15);                 
      } 
     }
    delay(100);
  }
  if (digitalRead(botonDer) == LOW)
  {
   
    if ( angulo > 10)
    {
    // now scan back from 180 to 0 degrees
      for(angulo = 90; angulo > 10; angulo--)   
      {                                
        servo.write(angulo);          
        delay(15);                 
      } 
      delay(100);
      for(angulo = 10; angulo < 90; angulo++)  
      {                                  
        servo.write(angulo);               
        delay(15);                   
      } 
    } 
    delay(100);
  }
  
} 

