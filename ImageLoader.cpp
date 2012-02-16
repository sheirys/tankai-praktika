#include "ImageLoader.h"

SDL_Surface* ImageLoader::GetImage(string file)
{
    map<string, SDL_Surface*>::iterator i = IMG_List.find(file);
    if( i == IMG_List.end() )
    {
        SDL_Surface* surf = IMG_Load( file.c_str() );
        if(surf != NULL)
            i = IMG_List.insert(i, make_pair(file, surf));
        else
            {
                cout<<"Nepavyko uzkrauti '"<<file<<"'failo."<<endl;
                exit(111);
            }
    }
    return i->second;
}
ImageLoader::~ImageLoader()
{
    map<string, SDL_Surface*>::iterator i = IMG_List.begin();

    for(;i != IMG_List.end();++i)
    SDL_FreeSurface(i->second);
    IMG_List.clear();
}
