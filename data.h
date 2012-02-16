#include <fstream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

#include "image.h"
#include "options.h"

using namespace std;

const int tiles = 32;

class data_loader {
	public:
		SDL_Surface* getImg( char* id);
		void load_images( char* filename );
		void load_options( char* filename );
		void load_map( char* filename );
		void apply(SDL_Surface* screen); // uzkrauna zemelapi ant &screen
		void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
		bool move( int x, int y );
		data_loader();
		opt options;
		vector<img> images;
		int size_x,size_y,layers;
		SDL_Surface* Map;
		SDL_Surface* load_IMG(string filename);
		
		// cia saugosim error paveiksliuka
		SDL_Surface* error;

	private:
		ifstream options_file;
		ifstream data_file;
		ifstream map_file;
		int ***map; // map[x][y][z]

};
