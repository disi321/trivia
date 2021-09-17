#include "Communicator.h"
#pragma comment(lib, "Ws2_32.lib")

Communicator::Communicator(RequestHandlerFactory& factory)
	:factory(factory)
{
	cout << "bulid Communicator" << endl;

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}


Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Communicator::handleNewCliant(SOCKET clientSocket)
{
	char request[1024] = { NULL };
	std::string str = "hello";
	std::string exit = "EXIT";

	try
	{
		 
		
		while (strcmp(request, "EXIT"))
		{
			memset(request, 0, sizeof(request));
			recv(clientSocket, request, 1024, 0);
			// do deserialize 
			RequestInfo info = Helper::createRequestInfo(request); // init struct RequestInfo
			std::cout << "code:" << info.id << std::endl;
			std::cout << "time:" << info.receivalTime << std::endl;


			if (this->_users[clientSocket]->isRequestRelevant(info)) // if the request is login or logout  (relvant)
			{
				std::vector <unsigned char> v = this->_users[clientSocket]->handleRequest(info).response;
				char* res = new char[v.size()];
				for (int i = 0; i < v.size(); i++)
				{
					res[i] = v[i];
				}
				
				send(clientSocket,res, str.size(), 0);
			}
			// 
			else
			{
				ErrorResponse error = { "Error, not relevant" };
				std::cout << error.msg << std::endl;
				send(clientSocket, str.c_str(), str.size(), 0);
				memset(request, 0, sizeof(request));
				for (int j = 0; j < exit.size(); j++)
				{
					request[j] = exit[j];
				}
				
			}

		}
		closesocket(clientSocket);// Closing the socket (in the level of the TCP protocol)
	}

	catch (const std::exception& e)
	{
		std::cout << "one left" << std::endl;
		// later for map
		//for (auto it = this->_userList.begin(); it != this->_userList.end(); ++it)
		//{
		//	if (*it == name)
		//	{
		//		this->_userList.erase(it);
		//		cout << "user: " << name << " removed" << endl;
		//		break;
		//	}
		//}
		closesocket(clientSocket);
	}
}

void Communicator::bindAndListen()
{
	while (true)
	{
		// notice that we step out to the global namespace
		// for the resolution of the function accept

		// this accepts the client and create a specific socket from server to this client
		SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);

		if (client_socket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		std::cout << "Client accepted. Server and client can speak" << std::endl;

		// the function that handle the conversation with the client
		this->_users.insert({ client_socket, factory.createLoginRequestHandler() });
		std::thread t1(&Communicator::handleNewCliant, this, client_socket);
		t1.detach();
		//this->_threadList.push_back(move(t1));
	}

}

void Communicator::startHandleRequests()
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(PORT); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// again stepping out to the global namespace
	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << PORT << std::endl;

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		bindAndListen();
	}
}
