#pragma once
#include <string>
typedef struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlyers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	int isActive;

}RoomData;