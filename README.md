#Establishing WiFi Connection with ESP8266 module#
----------------------------------------------------------------------------------------------------------------------------------------
The file contains the setup() function.

The Wi-Fi library for ESP8266 has been developed based on ESP8266 SDK, using naming convention and overall functional philosophy of Arduino WiFi library. ESP8266 is all about WiFi. If you are intrested in developing solution(s) for your problem with WiFi network, this is good available module to use.

Hopefully you are already aware with the simple LED Blink test code with an Arduino. This code guide you for estblishing connection with your local WiFi router. 

Enough comments are presented to guide you line by line.

#LED ON_OFF from Client Browser#
----------------------------------------------------------------------------------------------------------------------------------------
The second file of the project contains the loop() function. Where the status of the WiFi connection has been checked and request has been made for checking the status. 

By matching the status the value of the GPIO pin has set to ON or OFF.

The response of GPIO status has been delivered to client side HTML page showing the LED is ON or OFF.

#NOTE: Please initialize the LEDPIN variable with any GPIO of your intrest and interface the 3.5-5V LED to that GPIO.

-Vishvajit Bakrola
