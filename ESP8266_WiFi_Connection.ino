#include <ESP8266WiFi.h>

//Initializing network SSId PASSWORD as constant character.
const char* ssid = "GIVE_YOUR_NETWORK_SSID";
const char* password = "PASSWORD";

//Creates server that listen for incoming connections on the specific port. I've choosen port number 80.
WiFiServer server(80);


void setup() {
  //Initializing serial communication - Baud rate for me 115200.
  Serial.begin(115200);
  delay(10);

  //Connect to WiFi network.
  Serial.println("Connecting to");
  Serial.print(".");
  
  //Printing network SSID on serial monitor.
  Serial.println(ssid);
  
  //Initializing network settings of WiFi library.
  WiFi.begin(ssid, password);

  //WiFi.status() returns connection status, funtion returns WL_CONNECTED on successfull connection.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
 
  //Starting up the server.
  server.begin();
  Serial.println("Server started");
 
  //Printing an IP address on serial monitor to be opened on broweser for you problem specific purpose. 
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");

  //localIP() method retrives IP address of WiFi shield.
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

//YOUR LOOP AREA//

