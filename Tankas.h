#ifndef _TANKAS_H_
    #define _TANKAS_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>


#include "Konstantos.h"
#include "CLoad_image.h"
#include "Kulka.h"
#include "Susidurimai.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_mixer.h>

using std::vector;
class Tankas
{
    private:
        int ID;//Tanko id. Kiekvienas turi unikalu id
        bool gyvas;//ar tankas egzistuoja
        bool sprogsta; //ar tankas jau sprogimo stadijoje
        short int gyvybe;
//-------------------------------------
        double kampas;
        double senas_kampas;
        double senas_kampasP;
        int X, Y;//Tanko surfeiso koordinates
        double pk;//kampas kurio reikia pasukti vamzdi, kad jis butu nukreiptas i zimekli
        double vk;//vamzdzio kampas neisk tanko padieties

        vector<SDL_Surface*> TS1;

        static const int T_AUKSTIS = 100;
        static const int T_PLOTIS  = 100;
        static const int D         = 3;

        Mix_Music *Grotuvas;

        Mix_Chunk *TankasStovi;
        Mix_Chunk *TankasVaziuoja;
        Mix_Chunk *TankasStoja;


        SDL_Surface*   Tanks;   //pagrindinis tanko surfeisas
        SDL_Surface*   Patranka;//tanko vmzd pagrindinis

        int lastW;//paskutinio surfeiso iki sprogimo plotis
        int lastH;

        int Kuris_kadras;
        void Sprogimas();

    public:
        //Surface, kuri grazina
        SDL_Surface*   rotation;

        Tankas(int ID = 0,  int x =50, int y=50, double angle=0);
        void veiksmas(int kur, int mode, int xp, int yp);
        void Inicijuoti();
        void Sauti();
        int load_image();
        void atnaujinti(int xp, int yp, vector<Kulka*> &kulkos);
        int getX();
        int getY();
        double GetAngle();
        int GetID();

        bool GetBusena(); //grazina true jei tankas dar gyvas
        bool Normal();
        short int hp();   //grazina kiek liko gyvkiu
        void SendXY(int x, int y);

        void render(SDL_Surface* Ekranas);
        //Grazina koordinates kurios bus pavaziavus pasirinkta kryptimi
        /**
        @param kur nurodo kuria kryptimi vaziuos: 0 pirmyn 1 atgal. Pagal nutylejima pirmyn
        **/
        int GetNextX(unsigned short int kur);
        int GetNextY(unsigned short int kur);
        SDL_Rect dst;
};
#endif

