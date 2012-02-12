#include "CLoad_image.h"

SDL_Surface* Load::load_img(std::string Pavadinimas)
{
    SDL_Surface* Temp       = NULL;
    //SDL_Surface* Returnable = NULL;
    Temp = IMG_Load(Pavadinimas.c_str());

    if (Temp!=NULL)
        return Temp;
    else
        std::cout<<"Klaida kraunant paveiksleli: "<<Pavadinimas<<". "<<SDL_GetError()<<std::endl;
}
bool Load::draw_img(int X, int Y, SDL_Surface* Kur, SDL_Surface* Ka)
{
  if((Kur==NULL)||(Ka==NULL))
  {
      return false;
  }
  SDL_Rect KurR;

  KurR.x = X;
  KurR.y = Y;
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
  SDL_BlitSurface(Ka, NULL, Kur, &KurR);
  return true;
}
bool Load::draw_img(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
	if(Surf_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

	return true;
}
