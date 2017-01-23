#pragma once

#include "patient.h"
#include "nurse.h"
#include <vector>

namespace patientFuncs{
std::vector<Patient> get(int);

void update(const std::vector<Nurse>, std::vector<Patient>&);
}
