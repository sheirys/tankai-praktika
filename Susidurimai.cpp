#include "Susidurimai.h"

//Pora makrosu
    #define SDL_COLLIDE_MAX(a,b)	((a > b) ? a : b)
    #define SDL_COLLIDE_MIN(a,b)	((a < b) ? a : b)


int SDL_CollideTransparentPixel(SDL_Surface *surface , int u , int v)
{
	if(SDL_MUSTLOCK(surface))
	{
        SDL_LockSurface(surface);
	}

	assert((u < surface->w) && (v < surface->h));

	int bpp=surface->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)surface->pixels + v * surface->pitch + u * bpp;     //Pixelio adresas
    Uint32 pixelcolor;  //Pixelio spalva

	switch(bpp)
	{
		case(1):
			pixelcolor = *p;
		break;

		case(2):
			pixelcolor = *(Uint16 *)p;
		break;

		case(3):
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixelcolor = p[0] << 16 | p[1] << 8 | p[2];
			else
				pixelcolor = p[0] | p[1] << 8 | p[2] << 16;
		break;

		case(4):
			pixelcolor = *(Uint32 *)p;
		break;
	}
	if(SDL_MUSTLOCK(surface))
		SDL_UnlockSurface(surface);
    return (pixelcolor == surface->format->colorkey);
}
//-----------------------------------------------------------------------------
int SDL_CollidePixel(SDL_Surface *as , int ax , int ay , SDL_Surface *bs , int bx , int by, int skip)
{
	int ax1 = ax + as->w - 1;
	int ay1 = ay + as->h - 1;

	int bx1 = bx + bs->w - 1;
	int by1 = by + bs->h - 1;



	if((bx1 < ax) || (ax1 < bx))
	{
		return false;
	}
	if((by1 < ay) || (ay1 < by))
	{
		return false;
	}

	int xstart = SDL_COLLIDE_MAX(ax,bx);
	int xend = SDL_COLLIDE_MIN(ax1,bx1);

	int ystart = SDL_COLLIDE_MAX(ay,by);
	int yend = SDL_COLLIDE_MIN(ay1,by1);

	for(int y = ystart ; y <= yend ; y += skip)
	{
		for(int x = xstart ; x <= xend ; x += skip)
		{
			if(!SDL_CollideTransparentPixel(as , x-ax , y-ay) && !SDL_CollideTransparentPixel(bs , x-bx , y-by))
				return 1;
		}
	}

	return 0;
}
