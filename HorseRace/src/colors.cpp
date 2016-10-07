#include "BlackGPIO.h"
#include "colors.h"

extern const int NUMBER_OF_COLORS = 6;

void red_light(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::high);
    rgb_led[1].setValue(BlackLib::low);
    rgb_led[2].setValue(BlackLib::low);
}

void green_light(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::low);
    rgb_led[1].setValue(BlackLib::high);
    rgb_led[2].setValue(BlackLib::low);
}

void blue_light(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::low);
    rgb_led[1].setValue(BlackLib::low);
    rgb_led[2].setValue(BlackLib::high);
}

void white_light(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::high);
    rgb_led[1].setValue(BlackLib::high);
    rgb_led[2].setValue(BlackLib::high);
}

void yellow_light(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::high);
    rgb_led[1].setValue(BlackLib::high);
    rgb_led[2].setValue(BlackLib::low);
}

void turn_off(BlackLib::BlackGPIO (&rgb_led)[3]) {
    rgb_led[0].setValue(BlackLib::low);
    rgb_led[1].setValue(BlackLib::low);
    rgb_led[2].setValue(BlackLib::low);
}
