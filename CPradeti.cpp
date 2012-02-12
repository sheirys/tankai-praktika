#include "Core.h"
using namespace std;
bool Core::Pradeti()
{

 if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
 {
     return false;
 }
 Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
 Mix_Volume(-1, 10);

 bomba   = Mix_LoadWAV( "bum.wav" );
//f18  = Mix_LoadWAV( "f18.wav" );

 if(data.options.fullscreen)// Jei options.txt nurodyta fulscrean darom ff
{
    if((Ekranas = SDL_SetVideoMode(data.options.width, data.options.height, C_DEPTH, SDL_SWSURFACE | SDL_DOUBLEBUF| SDL_FULLSCREEN)) == NULL)
    {
     return false;
    }
}
else if((Ekranas = SDL_SetVideoMode(data.options.width, data.options.height, C_DEPTH, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
       {
            return false;
       }

//SDL_Surface* temp = new SDL_Surface;

Tk =  Load::load_img("g.png");
/*
Uint32 colorkey = SDL_MapRGB( temp->format, 0, 255, 0 );
SDL_SetColorKey( temp, SDL_SRCCOLORKEY, colorkey );

Tk= SDL_DisplayFormatAlpha(temp);
std::swap(temp, Tk);
SDL_FreeSurface(temp);
delete(temp);*/


//Lektuvas LL(250, 350, 0, 5, 0);
//Tempp = LL.GetSurface(1);
//Lektuvas Ll(800, 300, 180, 5, 0);
//Lektuvai.push_back(LL);
//Mix_PlayChannel( -1, f18, 0 );


//Lektuvai.push_back(Ll);
//LL.~Lektuvas();
//Ll.~Lektuvas();

 //if(!L.load())
 {
    // return false;
 }

 data.load_map("test.map");


  return true;
}
