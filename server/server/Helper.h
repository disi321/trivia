#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <WinSock2.h>
#include "json.hpp"
#include "Helper.h"
#include "reqStructs.h"

#define LOGIN_ID '1'
#define SIGNUP_ID '2'
#define SERVER_ERROR '3'
#define LOGOUT_ID '4'
#define GET_ROOM_ID '5'
#define GET_PLAYERS_ID '6'
#define GET_HIGH_SCORE_ID '7'
#define GET_PERSONAL_ID '8'
#define JOIN_ROOM_ID '9'
#define CREATE_ROOM_ID '0'

using json = nlohmann::json;
// 
class Helper
{
public:
	static char* serialize(std::string buffer, const char codeMsg);
	static json StringToJson(char* buffer);
	static RequestInfo createRequestInfo(char* msg);
	static char getCodeMsg(char* s);
	static std::string VectorToString(std::vector<char unsigned> v);
	
};

