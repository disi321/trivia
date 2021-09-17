#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string name)
{
    this->username = name;
}

std::string LoggedUser::getUsername()
{
    return this->username;
}


bool operator==(LoggedUser const& a, LoggedUser const& b)
{
    return b.username == a.username;
}
