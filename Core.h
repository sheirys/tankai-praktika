#ifndef _Core_H_
    #define _Core_H_

#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_net.h>

#include "ImageLoader.h"

#include "data.h"
#include "CLoad_image.h"
#include "Tankas.h"
#include "AutoBaze.h"


#include "Lauzas.h"
#include "Kulka.h"
#include "timer.h"
#include "Animacija.h"

#include "Susidurimai.h"


#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <sstream>


class Core{
 private:

        ImageLoader images;
        SDL_Surface*   Patranka;
        Mix_Chunk *bomba;
        SDL_Surface *Tempp;
        Mix_Chunk* f18;
        int kiek; //lauzo kadrai;

        SDL_Surface* fire;
        vector<SDL_Surface*> ugnis;
        vector<Kulka> K;

 bool upup;
 bool updw;
 bool upka;
 bool upde;

int   xp, yp; //peles koordinated

    int frame;
    bool cap;

    static const int C_DEPTH  = 32; //Spalvè gylis bitais

    SDL_Surface*   Tk;
    //SDL_Surface*   Tw;
   // SDL_Surface* Laikinas;
    //SDL_Surface* Laikinas1;
    SDL_Rect camera;
    bool busena;
    int kuris;
    std::vector< SDL_Surface* > A;                  //jei busena taps false programa baigas darba
//-----------------------------------------------------------------------------
//vector<Lektuvas> Lektuvai;
//-----------------------------------------------------------------------------
//void (*meniu) ();//pointeris · meniu metod‡
int  (Core::*game)();//pointeris · zaidimo metod‡
//void (Core::*iseiti)();//pointeris · darbo pabaigos metod‡
//stack<void (core::*)> sekcijos;
//-----------------------------------------------------------------------------
 public:
    bool Susidure;

    SDL_Surface*   Ekranas;
    Tankas T;

    Animacija Anim;

    Core();                         //Konstruktorius

    int  Vykdyti();                 //Grazina darbo babaigos koda
    int run();

    data_loader data;
    bool Pradeti();                 //Inicijuojamas programos darbas
    void OnEvent(SDL_Event* Event);
    void OnExit();

    void Zemyn();
    void CAtnaujinti();
    void Loop();
    void Render();
    void Valyti();

   // void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);


};
#endif
