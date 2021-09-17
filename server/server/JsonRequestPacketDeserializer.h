#pragma once
#include"reqStructs.h"
#include "json.hpp"
#include "Helper.h"


using json = nlohmann::json;


class JsonRequestPacketDeserializer
{
public:
	static  LoginRequest deserializeLoginRequest(char* buffer);
	static	SignupRequest deserializeSignupRequest(char* buffer);

	static	GetPlayersRoomRequest deserializeGetPlayersRoomRequest(char* buffer);
	static	JoinRoomRequest deserializeJoinRoomRequest(char* buffer);
	static	CreateRoomRequest deserializeCreateRoomRequest(char* buffer);
};

