#ifndef _BUTTON_H_
    #define _BUTTON_H_
#include <string>
#include "Engine.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
class Button
{
    private:
        int X, Y;
        int H, W;
        int alpha ;
        SDL_Rect KurR;
        TTF_Font *font;
        SDL_Surface* button;
        SDL_Surface* caption;
        SDL_Color textColor;
        Mix_Chunk* On; //Garsas uzvedus pele ant mygtuko
        bool OnFirst;//
    public:
        Button();

        void set( int y, int h, int w, std::string tektas);
        void Draw(Engine* Kur);

        bool MouseOn(int x, int y);
};

#endif
