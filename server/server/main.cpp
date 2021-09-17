#include "Server.h"
#include "JsonResponsePacketSerializer.h"
#include "ResponseStructs.h"
#include <vector>
#include <iostream>

int main()
{
	LoginResponse i;
	i.status = 1;
	std::vector<unsigned char> v = JsonResponsePacketSerializer::serializeResponse(i);
	

	Server myServer;
	std::thread t1(&Server::run, &myServer);
	t1.detach();
	std::string res;
	while (true)
	{
		std::cin >> res;
		if (res == "EXIT")
			break;
		else
			std::cout << "no" << std::endl;
	}
	std::cout << "goodbye" << std::endl;
	return 0;

}