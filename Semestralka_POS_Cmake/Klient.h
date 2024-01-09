#pragma once
#include <string>
#include "Sockety.h"
#include <vector>
#include "Hrac.h"

class Klient
{
public:
	Klient(std::string ip, int port);
	~Klient();
	std::string prijmyData();
	std::string getFarba(int index);
	void pridajHraca(Hrac* hrac);
	void nastavId(int _id);
	int getID();
	void vypis();
	void posliData(int moznost);
	void pohniFigurkouHraca(int idHraca, int idFigurky, int roll);

private:
	Sockety* socket;
	std::vector<Hrac*> hraci;
	std::vector<std::string> farby;
	int id;
};