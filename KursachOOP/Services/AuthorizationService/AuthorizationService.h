#pragma once

#include "../../Database/Database.h"

class AuthorizationService
{
private:
    SaveLoadService* saveLoadService;
    Database* database;
public:
    AuthorizationService(Database* db, SaveLoadService* SaveLoadService)
    {
        saveLoadService = SaveLoadService;
        database = db;
    }
    
    bool TryAuthorizeClient(UserBase** client);

    bool TryAuthorizeAdmin(UserBase** client);

};
