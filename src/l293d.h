#include <Arduino.h>

class L293D {
    public:
        L293D(uint8_t in1, uint8_t in2, uint8_t enable);
        void init();

        void forward();
        void reverse();
        void off();

    private:
        uint8_t enable_pin;
        uint8_t input_1;
        uint8_t input_2;
};
