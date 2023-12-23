#include "SendMoneyClientRequest.h"
#include "../../Database/Database.h"
#include "../ClientFactory.h"
#include "../../Services/StaticDataService/SaveLoadService.h"

void SendMoneyClientRequest::Initialize(Database** Database, ClientFactory* client_factory)
{
    database = Database;
    clientFactory = client_factory;
    for (auto& curr : (*database)->currencies)
    {
        if(curr.id == currencyId)
            currency = &curr;
    }
}

void AddMoneyTo(Database** database, ClientFactory* clientFactory, string userName, Currency* currency, int amount)
{
    for (auto it = begin ((*database)->clients); it != end ((*database)->clients); ++it)
    {
        if(it->getUserName() == userName)
        {
            clientFactory->InitUser(&*it);
            for (auto& currencyAccount : it->balance)
            {
                if(currencyAccount.CurrencyName() == currency->currencyName)
                {
                    currencyAccount.AddMoney(amount);
                    return;
                }
            }
        }
    }
}

void SendMoneyClientRequest::OnApply()
{
    AddMoneyTo(database, clientFactory, targetUserName, currency, amount);
}

void SendMoneyClientRequest::OnDecline()
{
    AddMoneyTo(database, clientFactory, clientUsername, currency, amount);
}
