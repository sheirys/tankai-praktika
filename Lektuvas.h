#ifndef _LEKTUVAS_H_
    #define _LEKTUVAS_H_

    #include "AutoBaze.h"
    #include "Core.h"
    class Lektuvas : public AutoBaze, private Core
    {
        private:

        public:
        Lektuvas(int x, int y, double k, double greitis, short int tipas);
        int GetX();
        int GetY();
        SDL_Surface* GetSurface(double scale);
        void Atnaujinti();
        void kairen();
        void desinen();
        Lektuvas();
        ~Lektuvas();

    };
#endif
