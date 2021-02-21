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

// cppcheck-suppress unusedFunction
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(115200);

  left.init();
  right.init();
}

// cppcheck-suppress unusedFunction
void loop() {
  unsigned char speed;
  digitalWrite(LED_BUILTIN, HIGH);

  // speed up
  for(speed=100; speed<255; speed++) {
    left.forward(speed);
    delay(25);
  }

  digitalWrite(LED_BUILTIN, LOW);

  // slow down
  for(speed=255; speed>100; speed--) {
    left.forward(speed);
    delay(25);
  }

  // left.off();
  // delay(500);
}
