#include "Core.h"
#include "Engine.h"
void Core::Render()
{
    SDL_FillRect( Ekranas, &Ekranas->clip_rect, SDL_MapRGB( Ekranas->format, 0, 0, 0 ) );

    data.apply(Ekranas);

     int X = T.getX();
     int Y = T.getY();
     int kk=0;

   /* kk=0;
    while(kk<Lektuvai.size())
    {
      int X  = Lektuvai[kk].GetX();
      int Y  = Lektuvai[kk].GetY();
      Load::draw_img(X, Y, Ekranas, Lektuvai[kk].GetSurface(0.5));
      kk++;
    }*/

//-----------------------------------------------------------------------------


   Uint32 colorkey = SDL_MapRGB( Tk->format, 0, 255, 0 );
   SDL_SetColorKey( Tk, SDL_SRCCOLORKEY, colorkey );

   SDL_Surface* temp = new SDL_Surface;
   temp = SDL_DisplayFormatAlpha(Tk);
   std::swap(Tk, temp);
   SDL_FreeSurface(temp);
   delete(temp);

    Load::draw_img(400, 50, Ekranas, Tk);

//-----------------------------------------------------------------------------
    T.render(Ekranas);


    kuris++;
    if(kuris>30)
        kuris=0;

    //Piesiamos ciakros apie tanka
    Load::draw_img(X + T.rotation->w/2 - A[kuris]->w/2,   Y+T.rotation->h/2 - A[kuris]->h/2, Ekranas, A[kuris]);

    /*SDL_SetColorKey( Tk, SDL_SRCCOLORKEY, colorkey );
    Tk=SDL_DisplayFormatAlpha(Tk);
    Load::draw_img(400, 50, Ekranas, Tk);*/

//-----------------------------------------------------------------------------


    for(int i = 0; i < K.size() ; i++)
    {
        if(K.size()!=0)
        {

            int kx, ky;     //Dabartines kulkos koordinates
            kx= K[i].GetX();
            ky= K[i].GetY();

            //tikriname, ar kulka niekur neatsitrenke, jei atsitrenke, ja sunaikiname
            if(data.move(kx,ky) && SDL_CollidePixel( Tk , 400 , 50,K[i].KPasukta , K[i].GetX()  , K[i].GetY()) == 0 )
            {
                Load::draw_img(K[i].GetX(),K[i].GetY(), Ekranas, K[i].KPasukta);
            }
            else
            {
                Mix_PlayChannel( -1, bomba, 0 ); //paled=iame sprogimo garsa
                Anim.AddBum(kx, ky);             //pridedame sprogimo animacija
                K.erase(K.begin()+ i);           //istriname kulka is saraso

            }

        }
    }
//-----------------------------------------------------------------------------


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
     X = T.getX();
     Y = T.getY();

    kk=0;
    while(kk<Anim.Sprogimai.size())
    {
      int X  = Anim.Sprogimai[kk].x;
      int Y  = Anim.Sprogimai[kk].y;
      Load::draw_img(X, Y, Ekranas, Anim.GetFrame( Anim.Sprogimai[kk].kadras )  );
      kk++;
    }
//-----------------------------------------------------------------------------



       SDL_Flip(Ekranas);
       //SDL_FreeSurface(Laikinas);
      // SDL_FreeSurface(Laikinas1);
       //SDL_FreeSurface(Tk);
}
