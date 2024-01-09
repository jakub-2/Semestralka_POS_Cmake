#pragma once
#include <vector>
#include "Sockety.h"
#include "Hrac.h"
#include <mutex>

class Server {
public:
	Server(int pocetHracov, int port);
	~Server();
	bool skontrolujVyhru();

private:
	std::vector<Sockety*> sockety;
	std::vector<Hrac*> hraci;
	std::vector<std::string> farby;

	//std::mutex hraci;


};