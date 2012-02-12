#ifndef _AUTOBAZE_H_
    #define _AUTOBAZE_H_

    #include <math.h>

    #include <SDL/SDL_image.h>
    #include "CLoad_image.h"
    #include <SDL/SDL_rotozoom.h>

class AutoBaze //Bazinë transporto priemoniø klasë
{
        public:
            AutoBaze();
            void Update();

            void sukti_kairen();
            void sukti_desinen();

            void sukti_kairen(int kiek);
            void sukti_desinen(int kiek);

            int GetX();
            int GetY();
            double GetAngle();

            protected:

            int X, Y;
            double kampas;
            double Greitis;
            SDL_Surface* Sprite;
};
#endif
