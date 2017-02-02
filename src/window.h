#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include "nurse.h"
#include "patient.h"

class Window{
public:
    Window(const int _numNurses, const int _numPatients, const int _numIts, const int _sleepTime);
    int main();
    void update();
    ~Window();
private:
    friend void BlitSurface(SDL_Surface*, SDL_Surface*, int, int, int, const double, const double);
    int sleepTime;
    int numIts;
    SDL_Window* window = NULL;
    SDL_Surface* mainSurface = NULL;
    SDL_Surface* noNurseImage = NULL;
    SDL_Surface* nurseImage = NULL;
    SDL_Surface* sickImage = NULL;
    SDL_Surface* deadImage = NULL;
    SDL_Surface* healthyImage = NULL;
    const double SCREEN_WIDTH=768;
    const double SCREEN_HEIGHT=512; 
    std::vector<Patient> pv;
    std::vector<Nurse> nv;
};
