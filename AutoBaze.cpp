#include "AutoBaze.h"
AutoBaze::AutoBaze()
{
    Sprite=NULL;
}

int AutoBaze::GetX()
{
    return X;
}

int AutoBaze::GetY()
{
    return Y;
}

double AutoBaze::GetAngle()
{
    return kampas;
}

void AutoBaze::Update()
{
    X += floor(Greitis * cos( (kampas) * M_PI / 180 ) + 0.5);
    Y -= floor(Greitis * sin( (kampas) * M_PI / 180 )  + 0.5);
}
//-----------------------------------------------------------------------------
void AutoBaze::sukti_kairen()
{
    kampas+=3;
    if (kampas>360) kampas-=360;
}

void AutoBaze::sukti_desinen()
{
    kampas-=3;
    if (kampas>360) kampas-=360;
}

void AutoBaze::sukti_kairen(int kiek)
{
  kampas+=kiek;
    if (kampas>360) kampas-=360;
}

void AutoBaze::sukti_desinen(int kiek)
{
  kampas-=kiek;
    if (kampas>360) kampas-=360;
}
//-----------------------------------------------------------------------------
// SDL_Surface* AutoBaze::GetSurface()
//{
    //return Sprite;
//}
