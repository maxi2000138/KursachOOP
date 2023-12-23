#pragma once
#include <string>

#include "../Database/Database.h"

class ClientFactory
{
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;
    CurrencyService* currencyService;
public:
    ClientFactory(Database** Database, SaveLoadService* SaveLoadService, RequestService* RequestService, CurrencyService* CurrencyService)
    : database(Database), saveLoadService(SaveLoadService), requestService(RequestService), currencyService(CurrencyService)  {  }
    Client* CreateUser();
    Client* CreateUser(std::string username, std::string password);
    void InitUser(Client* client);
};
