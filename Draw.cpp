#include "Game.h"
#include "CLoad_image.h"

void Game::Draw(Engine* game)
{
    SDL_FillRect( game->screen, &game->screen->clip_rect, SDL_MapRGB( game->screen->format, 0, 0, 0 ) );

    data.apply(game->screen);

     //int X = T.getX();
     //int Y = T.getY();
     //int kk=0;

   /* kk=0;
    while(kk<Lektuvai.size())
    {
      int X  = Lektuvai[kk].GetX();
      int Y  = Lektuvai[kk].GetY();
      Load::draw_img(X, Y, Ekranas, Lektuvai[kk].GetSurface(0.5));
      kk++;
    }*/

//-----------------------------------------------------------------------------
/*

   Uint32 colorkey = SDL_MapRGB( Tk->format, 0, 255, 0 );
   SDL_SetColorKey( Tk, SDL_SRCCOLORKEY, colorkey );

   SDL_Surface* temp = new SDL_Surface;
   temp = SDL_DisplayFormatAlpha(Tk);
   std::swap(Tk, temp);
   SDL_FreeSurface(temp);
   delete(temp);

    Load::draw_img(400, 50, Ekranas, Tk);
*/
//-----------------------------------------------------------------------------
 /*   T.render(Ekranas);


    kuris++;
    if(kuris>30)
        kuris=0;

    //Piesiamos ciakros apie tanka
    Load::draw_img(X + T.rotation->w/2 - A[kuris]->w/2,   Y+T.rotation->h/2 - A[kuris]->h/2, Ekranas, A[kuris]);
*/
    /*SDL_SetColorKey( Tk, SDL_SRCCOLORKEY, colorkey );
    Tk=SDL_DisplayFormatAlpha(Tk);
    Load::draw_img(400, 50, Ekranas, Tk);*/

//-----------------------------------------------------------------------------


    for(int i = 0; i < kulkos.size() ; i++)
    {
        if(kulkos.size()!=0)
        {

            int kx, ky;     //Dabartines kulkos koordinates
            kx= kulkos[i]->GetX();
            ky= kulkos[i]->GetY();

            Load::draw_img(kulkos[i]->GetX(),kulkos[i]->GetY(), game->screen, kulkos[i]->KPasukta);
        }
    }
//-----------------------------------------------------------------------------
/*Pieesiami visi vektoriuje esantys tankai*/
    int tmp = tankai.size();

    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
        tankai[i]->render(game->screen);
    }


//Load::draw_img(400, 50, Ekranas, Tk);
//-----------------------------------------------------------------------------
    /*kk=0;
    while(kk<Lektuvai.size())
    {
      int X  = Lektuvai[kk].GetX();
      int Y  = Lektuvai[kk].GetY();
      Load::draw_img(X, Y, Ekranas, Lektuvai[kk].GetSurface(1));
      kk++;
    }*/
//-----------------------------------------------------------------------------
    int     kk=0;
    while(kk<anim.Sprogimai.size())
    {
      int X  = anim.Sprogimai[kk].x;
      int Y  = anim.Sprogimai[kk].y;
      Load::draw_img(X, Y, game->screen, anim.GetFrame( anim.Sprogimai[kk].kadras )  );
      kk++;
    }
//-----------------------------------------------------------------------------

    //SDL_BlitSurface(bg, NULL, game->screen, NULL);
	//SDL_UpdateRect(game->screen, 0, 0, 0, 0);

      SDL_Flip(game->screen);
       //SDL_FreeSurface(Laikinas);
      // SDL_FreeSurface(Laikinas1);
       //SDL_FreeSurface(Tk);
}
