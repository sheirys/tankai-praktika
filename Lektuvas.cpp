#include "Lektuvas.h"
Lektuvas::Lektuvas(int x, int y, double k, double greitis, short int tipas = -1 )
{

    X = x;
    Y = y;
    Greitis=greitis;
    if (tipas == -1)
    {
        Sprite = Load::load_img("f18.png");
        kampas=90;
    }
    else
    {
        Sprite = Load::load_img("f18.png");
        kampas=k;
    }
}
Lektuvas::~Lektuvas()
{
 //   SDL_FreeSurface(Sprite);
}
int Lektuvas::GetX()
{
    return X;
}
int Lektuvas::GetY()
{
    return Y;
}
SDL_Surface* Lektuvas::GetSurface(double scale)
{
    return rotozoomSurface(Sprite, kampas, scale, 0);
}
void Lektuvas::Atnaujinti()
{
    Update();
}
void Lektuvas::kairen()
{
    sukti_kairen();
}
void Lektuvas::desinen()
{
    sukti_desinen();
}
