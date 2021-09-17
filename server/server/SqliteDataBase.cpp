#include "SqliteDataBase.h"
#include "questionStruct.h"

void SqliteDataBase::open()
{
	db << "create table if not exists users ("
		"   name text primary key not null,"
		"   password text,"
		"   email text,"
		"   phone text,"
		"   address text,"
		"   birthDay text"
		");";

	db << "create table if not exists questions ("
		"   name text primary key not null,"
		"   ans1 text,"
		"   ans2 text,"
		"   ans3 text,"
		"   ans4 text,"
		"   rightAns int"
		");";
}


SqliteDataBase::SqliteDataBase()
	:db(this->dbFileName)
{
	open(); //?
}

bool SqliteDataBase::doseUserExist(string name) // callback? need todo
{
	bool flag = false;

	try
	{
		db << "select name from users where name = ?;"
			<< name
			>> [&](string nam) {
			flag = name == nam;
		};

	}
	catch (std::exception& e) {
		cout << e.what() << " exist" << endl;
		flag = false;
	}
	return flag;
}

bool SqliteDataBase::dosePasswordMatch(string name, string password)
{
	bool flag;
	try
	{
		db << "select password from users where name = ? ;"
			<< name
			>> [&](string pass) {
			flag = pass == password;
		};

	}
	catch (std::exception& e) {
		cout << e.what() << "mach" << endl;
		flag = false;
	}

	return flag;

}

void SqliteDataBase::addNewUser(string name, string password, string email, string phone, string address, string birth) 
{
	try
	{
		db << "insert into users (name,password,email,phone,address,birthDay) values (?,?,?,?,?,?);"
			<< name
			<< password
			<< email
			<< phone
			<< address
			<< birth;
	}
	catch (std::exception& e) {
		cout << e.what() << " add"<< endl; 
		cout << "name alredy exist" << endl;
	}
}


std::list<Question> SqliteDataBase::getQuestions(int idk)
{
	std::list<Question> qlist;

	db << "select * from questions;"
		>> [&](string q, string a1, string a2, string a3, string a4, int right) {
		Question qu;
		qu.q = q;
		qu.ans1 = a1;
		qu.ans2 = a2;
		qu.ans3 = a3;
		qu.ans4 = a4;
		qu.rightAns = right;
		qlist.push_back(qu);
	};


	return qlist;
}

