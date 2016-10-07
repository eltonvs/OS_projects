#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <random>
#include "BlackGPIO.h"
#include "macros.h"
#include "analog.h"
#include "colors.h"

extern const int NUMBER_OF_COLORS;

// Constants
#define TIME_TO_SLEEP 2
#define POTENTIOMETER_MAX_VAL 4096

int main(int argc, char *argv[]) {
    // Button
    BL_GPIO button(BlackLib::GPIO_115, BlackLib::input, BlackLib::SecureMode);

    // Status Led
    BL_GPIO statusLed(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);

    //Led RGB
    BL_GPIO leds[3] = {
        BL_GPIO(BlackLib::GPIO_46,BlackLib::output, BlackLib::SecureMode),
        BL_GPIO(BlackLib::GPIO_26,BlackLib::output, BlackLib::SecureMode),
        BL_GPIO(BlackLib::GPIO_44,BlackLib::output, BlackLib::SecureMode)
    };

    void (*colors[])(BL_GPIO (&)[3]) = {
        turn_off,
        blue_light,
        green_light,
        red_light,
        white_light,
        yellow_light
    };

    // Set led Status led and RGB led off
    statusLed.TURN_OFF;
    turn_off(leds);

    int fraction = POTENTIOMETER_MAX_VAL/3,
        potentiometer_val,
        num_competitors = 0;

    while (!button.getNumericValue()) {
        potentiometer_val = readAnalog(1);
        num_competitors = (potentiometer_val < fraction) ? 1 : (potentiometer_val < fraction*2) ? 2 : 3;

        colors[num_competitors](leds);
    }

    // starting race
    colors[0](leds);
    statusLed.TURN_ON;

    // create {num_competitors} process (with fork())
    // Create all process here and set the alarm

    // After alarm, kill all subprocess and get the winner

    // show winner's color
    // blue  - 1
    // green - 2
    // red   - 3
    // white - 4

    // sleep before die
    sleep(TIME_TO_SLEEP);

    // reset everything and finish execution
    turn_off(leds);
    statusLed.TURN_OFF;

    return 0;
}
