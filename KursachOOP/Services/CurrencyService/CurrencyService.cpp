#include "CurrencyService.h"

CurrencyAccount* CurrencyService::Create(Currency* currency)
{
    return new CurrencyAccount(currency);
}

bool CurrencyService::TryAddMoney(CurrencyAccount* currencyAccount, int money)
{
    if(money < 0)
        return false;
    
    currencyAccount->AddMoney(money);
    saveLoadService->SaveDatabase(*database);
    
    return true;
}

bool CurrencyService::TryRemoveMoney(CurrencyAccount* currencyAccount, int money)
{
    if(currencyAccount->Value() < money)
        return false;
    
    currencyAccount->RemoveMoney(money);
    saveLoadService->SaveDatabase(*database);
    
    return true;
}


