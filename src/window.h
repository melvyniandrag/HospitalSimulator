#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include "nurse.h"
#include "patient.h"

class Window{
public:
    Window();
    int main(int numIts, int sleepTime, std::vector<Patient> pv, std::vector<Nurse> nv);
    void drawRectangle();
    void update(const std::vector<Nurse>, const std::vector<Patient>);
    ~Window();
private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    const int SCREEN_WIDTH=640;
    const int SCREEN_HEIGHT=480; 
};
