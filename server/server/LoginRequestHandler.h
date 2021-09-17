#pragma once
#include "IRequestHandler.h"
#include "reqStructs.h"
#include "Helper.h"
#include "ResponseStructs.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"
#include "RequestHandlerFactory.h"
#include "LoginManager.h"
#include "Regex.h"


#define IS ==
#define GOOD 1
#define BAD 0

class RequestHandlerFactory;

class LoginRequestHandler :
    public IRequestHandler
{
private:
    LoginManager& loingManeger;
    RequestHandlerFactory& handelerFactory;

    ReqResult login(RequestInfo info);
    ReqResult signup(RequestInfo info);
public:
    LoginRequestHandler(RequestHandlerFactory& fac);

    bool isRequestRelevant(RequestInfo info);
    virtual ReqResult handleRequest(RequestInfo info);

};