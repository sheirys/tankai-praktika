#ifndef _KULKA_H_
    #define _KULKA_H_

#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

#include "CLoad_image.h"

#include "ImageLoader.h"
class Kulka
{
    private:
       int  X, Y;
       double kampas;
       SDL_Surface* Klk;
       bool begin();
       bool begin(ImageLoader& images);
    public:
        SDL_Surface* KPasukta;

        Kulka(int X, int Y, double kampas);
        ~Kulka();

        int GetX();
        int GetY();
        void Atnaujinti();
};
#endif
