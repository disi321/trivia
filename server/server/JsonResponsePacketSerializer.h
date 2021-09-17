#pragma once

#include <vector>
#include<string>
#include"ResponseStructs.h"
#include "json.hpp"
#include "Helper.h"





class JsonResponsePacketSerializer
{
public:

	static std::vector<unsigned char> serializeResponse(ErrorResponse);
	static std::vector<unsigned char> serializeResponse(LoginResponse);
	static std::vector<unsigned char> serializeResponse(SignupResponse);

	static std::vector<unsigned char> serializeResponse(LogoutResponse);
	static std::vector<unsigned char> serializeResponse(GetRoomsResponse);
	static std::vector<unsigned char> serializeResponse(GetPlayersInRoomResponse);
	static std::vector<unsigned char> serializeResponse(GetHighScoreResponse);
	static std::vector<unsigned char> serializeResponse(GetPersonalStatsResponse);
	static std::vector<unsigned char> serializeResponse(JoinRoomResponse);
	static std::vector<unsigned char> serializeResponse(CreateRoomResponse);

	static std::string serializeRoomData(RoomData);

};

