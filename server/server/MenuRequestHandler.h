#pragma once
#include "IRequestHandler.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class MenuRequestHandler :
    public IRequestHandler
{
private:
    LoggedUser user;
    RoomManager& roomManager;
    //StatisticsManager& roomManager;
    RequestHandlerFactory& handleFactory;

    ReqtResult signout(RequestInfo);
    ReqtResult getRooms(RequestInfo);
    ReqtResult getPlayersInRoom(RequestInfo);
    //ReqtResult getPersonalStats(RequestInfo);
    //ReqtResult getHighScore(RequestInfo);
    ReqtResult joinRoom(RequestInfo);
    ReqtResult createRoom(RequestInfo);

public:

    //MenuRequestHandler(LoggedUser user, RoomManager& roomManager, StatisticsManager& roomManager, RequestHandlerFactory& handleFactory);
    MenuRequestHandler(LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& handleFactory);
    bool isRequestRelevant(RequestInfo info);
    ReqtResult handleRequest(RequestInfo);
};

