#include <SDL2/SDL.h>

void BlitSurface(SDL_Surface* mainSurface, SDL_Surface* image, int x, int y, int index, const double SCREEN_HEIGHT, const double SCREEN_WIDTH){
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    srcrect.x = 0;
    srcrect.y = 0;
    srcrect.w = SCREEN_WIDTH/6;
    srcrect.h = SCREEN_HEIGHT/4;

    dstrect.x = x * (SCREEN_WIDTH/3 + SCREEN_WIDTH/6) + SCREEN_WIDTH/3; 
    dstrect.y = y * (SCREEN_HEIGHT/2) + index * (SCREEN_HEIGHT/4);

    SDL_BlitSurface(image, &srcrect, mainSurface, &dstrect);
}


