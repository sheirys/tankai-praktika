
#include <stdio.h>

#include <SDL/SDL.h>
#include "Engine.h"
#include "Busena.h"
#include "Intro.h"
#include <SDL/SDL_mixer.h>

Intro Intro::m_IntroState;

void Intro::Init()
{
    //SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    IntroMusic = Mix_LoadMUS( "data/sound/intro.wav" );
    if(!IntroMusic)
        std::cout<<Mix_GetError()<<std::endl;

	SDL_Surface* temp = SDL_LoadBMP("data/img/intro.bmp");

	bg = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	// Sukuriame Surface su alfa sluoksniu
	fader = SDL_CreateRGBSurface( SDL_SRCALPHA, bg->w, bg->h,
								  bg->format->BitsPerPixel,
								  bg->format->Rmask, bg->format->Gmask,
								  bg->format->Bmask, bg->format->Amask );

	// Uzpildome sukurta sluoksni su pasirinkta spalva
	SDL_FillRect (fader, NULL, SDL_MapRGB (bg->format, 0, 0, 0)) ;

	// alfa blendingo reiksme nurodome visiskai nepermatoma
	alpha = 255;
	SDL_SetAlpha(fader, SDL_SRCALPHA, alpha);
	Mix_PlayMusic(IntroMusic, 0);
}

void Intro::Cleanup()
{
	SDL_FreeSurface(fader);
	SDL_FreeSurface(bg);
	Mix_FreeMusic(IntroMusic);
}

void Intro::Pause()
{
}

void Intro::Resume()
{
}
void Intro::HandleEvents(Engine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_SPACE:
						game->ChangeState( Meniu::Instance());
						break;

					case SDLK_ESCAPE:
						game->Quit();
						break;
				}
				break;
		}
	}
}

void Intro::Update(Engine* game)
{
	alpha--;

	if (alpha < 0)
		alpha = 0;

	SDL_SetAlpha(fader, SDL_SRCALPHA, alpha);
}

void Intro::Draw(Engine* game)
{
	SDL_BlitSurface(bg, NULL, game->screen, NULL);

	// Tikriname ar isnykstantis sluoksnis nera permatomas.
	// Jei permatomas jo nepiesiame
	if ( alpha != 0 )
		SDL_BlitSurface(fader, NULL, game->screen, NULL);

	SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}
