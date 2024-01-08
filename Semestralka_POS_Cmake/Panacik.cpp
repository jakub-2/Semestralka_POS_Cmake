#include "Panacik.h"

Panacik::Panacik(int _id, int _pozicia)
{
	id = _id;
	pozicia = _pozicia;
	vDomceku = false;
}

int Panacik::getPozicia()
{
	return pozicia;
}

void Panacik::potiahni(int roll)
{
	if (pozicia + roll > 40) {
		vDomceku = true;
	}
	pozicia += roll;
}

void Panacik::nastav()
{
	pozicia = 0;
}

bool Panacik::jeVDomceku()
{
	return vDomceku;
}

void Panacik::vyhod()
{
	pozicia = -1;
}
