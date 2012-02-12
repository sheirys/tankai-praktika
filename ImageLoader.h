#ifndef _IMAGELOADER_H
    #define _IMAGELOADER_H

#include <string>
#include <iostream>
#include <map>

#include <SDL/SDL_image.h>
using namespace std;
class ImageLoader
{
    private:
        map <string, SDL_Surface*> IMG_List;
    public:
        SDL_Surface* GetImage (string file);
        ~ImageLoader();
};

#endif
