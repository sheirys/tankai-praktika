#ifndef _CEvents_H_
    #define _CEvents_H_

#include <SDL/SDL.h>
#include "Core.h"

class CEvents
{
    public:
        CEvents();
        virtual ~CEvents();
        virtual void OnEvent(SDL_Event* Event);

        virtual void Zemyn();
        //virtual void OnKeyUp  (SDLKey sym, SDLMod mod, Uint16 unicode);

        virtual void OnExit();
};
#endif
