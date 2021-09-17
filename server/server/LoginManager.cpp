#include "LoginManager.h"


LoginManager::LoginManager(IDatabase* db)
	:db(db)
{
	cout << "bulid LoginManager" << endl;
}


void LoginManager::signUp(string name, string password, string email, string phone, string address, string birth)
{
	if (db->doseUserExist(name))
		std::cout << "this name alredy taken" << endl;
	else
	{
		db->addNewUser(name, password, email, phone, address, birth);
		cout << "nice " << name << " signed up" << endl;
	}
}

void LoginManager::login(string name, string password)
{
	if (db->doseUserExist(name))
		if (db->dosePasswordMatch(name, password))
		{
			if (std::find(loggedUsers.begin(), loggedUsers.end(), LoggedUser(name)) != loggedUsers.end())
				cout << name << " u are alredy in" << endl;
			else
			{
				cout << name << " nice u are in" << endl;
				loggedUsers.push_back(LoggedUser(name));
			}
		}
		else
			cout << "the password is not matching" << endl;
	else
		cout << "this name is not exist" << endl;
}

void LoginManager::logout(string name)
{
	if (NOT db->doseUserExist(name))
	{
		cout << "the user is not exist, u need to signup" << endl;
		return;
	}
	std::vector<LoggedUser>::iterator toDelete = std::find(loggedUsers.begin(), loggedUsers.end(), LoggedUser(name));
	if (toDelete == loggedUsers.end())
	{
		cout << "the user is not logged in" << endl;
		return;
	}

	loggedUsers.erase(toDelete);
	cout << "goodbye " << name << endl;

}

