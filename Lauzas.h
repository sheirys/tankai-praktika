#ifndef _LAUZAS_H_
    #define _LAUZAS_H_
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;
class Lauzas
{
    private:
        vector<SDL_Surface*> kadrai;//kadru vektorius
        int kuris;//kuris kadras bus grazintas
    public:
        Lauzas();

        bool load();

        SDL_Surface* Gauti_Kadra();
};

#endif
