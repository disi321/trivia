#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "RoomStructs.h"

typedef struct ErrorResponse
{
	std::string msg;

}ErrorResponse;

typedef struct LoginResponse
{
	unsigned int status;

}LoginResponse;

typedef struct SignupResponse
{
	unsigned int status;

}SignupResponse;


typedef struct LogoutResponse
{
	unsigned int status;

}LogoutResponse;

typedef struct GetRoomsResponse
{
	unsigned int status;
	std::vector<RoomData> rooms;

}GetRoomsResponse;

typedef struct GetPlayersInRoomResponse
{
	std::vector<std::string> players;

}GetPlayersInRoomResponse;

typedef struct GetHighScoreResponse
{
	unsigned int status;
	std::vector<std::string> statistics;

}GetHighScoreResponse;

typedef struct GetPersonalStatsResponse
{
	unsigned int status;
	std::vector<std::string> statistics;

}GetPersonalStatsResponse;

typedef struct JoinRoomResponse
{
	unsigned int status;

}JoinRoomResponse;

typedef struct CreateRoomResponse
{
	unsigned int status;

}CreateRoomResponse;









