#pragma once
#include<iostream>
#include <io.h>

#include "IDatabase.h"
#include "sqlite3.h"
#include "sqlite_modern_cpp.h"

using namespace sqlite;
using std::cout;
using std::endl;

#define AND &&
#define OR ||
#define NOT !

class SqliteDataBase :
    public IDatabase
{
private:
    string const dbFileName = "MyDB.sqlite";
    database db;

    void open();

public:
    SqliteDataBase();
    virtual bool doseUserExist(string name);
    virtual bool dosePasswordMatch(string name, string password);

    void addNewUser(string name, string password, string email, string phone, string address, string birth);

    virtual std::list<Question> getQuestions(int idk);
    //virtual float getPlayerAverageAnswerTime(std::string nameProbably);
    //virtual int getNumOfCorrectAnswers(std::string);
    //virtual int getNumOfTotalAnswers(std::string);
    //virtual int getNumOfPlayerGames(std::string);
};

