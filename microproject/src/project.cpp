#include "BlackGPIO.h"
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

int main(int argc, char *argv[]) {
    // Button
    BlackLib::BlackGPIO button(BlackLib::GPIO_115, BlackLib::input, BlackLib::SecureMode);

    // Status Led
    BlackLib::BlackGPIO statusLed(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);

    //Led RGB
    BlackLib::BlackGPIO ledR1(BlackLib::GPIO_65,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO ledR2(BlackLib::GPIO_46,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO ledG(BlackLib::GPIO_26,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO ledB(BlackLib::GPIO_44,BlackLib::output, BlackLib::SecureMode);

    // Set everything to "default" values
    statusLed.setValue(BlackLib::high);
    ledR1.setValue(BlackLib::high);
    ledR2.setValue(BlackLib::high);
    ledG.setValue(BlackLib::high);
    ledB.setValue(BlackLib::high);

    printf("Executando o programa, clique no botão para parar!\n");
    while (!button.getNumericValue()) {}
    printf("Programa encerrado, desligando leds\n");

    // Reset everything
    ledR1.setValue(BlackLib::low);
    ledR2.setValue(BlackLib::low);
    ledG.setValue(BlackLib::low);
    ledB.setValue(BlackLib::low);
    statusLed.setValue(BlackLib::low);

    return 0;
}
