#include "RequestHandlerFactory.h"

//RequestHandlerFactory::RequestHandlerFactory()
//	:loginManager(LoginManager(db))
//{
//}

RequestHandlerFactory::RequestHandlerFactory(IDatabase* d)
	:db(d), loginManager(LoginManager(d))
{
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler(*this);
}


LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->loginManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
	return this->roomManager;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser u)
{
	return new MenuRequestHandler(u ,this->getRoomManager(), *this);
}



