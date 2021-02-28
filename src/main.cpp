#include <Arduino.h>
#include <l293d.h>

// left motor
#define ENABLE_1 9
#define INPUT_A1 8
#define INPUT_A2 7

// right motor
#define ENABLE_2 6
#define INPUT_B1 5
#define INPUT_B2 4

#define MIN_SPEED 80
#define MAX_SPEED 255

L293D left(INPUT_A1, INPUT_A2, ENABLE_1);
L293D right(INPUT_B1, INPUT_B2, ENABLE_2);

// line detectors - TCRT5000
#define LINE_LEFT A3
#define LINE_RIGHT A2
#define LINE_DETECTED_THRESHOLD 300

// cppcheck-suppress unusedFunction
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(115200);

  left.init();
  right.init();

  left.forward();
  right.forward();
}

// cppcheck-suppress unusedFunction
void loop() {
  int lineDetectorLeft = analogRead(LINE_LEFT);

  Serial.print("Left ");
  Serial.print(lineDetectorLeft);

  int lineDetectorRight = analogRead(LINE_RIGHT);
  Serial.print("\tRight ");
  Serial.println(lineDetectorRight);

  // line detected on both lines
  if (lineDetectorLeft > LINE_DETECTED_THRESHOLD && lineDetectorRight > LINE_DETECTED_THRESHOLD) {
    left.forward(255);
    right.forward(255);

    Serial.println(" ## Line between");
  }
  // line detected on left
  else if (lineDetectorLeft > LINE_DETECTED_THRESHOLD) {
    // robot turns right
    left.reverse(128);
    right.forward(255);

    Serial.println(" << Line on left");
  }
  // line detected on right
  else if (lineDetectorRight > LINE_DETECTED_THRESHOLD) {
    // robot turns left
    right.reverse(128);
    left.forward(255);

    Serial.println(" >> Line on right");
  }
  // we're in between the lines - full throttle
  else {
    left.forward(255);
    right.forward(255);

    Serial.println(" ## Line between");
  }

  delay(250);
}
