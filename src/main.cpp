#include <Arduino.h>

// left motor
#define MOTOR_LEFT_PIN 3
#define MOTOR_RIGHT_PIN 2

#define MIN_SPEED 0
#define MAX_SPEED 255

// line detectors - TCRT5000
#define LINE_LEFT A3
#define LINE_CENTER A1
#define LINE_RIGHT A2
#define LINE_DETECTED_THRESHOLD 500

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(20);
  digitalWrite(LED_BUILTIN, LOW);
}


// cppcheck-suppress unusedFunction
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  blink();

  Serial.begin(115200);

  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);
  // analogWrite(MOTOR_LEFT_PIN, MAX_SPEED);
  // analogWrite(MOTOR_RIGHT_PIN, MAX_SPEED);
}

// cppcheck-suppress unusedFunction
void loop() {
  int lineDetectorLeft = analogRead(LINE_LEFT);
  int lineDetectorCenter = analogRead(LINE_CENTER);
  int lineDetectorRight = analogRead(LINE_RIGHT);

  Serial.print("Left ");
  Serial.print(lineDetectorLeft);

  Serial.print("\tCenter ");
  Serial.print(lineDetectorCenter);

  Serial.print("\tRight ");
  Serial.println(lineDetectorRight);

  blink();
  delay(20);
  // return;

  // line detected on both lines
  if (lineDetectorLeft > LINE_DETECTED_THRESHOLD && lineDetectorRight > LINE_DETECTED_THRESHOLD) {
    analogWrite(MOTOR_LEFT_PIN, MAX_SPEED);
    analogWrite(MOTOR_RIGHT_PIN, MAX_SPEED);

    Serial.println(" ## Line between");
  }
  // line detected on left
  else if (lineDetectorLeft > LINE_DETECTED_THRESHOLD) {
    // robot turns right
    analogWrite(MOTOR_LEFT_PIN, MAX_SPEED);
    analogWrite(MOTOR_RIGHT_PIN, MIN_SPEED);

    Serial.println(" << Line on left");
  }
  // line detected on right
  else if (lineDetectorRight > LINE_DETECTED_THRESHOLD) {
    // robot turns left
    analogWrite(MOTOR_LEFT_PIN, MIN_SPEED);
    analogWrite(MOTOR_RIGHT_PIN, MAX_SPEED);

    Serial.println(" >> Line on right");
  }
  // we're in between the lines - full throttle
  else {
    analogWrite(MOTOR_LEFT_PIN, MAX_SPEED);
    analogWrite(MOTOR_RIGHT_PIN, MAX_SPEED);

    Serial.println(" ## Line between");
  }

}
