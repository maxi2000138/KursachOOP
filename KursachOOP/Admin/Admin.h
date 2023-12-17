﻿class RequestService;
class SaveLoadService;
class Database;

#pragma once
#include "../UserBase/UserBase.h"
#include "../external/json/single_include/nlohmann/json.hpp"


class Admin : public UserBase
{
private:
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;
public:
    Admin(std::string username, std::string password) : UserBase(username, password) { }
    Admin() : UserBase("", "") { }

    void Construct(Database** Database, SaveLoadService* SaveLoadService, RequestService* RequestService)
    {
        requestService = RequestService;
        saveLoadService = SaveLoadService;
        database = Database;
    }

    bool showMenu() override;

    friend void to_json(nlohmann::json& j, const Admin& admin) {
        UserBase::to_json(j, admin);
    }

    friend void from_json(const nlohmann::json& j, Admin& admin) {
        UserBase::from_json(j, admin);
    }
};
