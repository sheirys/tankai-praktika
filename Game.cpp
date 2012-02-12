#include "Game.h"

Game Game::m_PlayState;

void Game::Init()
{
	cout << "Game Init\n";
    kiekP= 0;
    cout << "Kraunam paveiksliukus\n";
    data.load_images("data.txt");
    cout << "Kraunam mapa\n";
    data.load_map("test.map");


    net.init("localhost",5151);
    net.hello();

	upup=true;
    updw=true;
    upka=true;
    upde=true;

    //sukuriame objekta kuris rupinasi animacija
    /**@images  - surfeisu duomenu baze*/
    Animacija(images);

    Tankas* tk= NULL;
    tk = new Tankas();
    tankai.push_back(tk);

    Tankas* tk1= NULL;
    tk1 = new Tankas(1, 400, 300);
    tankai.push_back(tk1);


    Tankas* tk2= NULL;
    tk2 = new Tankas(2, 650,200);
    tankai.push_back(tk2);

    Tankas* tk3= NULL;
    tk3 = new Tankas(3, 300,100);
    tankai.push_back(tk3);

    Tankas* tk4= NULL;
    tk4 = new Tankas(4, 400,100);
    tankai.push_back(tk4);

}

void Game::Cleanup()
{

    images.~ImageLoader();
	SDL_FreeSurface(bg);
}

void Game::Pause()
{
    images.~ImageLoader();
}

void Game::Resume()
{
}

void Game::HandleEvents(Engine* game)
{
    kiekP++;
    //std::ostringstream temp;
    //temp<<kiekP;

   // string temp1 = "get"+temp.str();

   // net.send((char*)temp1.c_str());
	SDL_Event event;

	if (SDL_PollEvent(&event))
	 {

		switch (event.type)
		{
			case SDL_QUIT:
			{
                net.disconnect();
				game->Quit();
				break;
			}

			case SDL_MOUSEMOTION:
			{
			    px = event.motion.x;
                py = event.motion.y;
                break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
			    if (event.button.button == (SDL_BUTTON_LEFT))
               {
                   Kulka*  blt = NULL;
                   //blt = new Kulka(  tankai[0]->getX()+ tankai[0]->rotation->w/2 + 20    ,tankai[0]->getY()+ tankai[0]->rotation->h/2 + 25, tankai[0]->GetAngle());
                   blt = new Kulka(  tankai[0]->getX()+ tankai[0]->rotation->w/2 + 20+100    ,tankai[0]->getY()+ tankai[0]->rotation->h/2 + 25+100, tankai[0]->GetAngle());
                   kulkos.push_back(blt);
                   break;
               }
			}

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				 {
					case SDLK_ESCAPE:
						game->Quit();
						break;

					case SDLK_m:
						game-> PushState( Meniu::Instance() );
						break;

					case SDLK_UP:
					{
					    upup=false; //nurodome kad mygtukas aukstyn yra nuspaustas
					    break;
					}
					case SDLK_DOWN:
					{
					    updw = false;
					    break;
					}

					case SDLK_LEFT:
					{
					    upka=false;
					    break;
					}
					case SDLK_RIGHT:
					{
					    upde=false;
					    break;
					}
				}
				break;

             case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                     case SDLK_UP:
                    {
                        upup=true;
                        break;
                    }

                    case SDLK_DOWN:
                    {
                        updw=true;
                        break;
                    }

                    case SDLK_LEFT:
                    {
                        upka=true;
                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        upde=true;
                        break;
                    }
                }
                break;
		}
	}
}

void Game::Update(Engine* game)
{
/*Tinklo reikalai*/

//delay(3);
char* duom = NULL;
net.tankas_x = tankai[0]->getX();
net.tankas_y = tankai[0]->getY();
net.send();
//SDL_Delay(10);

//duom = net.listen();
duom = "2 1 1 200 500 0 0 0 0 2 1 325 50";
//cout<<"Gauti data:   "<<duom<<endl;

//D.temp_vec.clear();
D.parse(duom);
int  Xg =300;
int  Yg =300;

int  Xg1 =350;
int  Yg1 =300;

if(D.RT.size()> 0 )
{
    for( int i = 0; i < D.RT.size(); i++)
    {
        if(!ArYra(D.RT[i]->ID))//tikriname ar tankas u duotuoju id yra sarase jei nera pridedame
        {
            //Tankas* tk= NULL;
            //tk = new Tankas(D.RT[i]->ID, D.RT[i]->X, D.RT[i]->Y);
            //tankai.push_back(tk);
        }

        for(int j = 0; j<tankai.size(); j++)
        {
            cout<<"Tanko ID: "<<tankai[j]->GetID()<<" Gautas ID: "<<D.RT[i]->ID<<endl;
            if(tankai[j]->GetID() == D.RT[i]->ID)
                {
                    tankai[j]->SendXY(D.RT[i]->X, D.RT[i]->Y);
                    break;
                }
        }


         // Xg = D.RT[i]->X;
          //Yg = D.RT[i]->Y;
    }

    cout<<"koordinates X="<<Xg<<" Y="<<Yg<<"."<<endl;
   // Xg = D.RT[0]->X;
    //Xg = D.RT[0]->Y;
}

/*string kiekT;//kiek tanku


cout<<"Origininalas: "<<duom<<"."<<endl;
int len = 0;

while(duom[len] != NULL)
{
    len++;
}
string Xchar = "";
string Ychar = "";

for (int i = 0; i <= len; i++)
{
    if (duom[i] != ' ')
    {
        kiekT = kiekT+duom[i];
        //Xchar=Xchar+duom[i];
    }
}
  /*  else
    {
        for (int j = i+1; j<= len ; j++)
        {
           Ychar=Ychar+duom[j];
        }
        break;
    }
}*/



//string Xchar = "00";
//string Ychar = "00";
//xy[0]=duom[0];
//xy[1]=duom[1];
//cout<<Ychar<<endl;
/*
const char*  tempX =  Xchar.c_str();
const char*  tempY =  Ychar.c_str();
int Xgautas = atoi(tempX);
int Ygautas = atoi(tempY);
cout<<"X koordinate: "<<Xgautas <<". Y koordinate: "<<Ygautas<<"."<<endl;
*/
//-------------------------------------
/*Atnaujiname visas issautas kulkas*/
   /* int tmp = kulkos.size();

    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
      kulkos[i]->Atnaujinti();
    }
    tmp = kulkos.size();

    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
      if( SDL_CollidePixel( tankai[1]->rotation ,tankai[1]->getX()  , tankai[1]->getY(),kulkos[i]->KPasukta , kulkos[i]->GetX()  , kulkos[i]->GetY()) != 0)
      {
          anim.AddBum(kulkos[i]->GetX()+10, kulkos[i]->GetY()+10);               //pridedame sprogimo animacija
          kulkos.erase( kulkos.begin()+ i );                                     //istriname kulka is saraso

          break;
      }

    }*/

//-------------------------------------
/*Atnaujiname animacijas*/
    anim.Atnaujinti();
//-------------------------------------
    int tmp = kulkos.size();
    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
        kulkos[i]->Atnaujinti();
    }

//-------------------------------------
/*Atnaujiname visus tankus*/

    tmp = tankai.size();
    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
        if(!(tankai[i]->GetBusena()))
           tankai.erase(tankai.begin()+i);
    }


    tmp = tankai.size();
    if(tmp!=0)
    for(int i = 0; i < tmp; i++)
    {
        tankai[i]->atnaujinti(px, py, kulkos);
    }

    //tankai[1]->atnaujinti(Xg, Ygautas, kulkos);
   //tankai[1]->atnaujinti(700, 350, kulkos);
  /*
   tankai[1]->SendXY(Xg, Yg);
   tankai[1]->atnaujinti(px, py, kulkos);

   tankai[2]->SendXY(Xg1, Yg1);
   tankai[2]->atnaujinti(px, py, kulkos);*/

/*   tankai[3]->atnaujinti(700, 350, kulkos);*/

//-------------------------------------------------------
 /*Atnaujiname visas issautas kulkas*/
 /*ar nepataike i tanka*/
    tmp = kulkos.size();
    int tnk = tankai.size();

    if(tmp!=0 && tnk !=0)
    for(int i = 0; i < tmp; i++)
    {
      //kulkos[i]->Atnaujinti();
        for(int j = 0; j<tnk;j++)
            if( SDL_CollidePixel( tankai[j]->rotation ,tankai[j]->getX()  , tankai[j]->getY(),kulkos[i]->KPasukta , kulkos[i]->GetX()  , kulkos[i]->GetY()) != 0)
            {
               // anim.AddBum(kulkos[i]->GetX()+10, kulkos[i]->GetY()+10);               //pridedame sprogimo animacija
                kulkos.erase( kulkos.begin()+ i );                                     //istriname kulka is saraso
                break;
            }

    }

//-------------------------------------
if(!upup)
    {
       int TX = tankai[0]->GetNextX(0);
       int TY = tankai[0]->GetNextY(0);
        {
            if(SDL_CollidePixel( tankai[0]->rotation , TX , TY, tankai[1]->rotation ,tankai[1]->getX(), tankai[1]->getY())==0)
            {
              tankai[0]->veiksmas(2,1, px, py);
              net.tankas_x = tankai[0]->getX();
              net.tankas_y = tankai[0]->getY();
            }
        }
    }
//-------------------------------------
if(!updw)
     {


       int TX = tankai[0]->GetNextX(1);
       int TY = tankai[0]->GetNextY(1) ;
        {
            if(SDL_CollidePixel( tankai[0]->rotation , TX , TY, tankai[1]->rotation ,tankai[1]->getX(), tankai[1]->getY())==0)
            {
             tankai[0]->veiksmas(1,1, px, py);
            }
        }
    }
//-------------------------------------
if(!upka)
     {
       int TX = tankai[0]->getX();
       int TY = tankai[0]->getY();
        {
            if(SDL_CollidePixel( tankai[0]->rotation , TX , TY, tankai[1]->rotation ,tankai[1]->getX(), tankai[1]->getY())==0)
            {
              tankai[0]->veiksmas(4,1, px, py);
            }
        }

     }
//-------------------------------------
if(!upde)
     {
       int TX = tankai[0]->getX();
       int TY = tankai[0]->getY() ;
        {
            if( SDL_CollidePixel( tankai[0]->rotation , TX , TY, tankai[1]->rotation ,tankai[1]->getX(), tankai[1]->getY())==0)
            {
              tankai[0]->veiksmas(3,1, px, py);
            }
        }
     }

}

/*void Game::Draw(Engine* game)
{
    //CDraw(game);
	SDL_BlitSurface(bg, NULL, game->screen, NULL);
	SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}*/
bool Game::ArYra(int ID)
{
    for(int i = 0; i<tankai.size(); i++)
    {
        if(tankai[i]->GetID() == ID)
            return true;
    }
    return false;
}

