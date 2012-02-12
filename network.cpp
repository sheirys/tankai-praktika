#include <iostream>
#include <SDL/SDL_net.h>
#include <SDL/SDL.h>

#include "network.h"

using namespace std;

string network::i2string(int i) {
	std::ostringstream buffer;
	buffer << i;
	return buffer.str();
}

network::network() {

	nr = 0;
	tankas_x = tankas_y = 0;
	tankas_angle = 0;
	patranka_angle = 0;
	busena = 1;
	
	for(int i=0; i < SOVINIAI; i++) {
		sovinys_x[i] = 0;
		sovinys_y[i] = 0;
	}
}

void network::disconnect() {
	
	string data = "";
	string id = i2string(nr);
	data += id+" ";
	data += "bye ";
	send((char*)data.c_str());
	
}

bool network::hello() {

	cout << "\tSveikinames su serveriu...\n";
	char* answer = "";
	char* buffer = "";
	int number = -1;
	int nepavyko = 0;
	
	do {
		cout << "\tBandom jungtis " << nepavyko << " karta\n";
		send("hello");
		SDL_Delay(WAIT_ANSWER);
		answer = listen();
		if ( answer == "" ) {
			SDL_Delay(WAIT);
			nepavyko++;
		}
	} while ( (answer == "") && (nepavyko < BANDYMAI_PRISIJUNGTI ));
	
	number = atoi(answer);
	nr = number;
	if( number > 0 ) {
		cout << "\tGautas id: " << nr << "\n";
		return true;
	} else {
		cout << "\tTavo id yra: " << nr << " ,netinkamas vartojimui\n";
		return false;
	}

}

void network::send() {

	string tmp = "";

	tmp+=i2string(nr)+" ";
	tmp+=i2string(busena)+" ";
	tmp+=i2string(tankas_x)+" ";
	tmp+=i2string(tankas_y)+" ";
	tmp+=i2string(tankas_angle)+" ";
	tmp+=i2string(patranka_angle)+" ";
	
	for (int i=0; i<SOVINIAI; i++) {
		tmp+=i2string(sovinys_x[i])+" ";
		tmp+=i2string(sovinys_y[i])+" ";
	}
	
	send((char*)tmp.c_str());
}

void network::send(char* buffer) {
	
	strcpy((char*)p->data,buffer);
	p->len = strlen((char *)p->data) + 1;
	cout << "\tNetwork::send -> \"" << (char*)p->data << "\", " << p->len << "\n";
	SDLNet_UDP_Send(sd, -1, p);
}

char* network::listen() {

	if (SDLNet_UDP_Recv(sd, p)) 
	{
		cout << "\tNetwork::recv -> " << (char *)p->data << "\n";
		//cout << "\t\tChan:\t" <<  p->channel << "\n";
		//cout << "\t\tData:\t" << (char *)p->data << "\n";
		//cout << "\t\tLen:\t" <<  p->len << "\n";
		//cout << "\t\tMaxlen:\t" << p->maxlen << "\n";
		//cout << "\t\tStatus:\t" <<  p->status << "\n";
		//cout << "\t\tAddress:\t" <<  p->address.host << " " <<  p->address.port << "\n";
		return (char*)p->data;
	} else {
		return "";
	}
}

bool network::init(char* host, int port) {

	cout << "\tIkraunamas tinklas...\n";

	if (SDLNet_Init() < 0)
	{
		cout << "SDLNet_Init: " << SDLNet_GetError() << "\n";
		exit(EXIT_FAILURE);
	}
 
	if (!(sd = SDLNet_UDP_Open(0)))
	{
		cout << "SDLNet_UDP_Open: " << SDLNet_GetError() << "\n";
		exit(EXIT_FAILURE);
	}
 
	if (SDLNet_ResolveHost(&srvadd, host, port) == -1)
	{
		cout << "SDLNet_ResolveHost:" << SDLNet_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	if (!(p = SDLNet_AllocPacket(BUFFER)))
	{
		cout << "SDLNet_AllocPacket:" <<  SDLNet_GetError() << "\n";
		exit(EXIT_FAILURE);
	}
	
	cout << "\tNetwork = " << &srvadd << "\n";
	cout << "\t\tNetwork->host:\t" << host << "\n";
	cout << "\t\tNetwork->port:\t" << port << "\n";
	cout << "\t\tNetwork->buff:\t" << BUFFER << "\n";
	
	p->address.host = srvadd.host;
	p->address.port = srvadd.port;
}

