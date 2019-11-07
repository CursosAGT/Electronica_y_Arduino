/*                + -                               + -
                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * *  

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 
                   220 Ohm         Led         /------------pin 13
                  * 0-ww-0 * * * 0-(L)-0 * * * 0    * *

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 

                  * *    * * * * *     * * * * *    * * 

                  * 0    * * * * *     * * * * *    * * 
   pin GND----------/
                  * 0    * * * * *     * * * * *    * 0 
                    \---------------------------------/ - GND
                  0 *    * * * * *     * * * * *    * * 
   pin 5v---------/
                  0 *    * * * * *     * * * * *    0 *        
                  \---------------------------------/   + 3v < < < < < < < Prestar atencion>


          ----------------------
          |  [               o  |-----  Vcc 		a 3v              VCC
          |   ]           o  ---|--  TXD 			a Arduino (pin 2) TX – UART Transmitting channel
          |  [               o  |-----  RESET                         RESET (must be pulled to 3.3v)
          |   ]           o  ---|--  GPIO0                            GPIO0 (Digital I/O programmable, also used for BOOT modes)
          |  [               o  |-----  CH_PD- -Vcc a 3v              CH_PD (enable/power down, must be pulled to 3.3v directly or via resistor)
          |   ]           o  ---|--  GPIO2                            GPIO2 (Digital I/O programmable)
          |  [____           o  |-----  RXD 		a Arduino (pin 3) RX – UART Receiving channel
          |               o  ---|--  GND            a GND             GND
          ----------------------

https://www.prometec.net/arduino-wifi/#
https://www.geekstips.com/esp8266-arduino-tutorial-iot-code-example/
* */
#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX

void setup()
  {  Serial.begin(115200);
     BT1.begin(115200);
  }

void loop()
  {  String B= "." ;
     if (BT1.available())
         { char c = BT1.read() ;
           Serial.print(c);
         }
     if (Serial.available())
         {  char c = Serial.read();
            BT1.print(c);
         }
   }
Here is a simple Arduino blink example which you can use to test the esp module with the built in LED:

/*
 ESP8266 Arduino Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
Off course, after that you can try a more complex example by loading a ESP8266 Arduino WiFi Client example program that sends data via WiFi to the data.spakfun.com iot platform:

/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *  ESP8266 Arduino example
 */

#include <ESP8266WiFi.h>

const char* ssid     = "your-ssid";
const char* password = "your-password";

const char* host = "data.sparkfun.com";
const char* streamId   = "....................";
const char* privateKey = "....................";

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/input/";
  url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&value=";
  url += value;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}

Or if you need to make a server in your network, you can try ESP8266 Arduino Wifi Server example program:

/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 Arduino module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "your-ssid";
const char* password = "your-password";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1)
    val = 0;
  else if (req.indexOf("/gpio/1") != -1)
    val = 1;
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(2, val);
  
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val)?"high":"low";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

Iot Complete Starter Kit

And in the last example an ESP8266 Arduino WiFi Access Point which hosts a web server is created:

/* Create a WiFi access point and provide a web server on it.
ESP8266 Arduino example
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
