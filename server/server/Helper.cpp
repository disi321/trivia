#include "Helper.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <time.h>



char* Helper::serialize(std::string buffer, char const codeMsg)//get string in formt json 
{
	int size = buffer.size();
	char* response = new char[size+5];
	
	response[0] = codeMsg;
	memcpy(response + 1, &size, sizeof(int));

	for (int i = 0; i < buffer.size(); i++) {
		response[i + 4] = buffer[i];
	}

	return response;
}

std::string Helper::VectorToString(std::vector<char unsigned> v)
{
	std::string s(v.begin(), v.end());
	return s;
}
json Helper::StringToJson(char* buffer)
{
    json j;
	std::stringstream(buffer) >> j;
	return j;

}
RequestInfo Helper::createRequestInfo(char* msg)
{
	
	RequestInfo req; 
	req.id = msg[0];
	std::cout << req.id << std::endl;
	time(&req.receivalTime);
	int size;
	memcpy(&size, msg + 1, sizeof(int));
	req.msgFromClient = new char[size];
	memcpy(req.msgFromClient, msg+5, size * sizeof(char));


	return req;
}

char Helper::getCodeMsg(char* s)
{
	return s[0];
}