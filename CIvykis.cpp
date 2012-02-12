#include "Core.h"
#include <string>

void Core::OnEvent(SDL_Event* Event)
{

    switch(Event->type)
    {

        case SDL_KEYDOWN:
        {
            if(Event->key.keysym.sym== SDLK_ESCAPE)
            {
                busena=false;
                break;
            }

            if(Event->key.keysym.sym==SDLK_UP)
            {
               upup=false;
               //T.veiksmas(2,1);
               break;
            }

            if(Event->key.keysym.sym==SDLK_DOWN)
            {
                updw=false;
               //T.veiksmas(1,1);
               break;
            }

            if(Event->key.keysym.sym==SDLK_RIGHT)
            {
                upde=false;
              // T.veiksmas(3,1);
               break;
            }
            if(Event->key.keysym.sym==SDLK_LEFT)
            {
                upka=false;
               //T.veiksmas(4,1);
               break;
            }
            break;
        }
        case SDL_KEYUP:
        {
             if(Event->key.keysym.sym==SDLK_UP)
            {
               upup=true;
               //T.veiksmas(2,0);
               break;
            }

            if(Event->key.keysym.sym==SDLK_DOWN)
            {
                updw=true;
               //T.veiksmas(1,0);
               break;
            }

            if(Event->key.keysym.sym==SDLK_RIGHT)
            {
                upde=true;
               //T.veiksmas(3,0);
               break;
            }
            if(Event->key.keysym.sym==SDLK_LEFT)
            {
               upka=true;
               //T.veiksmas(4,0);
               break;
            }
            break;
        }

        case SDL_QUIT:
        {
            busena=false;
            break;
        }
    }
}
/*void Core::OnEvent(SDL_Event* Eventas)
{
     CEvents::OnEvent(Eventas);
}*/
/*void Core::OnExit()
{
    busena = false;
}

void Core::Zemyn()
{
    busena=false;
}
*/
