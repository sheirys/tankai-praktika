#include "Extract.h"
 #include <iostream>
 #include <stdio.h>
void Extract::parse(char* data)
{
    temp_vec.clear();
    int len = strlen(data);
    string temp = "";
    for(int i = 0; i< len+1; i++)
    {
       if((data[i]!=' ') && (i+1) <= len)
            temp=temp+data[i];
       else
       {
           temp_vec.push_back(temp);
           temp="";
       }
    }

    split();
}
void Extract::split()
{
    int kiekT = atoi((char*)temp_vec[0].c_str()); //suzinome kiek tanku yra zaidime

    if(kiekT > 0)
    {
        RT.clear();
        for(int i = 1; i <= kiekT; i++)
            {
                RecTankai *t = NULL; //Sukuriam nauja objekta tanko duomenims
                t = new RecTankai();
                int temp;

                temp =  atoi((char*)temp_vec[i * DuomenuKiekis - 7].c_str()); //Isskiriame ID
                t->ID = atoi((char*)temp_vec[i * DuomenuKiekis - 7].c_str());

                temp =  atoi((char*)temp_vec[i * DuomenuKiekis - 6].c_str()); //Isskiriame x
                t->X = atoi((char*)temp_vec[i * DuomenuKiekis - 5].c_str());

                temp =  atoi((char*)temp_vec[i * DuomenuKiekis -  5].c_str()); //Isskiriame y
                t->Y = atoi((char*)temp_vec[i * DuomenuKiekis  -  4].c_str());

                RT.push_back(t);

            }
    }
}
