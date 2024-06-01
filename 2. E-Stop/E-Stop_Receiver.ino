// Library for the receiver module
#include <VirtualWire.h>

// Assign pins for the relay and receiver module
const int relayPin = 10;                // Pin assigned for the relay
const int receive_pin = 11;             // Pin assigned for the receiver

void setup() 
{
  Serial.begin(9600);	                  // To debug in the serial monitor of the Arduino IDE
  Serial.println("setup");  

  // Initialise the IO and ISR
  pinMode(relayPin, OUTPUT);            // Set the GPIO to be an output pin
  vw_set_rx_pin(receive_pin);
  vw_setup(2000);	                      // Bits per sec
  vw_rx_start();                        // Start the receiver PLL running
  digitalWrite(relayPin, HIGH);
}

void loop() 
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];      // Create an array to hold the received data
  uint8_t buflen = VW_MAX_MESSAGE_LEN;  // Create a variable to hold the length of the array

  if (vw_get_message(buf, &buflen))     // If data is received, go into this if statement
  {
    if ((char)buf[0] == '5')            // If the received data has a value of 5
    {
      digitalWrite(relayPin, LOW);      // Open the relay

      Serial.print("Got: ");            // To debug, show the received value in the serial monitor
	    for (int i = 0; i < buflen; i++)
	    {
        Serial.write(buf[i]);
	      Serial.println();
	    }
    }
    if ((char)buf[0] == '0')            // If the received data has a value of 0
    {      
      digitalWrite(relayPin, HIGH);     // Short the relay

      Serial.print("Got: ");	          // To debug, show the received value in the serial monitor
	    for (int i = 0; i < buflen; i++)
	    {
        Serial.write(buf[i]);
	      Serial.println();
	    }
    }
  }
}
