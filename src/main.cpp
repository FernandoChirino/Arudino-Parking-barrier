#include <Arduino.h>
#include <HCSR04.h>
#include <Servo.h>

const int trigPin = 11;
const int echoPin = 10;
const int greenPin = 53;
const int redPin = 51;
const int servoPin = 13;

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);
Servo myServo; 


void setup() {
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);

}

void loop() {
  double distance = distanceSensor.measureDistanceCm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);

  if (distance <= 6.0 && distance > 0.0){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);

    myServo.write(90);
    delay(2000);
  }

  myServo.write(0);
}