#pragma once
#include "../../Database/Database.h"

class SaveLoadService;

class RequestService
{
    Database** database;
    SaveLoadService* saveLoadService;
    ClientFactory** clientFactory;

public:
    RequestService(Database** Database, SaveLoadService* SaveLoadService, ClientFactory** ClientFactory) : database(Database)
    , saveLoadService(SaveLoadService), clientFactory(ClientFactory)   {  }

    void InitalizeRequests();
    void AddAccountRequest(Database** database, SaveLoadService* saveLoadService, string userName);
    void AddSendMoneyRequest(Database** database, SaveLoadService* saveLoadService, Client* sender);
    void TryApply(ClientRequest& request);
    void ApproveRequest(ClientRequest& request);
    void DeclineRequest(ClientRequest& request);
};

