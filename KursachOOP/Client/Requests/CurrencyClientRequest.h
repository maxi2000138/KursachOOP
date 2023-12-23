#pragma once
#include "ClientRequest.h"

class Currency;
class Database;

using namespace std;

class CurrencyClientRequest : public ClientRequest
{
    Currency* currency;
    int currencyId;
    string currencyText(string currencyName) { return "Opening Account in " + currencyName; }
    void OnApply() override;
    void OnDecline() override;
public:
    CurrencyClientRequest(Currency* currency, string userName, string currencyName, int CurrencyId) : ClientRequest(userName, currencyText(currencyName)) , currency(currency), currencyId(CurrencyId)  { }
    CurrencyClientRequest() { }
    
    void Initialize(Database** database);
    

    friend void to_json(nlohmann::json& j, const CurrencyClientRequest& db)
    {
        ClientRequest::toJson(j, db);
        j["currencyId"] = db.currencyId;
    }
    
    friend void from_json(const nlohmann::json& j, CurrencyClientRequest& db)
    {
        ClientRequest::fromJson(j, db);
        if(j.contains("currencyId")) j.at("currencyId").get_to(db.currencyId);
    }
};
