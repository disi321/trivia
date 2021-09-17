#include "Room.h"

Room::Room(RoomData data)
{
	metaData = data;
}

void Room::addUser(LoggedUser u)
{
	users.push_back(u);
}

void Room::removeUser(LoggedUser u)
{
	//std::find(users.begin(), users.end(), u); // ?
	std::remove(users.begin(), users.end(), u);
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> b;
	for (auto val : users)
		b.push_back(val.getUsername());
	return b;
}

int Room::getStatus()
{
	return this->metaData.isActive;
}

RoomData Room::getData()
{
	return this->metaData;
}
