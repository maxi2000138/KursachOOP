#pragma once

#include "../../Admin/AdminFactory.h"
#include "../../Client/ClientFactory.h"
#include "../../Database/Database.h"
#include "../RequestService/RequestService.h"


class AuthorizationService
{
private:
    Database** database;
    ClientFactory* clientFactory;
    AdminFactory* adminFactory;

public:
    AuthorizationService(Database** db, ClientFactory* ClientFactory, AdminFactory* AdminFactory)
    : database(db),clientFactory(ClientFactory),adminFactory(AdminFactory) { }

    bool TryAuthorizeClient(UserBase** client);
    bool TryAuthorizeAdmin(UserBase** client);

};
