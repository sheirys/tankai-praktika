#include "Animacija.h"
Animacija::Animacija(ImageLoader& anim)
{
 /*Sprogimo efekto kadru vektorius*/
    for (int i = 0; i < 32; i++)
    {
        SDL_Surface* temp= new SDL_Surface;

        std::string pav="data/img/Bum/B";
        std::stringstream ss;
        ss << i;
        if(i<10)
        pav=pav +"000"+ss.str()+".png";
        else if(i<100)
                pav=pav +"00"+ss.str()+".png";
             else
                pav=pav+"0"+ss.str()+".png";

       //Uzkrauname kadra i mapa
       temp = anim.GetImage( pav.c_str() );

       if(temp != NULL)
       {
            B.push_back(temp);
       }
       //Isvalome ir istriname laikinavkintamaji
       SDL_FreeSurface(temp);
       delete temp;
    }

 for (int i = 1; i<32; i++)
 {
    //Ugnines auros vektorius
    SDL_Surface* temp= new SDL_Surface;
    std::string pav="data/img/aura/A";
    std::stringstream ss;
    ss << i;
    if(i<10)
        {pav=pav +"000"+ss.str()+".png"; std::cout<<pav<<std::endl;}
    else if(i<100)
            pav=pav +"00"+ss.str()+".png";
         else
        pav=pav+"0"+ss.str()+".png";

    temp = IMG_Load(pav.c_str());
    if(temp != NULL)
    {
        AuraFlame.push_back(temp);
    }

    SDL_FreeSurface(temp);
    delete temp;

}

}
//-----------------------------------------------------------------------------
Animacija::Animacija()
{
 SDL_Surface* temp=NULL;
 /*Sprogimo efekto kadru vektorius*/
 for (int i = 0; i < 32; i++)
 {
    std::string pav="data/img/Bum/B";
    std::stringstream ss;
    ss << i;
    if(i<10)
        pav=pav +"000"+ss.str()+".png";
    else if(i<100)
            pav=pav +"00"+ss.str()+".png";
         else
            pav=pav+"0"+ss.str()+".png";

    temp = IMG_Load(pav.c_str());

    if(temp != NULL)
    {
        B.push_back(temp);
    }
}

//----------------------------------------
}
Animacija::~Animacija()
{
    for(int i = 0; i < B.size(); i++)
    {
       // SDL_FreeSurface(B[i]);
    }
    B.clear();
    Sprogimai.clear();
}
//-----------------------------------------------------------------------------
void Animacija::Atnaujinti()
{
    int kuris = 0;
    while(kuris < Sprogimai.size())
    {
        Sprogimai[kuris].kadras++;
        if(Sprogimai[kuris].kadras>30)
        {
           Sprogimai.erase( Sprogimai.begin() + kuris );
           kuris++;
           continue;
        }
       kuris++;
    }
}
//-----------------------------------------------------------------------------
void Animacija::AddBum(int x, int y)
{
   Vieta temp;
   temp.x = x-B[0]->w/2;
   temp.y = y-B[0]->h/2;
   temp.kadras=0;
   Sprogimai.push_back(temp);
}
//-----------------------------------------------------------------------------
SDL_Surface* Animacija::GetFrame(int kuris)
{
    return  B[kuris];
}
