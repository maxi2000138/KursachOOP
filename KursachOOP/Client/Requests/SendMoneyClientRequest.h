#pragma once
#include "ClientRequest.h"

class ClientFactory;
class Currency;
class Database;

class SendMoneyClientRequest : public ClientRequest
{
    ClientFactory* clientFactory;
    std::string targetUserName;
    std::string currencyText(std::string targetName) { return "Send money to " + targetName; }
public:
    SendMoneyClientRequest(std::string senderUserName, std::string target_user_name, int currency_id, int amount)
        : ClientRequest(senderUserName, currencyText(target_user_name)),
            targetUserName(target_user_name),
          currencyId(currency_id),
          amount(amount)
    {
    }
    SendMoneyClientRequest() { }

private:
    int currencyId;
    int amount;
    Currency* currency;
    void OnApply() override;
    void OnDecline() override;
public:
    void Initialize(Database** database, ClientFactory* ClientFactory);


    friend void to_json(nlohmann::json& j, const SendMoneyClientRequest& request)
    {
        ClientRequest::toJson(j, request);
        j["targetUserName"] = request.targetUserName;
        j["amount"] = request.amount;
        j["currencyId"] = request.currencyId;

    }
    
    friend void from_json(const nlohmann::json& j, SendMoneyClientRequest& request)
    {
        ClientRequest::fromJson(j, request);
        if(j.contains("targetUserName")) j.at("targetUserName").get_to(request.targetUserName);
        if(j.contains("amount")) j.at("amount").get_to(request.amount);
        if(j.contains("currencyId")) j.at("currencyId").get_to(request.currencyId);
    }
};
