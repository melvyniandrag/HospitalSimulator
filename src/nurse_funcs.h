#pragma once

#include "nurse.h"
#include <vector>
#include "nurse.h"
#include "patient.h"

namespace nurseFuncs{
std::vector<Nurse> get(int);

void update(std::vector<Nurse>&, const std::vector<Patient>);
}
