// Libaries for the transmitter module & switch
#include <VirtualWire.h>
#include <ezButton.h>

// Assign pins for the switch and transmitter module
ezButton toggleSwitch(3);                     // Create ezButton object that attach to pin 3;
const int transmit_pin = 12;                  // Pin assigned for the transmitter module

void setup() {
  Serial.begin(9600);                         // To debug in the serial monitor of Arduino IDE
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);                             // Bits per sec
  toggleSwitch.setDebounceTime(50);           // Set debounce time to 50 milliseconds
  Serial.println("Setup Begin");
}

void loop() {
  toggleSwitch.loop();                        // MUST call the loop() function first

  //For debugging purposes
  if (toggleSwitch.isPressed())               // If the switch is turned on, print The "switch: OFF -> ON"
    Serial.println("The switch: OFF -> ON");

  if (toggleSwitch.isReleased())
    Serial.println("The switch: ON -> OFF");  // If the switch is turned off, print The "switch: ON -> OFF"

  int state = toggleSwitch.getState();        // Get the state of the switch
  if (state == HIGH)                          // If state is high, meaning it's turned on, however, show "The switch: OFF" meaning that the relay should be in open condition
  {
    Serial.println("The switch: OFF");

    const char *msg = "5";                    // Send data to be received by the received
    vw_send((uint8_t *)msg, 1);
    vw_wait_tx();                             // Wait until the whole message is gone

    Serial.print("Sent: ");                   // Show "Sent: 5"
    Serial.println(msg);
  }
  else
  {
    Serial.println("The switch: ON");         // else, meaning it's turned  off, however, show "The switch: ON" meaning that the relay should be in short condition

    const char *msg = "0";                    // Send data to be received by the received
    vw_send((uint8_t *)msg, 1);
    vw_wait_tx();                             // Wait until the whole message is gone

    Serial.print("Sent: ");                   // Show "Sent: 0"
    Serial.println(msg);
  }
}