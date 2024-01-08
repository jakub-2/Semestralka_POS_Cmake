// Semestralka_POS_Cmake.cpp : Defines the entry point for the application.
//

#include "Semestralka_POS_Cmake.h"

#include <Windows.h>
#include <unordered_map>
#include "Hrac.h"

using namespace std;

void vypis(std::vector<Hrac*>* hraci) {
	/*auto a = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 40; i++) {
		COORD cords = suradnice->at(i);
		SetConsoleCursorPosition(a, cords);
		if (cords.X == 6 * 2 and cords.Y == 0) {
			std::cout << "R";
		} else if (cords.X == 10 * 2 and cords.Y == 6) {
			std::cout << "B";
		} else if (cords.X == 4 * 2 and cords.Y == 10) {
			std::cout << "G";
		} else if (cords.X == 0 and cords.Y == 4) {
			std::cout << "Y";
		} else {
			std::cout << "O";
		}
	}
	for (int i = 40; i < 44; i++) {
		COORD cords = suradnice->at(i);
		SetConsoleCursorPosition(a, cords);
		std::cout << "R";
	}
	for (int i = 44; i < 48; i++) {
		COORD cords = suradnice->at(i);
		SetConsoleCursorPosition(a, cords);
		std::cout << "B";
	}
	for (int i = 48; i < 52; i++) {
		COORD cords = suradnice->at(i);
		SetConsoleCursorPosition(a, cords);
		std::cout << "G";
	}
	for (int i = 52; i < 56; i++) {
		COORD cords = suradnice->at(i);
		SetConsoleCursorPosition(a, cords);
		std::cout << "Y";
	}

	for (Hrac* hrac : *hraci) {
		for (int i = 0; i < 4; i++) {
			int pozicia = hrac->getPozicia(i);
			if (pozicia == 0) {
				if (hrac->getFarba() == "red") {
					COORD cords = suradnice->at(i + 56);
					SetConsoleCursorPosition(a, cords);
				} else if (hrac->getFarba() == "blue") {
					COORD cords = suradnice->at(i + 60);
					SetConsoleCursorPosition(a, cords);
				} else if (hrac->getFarba() == "green") {
					COORD cords = suradnice->at(i + 64);
					SetConsoleCursorPosition(a, cords);
				} else if (hrac->getFarba() == "yellow") {
					COORD cords = suradnice->at(i + 68);
					SetConsoleCursorPosition(a, cords);
				}
				std::cout << hrac->getFarba().at(0);
			} else {
				COORD cords = suradnice->at(pozicia - hrac->getOffset() + (4* (hrac->getOffset() / 10)));
				SetConsoleCursorPosition(a, cords);
				std::cout << hrac->getFarba().at(0);
			}
		}
	}

	COORD cords = { 0, 14 };
	SetConsoleCursorPosition(a, cords);*/
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
	//std::unordered_map<int, COORD> suradnice;
	//suradnice[0] = { 6*2, 0 }; //R
	//suradnice[1] = { 6*2, 1 };
	//suradnice[2] = { 6*2, 2 };
	//suradnice[3] = { 6*2, 3 };
	//suradnice[4] = { 6*2, 4 };
	//suradnice[5] = { 7*2, 4 };
	//suradnice[6] = { 8*2, 4 };
	//suradnice[7] = { 9*2, 4 };
	//suradnice[8] = { 10*2, 4 };
	//suradnice[9] = { 10*2, 5 };
	//suradnice[10] = { 10*2, 6 }; //B
	//suradnice[11] = { 9*2, 6 };
	//suradnice[12] = { 8*2, 6 };
	//suradnice[13] = { 7*2, 6 };
	//suradnice[14] = { 6*2, 6 };
	//suradnice[15] = { 6*2, 7 };
	//suradnice[16] = { 6*2, 8 };
	//suradnice[17] = { 6*2, 9 };
	//suradnice[18] = { 6*2, 10 };
	//suradnice[19] = { 5*2, 10 };
	//suradnice[20] = { 4*2, 10 }; //G
	//suradnice[21] = { 4*2, 9 };
	//suradnice[22] = { 4*2, 8 };
	//suradnice[23] = { 4*2, 7 };
	//suradnice[24] = { 4*2, 6 };
	//suradnice[25] = { 3*2, 6 };
	//suradnice[26] = { 2*2, 6 };
	//suradnice[27] = { 1*2, 6 };
	//suradnice[28] = { 0, 6 };
	//suradnice[29] = { 0, 5 };
	//suradnice[30] = { 0, 4 }; //Y
	//suradnice[31] = { 1*2, 4 };
	//suradnice[32] = { 2*2, 4 };
	//suradnice[33] = { 3*2, 4 };
	//suradnice[34] = { 4*2, 4 };
	//suradnice[35] = { 4*2, 3 };
	//suradnice[36] = { 4*2, 2 };
	//suradnice[37] = { 4*2, 1 };
	//suradnice[38] = { 4*2, 0 };
	//suradnice[39] = { 5*2, 0 };
	//suradnice[40] = { 5*2, 1 }; //r
	//suradnice[41] = { 5*2, 2 };
	//suradnice[42] = { 5*2, 3 };
	//suradnice[43] = { 5*2, 4 };
	//suradnice[44] = { 9*2, 5 }; //b
	//suradnice[45] = { 8*2, 5 };
	//suradnice[46] = { 7*2, 5 };
	//suradnice[47] = { 6*2, 5 };
	//suradnice[48] = { 5*2, 9 }; //g
	//suradnice[49] = { 5*2, 8 };
	//suradnice[50] = { 5*2, 7 };
	//suradnice[51] = { 5*2, 6 };
	//suradnice[52] = { 1*2, 5 }; //y
	//suradnice[53] = { 2*2, 5 };
	//suradnice[54] = { 3*2, 5 };
	//suradnice[55] = { 4*2, 5 };
	//suradnice[56] = { 9 * 2, 0 }; //RR
	//suradnice[57] = { 10 * 2, 0 };
	//suradnice[58] = { 9 * 2, 1 };
	//suradnice[59] = { 10 * 2, 1 };
	//suradnice[60] = { 9 * 2, 9 }; //BB
	//suradnice[61] = { 10 * 2, 9 };
	//suradnice[62] = { 9 * 2, 10 };
	//suradnice[63] = { 10 * 2, 10 };
	//suradnice[64] = { 0, 9 }; //GG
	//suradnice[65] = { 1 * 2, 9 };
	//suradnice[66] = { 0, 10 };
	//suradnice[67] = { 1 * 2, 10 };
	//suradnice[68] = { 0, 0 }; //YY
	//suradnice[69] = { 1 * 2, 0 };
	//suradnice[70] = { 0, 1 };
	//suradnice[71] = { 1 * 2, 1 };


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
	vypis(&hraci); //TODO hracov
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
					checkPozicia = (hrac->getPozicia(tah - 1) % 40) + 1;
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
			vypis(&hraci); //TODO hracov

		}
	}
	return 0;
}

