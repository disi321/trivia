#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
	bool ret = false;
	if (info.id == LOGIN_ID || info.id == SIGNUP_ID)
	{
		ret = true;
	}
	return ret;
}
ReqResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	ReqtResult result;// response that will be after serializer data
	//LoginRequestHandler* loginHandler = new LoginRequestHandler(this->handelerFactory);

	if (info.id == LOGIN_ID)
	{
		LoginResponse login;
		login.status = 1;
		result = this->login(info);
		result.response = JsonResponsePacketSerializer::serializeResponse(login);
	}
	else if (info.id == SIGNUP_ID)
	{
		result = this->signup(info);
		SignupResponse signup;
		signup.status = 1;
		result.response = JsonResponsePacketSerializer::serializeResponse(signup);
	}

	json j = Helper::StringToJson(info.msgFromClient);
	std::string name = j["username"].get<std::string>();

	result.newHandler = this->handelerFactory.createMenuRequestHandler(LoggedUser(name));
	return result;
}

ReqResult LoginRequestHandler::login(RequestInfo info)
{
	LoginRequest l;
	ReqResult r;
	r.newHandler = this;
	std::string login_failed = "Login failed";
	std::string login_seccses = "Login seccses";
	try
	{
		l = JsonRequestPacketDeserializer::deserializeLoginRequest(info.msgFromClient);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
		
	this->loingManeger.login(l.userName, l.password);

	for (int i = 0; i < login_seccses.size(); i++)
	{
		r.response.push_back(login_seccses[i]);
	}
	//r.response = 
	return r;
}

ReqResult LoginRequestHandler::signup(RequestInfo info)
{
	SignupRequest s;
	ReqResult r;
	std::string email_error = "The email is not in the right format";
	std::string password_error = "The password is not in the right format";
	std::string phoneNumber_error = "The phone number is not in the right format";
	std::string address_error = "The address is not in the right format";
	std::string bDay_error = "The birthday is not in the right format";
	std::string signup_seccses = "Signup seccses";
	r.newHandler = this;
	int i = 0;
	
	s = JsonRequestPacketDeserializer::deserializeSignupRequest(info.msgFromClient);
	if (Regex::password(s.password) IS BAD)
	{
		cout << password_error << endl;
		for (i = 0; i < password_error.size(); i++)
		{
			r.response.push_back(password_error[i]);
		}
		return r;
	}
	if (Regex::phone(s.phoneNumber) IS BAD)
	{
		cout << phoneNumber_error << endl;
		for (i = 0; i < phoneNumber_error.size(); i++)
		{
			r.response.push_back(phoneNumber_error[i]);
		}
		return r;

	}
	if (Regex::address(s.address) IS BAD)
	{
		cout << address_error << endl;
		for (i = 0; i < address_error.size(); i++)
		{
			r.response.push_back(address_error[i]);
		}
		return r;

	}
	if (Regex::birth(s.BdayDate) IS BAD)
	{
		cout << bDay_error << endl;
		for (i = 0; i < bDay_error.size(); i++)
		{
			r.response.push_back(bDay_error[i]);
		}
		return r;

	}
	if (Regex::mail(s.email) IS BAD)
	{
		cout << email_error << endl;
		for (i = 0; i < email_error.size(); i++)
		{
			r.response.push_back(email_error[i]);
		}
		return r;

	}

	this->loingManeger.signUp(s.userName, s.password, s.email, s.phoneNumber, s.address, s.BdayDate);
	
	for (i = 0; i < signup_seccses.size(); i++)
	{
		r.response.push_back(signup_seccses[i]);
	}
	
	this->loingManeger.login(s.userName, s.password); // login after sign up
	return r;
}

LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory& fac)
	: handelerFactory(fac), loingManeger(fac.getLoginManager())
{
	cout << "bulid LoginRequestHandler" << endl;

}


