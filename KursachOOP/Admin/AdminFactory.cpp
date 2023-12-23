#include "AdminFactory.h"

#include "Admin.h"

void AdminFactory::InitAdmin(Admin* admin)
{
    admin->Construct(database, saveLoadService, requestService, clientFactory);
}

Admin* AdminFactory::CreateAdmin()
{
    return CreateAdmin("", "");
}

Admin* AdminFactory::CreateAdmin(std::string username, std::string password)
{
    Admin* client = new Admin(username, password);
    InitAdmin(client);
    return client;
}