#pragma once
#include <regex>
#include <string>
using std::regex;
using std::smatch;
using std::string;

class Regex
{
private:
	smatch smaches; /*???*/
public:
	static bool phone(string a); // (?<prefix>0\d{1,2})[ -]?(\d{3})[ -]?(\d{4})
	static bool mail(string a); // .{1,20}@gmail(\.[\w]{1,20}){1,2}
	static bool password(string a); // (?=.*[a-z])(?=.*[A-Z])(?=.*[1-9])[\W\w]{8,}
	static bool address(string a); // (?<Street>[\w]{1,10})[,](?<Apt>[ ]?[\d]{1,3})[,](?<City>[ ]?[\w]{1,10}) // till 10 chars
	static bool birth(string a); // ([1-3]?\d)[\.\/]([1-2]?\d)[\.\/]([12]\d{3})


};

