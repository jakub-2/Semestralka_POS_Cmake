// Semestralka_POS_Cmake.cpp : Defines the entry point for the application.
//

#include "Semestralka_POS_Cmake.h"

#include <Windows.h>
#include <unordered_map>
#include "Hrac.h"

using namespace std;

void vypis(std::vector<Hrac*>* hraci) {
	system("CLS");
	for (Hrac* hrac : *hraci) {
		for (int i = 0; i < 4; i++) {
			if (hrac->getPozicia(i) == -1) {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je na zaciatku" << std::endl;
			} else if (hrac->getPozicia(i) > 39 + hrac->getOffset()) {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je v domceku na pozici " << (hrac->getPozicia(i) - 39 - hrac->getOffset()) << std::endl;
			} else {
				std::cout << "Figurka - " << i + 1 << " hraca " << hrac->getID() << " je na pozici - " << (hrac->getPozicia(i) % 40) + 1 << std::endl;
			}
		}
		std::cout << "----------------------------" << std::endl;
	}
}


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<std::string> farby;
	farby.push_back("red");
	farby.push_back("blue");
	farby.push_back("green");
	farby.push_back("yellow");


	std::vector<Hrac*> hraci;
	srand(time(0));

	for (int i = 0; i < 2; i++) {
		Hrac* hrac = new Hrac(i, farby.at(i));
		hraci.push_back(hrac);
	}
	vypis(&hraci);
	bool ended = false;
	while (!ended) {
		for (Hrac* hrac : hraci) {
			int roll = rand() % (6 - 1 + 1) + 1;
			std::cout << "Padlo: " << roll << std::endl;
			int checkPozicia = 0;
			bool tahUkonceny = false;
			while (!tahUkonceny) {
				std::cout << "Na tahu je hrac " << hrac->getID() << "\nVyber tah 1-4 alebo 5 pre preskocenie tahu" << std::endl;
				int tah = 0;
				std::cin >> tah;
				if (tah == 5) {
					tahUkonceny = true;
					checkPozicia = 100; // pozicia mimo boardu kedze sa skiplo
				} else if (hrac->tahCheck(roll, tah - 1)) {
					checkPozicia = (hrac->getPozicia(tah - 1) % 40);
					tahUkonceny = true;
				} else {
					std::cout << "Zly tah" << std::endl;
				}
			}
			for (Hrac* hracKontrola : hraci) {
				if (hrac->getID() == hracKontrola->getID()) {
					continue;
				}
				if (hracKontrola->checkPanak(checkPozicia)) {
					break;
				}
			}
			if (hrac->vyhral())
			{
				system("CLS");
				std::cout << "Hru vyhral hrac - " << hrac->getID() << std::endl;
				ended = true;
				break;
			}
			vypis(&hraci); //TODO hracov

		}
	}
	return 0;
}

