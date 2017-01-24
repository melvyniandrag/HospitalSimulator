#include "patient.h"
#include "nurse.h"
#include <vector>
#include <iostream>

namespace patientFuncs{

std::vector<Patient> get(int numPats){
    std::vector<Patient> pv;
    for(int i = 0; i < numPats; ++i){
        if (i==0)
            pv.push_back(Patient(0, 0));
        if (i == 1)
            pv.push_back(Patient(0, 1));
        if (i == 2)
            pv.push_back(Patient(1, 0));
        if (i == 3)
            pv.push_back(Patient(1, 1));
    }
    return pv;
}

void update(const std::vector<Nurse> nv, std::vector<Patient>& pv){
    std::cout << "In patientFuncs::update()" << std::endl;
}

}
