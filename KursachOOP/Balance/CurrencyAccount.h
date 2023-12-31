#pragma once

#include "../Currency/Currency.h"
class Database;

class CurrencyAccount
{
    Currency* currency;
    int currencyId;
    float value;
public:
    void ShowAccountInfo();
    void AddMoney(int value);
    void RemoveMoney(int value);
    CurrencyAccount(Currency* currency): currency(currency), currencyId(currency->id),value(0){ }
    CurrencyAccount() { }
    float Value() { return value; }
    std::string CurrencyName() { return currency->currencyName; }
    

    void Initialize(Database** database);
    
    friend void to_json(nlohmann::json& j, const CurrencyAccount& currencyAccount)
    {
        j = nlohmann::json
        {
            {"currencyId", currencyAccount.currencyId},
            {"value", currencyAccount.value}
        };
    }

    friend void from_json(const nlohmann::json& j, CurrencyAccount& currencyAccount)
    {
        j.at("currencyId").get_to(currencyAccount.currencyId);
        j.at("value").get_to(currencyAccount.value);
    }
};
