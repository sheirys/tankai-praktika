#ifndef class_fps_counter_h
#define class_fps_counter_h
#include <SDL/SDL.h>
class fps_counter{
private:
        unsigned int app_ticks;//total ticks so far in this app
        int frame_cap; //limit FPS to this
        bool cap_frames; //do we need to?
        float last_fps;
        float last_timeslice;
public:
        fps_counter();

        void set_cap(int fps);
        void cap_on();
        void cap_off();
        void tick();

        float get_fps(){return last_fps;};
        float get_timeslice(){return last_timeslice;};

};
#endif
