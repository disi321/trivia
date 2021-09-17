#include "JsonRequestPacketDeserializer.h"
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(char* buffer)
{
	
	LoginRequest login;
	json j = Helper::StringToJson(buffer);
	login.userName = j["username"].get<std::string>();
	login.password = j["password"].get<std::string>();
	return login;
}
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(char* buffer)
{
	SignupRequest signup;
	json j = Helper::StringToJson(buffer);
	signup.userName = j["username"].get<std::string>();
	signup.password = j["password"].get<std::string>();
	signup.email = j["email"].get<std::string>();
	signup.address = j["address"].get<std::string>();
	signup.phoneNumber = j["phoneNumber"].get<std::string>();
	signup.BdayDate= j["BdayDate"].get<std::string>();
	return signup;
}

GetPlayersRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersRoomRequest(char* buffer)
{
	GetPlayersRoomRequest getPlayer;
	json j = Helper::StringToJson(buffer);
	getPlayer.roomId = stoi(j["roomId"].get<std::string>());
	return getPlayer;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(char* buffer)
{
	JoinRoomRequest join;
	json j = Helper::StringToJson(buffer);
	join.roomId = stoi(j["roomId"].get<std::string>());
	return join;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(char* buffer)
{
	CreateRoomRequest create;
	json j = Helper::StringToJson(buffer);
	create.answerTimeout = stoi(j["answerTimeout"].get<std::string>());
	create.maxPlayers = stoi(j["maxPlayers"].get<std::string>());
	create.questionCount = stoi(j["questionCount"].get<std::string>());
	create.roomName = j["roomNmae"].get<std::string>();
	return create;
}
