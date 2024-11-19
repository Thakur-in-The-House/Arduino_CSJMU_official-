void setup() {
  // Start serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // If data is available to read from Bluetooth module
  if (Serial.available()) {
    char received = Serial.read();
    // Print received data to Serial Monitor
    Serial.print("Received: ");
    Serial.println(received);
  }
  
  // If data is available from the Serial Monitor, send it to Bluetooth
  if (Serial.available()) {
    char toSend = Serial.read();
    // Send data to Bluetooth module
    Serial.print("Sending: ");
    Serial.println(toSend);
  }
}
