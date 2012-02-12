#include <stdio.h>


#include "Engine.h"
#include "Busena.h"
#include "Meniu.h"
#include "Game.h"
#include "Konstantos.h"
Meniu Meniu::m_Meniu;

void Meniu::Init()
{
	SDL_Surface* temp = IMG_Load("data/img/Meniu4.jpg");
	bg = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
//-----------------------------------------------------------------------------
 Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
MeniuMusic = Mix_LoadMUS("data/sound/Meniu.wav");
if(!MeniuMusic)
    std::cout<<Mix_GetError()<<std::endl;
Mix_PlayMusic(MeniuMusic,1);

   /*knopke naus;
   naus.Mygtukas.set(W_HEIGHT/2 - bH/2 - 2*bH - 2*tarpas, bH, bW, "New game");
   Head.Mygtukas.set(W_HEIGHT/2 - bH/2 - 2*bH - 2*tarpas, bH, bW, "New game");
   Head.kitas=&naus;//Mygtukas.set(W_HEIGHT/2-bH/2 - bH -  tarpas, bH, bW, "Multiplayer");
   Head.kitas->kitas->Mygtukas.set( W_HEIGHT/2 - bH/2, bH, bW, "Setings");
   //--------------------------------------------------------------------------
   Head.kitas->kitas->kitas->Mygtukas.set(W_HEIGHT/2  + (bH/2 + tarpas), bH, bW, "About");

   //--------------------------------------------------------------------------
   Head.kitas->kitas->kitas->kitas->Mygtukas.set(W_HEIGHT/2+(bH/2 + bH+2*tarpas ), bH, bW, "Quit");
   Head.kitas->kitas->kitas->kitas->kitas=&Head;
   Head.kitas->kitas->kitas->kitas->buves= Head.kitas->kitas->kitas;*/

  // Head.kitas->buves=&Head;
    //M.kitas.kitas.set( W_HEIGHT/2 - bH/2, bH, bW, "Setings");
    MygtukuSarasas = new DLCL;
//-----------------------------------------------------------------------------
    Button* b1;
    b1 = new Button;
    b1->set(W_HEIGHT/2 - bH/2 - 2*bH - 2*tarpas, bH, bW, "New game");
    MygtukuSarasas->insert(b1);
//-----------------------------------------------------------------------------
    Button* b2;
    b2 = new Button;
    b2->set(W_HEIGHT/2-bH/2 - bH -  tarpas, bH, bW, "Multiplayer");
    MygtukuSarasas->insert(b2);

//-----------------------------------------------------------------------------
    Button* b3;
    b3 = new Button;
    b3->set( W_HEIGHT/2 - bH/2, bH, bW, "Settings");
    MygtukuSarasas->insert(b3);
//-----------------------------------------------------------------------------
    Button* b4;
    b4 = new Button;
    b4->set(W_HEIGHT/2  + (bH/2 + tarpas), bH, bW, "About");
    MygtukuSarasas->insert(b4);
//-----------------------------------------------------------------------------
    Button* b5;
    b5 = new Button;
    b5->set(W_HEIGHT/2+(bH/2 + bH+2*tarpas ), bH, bW, "Quit");
    MygtukuSarasas->insert(b5);
//-----------------------------------------------------------------------------



    Naujas.set(W_HEIGHT/2 - bH/2 - 2*bH - 2*tarpas, bH, bW, "New game");

    Multiplayer.set(W_HEIGHT/2-bH/2 - bH -  tarpas, bH, bW, "Multiplayer");

    Nustatymai.set( W_HEIGHT/2 - bH/2, bH, bW, "Settings");//per lango viduri

    Apie.set(W_HEIGHT/2  + (bH/2 + tarpas), bH, bW, "About");
    Iseiti.set(W_HEIGHT/2+(bH/2 + bH+2*tarpas ), bH, bW, "Quit");


}

void Meniu::Cleanup()
{
	SDL_FreeSurface(bg);
	Mix_FreeMusic(MeniuMusic);
	//reikes isvalyti visus mygtukus db tyngiu
}

void Meniu::Pause()
{
    Mix_PauseMusic();

}

void Meniu::Resume()
{
    Mix_ResumeMusic();
}

void Meniu::HandleEvents(Engine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
{

		switch (event.type)
		 {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
                        //game->PushState( Intro::Instance());
                        //game->ChangeState(Game::Instance());
						game->PopState();
						break;
				}
				break;
			case SDL_MOUSEMOTION:
			{
                x=event.motion.x;
                y=event.motion.y;
			}
            case SDL_MOUSEBUTTONUP:
            {
              if (event.button.button == (SDL_BUTTON_LEFT))
               {
                    //Tikriname ar paspaudeme ant isejimo knopkes
                    if(MygtukuSarasas->front->next->next->next->next->mygtukas->MouseOn(x, y))//Iseiti.MouseOn(x, y))
                        game->Quit();
                    //Tikriname ar paspaudeme ant pradeti knopkes
                    if(MygtukuSarasas->front->mygtukas->MouseOn(x, y))
                    {
                        Pause();
                        game->ChangeState(Game::Instance());
                        Resume();
                    }




               }
            }
		}
	}
}

void Meniu::Update(Engine* game)
{/*
    Naujas.MouseOn(x, y);
    Multiplayer.MouseOn(x, y);
    Nustatymai.MouseOn(x, y);
    Apie.MouseOn(x, y);
    Iseiti.MouseOn(x, y);*/
    	Node* t;
	t = MygtukuSarasas->front;
    while(1)
    {
        t->mygtukas->MouseOn(x, y);
        t=t->next;
        if(t == MygtukuSarasas->front)
            break;
    }
}

void Meniu::Draw(Engine* game)
{
	SDL_BlitSurface(bg, NULL, game->screen, NULL);

	Node* t;
	t = MygtukuSarasas->front;
    while(1)
    {
        t->mygtukas->Draw(game);
        t=t->next;
        if(t == MygtukuSarasas->front)
            break;
    }
	/*Naujas.Draw(game);
	Multiplayer.Draw(game);
	Nustatymai.Draw(game);
	Apie.Draw(game);
	Iseiti.Draw(game);*/
	//MygtukuSarasas.back->next->mygtukas->Draw(game);
	SDL_Flip(game->screen);
    //SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}
