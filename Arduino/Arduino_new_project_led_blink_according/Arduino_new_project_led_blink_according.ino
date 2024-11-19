#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(8, 9); // RX, TX for Bluetooth module (HC-05)
int ledPin = 13;                // Pin connected to LED
int btStatePin = 11;            // Pin connected to HC-05 STATE pin

void setup() {
  pinMode(ledPin, OUTPUT);      // Set LED pin as output
  pinMode(btStatePin, INPUT);   // Set Bluetooth STATE pin as input
  digitalWrite(ledPin, LOW);    // Ensure LED is off initially
  Bluetooth.begin(9600);        // Start Bluetooth communication at 9600 baud
  Serial.begin(9600);           // Start Serial communication for debugging
}

void loop() {
  int btState = digitalRead(btStatePin);  // Read Bluetooth connection status
  
  if (btState == HIGH) {  // If Bluetooth is connected
    if (Bluetooth.available()) {  // Check if there's incoming data
      String message = Bluetooth.readString();  // Read the incoming message

      // Debug: Print the received message to the Serial Monitor
      Serial.println("Received message: " + message);

      int messageLength = message.length();  // Get the number of characters in the message

      // Blink LED according to the number of characters in the message
      for (int i = 0; i < messageLength; i++) {
        digitalWrite(ledPin, HIGH);  // Turn on LED
        delay(500);                  // Wait for 500 milliseconds
        digitalWrite(ledPin, LOW);   // Turn off LED
        delay(500);                  // Wait for 500 milliseconds
      }
    }
  } else {  // If Bluetooth is not connected
    // Optional: Add a pattern for when Bluetooth is disconnected
    digitalWrite(ledPin, LOW);  // Turn off LED if not connected
  }
}

