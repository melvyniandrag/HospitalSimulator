#pragma once

#include "nurse.h"
#include <vector>

namespace nurseFuncs{

std::vector<Nurse> get(int numNurses){
    std::vector<Nurse> nv;
    for (int i = 0; i < numNurses; ++i){
        nv.push_back(Nurse());
    }
    return nv;
}
}
