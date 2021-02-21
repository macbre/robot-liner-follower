#include <Arduino.h>

class L293D {
    public:
        L293D(uint8_t in1, uint8_t in2, uint8_t enable);
        void init();

        void forward();
        void forward(uint8_t speed);
        void reverse();
        void reverse(uint8_t speed);
        void off();

    private:
        uint8_t enable_pin;
        uint8_t input_1;
        uint8_t input_2;
};
