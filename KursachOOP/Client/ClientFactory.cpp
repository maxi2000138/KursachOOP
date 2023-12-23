#include "ClientFactory.h"

void ClientFactory::InitUser(Client* client)
{
    client->Construct(database, saveLoadService, requestService, currencyService);
}


Client* ClientFactory::CreateUser()
{
    return  CreateUser("", "");
}

Client* ClientFactory::CreateUser(std::string username, std::string password)
{
    Client* client = new Client(username, password);
    InitUser(client);
    return client;
}



