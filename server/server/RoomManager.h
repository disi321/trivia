#pragma once
#include "Room.h"
#include <map>
class RoomManager
{
private:
	std::map<int, Room*> rooms;
public:
	void createRoom(LoggedUser, RoomData);
	void deleteRoom(int id);
	unsigned int getRoomState(int id);
	std::map<int, Room*> getRooms();
	int getNumOfRooms();

	bool joinRoom(LoggedUser u, int roomId);
};

