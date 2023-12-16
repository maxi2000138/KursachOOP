#pragma once

#include "../Currency/Currency.h"
class Database;

class CurrencyAccount
{
    Currency* currency;
    float currencyId;
    float value;
public:
    void ShowAccountInfo();
    CurrencyAccount(Currency* currency): currency(currency),value(0){ }
    CurrencyAccount() { }

    void Initialize(Database* database);
    
    friend void to_json(nlohmann::json& j, const CurrencyAccount& currencyAccount)
    {
        j = nlohmann::json
        {
            {"currencyId", currencyAccount.currency->id},
            {"value", currencyAccount.value}
        };
    }

    friend void from_json(const nlohmann::json& j, CurrencyAccount& currencyAccount)
    {
        j.at("currencyId").get_to(currencyAccount.currency->id);
        j.at("value").get_to(currencyAccount.value);
    }
};
