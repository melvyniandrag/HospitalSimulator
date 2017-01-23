#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "window.h"
#include <thread>
#include <chrono>
#include <vector>
#include "nurse.h"
#include "patient.h"

int Window::main(int numIts, int sleepTime, std::vector<Patient> pv, std::vector<Nurse> nv){
    SDL_Event e;
    for (int iteration = 0; iteration < numIts; ++iteration){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                return 0;
            }
        }

        std::cout << "Currently on iteration " << iteration << std::endl;
        
        for(auto p : pv){
            std::cout << p.time_til_death << std::endl;
        }

        for(auto n :  nv){
            std::cout << n.name << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    }
    return 0;
}

Window::Window(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else{
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
            printf( "Warning: Linear texture filtering not enabled!" );
        }
    
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else{
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL ){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            }
            else{
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }
}

Window::~Window(){
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    SDL_Quit();
}


void Window::drawRectangle(){
    bool quit = false;
    SDL_Event e;
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
 
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
 
        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );        
        SDL_RenderFillRect( renderer, &fillRect );
        
        SDL_Rect outlineRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
        SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );        
        SDL_RenderDrawRect( renderer, &outlineRect );
        
        SDL_RenderPresent( renderer );
    }
}
