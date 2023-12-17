#include "CurrencyClientRequest.h"
#include "../../Database/Database.h"
#include "../../Services/StaticDataService/SaveLoadService.h"

void CurrencyClientRequest::OnApply()
{
    for (auto it = begin ((*database)->clients); it != end ((*database)->clients); ++it)
    {
        if(it->getUserName() == clientUsername)
        {
            it->AddAccount(currency);
        }
    }
}

void CurrencyClientRequest::Initialize(Database** Database)
{
    database = Database;
    
    for (auto& curr : (*database)->currencies)
    {
        if(curr.id == currencyId)
            currency = &curr;
    }
}

