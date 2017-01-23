COMP = g++ -std=c++11
LINKER_FLAGS = -lSDL2 
COMPILER_FLAGS = -Wall
all: MyFirstGame

MyFirstGame: _main.o window.o
	$(COMP) $(COMPILER_FLAGS) _main.o window.o -o MyFirstGame $(LINKER_FLAGS)

_main.o: _main.cpp
	$(COMP) $(COMPILER_FLAGS) -c _main.cpp

window.o: window.cpp
	$(COMP) $(COMPILER_FLAGS) -c window.cpp $(LINKER_FLAGS)

clean:
	rm *.o
