#pragma once
#include <string>

#include "../Client/ClientFactory.h"

class ClientFactory;
class Admin;
class CurrencyService;
class RequestService;
class Database;
class SaveLoadService;

class AdminFactory
{
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;
    CurrencyService* currencyService;
    ClientFactory* clientFactory;
public:
    AdminFactory(Database** Database, SaveLoadService* SaveLoadService, RequestService* RequestService
        , CurrencyService* CurrencyService, ClientFactory* ClientFactory)
    : database(Database), saveLoadService(SaveLoadService), requestService(RequestService)
    , currencyService(CurrencyService), clientFactory(ClientFactory)  {  }
    Admin* CreateAdmin();
    Admin* CreateAdmin(std::string username, std::string password);
    void InitAdmin(Admin* admin);
};
