#include <vector>
#include "nurse.h"
#include "nurse_funcs.h"
#include "patient.h"
#include <iostream>
#include <cstdlib>

namespace nurseFuncs{

std::vector<Nurse> get(int numNurses){
    std::vector<Nurse> nv;
    for (int i = 0; i < numNurses; i++){
        nv.push_back(Nurse(i));
    }
    return nv;
}

void update(std::vector<Nurse>& nv, const std::vector<Patient> pv){
    std::cout << "In nurseFuncs::update()" << std::endl;
    std::vector<Nurse>::iterator it;
    for(it = nv.begin(); it != nv.end(); it++){
        int random_x = rand() % nv.size(); 
        int random_y = rand() % nv.size(); 
        it->current_x = random_x;
        it->current_y = random_y;
    }
}

}
