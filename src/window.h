/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

class Window{
public:
    Window();
    void drawRectangle();
    ~Window();
private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    const int SCREEN_WIDTH=640;
    const int SCREEN_HEIGHT=480; 
};
