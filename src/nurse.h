#pragma once

#include <string>

class Nurse{
public:
    Nurse(int _y_index);
    std::string name;
    int current_x;
    int current_y;
    int y_index;
};
