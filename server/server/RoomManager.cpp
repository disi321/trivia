#include "RoomManager.h"
void RoomManager::createRoom(LoggedUser u, RoomData data)
{
	Room* room = new Room(data);
	room->addUser(u);
	rooms.insert({data.id, room});
	std::cout << "room " << data.name << " is cretaed, id = " << data.id << std::endl;
}

void RoomManager::deleteRoom(int id)
{
	for (auto itr = rooms.begin(); itr != rooms.end(); ++itr) {
		if (itr->first == id) {
			std::cout << "room id: " << id << " is deleted" << std::endl;
			rooms.erase(itr);
		}
	}
}


unsigned int RoomManager::getRoomState(int id)
{
	for (auto itr = rooms.begin(); itr != rooms.end(); ++itr) {
		if (itr->first == id) {
			return itr->second->getStatus();
		}
	}
}

std::map<int, Room*> RoomManager::getRooms()
{
	return this->rooms;
}

int RoomManager::getNumOfRooms()
{
	return this->rooms.size();
}

bool RoomManager::joinRoom(LoggedUser u, int roomId)
{
	for (auto itr = rooms.begin(); itr != rooms.end(); ++itr) {
		if (itr->first == roomId) {
			itr->second->addUser(u);
			return true;
		}
	}
	return false;
}
