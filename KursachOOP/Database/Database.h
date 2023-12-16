#pragma once

#include <vector>
#include "../external/json/single_include/nlohmann/json.hpp"

#include "../Admin/Admin.h"
#include "../Client/Client.h"
#include "../Client/Requests/CurrencyClientRequest.h"
#include "../Currency/Currency.h"

using namespace std;

class CurrencyAccount;

class Database {

public:
    vector<Client> clients;
    vector<Admin> admins;
    vector<Currency> currencies;
    
    vector<CurrencyClientRequest> currencyClientRequests;
    
    
    void to_json(nlohmann::json& j, const Database& db)
    {
        j = nlohmann::json
        {
            {"currencies", db.currencies },
            {"admins", db.admins },
          {"clients", db.clients },
            {"requests", db.currencyClientRequests },
        };
    }
    
    void from_json(const nlohmann::json& j, Database& db)
    {
        
        if(j.contains("currencies")) j.at("currencies").get_to(db.currencies);
        if(j.contains("admins"))     j.at("admins").get_to(db.admins);
        if(j.contains("clients"))    j.at("clients").get_to(db.clients);
        if(j.contains("requests"))   j.at("requests").get_to(db.currencyClientRequests);
    }
};