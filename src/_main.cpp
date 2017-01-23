#include <iostream>
#include "window.h"
#include "patient_funcs.h"
#include "patient.h"

int main(){
    Window w = Window();
    std::vector<Patient> pv = patientFuncs::getPatientVector();
    for(auto p : pv){
        std::cout << p.time_til_death << std::endl;
    }
}
