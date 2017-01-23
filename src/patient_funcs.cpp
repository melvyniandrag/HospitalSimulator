#include "patient.h"
#include "nurse.h"
#include <vector>
#include <iostream>

namespace patientFuncs{

std::vector<Patient> get(int numPats){
    std::vector<Patient> pv;
    for(int i = 0; i < numPats; ++i){
        pv.push_back(Patient());
    }
    return pv;
}

void update(const std::vector<Nurse> nv, std::vector<Patient>& pv){
    std::cout << "In patientFuncs::update()" << std::endl;
}

}
