#include "Helper.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <time.h>



char* Helper::serialize(std::string buffer, char const codeMsg)//get string in formt json 
{
	int size = buffer.size();
	char* response = new char[size+6];
	memcpy(response, &codeMsg, sizeof(char));
	
	memcpy(response + 1, &size, sizeof(int));
	memcpy(response + 5, &buffer, size*sizeof(char));
	response[size + 5] = NULL;

	std::cout << std::string(response) << std::endl;

	return response;
}
std::string VectorToString(std::vector<char unsigned> v)
{
	std::string s(v.begin(), v.end());
	return s;
}
json Helper::StringToJson(std::string buffer)
{
	json j;
	j.parse(buffer);
	return j;

}
RequestInfo Helper::createRequestInfo(std::string msg)
{
	RequestInfo req; 
	std::string onlyMsg = "";
	for (int i = 5; i < msg.size(); i++)
	{
		onlyMsg += msg[i];
	}
	req.id = msg[0];
	time(&req.receivalTime);
	memcpy(req.msgFromClient, &onlyMsg, (onlyMsg.size()) * sizeof(char));

	return req;
}

char Helper::getCodeMsg(std::string s)
{
	return s[0];
}