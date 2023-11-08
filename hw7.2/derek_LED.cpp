#include "derek_LED.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

LED::LED(int number) {
    this->number = number;
    std::ostringstream s;
    s << LED_PATH << number;
    path = s.str();
}

void LED::writeLED(std::string filename, std::string value) {
    std::ofstream fs;
    fs.open((path + filename).c_str());
    fs << value;
    fs.close();
}

void LED::removeTrigger() {
    writeLED("/trigger", "none");
}

void LED::turnOn() {
    std::cout << "Turning LED" << number << " on." << std::endl;
    removeTrigger();
    writeLED("/brightness", "1");
}

void LED::turnOff() {
    std::cout << "Turning LED" << number << " off." << std::endl;
    removeTrigger();
    writeLED("/brightness", "0");
}

void LED::blink(int num) {
	for(int i = 0; i < num; i++) {
		removeTrigger();
		turnOn();
		sleep(1);
		turnOff();
		sleep(1);
	}
}

void LED::flash(std::string delayms) {
    std::cout << "Making LED" << number << " flash." << std::endl;
    writeLED("/trigger", "timer");
    writeLED("/delay_on", delayms);
    writeLED("/delay_off", delayms);
}

void LED::outputState() {
    std::ifstream fs;
    fs.open((path + "/trigger").c_str());
    std::string line;
    while (getline(fs, line))
        std::cout << line << std::endl;
    fs.close();
}

LED::~LED() {
    std::cout << "Destroying the LED with path: " << path << std::endl;
}

