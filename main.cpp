#include "Engine.h"
#include "Intro.h"
#include "Timer.h"

#define FRAMES_PER_SECOND 100

int main(int argc, char* argv[])
{
   //freopen("CON", "w", stdout);
   //freopen("CON", "w", stderr);
   //Core P;
   // return P.run();
  //  P.Vykdyti();


    Engine game;
    Timer fps;

     game.Init( "Pre-alpha edition!" );
     game.ChangeState( Intro::Instance() );

	fps.start();
	
    while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
		//SDL_Delay(10);
		
		// cia apribojam fps
		if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) 
       		{
            		SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
		}
	}
	fps.stop();
    return 0;
}
