#include <iostream>
#include "window.h"
#include "patient.h"
#include "nurse.h"
#include "nurse_funcs.h"
#include "patient_funcs.h"
#include <chrono>
#include <thread>

int main(){
    Window w = Window();

    const int numPatients = 4;
    std::vector<Patient> pv = patientFuncs::get(numPatients);

    const int numNurses = 3; 
    std::vector<Nurse> nv = nurseFuncs::get(numNurses);

    const int numIts = 10;
    const int sleepTime = 3;
    int status = w.main(numIts, sleepTime, pv, nv);
    return status;
}
