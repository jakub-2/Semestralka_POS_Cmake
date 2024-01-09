#pragma once

#include <WinSock2.h>
#include <string>

class Sockety
{
public:
	Sockety();
	~Sockety();

	void vytvorPripojenieKlient(std::string adresa, short port);
	void vytvorSocketServer(short port);
	void posliData(std::string data);
	std::string prijmiData();

private:
	const char* endMessage;
	SOCKET connectSocket;
};