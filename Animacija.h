#ifndef _ANIMACIJA_H_
    #define _ANIMACIJA_H
 #include <vector>
 #include <string>
 #include <sstream>
 #include "ImageLoader.h"
 #include <SDL/SDL_image.h>

using namespace std;
struct Vieta
{
    int x;
    int y;
    int kadras;
};

class Animacija
{
    private:
        vector<SDL_Surface*> AuraFlame;
        vector<SDL_Surface*> B;
    public:
        vector <Vieta> Sprogimai;

        Animacija(ImageLoader& anim);
        Animacija();
        ~Animacija();
        void Atnaujinti();

        void AddBum(int x, int y);
        SDL_Surface* GetFrame(int kuris);

};
#endif
