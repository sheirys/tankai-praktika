#include "Core.h"
#include "Engine.h"
#include "Intro.h"
#include "network.h"

using namespace std;


Core::Core()
{
 Ekranas = NULL;
 Tempp = NULL;
 for (int i = 1; i<32; i++)
 {
    std::string pav="aura/A";
    std::stringstream ss;
    ss << i;
    if(i<10)
        {pav=pav +"000"+ss.str()+".png"; std::cout<<pav<<std::endl;}
    else if(i<100)
            pav=pav +"00"+ss.str()+".png";
         else
        pav=pav+"0"+ss.str()+".png";

    Tempp = IMG_Load(pav.c_str());
    if(Tempp != NULL)
    {
        A.push_back(Tempp);
    }

}
 Tempp=NULL;
 busena  = true;
 Susidure=false;
 frame   = 0;
 cap = true;
 data.load_options("options.txt");
 data.load_images("data.txt");

 kiek=1;
 K.clear();
 //iseiti = &Core::Valyti;
 //game   = &Core::Vykdyti;


// sekcijos.push_back(iseiti);
 //sekcijos.push(iseiti);
 //sekcijos.push_(game);
}


/*int Core::Vykdyti()
{
    Timer FPS;

    Uint32    update = SDL_GetTicks();
    int frames=0;

   if(Pradeti()==false)
    {
        return -1;
    }
    SDL_Event Event;

    upup=true;
    updw=true;
    upka=true;
    upde=true;

 while(busena)
 {

     Anim.Atnaujinti();

     while(SDL_PollEvent(&Event))
     {

        if( Event.type == SDL_MOUSEBUTTONDOWN  )
        {
            K.push_back( Kulka( T.getX()+T.rotation->w/2,T.getY()+T.rotation->h/2, T.GetAngle() ) );
        }
        if( Event.type == SDL_MOUSEMOTION)
        {
            xp = Event.motion.x;
            yp = Event.motion.y;
        }

      OnEvent(&Event);
     }
    int tmp = K.size();

    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
       K[i].Atnaujinti();
    }


    T.atnaujinti(xp, yp);//peles kooerdinates

     if(!upup)
    {
       int TX = T.GetNextX(0);
       int TY = T.GetNextY(0) ;
        {
            if(SDL_CollidePixel( T.rotation , TX , TY, Tk , 400 , 50)==0)
            {
              T.veiksmas(2,1, xp, yp);

            }
        }
    }
     if(!updw)
     {


       int TX = T.GetNextX(1);
       int TY = T.GetNextY(1) ;
       cout<<"Next: X ="       <<T.GetNextX(0)<<" Y ="<<T.GetNextY(1) <<"."<<endl;
       cout<< "Dabartiniai: X ="<< T.getX() <<" Y ="<<T.getY() <<"."<<endl;
        {
            if(SDL_CollidePixel( T.rotation , TX , TY, Tk , 400 , 50)==0)
            {
              T.veiksmas(1,1, xp, yp);
            }
        }
    }
     if(!upka)
     {
       int TX = T.getX();
       int TY = T.getY() ;
        {
            if(SDL_CollidePixel( T.rotation , TX , TY, Tk , 400 , 50)==0)
            {
              T.veiksmas(4,1, xp, yp);
            }
        }

     }
     if(!upde)
     {
       int TX = T.getX();
       int TY = T.getY() ;
        {
            if(SDL_CollidePixel( T.rotation , TX , TY, Tk , 400 , 50)==0)
            {
              T.veiksmas(3,1, xp, yp);
            }
        }
     }
     Render();


    if(SDL_GetTicks()-update>1000)
    {
     float fps = (frames*1.0)/(SDL_GetTicks()-update)*1000;
     stringstream  ss;
     ss<<floor(fps);
     SDL_WM_SetCaption(("FPS: "+ss.str()).c_str(), NULL);
     update = SDL_GetTicks();
     frames = 0;
    }
    ++frames;


     FPS.delay(60);
 }

 Valyti();
 return 0;
}*/
int Core::run()
{
   Vykdyti();

}
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
