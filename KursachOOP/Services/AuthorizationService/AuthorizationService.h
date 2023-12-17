#pragma once

#include "../../Database/Database.h"
#include "../RequestService/RequestService.h"

class AuthorizationService
{
private:
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;

public:
    AuthorizationService(Database** db, SaveLoadService* SaveLoadService, RequestService* RequestService)
    {
        saveLoadService = SaveLoadService;
        requestService = RequestService;
        database = db;
    }
    
    bool TryAuthorizeClient(UserBase** client);

    bool TryAuthorizeAdmin(UserBase** client);

};
