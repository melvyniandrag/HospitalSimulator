#pragma once

#include <string>

class Patient{
public:
    Patient(int _x_pos, int _y_pos);
    int time_til_death;
    std::string status;
    int x_pos;
    int y_pos;
};
