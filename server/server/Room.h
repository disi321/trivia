#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "LoggedUser.h"
#include "RoomStructs.h"

class Room
{
private:
	RoomData metaData;
	std::vector<LoggedUser> users;

public:
	Room(RoomData data);

	void addUser(LoggedUser u);
	void removeUser(LoggedUser u);
	std::vector<std::string> getAllUsers();

	int getStatus();
	RoomData getData();

};

