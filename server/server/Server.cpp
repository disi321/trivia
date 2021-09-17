#include "Server.h"



Server::Server()
	:db(new SqliteDataBase()), communicator(this->factory), factory(db)
{
	cout << "bulid Server" << endl;
}

Server::~Server()
{
}

void Server::run()
{
	try
	{
		communicator.startHandleRequests();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
}
