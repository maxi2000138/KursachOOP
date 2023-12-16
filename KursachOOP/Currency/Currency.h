#pragma once
#include <string>
#include "../external/json/single_include/nlohmann/json.hpp"


class Currency
{
public:
    int id;
    std::string currencyName;
    std::string currencySymbol;

    Currency(std::string name, std::string symbol, int Id) : currencyName(name), currencySymbol(symbol), id(Id) {  }
    Currency() {  }

    
    friend void to_json(nlohmann::json& j, const Currency& currency)
    {
        j = nlohmann::json{
                {"id", currency.id},
                {"currencyName", currency.currencyName},
                {"currencySymbol", currency.currencySymbol}
        };
    }

    friend void from_json(const nlohmann::json& j, Currency& currency)
    {
        j.at("id").get_to(currency.id);
        j.at("currencyName").get_to(currency.currencyName);
        j.at("currencySymbol").get_to(currency.currencySymbol);
    }
};