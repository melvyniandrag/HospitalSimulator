#pragma once

#include "patient.h"
#include <vector>

namespace patientFuncs{

std::vector<Patient> get(int numPats){
    std::vector<Patient> pv;
    for(int i = 0; i < numPats; ++i){
        pv.push_back(Patient());
    }
    return pv;
}

}
