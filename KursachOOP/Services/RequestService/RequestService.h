#pragma once
#include "../../Database/Database.h"

class SaveLoadService;

class RequestService
{
    Database** database;
    SaveLoadService* saveLoadService;
public:
    RequestService(Database** Database, SaveLoadService* SaveLoadService) : database(Database), saveLoadService(SaveLoadService)   {  }

    void InitalizeRequests();
    void AddAccountRequest(Database** database, SaveLoadService* saveLoadService, string userName);
    void TryApply(ClientRequest& request);
    void ApproveRequest(ClientRequest& request);
    void DeclineRequest(ClientRequest& request);
};

