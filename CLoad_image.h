#ifndef _CLoad_image_H_
    #define _CLoad_image_H_
#include <string>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Load
{
    public:
        Load();
        static SDL_Surface* load_img(std::string Pavadinimas);
        static bool draw_img(int x, int y, SDL_Surface *Kur, SDL_Surface *Ka);
        static bool draw_img(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);
};

#endif
