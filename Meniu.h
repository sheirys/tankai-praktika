#ifndef _MENIU_H_
    #define _MENIU_H_

#include <SDL/SDL.h>
#include "Button.h"
#include <SDL/SDL_mixer.h>

class Node
{
  public:
        Button* mygtukas;
//-----------------------
        Node* next;//Pointeris i sekanti elementa
        Node* prev;//pointeris i pries tai einanti
};
class DLCL //Dvikryptis ciklinis sarasas
{
    public:
        Node* front;//pointeris i pirmaji elementa
        Node* back;//pointeris i sekanti elementa
        DLCL()
        {
            front = NULL;
            back  = NULL;
        }
//-----------------------------------------------------
        void insert(Button* bt)
        {
            Node *newNode;
            newNode=new Node();
            newNode->mygtukas = bt;
            if(back==NULL)//jegu sarasas tuscias
            {
                this->back =newNode;
                this->front=newNode;

                newNode->next=newNode;
                newNode->prev=newNode;
            }
            else
            {
                newNode->next=this->front;//nurodome kad paskutinis elementas rodo i pirma
                newNode->prev=this->back;
                this->back->next=newNode;
                this->back=newNode;
            }

     }




};

class Meniu : public Busena
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Engine* game);
	void Update(Engine* game);
	void Draw(Engine* game);


	static Meniu* Instance() {
		return &m_Meniu;
	}

protected:
	Meniu() { }

private:
//-----------------------------------------------------------------------------
Mix_Music* MeniuMusic;
//-----------------------------------------------------------------------------
	static Meniu m_Meniu;
	static const int bH = 60; //Mygtuko aukstis
	static const int bW = 550;//Mygtuko plotis
	static const int tarpas = 30; //Tarpas tarp mygtuko
//-----------------------------------------------------------------------------
int x, y; //peles koordinates
//-----------------------------------------------------------------------------
    /*Mygtukai*/

//    knopke Head;
    DLCL* MygtukuSarasas;
	Button Naujas;//(100, 100, 20, 150, "gfhgfng");
	Button Multiplayer;
	Button Nustatymai;
	Button Apie;
	Button Iseiti;
//-----------------------------------------------------------------------------
	SDL_Surface* bg;
};
#endif
