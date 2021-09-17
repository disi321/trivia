#pragma once
#include "reqStructs.h"
class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual ReqResult handleRequest(RequestInfo info) = 0;


};