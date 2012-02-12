#include "Lauzas.h"

Lauzas::Lauzas()
{
    kadrai.clear();
    kuris = -1;;
}
bool Lauzas::load()
{
for (int i = 1; i<128; i++)
 {
    string pav="bumt1/fire1_";
    SDL_Surface* temp;
    stringstream ss;
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
        kadrai.push_back(temp);

        //SDL_FreeSurface(temp);
    }
    else
        return false;
    //temp=NULL;
}
return true;
}

SDL_Surface* Lauzas::Gauti_Kadra()
{
    kuris++;
    if(kuris>126)
        kuris=0;
    return kadrai[kuris];
}
