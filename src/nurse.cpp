#include "nurse.h"
#include <string>

Nurse::Nurse(int _y_index){
    std::string _name = "Betsy";
    name = _name;
    current_x = 1;
    current_y = 1;
    y_index = _y_index;
}
