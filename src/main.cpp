#include <Arduino.h>
#include <HCSR04.h>

const int trigPin = 11;
const int echoPin = 10;
const int greenPin = 53;
const int redPin = 51;

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

// put function declarations here:

void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test");
}

void loop() {
  double distance = distanceSensor.measureDistanceCm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);

  if (distance <= 5.0 && distance > 0.0){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(1500);
  }

  delay(500);
}

// put function definitions here:
