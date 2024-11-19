#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(8,9); //for rx and tx
int ledPin = 13;       // Pin connected to LED
int btStatePin = 11;    // Pin connected to the HC-05 STATE pin

void setup() {
  pinMode(ledPin, OUTPUT);       // Set LED pin as output
  pinMode(btStatePin, INPUT);    // Set Bluetooth STATE pin as input
  digitalWrite(ledPin, LOW);     // Ensure LED is off initially
  Bluetooth.begin(9600);
  Serial.begin(9600);           // Start serial communication
}

void loop() {
  int btState = digitalRead(btStatePin); // Read Bluetooth connection status

  if (btState == HIGH) {         // If connected
    if (Bluetooth.available())  {   //check if there's incoming data
    string message = Bluetooth.readstring();  Read the incoming message

    //Blink LED according to the number of characters in the message
      for (int i = 0; i <messagelength; i++){
        digitalwrite(ledPin, HIGH); //Turn on LED
        delay(500);                  // Wait for 500 milliseconds
        digitalWrite(ledPin, LOW);   // Turn off LED
        delay(500);                  // Wait for 500 milliseconds
      }
      }
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {                       // If not connected
    digitalWrite(ledPin, HIGH);   // Turn off LED
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(50);
    digitalWrite(ledPin, HIGH);   // Turn off LED
    delay(100);
  }

  delay(100); // Small delay to stabilize the loop
}