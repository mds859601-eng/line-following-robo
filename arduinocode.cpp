// IR Sensor Pins
#include<iostream>
#include<Arduino.h>
#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

// Motor Driver Pins
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

void setup() {
  // Sensor Pins
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  // Motor Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set motor speed (0–255)
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  // Assuming:
  // 0 = Black line detected
  // 1 = White surface

  if (left == 0 && right == 0) {
    // Move Forward
    forward();
  }
  else if (left == 0 && right == 1) {
    // Turn Left
    turnLeft();
  }
  else if (left == 1 && right == 0) {
    // Turn Right
    turnRight();
  }
  else {
    // Stop (line lost)
    stopMotors();
  }
}

// 🚗 Movement Functions

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}