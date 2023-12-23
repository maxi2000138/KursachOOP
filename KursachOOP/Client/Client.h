#pragma once
class CurrencyService;
class RequestService;
class SaveLoadService;
class Database;
#include "../external/json/single_include/nlohmann/json.hpp"
#include "../Balance/CurrencyAccount.h"
#include "../UserBase/UserBase.h"


class Client : public UserBase
{
    Database** database;
    SaveLoadService* saveLoadService;
    RequestService* requestService;
    CurrencyService* currencyService;
public:
    std::vector<CurrencyAccount> balance;

    Client() : UserBase("", "") {  }
    Client(std::string username, std::string password) : UserBase(username, password) {  }

    void Construct(Database** Database, SaveLoadService* SaveLoadService, RequestService* RequestService, CurrencyService* CurrencyService)
    {
        saveLoadService = SaveLoadService;
        database = Database;
        requestService = RequestService;
        currencyService = CurrencyService;
        
        for (auto& balanc : balance)
        {
            balanc.Initialize(database);
        }
    }

    void AddAccount(Currency* currency);
    bool showMenu() override;

    
    friend void to_json(nlohmann::json& j, const Client& client) {
        UserBase::to_json(j, client);
        j["balance"] = client.balance;
                        
    }

    friend void from_json(const nlohmann::json& j, Client& client)
    {
        UserBase::from_json(j, client);
        if(j.contains("balance")) j.at("balance").get_to(client.balance);
    }
};
