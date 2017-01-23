#pragma once

#include "patient.h"
#include <vector>

namespace patientFuncs{

std::vector<Patient> getPatientVector(){
    std::vector<Patient> pv;
    int numPats = 16;
    for(int i = 0; i < numPats; ++i){
        pv.push_back(Patient());
    }
    return pv;
}

}
