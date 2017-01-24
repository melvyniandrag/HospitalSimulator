#include <iostream>
#include <chrono>
#include <thread>
#include "window.h"

int main(){

    const int numPatients = 4; // dont change this
    const int numNurses = 2; // and dont change this
    const int numIts = 10;
    const int sleepTime = 1;
    Window w = Window(numNurses, numPatients, numIts, sleepTime);
    int status = w.main();
    return status;
}
