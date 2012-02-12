#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_rotozoom.h"

class rotate
{
  public:
    static SDL_Surface* pasukti (SDL_Surface* source, double angle, double zoom, int smooth);
};
