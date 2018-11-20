/*
* Demo for RF remote switch receiver.
* For details, see RemoteReceiver.h!
*
* This sketch shows the received signals on the serial port.
* Connect the receiver to digital pin 2.
*/

#include <RemoteReceiver.h>

void setup() {
  while (!Serial)
{
    // do nothing
} ;
  Serial.begin(57600);
    Serial.println("Serial port inited (old RemoteReceiver");
  // Initialize receiver on interrupt 0 (= digital pin 2), calls the callback "showCode"
  // after 3 identical codes have been received in a row. (thus, keep the button pressed
  // for a moment)
  //
  // See the interrupt-parameter of attachInterrupt for possible values (and pins)
  // to connect the receiver.
  // - interrupt
  // - minRepeat (default was 3)
  // - callback
  RemoteReceiver::init(digitalPinToInterrupt(3),1, showCode);
    Serial.println("old RemoteReceiver inited");
}
int i=0;






void loop() {
  delay(3000);
  Serial.println(i++);
}

// Callback function is called only when a valid code is received.
void showCode(unsigned long receivedCode, unsigned int period) {
  // Note: interrupts are disabled. You can re-enable them if needed.
  
  // Print the received code.
  Serial.print("Code: ");
  Serial.print(receivedCode);
  Serial.print(", period duration: ");
  Serial.print(period);
  Serial.println("us.");
}



