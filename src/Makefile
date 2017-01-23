COMP = g++ -std=c++11
LINKER_FLAGS = -lSDL2 
COMPILER_FLAGS = -Wall
all: HospitalSimulator

HospitalSimulator: _main.o window.o patient.o nurse.o patient_funcs.o nurse_funcs.o
	$(COMP) $(COMPILER_FLAGS) _main.o window.o patient.o nurse.o patient_funcs.o nurse_funcs.o -o HospitalSimulator $(LINKER_FLAGS)

_main.o: _main.cpp
	$(COMP) $(COMPILER_FLAGS) -c _main.cpp

window.o: window.cpp
	$(COMP) $(COMPILER_FLAGS) -c window.cpp $(LINKER_FLAGS)

patient_funcs.o: patient_funcs.cpp
	$(COMP) $(COMPILER_FLAGS) -c patient_funcs.cpp

nurse_funcs.o: nurse_funcs.cpp
	$(COMP) $(COMPILER_FLAGS) -c nurse_funcs.cpp

nurse.o: nurse.cpp
	$(COMP) $(COMPILER_FLAGS) -c nurse.cpp 

patient.o: patient.cpp
	$(COMP) $(COMPILER_FLAGS) -c patient.cpp

clean:
	rm *.o
