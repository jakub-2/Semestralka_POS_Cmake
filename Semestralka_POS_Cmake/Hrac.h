#pragma once
#include "Panacik.h"
#include <string>
#include <vector>


class Hrac {
public:
	Hrac(int _id, std::string _farba);
	~Hrac();
	bool tahCheck(int roll, int idFigurky);
	bool checkPanak(int pozicia);
	int getID();
	int getPozicia(int idFigurky);
	int getOffset();
	std::string getFarba();

	//void potiahni(int roll, int idFigurky);

private:
	std::vector<Panacik*> panacikovia;
	int id;
	std::string farba;
	int offset;
	bool polickoOkupovane(int idFigurky, int buducaPozicia);

};