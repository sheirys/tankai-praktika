#ifndef _SUSIDURIMAI_H_
    #define _SUSIDURIMAI_H_

    #include <assert.h>
    #include <SDL/SDL.h>
    #include <SDL/SDL_image.h>

int SDL_CollideTransparentPixel(SDL_Surface *surface , int u , int v);

int SDL_CollidePixel(SDL_Surface *as , int ax , int ay , SDL_Surface *bs , int bx , int by, int skip = 4);

#endif
