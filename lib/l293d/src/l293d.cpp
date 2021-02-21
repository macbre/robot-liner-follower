#include "l293d.h"

L293D::L293D(uint8_t in1, uint8_t in2, uint8_t enable) {
    enable_pin = enable;
    input_1 = in1;
    input_2 = in2;
}

void L293D::init() {
    Serial.println("Initializing L293D channel");

    pinMode(input_1, OUTPUT);
    pinMode(input_2, OUTPUT);

    pinMode(enable_pin, OUTPUT);
    off();
}

void L293D::forward() {
    digitalWrite(enable_pin, HIGH);
    digitalWrite(input_1, HIGH);
    digitalWrite(input_2, LOW);
}

void L293D::forward(uint8_t speed) {
    analogWrite(enable_pin, speed);
    digitalWrite(input_1, HIGH);
    digitalWrite(input_2, LOW);
}

void L293D::reverse() {
    digitalWrite(enable_pin, HIGH);
    digitalWrite(input_1, LOW);
    digitalWrite(input_2, HIGH);
}

void L293D::reverse(uint8_t speed) {
    analogWrite(enable_pin, speed);
    digitalWrite(input_1, LOW);
    digitalWrite(input_2, HIGH);
}

void L293D::off() {
    digitalWrite(enable_pin, LOW);
}
