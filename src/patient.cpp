#include "patient.h"
#include <string>

Patient::Patient(int _x_pos, int _y_pos){
    time_til_death=10;
    status = "alive";
    x_pos = _x_pos;
    y_pos = _y_pos;
}

