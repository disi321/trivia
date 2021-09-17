#pragma once
#include <string>
#include <list>
#include "questionStruct.h"
using std::string;

class IDatabase
{
public:
	virtual bool doseUserExist(string name) = 0;
	virtual bool dosePasswordMatch(string a, string b) = 0;
	virtual void addNewUser(string name, string password, string email, string phone, string address, string birth) = 0;

	virtual std::list<Question> getQuestions(int idk) = 0;
	//virtual float getPlayerAverageAnswerTime(std::string nameProbably) = 0;
	//virtual int getNumOfCorrectAnswers(std::string) = 0;
	//virtual int getNumOfTotalAnswers(std::string) = 0;
	//virtual int getNumOfPlayerGames(std::string) = 0;
};
