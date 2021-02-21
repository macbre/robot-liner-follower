#include <Arduino.h>
#include "l293d.h"

// left motor
#define ENABLE_1 9
#define INPUT_A1 8
#define INPUT_A2 7

// right motor
#define ENABLE_2 6
#define INPUT_B1 11
#define INPUT_B2 12


L293D left(INPUT_A1, INPUT_A2, ENABLE_1);
L293D right(INPUT_B1, INPUT_B2, ENABLE_2);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  left.init();
  right.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  left.forward();
  delay(1500);

  digitalWrite(LED_BUILTIN, LOW);
  left.reverse();
  delay(1500);

  left.off();
  delay(500);
}
