#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Winsock2.h>
#include <Windows.h>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <exception>
#include "LoginRequestHandler.h"
#include "WSAInitializer.h"
#include "Helper.h"
#include "reqStructs.h"
#include "ResponseStructs.h"
#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "RequestHandlerFactory.h"


#define PORT 8826

class Communicator
{
private:
	SOCKET _serverSocket;
	std::map<SOCKET, IRequestHandler*> _users;
	RequestHandlerFactory factory;

	WSAInitializer wsaInit;
	//std::vector<std::thread> _threadList;

	void handleNewCliant(SOCKET clientSocket);
	//void bindAndListen();

	void bindAndListen();

public:
	void startHandleRequests();

	Communicator(RequestHandlerFactory& factory);
	~Communicator();



};

