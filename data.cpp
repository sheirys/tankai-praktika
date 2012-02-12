#include <iostream>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "data.h"

using namespace std;

void data_loader::getImg( char* id, SDL_Surface* surface) {



}

// tikrinam ar galim vaziuot i x,y koordinates
bool data_loader::move( int x, int y ) {

	int coord_X, coord_Y;

	coord_X = coord_Y = 0;
	
	coord_X = x / tiles;
	coord_Y = y / tiles;

	/*
	if ( x % tiles == 0 ) {
		coord_X = x / tiles;
	} else {
		coord_X = x / tiles + 1;
	}
	
	if ( y % tiles == 0 ) {
		coord_Y = y / tiles;
	} else {
		coord_Y = y / tiles + 1;
	}
	*/
	
	if ( map[0][coord_X][coord_Y] == 0 ) {
		return true;
	} else {
		return false;
	}
}

void data_loader::load_images( char* filename ) {

	string line;
 	img image;

	data_file.open( filename );
	cout << "\tImages file: " << filename << "\n";
	
	while( !data_file.eof() ) {
	
		// skaitom failo varda
		data_file >> image.filename;
		// skaitom failo id
		data_file >> image.id;
		
		// kraunam paveiksliuka
		image.load(image.filename);
		
		// keliam visa paveiksliuka i vektoriu
		images.push_back( image );
	}
	
//	while( getline( data_file, line ) ) {
//		if( image.load(line) ) {
//			image.filename = line;
//			images.push_back( image );
//		}

//	}
	cout << "\n\tTotal loaded images: " << images.size() << "\n";
}

void data_loader::load_options( char* filename ) {

	options_file.open( filename );
	cout << "\tOptions file: " << filename << "\n";
	
	if( options_file.is_open() ) {
		options_file >> options.fullscreen;
		cout << "\t\tFullscreen:\t" << options.fullscreen << "\n";
		options_file >> options.width;
		cout << "\t\tWidth:\t" << options.width << "\n";
		options_file >> options.height;
		cout << "\t\tHeight:\t" << options.height << "\n";
		options_file >> options.host;
		//cout << "\t\tHost:\t" << options.host << "\n";
		//options_file >> options.port;
		//cout << "\t\tPort:\t" << options.port << "\n";
		 
	} else {
		cout << "\tUsing defaults:\n";
		cout << "\t800x600\n";
		options.fullscreen = 0;
		options.width = 600;
		options.height = 800;
		options.host = "localhost";
		options.port = 5151;
	}
	
}

void data_loader::apply(SDL_Surface* screen) {
	int temp;
	
	for (int z=1; z < layers; z++)
	{
		for(int y=0; y < size_y; y++)
		{	
			for(int x=0; x < size_x; x++)
			{
				temp = map[z][x][y];
				apply_surface(x*tiles,y*tiles, images[temp].IMG, screen, NULL);
			}
		}
	}
}

void data_loader::load_map( char* filename ) {

	SDL_Rect offset;
	int temp;

	map_file.open( filename );
	cout << "\tLoading map: " << filename << "\n";
	
	if( map_file.is_open() ) {
		map_file >> size_x;
		cout << "\t\tSize x: " << size_x << "\n";
		map_file >> size_y;
		cout << "\t\tSize y: " << size_y << "\n";
		map_file >> layers;
		cout << "\t\tLayers: " << layers << "\n";
		
		// Kuriam dydeli 3d masyva
		
		map = (int***) malloc(size_y*sizeof(int**));
		for (int z = 0; z < layers; z++)
		{
			map[z] = (int**) malloc(size_x*sizeof(int*));
			
			for (int x = 0; x < size_x; x++)
			{
				map[z][x] = (int*) malloc(size_x*sizeof(int));
			}
			
		}
		
		// skaitom i masyva is failo
		
		cout << "\tMap:\n";
		for (int z=0; z < layers; z++)
		{
			cout << "\tlayer " << z << " :\n";
			for(int y=0; y < size_y; y++)
			{	
				cout << "\t\t";
				for(int x=0; x < size_x; x++)
				{
					map_file >> temp;
					map[z][x][y] = temp;
					cout << temp << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		
	} else {
		cout << "[!]\tMap not found!\n";
	}
	cout << "\t\tMap: " << Map << "\n";
}

void data_loader::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip) {

	SDL_Rect offset;

	offset.x = x;
	offset.y = y;
	
	SDL_BlitSurface( source, clip, destination, &offset );
}

data_loader::data_loader() {

}
