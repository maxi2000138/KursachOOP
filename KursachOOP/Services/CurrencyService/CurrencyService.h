#pragma once
#include "../../Balance/CurrencyAccount.h"
#include "../StaticDataService/SaveLoadService.h"

class CurrencyService
{
    Database** database;
    SaveLoadService* saveLoadService;
public:
    CurrencyService(Database** Database, SaveLoadService* SaveLoadService) : saveLoadService(SaveLoadService), database(Database)  {  }
    
    CurrencyAccount* Create(Currency* currency);
    bool TryAddMoney(CurrencyAccount* currencyAccount,int money);
    bool TryRemoveMoney(CurrencyAccount* currencyAccount, int money);
};
