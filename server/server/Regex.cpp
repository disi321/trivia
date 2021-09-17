#include "Regex.h"

bool Regex::mail(string a)
{
	return std::regex_match(a, regex(".{1,20}@gmail(\\.[\\w]{1,20}){1,2}"));
}

bool Regex::phone(string a)
{
	return std::regex_match(a, regex("(0\\d{1,2}[ -]?\\d{3}[ -]?\\d{4})"));
}

bool Regex::password(string a)
{
	return std::regex_match(a, regex("((?=.*[a-z])(?=.*[A-Z])(?=.*[1-9])[\\W\\w]{8,})"));
}

bool Regex::address(string a)
{
	return std::regex_match(a, regex("(([\\w]{1,10})[,]([ ]?[\\d]{1,3})[,]([ ]?[\\w]{1,10}))"));
}

bool Regex::birth(string a)
{
	return std::regex_match(a, regex("([1-3]?\\d[\\\\ \\/]?[1-2]?\\d[\\\\ \\/][1-2]\\d{3})"));
}

