/**Simple OOP structure for controlling LEDs on BeagleBone
*
*  This program uses all four LEDs and can be executed in three ways:
*     myApp on      (Turn on all LEDs)
*     myApp off     (Turn off all LEDs)
*     myApp flash   (Flash all LEDs at time delay intervals)
*     myApp status  (Get the trigger status of all LEDs)
*
*  Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
*  Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
*  ISBN 9781118935125. Please see the file README.md in the repository root
*  directory for copyright and GNU GPLv3 license information.
*/

#include "derek_LED.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage is myApp <command>" << std::endl;
        std::cout << "   command is one of: on, off, flash, or status" << std::endl;
        std::cout << " e.g. myApp flash" << std::endl;
    }

    std::cout << "Starting the myApp program" << std::endl;
    std::string cmd(argv[1]);
    LED leds[4] = {LED(0), LED(1), LED(2), LED(3)};

    for (int i = 0; i <= 3; i++) {
        if (cmd == "on")
            leds[i].turnOn();
        else if (cmd == "off")
            leds[i].turnOff();
        else if (cmd == "flash")
            leds[i].flash("100");  // Default is "50"
        else if (cmd == "status")
            leds[i].outputState();
        else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    std::cout << "Finished the myApp program" << std::endl;
    return 0;
}

