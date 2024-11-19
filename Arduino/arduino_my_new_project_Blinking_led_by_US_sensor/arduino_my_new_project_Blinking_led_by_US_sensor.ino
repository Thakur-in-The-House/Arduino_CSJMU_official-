// Define the Pins
const int trigPin = 9;      // Pin connected to Trig of HC-SR04
const int echoPin = 10;     // Pin connected to Echo of HC-SR04
const int RedPin = 8;      // Pin connected to the LED
const int BluePin = 11;
const int GreenPin = 12 ;
// Define the threshold distance in centimeters
const int distanceThresholdR = 10;  // 10 cm
const int distanceThresholdG = 25;  // 10 cm
const int distanceThresholdB = 40;  // 10 cm
const int distanceThresholdM = 50;
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the LED Pin as OUTPUT
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  // Set the Trigger and Echo Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // Wait for a short time to ensure the sensor is ready
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Send a 10µs pulse to trigger the sensor
  digitalWrite(trigPin, LOW);

  // Read the Echo Pin to get the pulse duration
  long duration = pulseIn(echoPin, HIGH);  // Measure how long the Echo Pin stays HIGH

  // Calculate the distance (in centimeters) using the duration
  long distance = duration * 0.0344 / 2;  // Speed of sound is 0.0344 cm/µs

  //Print the distance for debugging purposes
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the distance is less than the threshold, blink the LED
  if (distance < distanceThresholdR) {
    digitalWrite(RedPin, HIGH); // play red
    delay(200);
    digitalWrite(RedPin, LOW);
  }else if(distance >=distanceThresholdR && distance < distanceThresholdG){
    digitalWrite(GreenPin, HIGH); // play red
    delay(200); //play green
    digitalWrite(GreenPin, LOW);
  } 
  else if(distance >= distanceThresholdG && distance <= distanceThresholdB){
    digitalWrite(BluePin, HIGH); // play red
    delay(200); //play blue
    digitalWrite(BluePin, LOW);
  }else if(distance < distanceThresholdM){
    digitalWrite(RedPin, HIGH); // play red
    delay(50); //play blue
    digitalWrite(RedPin, LOW);
    digitalWrite(BluePin, HIGH); // play red
    delay(50); //play blue
    digitalWrite(BluePin, LOW);
    digitalWrite(GreenPin, HIGH); // play red
    delay(50); //play blue
    digitalWrite(GreenPin, LOW);
  }else {
    digitalWrite(RedPin, LOW);    // Turn LED off if object is far away
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, LOW);
  }

  delay(50);  // Delay to avoid too many readings per second
}

