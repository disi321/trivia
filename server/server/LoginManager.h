#pragma once
#include <vector>
#include "LoggedUser.h"
#include "SqliteDataBase.h"
#include "sqlite_modern_cpp.h"

class LoginManager
{
private:
	std::vector<LoggedUser> loggedUsers;
	IDatabase* db;
public:
	LoginManager(IDatabase* db);
	void signUp(string name, string password, string email, string phone, string address, string birth);
	void login(string name, string password);
	void logout(string name);

};


