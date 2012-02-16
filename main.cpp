#include "Engine.h"
#include "Intro.h"
int main(int argc, char* argv[])
{
   freopen("CON", "w", stdout);
   freopen("CON", "w", stderr);
   //Core P;
   // return P.run();
  //  P.Vykdyti();


    Engine game;

     game.Init( "Pre-alpha edition!" );
     game.ChangeState( Intro::Instance() );


    while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
		SDL_Delay(10);
	}
    return 0;
}
