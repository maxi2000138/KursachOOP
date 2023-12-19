#pragma once

#include "../../Database/Database.h"
#include "../RequestService/RequestService.h"


class AuthorizationService
{
private:
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;
    CurrencyService* currencyService;

public:
    AuthorizationService(Database** db, SaveLoadService* SaveLoadService, RequestService* RequestService,
                CurrencyService* CurrencyService)
    {
        currencyService = CurrencyService;
        saveLoadService = SaveLoadService;
        requestService = RequestService;
        database = db;
    }
    
    bool TryAuthorizeClient(UserBase** client);

    bool TryAuthorizeAdmin(UserBase** client);

};
