/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <chrono>
#include <thread>

//Screen dimension constants
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* sickImage = NULL;
SDL_Surface* deadImage = NULL;
SDL_Surface* healthyImage = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	sickImage = SDL_LoadBMP( "../images/square_sick.bmp" );
	if( sickImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_sick.bmp", SDL_GetError() );
		success = false;
        return success;
	}
  
	deadImage = SDL_LoadBMP( "../images/dead.bmp" );
	if( deadImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "dead.bmp", SDL_GetError() );
		success = false;
	    return success;
    }

 
	healthyImage = SDL_LoadBMP( "../images/square_healthy.bmp" );
	if( healthyImage == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "square_healthy.bmp", SDL_GetError() );
		success = false;
	    return success;
    }


	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( deadImage );
	deadImage = NULL;

	SDL_FreeSurface( sickImage );
	sickImage = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{			
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}


                SDL_Rect srcrect1;
                SDL_Rect dstrect1;
                
                srcrect1.x = 0;
                srcrect1.y = 0;
                srcrect1.w = SCREEN_WIDTH/2;
                srcrect1.h = SCREEN_HEIGHT/2;
                dstrect1.x = 0;
                dstrect1.y = 0;
                dstrect1.w = SCREEN_WIDTH/2;
                dstrect1.h = SCREEN_HEIGHT/2;

                SDL_Rect srcrect2;
                SDL_Rect dstrect2;
                
                srcrect2.x = 0;
                srcrect2.y = 0;
                srcrect2.w = SCREEN_WIDTH;
                srcrect2.h = SCREEN_HEIGHT;
                dstrect2.x = 0;
                dstrect2.y = SCREEN_HEIGHT/2;
                dstrect2.w = SCREEN_WIDTH/2;
                dstrect2.h = SCREEN_HEIGHT/2;

                SDL_Rect srcrect3;
                SDL_Rect dstrect3;
                
                srcrect3.x = 0;
                srcrect3.y = 0;
                srcrect3.w = SCREEN_WIDTH;
                srcrect3.h = SCREEN_HEIGHT;
                dstrect3.x = SCREEN_WIDTH/2;
                dstrect3.y = 0;
                dstrect3.w = SCREEN_WIDTH/2;
                dstrect3.h = SCREEN_HEIGHT/2;




                SDL_Rect srcrect4;
                SDL_Rect dstrect4;
                
                srcrect4.x = 0;
                srcrect4.y = 0;
                srcrect4.w = SCREEN_WIDTH;
                srcrect4.h = SCREEN_HEIGHT;
                dstrect4.x = SCREEN_WIDTH/2;
                dstrect4.y = SCREEN_HEIGHT/2;
                dstrect4.w = SCREEN_WIDTH/2;
                dstrect4.h = SCREEN_HEIGHT/2;


				//Apply the image
				SDL_BlitSurface( deadImage, &srcrect1, gScreenSurface, &dstrect1 );
				SDL_BlitSurface( sickImage, &srcrect4, gScreenSurface, &dstrect2 );
				SDL_BlitSurface( sickImage, &srcrect3, gScreenSurface, &dstrect3 );
				SDL_BlitSurface( healthyImage, &srcrect2, gScreenSurface, &dstrect4 );
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
