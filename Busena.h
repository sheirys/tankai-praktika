#ifndef _BUSENA_H_
    #define _BUSENA_H_

#include "Engine.h"
class Busena
{
    protected:
        Busena(){};
    public:
        virtual void Init()    = 0;
        virtual void Cleanup() = 0;

        virtual void Pause()   = 0;
        virtual void Resume()  = 0;

        virtual void HandleEvents(Engine* game) = 0;
        virtual void Update(Engine* game)       = 0;
        virtual void Draw(Engine* game)         = 0;

        void ChangeState(Engine* game, Busena* state)
        {
            game->ChangeState(state);
        }


};

#endif
