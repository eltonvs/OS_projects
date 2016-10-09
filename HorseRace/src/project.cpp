#include <unistd.h>
#include <fstream>
#include <random>
#include <cstdlib>
#include <csignal>

#include "BlackGPIO.h"
#include "macros.h"
#include "analog.h"
#include "colors.h"

extern const int NUMBER_OF_COLORS;

// Constants
#define POTENTIOMETER_MAX_VAL 4096
#define MAX_COMPETITORS 4
#define MIN_COMPETITORS 2
#define LOG_FILE_NAME "run_data.log"

// Global vars
int distance = 0;
int num_competitors = 0;
pid_t competitors[MAX_COMPETITORS];

void (*colors[])(BL_GPIO (&)[3]) = {
    blue_light,
    green_light,
    red_light,
    white_light,
    yellow_light,
    pink_light,
    cyan_light
};

void alarmFunction(int sig) {
    if (distance == 0) {
        // It's the father process, so read the file and show winner
        std::ifstream fs(LOG_FILE_NAME);
        int max_v = 0, max_c = 0, min_c = 0, curr_v, curr_c, fst = 1;
        while (fs >> curr_c >> curr_v) {
            if (curr_v > max_v)
                max_v = curr_v, max_c = curr_c;
            if (fst)
                min_c = curr_c, fst = 0;
            else if (curr_c < min_c)
                min_c = curr_c;
        }
        fs.close();

        // Button
        BL_GPIO button(BlackLib::GPIO_115, BL_IN, BL_SM);

        // Status Led
        BL_GPIO statusLed(BlackLib::GPIO_50, BL_OUT, BL_SM);

        //Led RGB
        BL_GPIO leds[3] = {
            BL_GPIO(BlackLib::GPIO_46, BL_OUT, BL_SM),
            BL_GPIO(BlackLib::GPIO_26, BL_OUT, BL_SM),
            BL_GPIO(BlackLib::GPIO_44, BL_OUT, BL_SM)
        };

        // Turn off the status led and shows the winner's color
        statusLed.TURN_OFF;
        colors[max_c - min_c](leds);

        // Wait for a button press to turn off
        while (!button.getNumericValue()) {}

        // reset everything and finish execution
        turn_off(leds);
    } else {
        // Append to log file the PID and the traveled distace (from current process)
        std::ofstream fs(LOG_FILE_NAME, std::ofstream::app);
        fs << getpid() << " " << distance << "\n";
        fs.close();
    }

    // Terminate the current process
    kill(getpid(), SIGTERM);
}

int main(int argc, char *argv[]) {
    // Alarm treatment
    signal(SIGALRM, alarmFunction);

    // Create variable to store the father pid
    int father = getpid();

    // Create an empty file to store the execution data
    std::ofstream fs(LOG_FILE_NAME, std::ofstream::trunc);
    fs.close();

    // Random Device
    std::random_device rd;

    // Button
    BL_GPIO button(BlackLib::GPIO_115, BL_IN, BL_SM);

    // Status Led
    BL_GPIO statusLed(BlackLib::GPIO_50, BL_OUT, BL_SM);

    //Led RGB
    BL_GPIO leds[3] = {
        BL_GPIO(BlackLib::GPIO_46, BL_OUT, BL_SM),
        BL_GPIO(BlackLib::GPIO_26, BL_OUT, BL_SM),
        BL_GPIO(BlackLib::GPIO_44, BL_OUT, BL_SM)
    };

    // Set led Status led and RGB led off
    statusLed.TURN_OFF;
    turn_off(leds);

    int fraction = POTENTIOMETER_MAX_VAL/(MAX_COMPETITORS - 1), potentiometer_val;

    while (!button.getNumericValue()) {
        potentiometer_val = readAnalog(1);
        num_competitors = potentiometer_val/fraction + MIN_COMPETITORS;

        colors[num_competitors - 2](leds);
    }

    // starting race
    turn_off(leds);
    statusLed.TURN_ON;

    // create 'num_competitors' process (with fork()) and set alarm to each one
    for (int i = 0; i < num_competitors; i++) {
        if (getpid() == father) {
            // Create competitor fork
            competitors[i] = fork();
            if (competitors[i] == -1)
                // Something wrong happened
                exit(1);
            else if (competitors[i] == 0)
                // Set competitor's alarm
                alarm(5);
            else
                // It's the parent process
                alarm(6);
        }
    }

    while (true) {
        if (getpid() != father) {
            distance += rd()%100;
            sleep(1);
        } else {
            // blink status led
            statusLed.TURN_ON;
            usleep(150000);
            statusLed.TURN_OFF;
            usleep(150000);
        }
    }

    return 0;
}
