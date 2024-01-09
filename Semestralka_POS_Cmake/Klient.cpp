#include "Klient.h"
#include <iostream>
#include <sstream>

Klient::Klient(std::string ip, int port)
{
	socket = new Sockety();
	socket->vytvorPripojenieKlient(ip, port);
	farby.push_back("red");
	farby.push_back("blue");
	farby.push_back("green");
	farby.push_back("yellow");
}

Klient::~Klient()
{
	delete socket;
}

std::string Klient::prijmyData()
{
	std::string data;
	data = socket->prijmiData();
	return data;
}

std::string Klient::getFarba(int index)
{
	return farby.at(index);
}

void Klient::pridajHraca(Hrac* hrac)
{
	hraci.push_back(hrac);
}

void Klient::nastavId(int _id)
{
	id = _id;
}

int Klient::getID()
{
	return id;
}

void Klient::vypis()
{
	system("CLS");
	std::cout << "Hrac - " << id << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	for (Hrac* hrac : hraci) {
		for (int i = 0; i < 4; i++) {
			if (hrac->getPozicia(i) == -1) {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je na zaciatku" << std::endl;
			}
			else if (hrac->getPozicia(i) > 39 + hrac->getOffset()) {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je v domceku na pozici " << (hrac->getPozicia(i) - 39 - hrac->getOffset()) << std::endl;
			}
			else {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je na pozici - " << (hrac->getPozicia(i) % 40) + 1 << std::endl;
			}
		}
		std::cout << "--------------------------------------------------------" << std::endl;
	}
}

void Klient::posliData(int moznost)
{
	std::string data;
	data += id + ";" + std::to_string(moznost) + ":end";
	socket->posliData(data);
}

void Klient::pohniFigurkouHraca(int idHraca, int idFigurky, int roll)
{
	hraci.at(idHraca)->posun(idFigurky, roll);
}



int main() {
	std::string ip;
	int port;
	std::cout << "Zadaj ip servera: ";
	std::cin >> ip;
	std::cout << "Zadaj port servera: ";
	std::cin >> port;

	Klient* klient = new Klient(ip, port);

	std::string data = klient->prijmyData();
	// prva sprava "2;1" - zaciatok hry, 2 hraci, moje ID,
	int idHraca;
	int pocetHracov;
	std::stringstream ss(data);
	ss >> pocetHracov >> idHraca;
	klient->nastavId(idHraca);
	for (int i = 0; i < pocetHracov; i++)
	{
		Hrac* hrac = new Hrac(i, klient->getFarba(i));
		klient->pridajHraca(hrac);
	}
	bool end = false;
	while (!end) {
		std::string data = klient->prijmyData();
		int id;
		std::stringstream ss(data);
		ss >> id;
		klient->vypis();
		if (id == klient->getID())
		{
			// po id bude hod;1.moznost;2.moznost;3.moznost;4.moznost;5.moznost
			// moznost ma tvar idFigurky-
			int roll;
			std::cout << "Padlo: " << roll << std::endl;
			int velkost = 0;
			while (!ss.eof())
			{
				int moznost;
				ss >> moznost;
				velkost += 1;
				if (moznost == 5)
				{
					std::cout << velkost << ". Skip" << std::endl;
				}
				else {
					std::cout << velkost << ". Tah figurkou - " << moznost << std::endl;
				}
			}
			bool vybrane = false;
			while (!vybrane) {
				int moznost;
				std::cin >> moznost;
				if (moznost < 0 || moznost > velkost)
				{
					std::cout << "Zly vyber" << std::endl;
					continue;
				}
				klient->pohniFigurkouHraca(id, moznost, roll);
				klient->posliData(moznost);
				break;
			}
		}
		else if (id > pocetHracov)
		{
			std::cout << "Vyhral hrac " << id - pocetHracov << std::endl;
			end = true;
			continue;
		}
		else
		{
			int roll;
			int figurka;
			ss >> roll >> figurka;
			klient->pohniFigurkouHraca(id, figurka, roll);
		}
	}

	delete klient;
	klient = nullptr;
	return 0;
}