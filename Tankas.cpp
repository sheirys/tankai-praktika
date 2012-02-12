#include "Tankas.h"

Tankas::Tankas(int id, int x , int y, double angle)
{
    ID = id;
    gyvas=true;
    sprogsta = false;
    gyvybe=100;
    Kuris_kadras=0;

    X=x;
    Y=y;
    kampas=angle;
    pk = 0;
    senas_kampas=1;
    senas_kampasP = 1;
    rotation=NULL;
    Inicijuoti();
//    atnaujinti(555, 300, NULL);
}
void Tankas::veiksmas(int kur, int mode, int xp,int yp)
{

    if(mode==1)
    switch(kur)
    {
        case 2://Pirmyn
        {

          int tempX = X;
          int tempY = Y;

          Y -= floor(3 * sin( kampas * M_PI / 180)  + 0.5);
          X += floor(3 * cos( kampas * M_PI / 180 ) + 0.5);

          if( ( X < 0 ) || ( X+T_PLOTIS > W_WIDTH ) )
            X = tempX;

          if( ( Y < 0 ) || ( Y+T_PLOTIS > W_HEIGHT) )
            Y = tempY;
          //Mix_PlayChannel( -1, TankasVaziuoja, 0 );
          break;
        }
        case 1://atgal
        {
          int tempX = X;
          int tempY = Y;

          Y += floor(3* sin( (180-kampas) * M_PI / 180)  + 0.5);
          X += floor(3* cos( (180-kampas) * M_PI / 180 ) + 0.5);

          if( ( X < 0 ) || ( X + T_PLOTIS >  W_WIDTH ) )
            X = tempX;

          if( ( Y < 0 ) || ( Y + T_PLOTIS >  W_HEIGHT) )
            Y = tempY;
         break;
        }
        case 4:
        {
         kampas+=3;
         if (kampas>360)
            kampas-=360;
         break;
        }
        case 3:
        {
         kampas-=3;
        if (kampas>360)
            kampas-=360;
          break;
        }
    }
    else
    switch(kur)
    {
        //case 2: Mix_PlayChannel( -1, TankasStoja, 0 ); break;
        //case 1: yg -= T_AUKSTIS / D; break;
        //case 4: xg += T_PLOTIS  / D; break;
        //case 3: xg -= T_PLOTIS  / D; break;
    }
}
int Tankas::getX()
{
    return X;
}
int Tankas::getY()
{
    return Y;
}
double Tankas::GetAngle()
{
    return vk+180;
}
void Tankas::Inicijuoti()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Tanks = Load::load_img("tankas.png");
    Patranka = Load::load_img("Patranka.png");
    TankasStovi   = Mix_LoadWAV( "1.wav" );
    TankasVaziuoja= Mix_LoadWAV( "2.wav" );
    TankasStoja   = Mix_LoadWAV( "3.wav" );

    //----------------------------------------

    SDL_Surface* temp=NULL;
 /*Tankoprogimo efekto kadru vektorius*/
 for (int i = 0; i < 64; i++)
 {
    std::string pav="data/img/TS1/TS1";
    std::stringstream ss;
    ss << i;
    if(i<10)
        pav=pav +"000"+ss.str()+".png";
    else if(i<100)
            pav=pav +"00"+ss.str()+".png";
         else
            pav=pav+"0"+ss.str()+".png";
	cout << "\tKraunam " << pav << "\n";
    temp = IMG_Load(pav.c_str());

    if(temp != NULL)
    {
        TS1.push_back(temp);
    }
}

}
void Tankas::atnaujinti(int xp, int yp, vector<Kulka*> &kulkos)
{
    if(sprogsta)
    {

        Sprogimas();

        return;
    }
    int dx, dy;

    dx = X+Tanks->w/2 - xp;
    dy = Y+Tanks->h/2 - yp;

    vk = atan2(dx , dy) * 180 / M_PI;
    pk = vk - kampas + 90;

//    if( kulkos != NULL )
    //{
            int i = 0;
            while(i < kulkos.size())
            {
               // cout<<"kulkos x"<<kulkos[i]->GetX()<<endl;
                if( SDL_CollidePixel(rotation, X, Y, kulkos[i]->KPasukta, kulkos[i]->GetX(), kulkos[i]->GetY()) != 0 )
                {
                    /*I mane pataike!*/
                    sprogsta = true;
                    lastW=rotation->w;
                    lastH=rotation->h;
                    cout<<"Pataike!"<<endl;
                }
                i++;
            }
           // }



     if(senas_kampas!=kampas || senas_kampasP != pk)
     {

     SDL_Surface* Tn = new SDL_Surface;   //Tanko vamzdis
     SDL_Surface* ND = new SDL_Surface;   //Laikinas sluoksnis
     SDL_Surface* Tm = new SDL_Surface;   //Originaliojo tanko sluoksnio kopija
//-----------------------------------------------------------------------------
    ND = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, Tanks->w, Tanks->h, 32, NULL, NULL, NULL, 0);
    SDL_BlitSurface(Tanks, NULL, ND, NULL);

    Uint32 colorkey1 = SDL_MapRGB( Tanks->format, 0, 255, 0 );
    SDL_SetColorKey( ND, SDL_SRCCOLORKEY, colorkey1 );//naujai sukurtam sluoksniu nustatom sena color key

    Tm = SDL_DisplayFormatAlpha( ND );

    std::swap(Tm, ND);
	//delete(ND);
    SDL_FreeSurface(ND);
//-----------------------------------------------------------------------------

    Tn =  rotozoomSurfaceXY(Patranka, pk, 1, 1, 0);

    SDL_Rect dst = {Tn->w / 2,  Tn->h / 2};

    dst.x = ( Tanks->w - Tn->w ) / 2;
    dst.y = ( Tanks->h - Tn->h ) / 2;

    SDL_BlitSurface(Tn, NULL, Tm, &dst);
	//delete(Tn);
    SDL_FreeSurface(Tn);

    

    SDL_FreeSurface(rotation);
    rotation = rotozoomSurface(Tm, kampas, 0.45, 0);

	//delete(Tm);
    SDL_FreeSurface(Tm);

    Uint32 colorkey = SDL_MapRGB( rotation->format, 0, 255, 0 );
    SDL_SetColorKey( rotation, SDL_SRCCOLORKEY, colorkey );

    SDL_Surface * www = new SDL_Surface;
    www = SDL_DisplayFormatAlpha(rotation);
    std::swap(www, rotation);
    //delete(www);
    SDL_FreeSurface(www);

    senas_kampas = kampas;
    senas_kampasP = pk;

}
}
void Tankas::Sauti()
{

}
int Tankas::GetNextX(unsigned short int kur )
{
    int x = X;
    if(kur == 0)
         x += floor(4 *cos(  kampas * M_PI / 180)  + 0.5);
    else
         x -= floor(4 * cos( kampas * M_PI / 180)  + 0.5);

    return x;
}
int Tankas::GetNextY(unsigned short int kur )
{
   int y = Y;
   if(kur == 0)
         y -= floor(4 * sin( kampas * M_PI / 180)  + 0.5);
    else
         y += floor(4 * sin( kampas * M_PI / 180)  + 0.5);
    return y;
}
void Tankas::render(SDL_Surface* Ekranas)
{
    if(sprogsta)
    {
        int SX = (X + lastW/2) - rotation->w/2;
        int SY = (Y + lastH/2) - rotation->h/2;

        Load::draw_img(SX, SY, Ekranas,/*( rotation )*/rotation);
    }
    else
        Load::draw_img(X, Y, Ekranas,/*( rotation )*/rotation);
}

void Tankas::Sprogimas()
{
    if(Kuris_kadras>63)
    {
        gyvas = false;
    }
    else
    {
        rotation = TS1[Kuris_kadras];
        Kuris_kadras++;
    }

}
bool Tankas::GetBusena()
{
    return gyvas;
}
bool Tankas::Normal()
{
    if(!sprogsta)
        return true;
    return false;

}
void Tankas::SendXY(int x, int y)
{
    X = x;
    Y = y;
}
int Tankas::GetID()
{
    return ID;
}
