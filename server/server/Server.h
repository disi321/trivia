#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "LoginRequestHandler.h"
#include "WSAInitializer.h"
#include "Communicator.h"

class Server
{
private:
	IDatabase* db;
	RequestHandlerFactory factory;
	Communicator communicator;
	//std::vector<std::string> _userList;

	//Comunicator


public:
	Server();
	~Server();
	void run();


};
