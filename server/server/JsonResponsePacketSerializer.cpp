#include "JsonResponsePacketSerializer.h"
using json = nlohmann::json;

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse error)
{

	json j;
	std::vector<unsigned char> v;
	j["message"] = error.msg;    //convert format struct to json
	char* ret = Helper::serialize(j.dump(), SERVER_ERROR);// return in msg in format [code,lenMsg,msg]
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse login)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = login.status;  //convert format struct to json
	char* ret = Helper::serialize(j.dump(), LOGIN_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;

}
std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse signUp)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = signUp.status;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), SIGNUP_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;

}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LogoutResponse logout)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = logout.status;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), LOGOUT_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse getRoom)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = getRoom.status;//convert format struct to json
	//j["rooms"] = getRoom.rooms;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), GET_ROOM_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse getPlayers)
{
	json j;
	std::vector<unsigned char> v;
	j["plyers"] = getPlayers.players;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), GET_PLAYERS_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(GetHighScoreResponse getHigh)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = getHigh.status;//convert format struct to json
	j["statistics"] = getHigh.statistics;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), GET_HIGH_SCORE_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(GetPersonalStatsResponse getPersonal)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = getPersonal.status;//convert format struct to json
	j["statistics"] = getPersonal.statistics;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), GET_PERSONAL_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse join)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = join.status;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), JOIN_ROOM_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse create)
{
	json j;
	std::vector<unsigned char> v;
	j["status"] = create.status;//convert format struct to json
	char* ret = Helper::serialize(j.dump(), CREATE_ROOM_ID);
	for (int i = 0; i < (j.dump().size() + 5); i++)
	{
		v.push_back(ret[i]);
	}
	return v;
}

std::string JsonResponsePacketSerializer::serializeRoomData(RoomData data)
{
	json j;
	std::vector<unsigned char> v;
	j["id"] = data.id;//convert format struct to json
	j["isActive"] = data.isActive;//convert format struct to json
	j["maxPlyers"] = data.maxPlyers;//convert format struct to json
	j["name"] = data.name;//convert format struct to json
	j["numOfQuestionsInGame"] = data.numOfQuestionsInGame;//convert format struct to json
	j["timePerQuestion"] = data.timePerQuestion;//convert format struct to json

	std::cout << j.dump();
	return j.dump();
}
