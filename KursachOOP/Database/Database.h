#pragma once

#include <vector>
#include "../external/json/single_include/nlohmann/json.hpp"

#include "../Admin/Admin.h"
#include "../Client/Client.h"
#include "../Client/Requests/CurrencyClientRequest.h"
#include "../Client/Requests/SendMoneyClientRequest.h"
#include "../Currency/Currency.h"

using namespace std;

class CurrencyAccount;

class Database {

public:
    vector<Client> clients;
    vector<Admin> admins;
    vector<Currency> currencies;
    
    vector<CurrencyClientRequest> currencyClientRequests;
    vector<SendMoneyClientRequest> sendMoneyClientRequests;
    
    
    void to_json(nlohmann::json& j, const Database& db)
    {
        j = nlohmann::json
        {
            {"currencies", db.currencies },
            {"admins", db.admins },
          {"clients", db.clients },
            {"addCurrencyRequests", db.currencyClientRequests },
            {"sendMoneyRequests", db.sendMoneyClientRequests },
        };
    }
    
    void from_json(const nlohmann::json& j, Database& db)
    {
        if(j.contains("currencies")) j.at("currencies").get_to(db.currencies);
        if(j.contains("admins")) j.at("admins").get_to(db.admins);
        if(j.contains("clients")) j.at("clients").get_to(db.clients);
        if(j.contains("addCurrencyRequests")) j.at("addCurrencyRequests").get_to(db.currencyClientRequests);
        if(j.contains("sendMoneyRequests")) j.at("sendMoneyRequests").get_to(db.sendMoneyClientRequests);
    }
};