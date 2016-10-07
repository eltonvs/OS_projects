#ifndef _macros_h_
#define _macros_h_

#include "BlackGPIO.h"

// Macros
#define TURN_ON setValue(BlackLib::high)
#define TURN_OFF setValue(BlackLib::low)
#define BL_GPIO BlackLib::BlackGPIO

#endif
