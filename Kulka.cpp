#include "Kulka.h"
Kulka::Kulka(int x, int y, double angle)
{
    X=x-32;
    Y=y-32;
    kampas = angle;
    begin();

}
Kulka::~Kulka()
{
 //SDL_FreeSurface(Klk);
}
bool Kulka::begin()
{
    Klk = Load::load_img("data/img/kulka.png");
    KPasukta=rotozoomSurface(Klk,kampas,0.75,0);
    return true;
}

bool Kulka::begin(ImageLoader& images)
{
    Klk = images.GetImage("data/img/kulka.png");
    KPasukta=rotozoomSurface(Klk,kampas,0.75,0);
    return true;
}

int Kulka::GetX()
{
    return  X;
}

int Kulka::GetY()
{
    return Y;
}

void Kulka::Atnaujinti()
{
    X += floor(20 * sin( (kampas) * M_PI / 180 ) + 0.5);
    Y += floor(20 * cos( (kampas) * M_PI / 180)  + 0.5);
}
