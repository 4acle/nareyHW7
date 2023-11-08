/**Simple OOP structure for controlling LEDs on BeagleBone
*
*  This program uses all four LEDs and can be executed in three ways:
*     myBlink on      (Turn on an LED)
*     myBlink off     (Turn off an LED)
*     myBlink flash   (Flash all LEDs at time delay intervals)
*     myBlink status  (Get the trigger status of all LEDs)
*     myBlink blink 	(Blink an LED a number of times)
*
*     Example: ./myBlink blink 2 5
*
*  Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
*  Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
*  ISBN 9781118935125. Please see the file README.md in the repository root
*  directory for copyright and GNU GPLv3 license information.
*/

#include "derek_LED.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Usage is myBlink <cmd> <led> <num>" << endl;
        cout << "where <cmd> is on, off, blink, or status" << endl;
        cout << "and <led> is 0, 1, 2, or 3" << endl;
        cout << "and <num> is the number of times for blink" << endl;
        return 2;
    }
    string cmd(argv[1]);
    int ledNum = stoi(argv[2]);
    LED led(ledNum);
    int num = stoi(argv[3]);
    if(cmd == "on") led.turnOn();
    else if(cmd == "off") led.turnOff();
    else if(cmd == "blink") led.blink(num);
    else if(cmd == "status") led.outputState();
    else cout << "Invalid command!" << endl;

    std::cout << "Finished the myApp program" << std::endl;
    return 0;
}


