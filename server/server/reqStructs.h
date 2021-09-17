#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <ctime>


class IRequestHandler;



typedef struct LoginRequest
{
	std::string userName;
	std::string password;

}LoginRequest;

typedef struct SignupRequest
{
	std::string userName;
	std::string password;
	std::string email;
	std::string address;
	std::string phoneNumber;
	std::string BdayDate;

}SignupRequest;

typedef struct RequestInfo
{
	char  id;
	time_t receivalTime;
	char* msgFromClient;  

}RequestInfo;

typedef struct ReqtResult
{
	IRequestHandler* newHandler;
	std::vector<char unsigned> response;

}ReqResult;

typedef struct GetPlayersRoomRequest
{
	unsigned int roomId;

}GetPlayersRoomRequest;

typedef struct JoinRoomRequest
{
	unsigned int roomId;

}JoinRoomRequest;

typedef struct CreateRoomRequest
{
	std::string roomName;
	unsigned int maxPlayers;
	unsigned int questionCount;
	unsigned int answerTimeout;

}CreateRoomRequest;
