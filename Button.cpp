#include "Button.h"
Button::Button()
{
    font = NULL;
    textColor = { 0, 0, 0 };
    TTF_Init();
    font = TTF_OpenFont( "data/fonts/DUE.TTF", 48 );

    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    On = Mix_LoadWAV( "data/sound/On.wav" );
    OnFirst = false;
}
void Button::set(int y, int h, int w, std::string tekstas)
{
    Y=y;
    H=h;
    W=w;
    SDL_Surface* temp1 = SDL_LoadBMP("data/img/intro.bmp");
    SDL_Surface* temp = SDL_DisplayFormat(temp1);
    SDL_FreeSurface(temp1);

    //Sukuriame nauja sluoksni
    button = SDL_CreateRGBSurface( SDL_SRCALPHA, W, H, temp->format->BitsPerPixel,
								  temp->format->Rmask, temp->format->Gmask,
								  temp->format->Bmask, temp->format->Amask );
   SDL_FillRect (button, NULL, SDL_MapRGB (temp->format, 103, 107, 84)) ;

   alpha = 128;
   SDL_SetAlpha(button, SDL_SRCALPHA, alpha);
    using namespace std;
   caption = TTF_RenderText_Solid( font, tekstas.c_str(), textColor );

   SDL_FreeSurface(temp);
   temp = NULL;
}

void Button::Draw(Engine* Kur)
{
    KurR.x = Kur->screen->w/2 - button->w/2-2;  //Apskaiciuajame x mygtuko kooedinate
    KurR.y = Y;                                 //y koordinate jau zinom
    SDL_BlitSurface(button,  NULL, Kur->screen, &KurR);
//-----------------------------------------------------------------------------
    SDL_Rect Cap;                               //teksto vieta
    Cap.x =KurR.x + button->w/2 - caption->w/2;
    Cap.y = Y +button->h/2 -caption->h/2;
    SDL_BlitSurface(caption, NULL, Kur->screen, &Cap);
}
bool Button::MouseOn(int x, int y)
{
    if(KurR.x < x &&  x < (KurR.x+ button->w) && KurR.y<y && (KurR.y+button->h)>y)
    {
        alpha = 200;
        SDL_SetAlpha(button, SDL_SRCALPHA, alpha);
        if(!OnFirst)
        {
            Mix_Resume(-1);
            Mix_PlayChannel( -1, On, 0);
            OnFirst = true;
        }
        return true;
    }
    else
    {
        alpha = 100;
        SDL_SetAlpha(button, SDL_SRCALPHA, alpha);
        OnFirst=false;
       // Mix_Pause(-1);
        return false;
    }
    return false;
}
