#pragma once

class Panacik {
public:
	Panacik(int _id, int _pozicia);
	~Panacik();
	int getPozicia();
	void potiahni(int roll);
	void nastav();
	bool jeVDomceku();
	void vyhod();

private:
	int id;
	int pozicia;
	bool vDomceku;

};
