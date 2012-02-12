#ifndef _ENGINE_H_
    #define _ENGINE_H_

#include <iostream>
#include <stack>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
class Busena;

class Engine
{
    private:
        //Stekas, kuris saugo pointerius i busenu objektus
        std::stack<Busena*> busenos;

        bool m_running;
        bool m_fullscreen;

	public:
        void Init(const char* title, int width=800, int height=600, int bpp=32, bool fullscreen=false);
        void Cleanup();
        void ChangeState(Busena* state);

        void PushState(Busena* state);
        void PopState();

        void HandleEvents();
        void Update();
        void Draw();

        bool Running() { return m_running; }
        void Quit() { m_running = false; }

        SDL_Surface* screen;
};
#endif
