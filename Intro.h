#ifndef _INTRO_H_
    #define _INTRO_H_

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "Busena.h"
#include "Meniu.h"

class Intro : public Busena
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);

	static Intro* Instance()
	{
		return &m_IntroState;
	}

protected:
	Intro(){};

private:
	static Intro m_IntroState;

    Mix_Music *IntroMusic;
	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;
};
#endif
