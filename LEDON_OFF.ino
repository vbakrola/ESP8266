void setup() {
  //Your setup code  
  //WiFi Network establishment as given in https://github.com/vbakrola/NodeMCU---ESP8266/blob/master/ESP8266_WiFi_Connection.ino
}

void loop() {
  //Check whether the client is connected or not.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  //Wait until new client sends some data.
  Serial.println("New Client Connected");
  while(!client.available()){
    delay(1);
  }
 
  //Read the first line of a Request.
  String request = client.readStringUntil('\r');
  Serial.println(request);

  //Waits until all outgoing characters in buffer have been sent.
  client.flush();
 
  //Check whether the request match or not. And according to request turn the LED ON or OFF.
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(LEDPIN, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(LEDPIN, LOW);
    value = LOW;
  }
 
  //Return the status of the LEDPIN to client.
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("LED IS NOW:");
 
  if(value == HIGH) {
    client.print("ON");
  } else {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On LED </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off LED</button></a><br/>");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client has been disconnected.");
  Serial.println("");
}
