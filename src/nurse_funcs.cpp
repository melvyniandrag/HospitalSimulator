#include <vector>
#include "nurse.h"
#include "nurse_funcs.h"
#include "patient.h"
#include <iostream>

namespace nurseFuncs{

std::vector<Nurse> get(int numNurses){
    std::vector<Nurse> nv;
    for (int i = 0; i < numNurses; ++i){
        nv.push_back(Nurse());
    }
    return nv;
}

void update(std::vector<Nurse>& nv, const std::vector<Patient> pv){
    std::cout << "In nurseFuncs::update()" << std::endl;
}

}
