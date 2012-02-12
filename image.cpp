#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <iostream>

#include "image.h"

using namespace std;

void img::SetSurface( SDL_Surface* surface ) 
{
	IMG = surface;	
}

bool img::load( string filename ) 
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load( filename.c_str() );

	cout << "\tLoading \"" << filename << "\"\t\t" << loadedImage << "\t\"" << id << "\"\n";

	if( loadedImage != NULL )
	{
        	SetSurface(loadedImage);

        	return true;
    	}
    	else
    	{
    		cout << "[!]\tError while loading \"" << filename << "\"\n";
    		cout << "\t" << IMG_GetError() << "\n";

    		return false;
    	}

	return false;
}
