#ifndef _EXTRACT_H_
    #define _EXTRACT_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    #include <iostream>
    #include <string>
    #include <string.h>

    #include "RecTankai.h"

#define DuomenuKiekis 8
using namespace std;
class Extract
{   private:
        vector<string> temp_vec;
    public:
        vector<RecTankai*> RT;//duomenys gauti apie visus tankus
       //vector<string> temp_vec;
       void parse(char* data);
       void split();

};
#endif
