// Program: I2C slave sender template for multi-node Arduino I2C network
// Programmer: Hazim Bitar (techbitar.com)
// Date: March 30, 2014
// This example code is in the public domain.

#include <Wire.h>

#define NODE_ADDRESS 2  // Change this unique address for each I2C slave node
#define PAYLOAD_SIZE 5 // Number of bytes  expected to be received by the master I2C node

byte nodePayload[PAYLOAD_SIZE];

void setup()
{

  Serial.begin(9600);  
/*  
  Serial.println("SLAVE SENDER NODE");
  Serial.print("Node address: ");
  Serial.println(NODE_ADDRESS);
  Serial.print("Payload size: ");
  Serial.println(PAYLOAD_SIZE);
*/  
  Serial.println("********SLAVE*********");

  Wire.begin(NODE_ADDRESS);  // Activate I2C network
  Wire.onRequest(requestEvent); // Request attention of master node
}

void loop()
{ 
  delay(100);
  nodePayload[0] = NODE_ADDRESS; // I am sending Node address back.  Replace with any other data 
  nodePayload[1] = analogRead(A0)/4; // Read A0 and fit into 1 byte. Replace this line with your sensor value
  nodePayload[2] = analogRead(A1)/4; // Read A1 and fit into 1 byte. Replace this line with your sensor value
  nodePayload[3] = analogRead(A2)/4; // Read A2 and fit into 1 byte. Replace this line with your sensor value
  nodePayload[4] = analogRead(A3)/4; // Read A3 and fit into 1 byte. Replace this line with your sensor value   
}

void requestEvent()
{
  Wire.write(nodePayload,PAYLOAD_SIZE);  
  Serial.print("Sensor value 1: ");  // for debugging purposes. 
  Serial.println(nodePayload[1]); // for debugging purposes. 
  Serial.print("Sensor value 2: ");  // for debugging purposes. 
  Serial.println(nodePayload[2]); // for debugging purposes. 
  Serial.print("Sensor value 3: ");  // for debugging purposes. 
  Serial.println(nodePayload[3]); // for debugging purposes. 
  Serial.print("Sensor value 4: ");  // for debugging purposes. 
  Serial.println(nodePayload[4]); // for debugging purposes.   
  Serial.println("********SLAVE*********");
}
