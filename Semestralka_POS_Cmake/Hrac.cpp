#include "Hrac.h"

Hrac::Hrac(int _id, std::string _farba)
{
	id = _id;
	farba = _farba;
	if (farba == "red") {
		offset = 0;
	} else if (farba == "blue") {
		offset = 10;
	} else if (farba == "green") {
		offset = 20;
	} else {
		offset = 30;
	}

	for (int i = 0; i < 4; i++) {
		Panacik* panak = new Panacik(i, -1);
		panacikovia.push_back(panak);
	}
}

bool Hrac::tahCheck(int roll, int idFigurky)
{
	// overenia
	// panacik mimo boardy
	// okupovane
	// panacik na 0 (pociatona pozicia v rohu)
	if (idFigurky > 3 or idFigurky < 0) {
		return false;
	}

	// panacik mimo boardy
	if (panacikovia.at(idFigurky)->getPozicia() + roll > 44) {
		return false;
	}
	// panacik na 0
	if (panacikovia.at(idFigurky)->getPozicia() == -1 and roll != 6) {
		return false;
	}
	// okupovane
	if (polickoOkupovane(idFigurky, panacikovia.at(idFigurky)->getPozicia() + roll)) {
		return false;
	}

	if (panacikovia.at(idFigurky)->getPozicia() == -1 and roll == 6) {
		if (polickoOkupovane(idFigurky, 1)) {
			return false;
		}
		panacikovia.at(idFigurky)->nastav();
		return true;
	}
	panacikovia.at(idFigurky)->potiahni(roll);
	return true;
}

bool Hrac::checkPanak(int pozicia)
{
	for (Panacik* panak : panacikovia) {
		if (!panak->jeVDomceku() and (panak->getPozicia() + offset) % 40 == pozicia) {
			panak->vyhod();
			return true;
		}
	}
	return false;
}

int Hrac::getID()
{
	return id;
}

int Hrac::getPozicia(int idFigurky)
{
	if (panacikovia.at(idFigurky)->getPozicia() == -1) {
		return -1;
	}
	return (panacikovia.at(idFigurky)->getPozicia() + offset);
}

int Hrac::getOffset()
{
	return offset;
}

std::string Hrac::getFarba()
{
	return farba;
}

bool Hrac::vyhral()
{
	for (Panacik* panak : panacikovia)
	{
		if (!panak->jeVDomceku())
		{
			return false;
		}
	}
	return true;
}

void Hrac::posun(int idFigurky, int roll)
{
	if (roll == -1)
	{
		panacikovia.at(idFigurky)->vyhod();
	}
	else if (roll == 6 and panacikovia.at(idFigurky)->getPozicia() == -1)
	{
		panacikovia.at(idFigurky)->nastav();
	}
	else {
		panacikovia.at(idFigurky)->potiahni(roll);
	}
}

bool Hrac::polickoOkupovane(int idFigurky, int buducaPozicia)
{
	for (int i = 0; i < 4; i++) {
		if (i == idFigurky) {
			continue;
		}
		if (buducaPozicia == panacikovia.at(i)->getPozicia()) {
			return true;
		}
	}
	return false;
}
