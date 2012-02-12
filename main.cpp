#include <SDL/SDL.h>
#include <sstream>
#include <string>
#include <iostream>

#include "data.h"
#include "timer.h"
#include "network.h"

using namespace std;

const int FRAMES_PER_SECOND = 20;

string i2string(int i) {
	std::ostringstream buffer;
	buffer << i;
	return buffer.str();
}

int main(int argc, char **argv) {
	int x,y;
	string cx, cy,tmp;
	stringstream ss;
	const char* buff = NULL;

	data_loader data;
	SDL_Surface* map = NULL;
	SDL_Surface* screen = NULL;
	bool quit = false;
	SDL_Event event;
	Timer fps;
	network net;
	
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
        	cout << "Error on SDL_INIT_EVERYTHING\n";
		return 1;
	}
	
	screen = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE );

	data.load_images("data.txt");
	//data.load_options("options.txt");
	data.load_map("test.map");
	
	net.init("localhost",5151);
	net.hello();
	
	while ( quit == false )
	{
		//net.send("get");
		net.listen();
		
		while( SDL_PollEvent( &event ) )
        	{	
        		switch (event.type) {
        		
        			case SDL_QUIT: 
        				quit = true;
        				net.disconnect();
        				break;
        				
        			case SDL_KEYDOWN:
        				net.send("get");
					break;
					
				case SDL_MOUSEMOTION:
					net.tankas_x = event.motion.x;
					net.tankas_y = event.motion.y;
					//cx = i2string(x);
					//cy = i2string(y);
					//tmp = cx+" "+cy;
					//buff = tmp.c_str();
					//net.send((char*)buff);
					net.send();
				break;
					
			}
        	}

        	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); // Clear all & redraw

        	data.apply(screen);
        	if( SDL_Flip( screen ) == -1 ) { return 1; } 	
		//fps.delay(30);
		
	}
	
	return 0;
}
