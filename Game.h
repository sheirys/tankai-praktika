#ifndef _GAME_H_
    #define _GAME_H_
#include <vector>
#include <stdio.h>
#include <sstream>
#include "SDL/SDL.h"
#include "Busena.h"

#include "Engine.h"
#include "Meniu.h"
#include "ImageLoader.h"
#include "Animacija.h"
#include "Tankas.h"
#include "Susidurimai.h"
#include "data.h"
#include "Extract.h"

#include "network.h"

using namespace std;
class Game : public Busena
{
public:
//-------------------------------------
ImageLoader images; //Surfeisu baze (saugomi visi uzkrauti paveksleliai)
Animacija anim;     //Animacijos
//-------------------------------------
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static Game* Instance()
    {
		return &m_PlayState;
	}

protected:
	Game() { }

private:

bool ArYra(int ID); //tikrina ar yra tankas, apie kuri gauti duomenys
int kiekP;
data_loader data;
//-------------------------------------
    bool upup;
    bool updw;
    bool upka;
    bool upde;
//-------------------------------------
int px, py; //peles kooedinates
vector<Tankas*> tankai;//Saugo visus zaidime esancius tankus
vector<Kulka* > kulkos;//saugo visas zaidime esancias issautas kulkas
//-------------------------------------
network net;
Extract D;
//-------------------------------------
	static Game m_PlayState;
	SDL_Surface* bg;
};

#endif
