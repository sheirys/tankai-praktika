#include "CEvents.h"
CEvents::CEvents()
 {
 }

 CEvents::~CEvents()
 {
 }

void CEvents::OnEvent(SDL_Event* Event)
{
    switch(Event->type)
    {

        case SDL_KEYDOWN:
        {
            if(Event->key.keysym.sym==SDLK_SPACE)
                {

                }
            break;
        }


        case SDL_QUIT:
        {
            OnExit();
            break;
        }
    }
}

 void CEvents::OnExit()
{
}
void CEvents::Zemyn()
{
}

