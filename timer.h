#include <SDL/SDL.h>

class Timer
{
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void unpause();
		int get_ticks();
		bool is_started();
		bool is_paused();
		
		void delay( int fps );

	private:

		int startTicks;
		int pausedTicks;
		bool paused;
		bool started;
};
