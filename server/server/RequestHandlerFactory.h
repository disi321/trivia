#pragma once
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "RoomManager.h"
class LoginRequestHandler;
class MenuRequestHandler;
class RequestHandlerFactory
{
private:
	LoginManager loginManager;
	IDatabase* db;
	RoomManager roomManager;
	//StatisticsManager statisticsManager;


public:
	RequestHandlerFactory(IDatabase* d);
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();

	RoomManager& getRoomManager();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser u);
	//StatisticsManager& getStatisticsManager();

};

