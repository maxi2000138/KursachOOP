#pragma once
#include "../../Database/Database.h"

class SaveLoadService;

class RequestService
{
    Database* database;
    SaveLoadService* saveLoadService;
public:
    RequestService(Database* Database, SaveLoadService* SaveLoadService) : database(Database), saveLoadService(SaveLoadService)   {  }

    void InitalizeRequests();
};

