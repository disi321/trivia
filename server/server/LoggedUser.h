#pragma once
#include <string>
class LoggedUser
{
private:
	std::string username;
public:
	LoggedUser(std::string name);
	std::string getUsername();
	friend bool operator == (LoggedUser const&, LoggedUser const&);
};

