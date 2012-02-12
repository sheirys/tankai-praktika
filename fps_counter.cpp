#include "fps_counter.h"

fps_counter::fps_counter()
{
        frame_cap = 60;
        cap_off();
        last_fps=0;
        last_timeslice=1;
};

void fps_counter::tick()
{
        float fps;
        float total_ticks,last_ticks;
        do{
                total_ticks = SDL_GetTicks();
                last_ticks = total_ticks - app_ticks;
                fps = 1000.0 / last_ticks;

        }while ( fps > 1000 || ((fps > frame_cap) && cap_frames));

        app_ticks = total_ticks;
        last_fps = fps;
        last_timeslice = 1.0f / fps;
        //printf("Timer updated, last_fps= %f , last_timeslice=%f\n",last_fps,last_timeslice);
};

void fps_counter::set_cap(int cap)
{
        frame_cap = cap;
};

void fps_counter::cap_off()
{
        cap_frames = false;
};

void fps_counter::cap_on()
{
        cap_frames = true;
};
