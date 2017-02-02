#include <SDL2/SDL.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cassert>
#include <thread>
#include "nurse.h"
#include "patient.h"
#include "nurse_funcs.h"
#include "patient_funcs.h"
#include "window.h"
#include "utility.h"

int Window::main(){
    SDL_Event e;
    for (int iteration = 0; iteration < numIts; ++iteration){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                return 0;
            }
        }

        std::cout << "Currently on iteration " << iteration << std::endl;
        // move the nurses
        nurseFuncs::update(nv, pv);
        // update the patients
        patientFuncs::update(nv, pv);
        // update the image

        this->update();

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


void Window::update(){
    std::cout << "In window.update()" << std::endl;
    for(auto p : this->pv){
        SDL_Rect srcrect;
        SDL_Rect dstrect;
        srcrect.x = 0;
        srcrect.y = 0;
        srcrect.w = SCREEN_WIDTH/3;
        srcrect.h = SCREEN_HEIGHT/2;

        dstrect.x = p.x_pos * (SCREEN_WIDTH/3 + SCREEN_WIDTH/6); 
        dstrect.y = p.y_pos * (SCREEN_HEIGHT/2);
        dstrect.w = SCREEN_WIDTH/3;
        dstrect.h = SCREEN_HEIGHT/2;
        if (p.status == std::string("alive")){
            SDL_BlitSurface(this->healthyImage, &srcrect, this->mainSurface, &dstrect);
        } else {
            if (p.status == std::string("sick")){
                SDL_BlitSurface(this->sickImage, &srcrect, this->mainSurface, &dstrect);
            } else { 
                 SDL_BlitSurface(this->deadImage, &srcrect, this->mainSurface, &dstrect);
            } 
        }
    }


    std::vector<std::thread> threads;
    for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
            for(int index = 0; index < 2; ++index){
                std::thread th(&BlitSurface, this->mainSurface, this->noNurseImage, x, y, index, this->SCREEN_HEIGHT, this->SCREEN_WIDTH);
                th.join();
                //threads.push_back((std::move(th)));
                //assert(!th.joinable());
            }
        }
    }
//    std::for_each(threads.begin(), threads.end(), [](std::thread & th){th.join();});

    for(auto n : this->nv){
        SDL_Rect srcrect;
        SDL_Rect dstrect;
        srcrect.x = 0;
        srcrect.y = 0;
        srcrect.w = SCREEN_WIDTH/6;
        srcrect.h = SCREEN_HEIGHT/4;

        dstrect.x = n.current_x * (SCREEN_WIDTH/3 + SCREEN_WIDTH/6) + SCREEN_WIDTH/3; 
        dstrect.y = n.current_y * (SCREEN_HEIGHT/2) + n.y_index * (SCREEN_HEIGHT/4);
        dstrect.w = SCREEN_WIDTH/6;
        dstrect.h = SCREEN_HEIGHT/4;
        SDL_BlitSurface(this->nurseImage, &srcrect, this->mainSurface, &dstrect);
    }

    SDL_UpdateWindowSurface( window );

}

Window::Window(const int _numNurses, const int _numPatients, const int _numIts, const int _sleepTime){
    // put some asserts here to make sure that the num nurses and patients will fit our window shape.

    pv = patientFuncs::get(_numPatients);
    nv = nurseFuncs::get(_numNurses);

    numIts = _numIts;
    sleepTime = _sleepTime;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else{
	    window = SDL_CreateWindow( "Hospital Simulator!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			mainSurface = SDL_GetWindowSurface( window );
		}
    }
 
    noNurseImage = SDL_LoadBMP( "../images/square_no_nurse.bmp" );
	if( noNurseImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_no_nurse.bmp", SDL_GetError() );
	}
 
    nurseImage = SDL_LoadBMP( "../images/square_nurse.bmp" );
	if( nurseImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_nurse.bmp", SDL_GetError() );
	}
   
    sickImage = SDL_LoadBMP( "../images/square_sick.bmp" );
	if( sickImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_sick.bmp", SDL_GetError() );
	}
  
	deadImage = SDL_LoadBMP( "../images/dead.bmp" );
	if( deadImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "dead.bmp", SDL_GetError() );
    }

	healthyImage = SDL_LoadBMP( "../images/square_healthy.bmp" );
	if( healthyImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_healthy.bmp", SDL_GetError() );
    } 
}

Window::~Window(){
    SDL_FreeSurface( mainSurface );
	mainSurface = NULL;

    SDL_FreeSurface( noNurseImage );
	noNurseImage = NULL;

    SDL_FreeSurface( nurseImage );
	nurseImage = NULL;

    SDL_FreeSurface( deadImage );
	deadImage = NULL;
    
    SDL_FreeSurface( healthyImage );
	healthyImage = NULL;


	SDL_FreeSurface( sickImage );
	sickImage = NULL;

    SDL_DestroyWindow( window );
    window = NULL;
    SDL_Quit();
}
