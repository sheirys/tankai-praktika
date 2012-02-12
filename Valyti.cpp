#include "Core.h"

void Core::Valyti()
{

    //cout<<"valob benderi"<<endl;
    //SDL_FreeSurface(Benderis);
   // cout<<"valom ekrana"<<endl;
    SDL_FreeSurface(Ekranas);
    //cout<<"isvalem ekranà"<<endl;
    //Anim.~Animacija();
    SDL_Quit();
}
