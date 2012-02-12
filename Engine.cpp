#include "Engine.h"
#include "Busena.h"

//-----------------------------------------------------------------------------
//Paledziamas zaidimo varikliukas
void Engine::Init(const char* title, int width, int height,	int bpp, bool fullscreen)
{
	int flags = 0;
    //inicijuojame SDL funkcijas
	SDL_Init(SDL_INIT_EVERYTHING);
    //Nustatome lango antraste
	SDL_WM_SetCaption(title, title);

    //tikriname ar fullscreen
	if ( fullscreen )
    {
		flags = SDL_FULLSCREEN;
	}

    //inicijuojame ekrana
	screen = SDL_SetVideoMode(width, height, bpp, flags);

	m_fullscreen = fullscreen;

	m_running = true;

	std::cout<<("Zaidimo varikliukas veikia!\n");
}
//-----------------------------------------------------------------------------
//Isvalomos visos busenu klases
void Engine::Cleanup()
{
	while ( !busenos.empty() )
	{
		busenos.top()->Cleanup();
		busenos.pop();
	}

	// switch back to windowed mode so other
	// programs won't get accidentally resized
	if ( m_fullscreen )
	{
		//screen = SDL_SetVideoMode(640, 480, 0, 0);
	}

	std::cout<<("Variklis iðvalytas!\n")<<std::endl;

	SDL_Quit();
}
//-----------------------------------------------------------------------------
void Engine::ChangeState(Busena* state)
{
	// Istriname dabartine busena
	if ( !busenos.empty() )
    {
		busenos.top()->Cleanup();
		busenos.pop();
	}

	//Patalpiname ir paleiziame nauja busena
	busenos.push(state);
	busenos.top()->Init();
}
//-----------------------------------------------------------------------------
void Engine::PushState(Busena* state)
{
	// pause current state
	if ( !busenos.empty() )
    {
		busenos.top()->Pause();
	}

	// store and init the new state
	busenos.push(state);
	busenos.top()->Init();
}
//-----------------------------------------------------------------------------
void Engine::PopState()
{
	// cleanup the current state
	if ( !busenos.empty() )
    {
		busenos.top()->Cleanup();
		busenos.pop();
	}

	// resume previous state
	if ( !busenos.empty() ) {
		busenos.top()->Resume();
	}
}
//-----------------------------------------------------------------------------
void Engine::HandleEvents()
{
	// let the state handle events
	busenos.top()->HandleEvents(this);
}
//-----------------------------------------------------------------------------
void Engine::Update()
{
	// let the state update the game
	busenos.top()->Update(this);
}
//-----------------------------------------------------------------------------
void Engine::Draw()
{
	// let the state draw the screen
	busenos.top()->Draw(this);
}
