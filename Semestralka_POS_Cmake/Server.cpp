#include "Server.h"
#include <iostream>

Server::Server(int pocetHracov, int port)
{
	farby.push_back("red");
	farby.push_back("blue");
	farby.push_back("green");
	farby.push_back("yellow");
	Hrac* hrac = new Hrac(0, farby.at(0)); // server
	hraci.push_back(hrac);
	for (int i = 1; i < pocetHracov; i++)
	{
		Sockety* socket = new Sockety();
		Hrac* hrac = new Hrac(i, farby.at(i));
		socket->vytvorSocketServer(port + i - 1);
		hraci.push_back(hrac);
	}
}

bool Server::skontrolujVyhru()
{
	for (Hrac* hrac : hraci)
	{
		if (hrac->vyhral())
		{
			return true;
		}
	}
}

int main() {


	int pocetHracov, port;
	std::cout << "Zadaj pocet hracov - ";
	std::cin >> pocetHracov;
	std::cout << "Zadaj port pre Hraca 1, ostatny hraci maju port zadany + index hraca - ";
	std::cin >> port;

	Server* server = new Server(pocetHracov, port);
	bool vyhral = false;
	while (!vyhral)
	{
		if (server->skontrolujVyhru()) {
			break;
		}
	}
	// 

	return 0;
}