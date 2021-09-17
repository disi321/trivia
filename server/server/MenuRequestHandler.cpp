#include "MenuRequestHandler.h"


ReqtResult MenuRequestHandler::signout(RequestInfo info)
{
	ReqResult r;
	std::string signout_seccses = "join room seccses";
	std::string signout_failed = "join room failed";
	
	r.newHandler = this; // ?
	try
	{
		this->handleFactory.getLoginManager().logout(this->user.getUsername());
		for (int i = 0; i < signout_seccses.size(); i++)
		{
			r.response.push_back(signout_seccses[i]);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		for (int i = 0; i < signout_failed.size(); i++)
		{
			r.response.push_back(signout_failed[i]);
		}
	}


	return r;
}

ReqtResult MenuRequestHandler::getRooms(RequestInfo info)
{
	ReqResult r;
	string allData;
	std::vector<RoomData> rooms;
	GetRoomsResponse getR;
	for (auto x : this->roomManager.getRooms())
	{
		rooms.push_back(x.second->getData());
	}
	for (auto x : rooms)
	{
		//make string and then take 
		allData += JsonResponsePacketSerializer::serializeRoomData(x);
	}

	for (int i = 0; i < allData.size(); i++)
	{
		r.response.push_back(allData[i]); 
	}
	return r;
}

ReqtResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	ReqResult r;
	GetPlayersRoomRequest getP;
	try
	{
		getP = JsonRequestPacketDeserializer::deserializeGetPlayersRoomRequest(info.msgFromClient);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	for(auto x: this->roomManager.getRooms())
	{
		if (x.first == getP.roomId)
		{
			for (auto y : x.second->getAllUsers())
			{
				for (int i = 0; i < y.size(); i++)
				{
					r.response.push_back(y[i]); // sending the players in the room
				}
				r.response.push_back(',');
			}
		}
	}
	r.response.pop_back(); // the last one?;
	return r;
}

ReqtResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	ReqResult r;
	JoinRoomRequest join;
	std::string join_room_seccses = "join room seccses";
	std::string join_room_failed = "join room failed";

	r.newHandler = this; // ?
	try
	{
		join = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(info.msgFromClient);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	if (this->roomManager.joinRoom(user, join.roomId))
	{
		for (int i = 0; i < join_room_seccses.size(); i++)
		{
			r.response.push_back(join_room_seccses[i]);
		}
	}
	else
	{
		for (int i = 0; i < join_room_failed.size(); i++)
		{
			r.response.push_back(join_room_failed[i]);
		}
	}

	return r;
}

ReqtResult MenuRequestHandler::createRoom(RequestInfo info)
{
	ReqResult r;
	CreateRoomRequest create;
	std::string create_room_seccses = "create room seccses";
	std::string create_room_failed = "create room failed";

	r.newHandler = this; // ?
	try
	{
		create = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(info.msgFromClient);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	RoomData data;
	data.name = create.roomName;
	data.timePerQuestion = create.answerTimeout;
	data.maxPlyers = create.maxPlayers;
	data.numOfQuestionsInGame = create.questionCount;
	data.id = this->roomManager.getNumOfRooms();
	data.isActive = 1;

	this->roomManager.createRoom(user ,data);

	for (int i = 0; i < create_room_seccses.size(); i++)
	{
		r.response.push_back(create_room_seccses[i]);
	}

	return r;
}

MenuRequestHandler::MenuRequestHandler(LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& handleFactory)
	:user(user), roomManager(roomManager),  handleFactory(handleFactory)
{
	std::cout << "building MenuRequestHandler" << std::endl;
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	bool ret = false;
	if (info.id == LOGOUT_ID OR info.id == GET_ROOM_ID OR info.id == GET_PLAYERS_ID OR info.id == GET_HIGH_SCORE_ID OR info.id == GET_PERSONAL_ID OR info.id == JOIN_ROOM_ID OR info.id == CREATE_ROOM_ID)
	{
		ret = true;
	}
	return ret;
}

ReqtResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	ReqtResult result;// response that will be after serializer data

	switch (info.id)
	{
	case LOGOUT_ID:
		LogoutResponse logout;
		logout.status = 1;
		result = this->signout(info);
		result.response = JsonResponsePacketSerializer::serializeResponse(logout);
		break;

	case GET_ROOM_ID:
	{
		GetRoomsResponse getR;
		getR.status = 1;
		for (auto x : this->roomManager.getRooms())
			getR.rooms.push_back(x.second->getData());
		result.response = JsonResponsePacketSerializer::serializeResponse(getR);
		break;
	}
	case GET_PLAYERS_ID:
	{
		GetPlayersRoomRequest g;
		g = JsonRequestPacketDeserializer::deserializeGetPlayersRoomRequest(info.msgFromClient);
		GetPlayersInRoomResponse getP;
		for (auto x : this->roomManager.getRooms())
		{
			if (x.first == g.roomId)
			{
				getP.players = x.second->getAllUsers();
			}
		}
		result = this->getPlayersInRoom(info);
		result.response = JsonResponsePacketSerializer::serializeResponse(getP);
		break;
	}
	//case GET_HIGH_SCORE_ID:
	//	break;
	//case GET_PERSONAL_ID:
	//	break;
	case JOIN_ROOM_ID:
		JoinRoomResponse join;
		join.status = 1;
		result = this->joinRoom(info);
		result.response = JsonResponsePacketSerializer::serializeResponse(join);
		break;

	case CREATE_ROOM_ID:
		CreateRoomResponse create;
		create.status = 1;
		result = this->createRoom(info);
		result.response = JsonResponsePacketSerializer::serializeResponse(create);
		break;

	default:
		break;
	}

	result.newHandler = this->handleFactory.createMenuRequestHandler(this->user); //// 

	return result;
}


