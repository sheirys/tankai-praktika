#include <iostream>
#include <SDL/SDL_net.h>
#include <string>
#include <sstream>

#define BUFFER 512
#define SOVINIAI 4
#define BANDYMAI_PRISIJUNGTI 5
#define WAIT 2000
#define WAIT_ANSWER 20

using namespace std;

class network {
	public:
		bool init(char* host, int port); //uzkrauti
		char* listen(); //Klausom ir grazinam teksta
		void send(char*); //siunciam teksta
		void send(); // siunciam savo info
		void hello();
		void disconnect();
		int tankas_x;
		int tankas_y;
		int tankas_angle;
		int patranka_angle;
		int sovinys_x[SOVINIAI];
		int sovinys_y[SOVINIAI];
		int busena;
		int nr;
		network();
	
	private:
		string i2string(int);
		UDPsocket sd;
		IPaddress srvadd;
		UDPpacket *p;
};
