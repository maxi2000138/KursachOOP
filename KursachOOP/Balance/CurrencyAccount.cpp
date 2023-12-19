#include <iostream>
#include "CurrencyAccount.h"

#include "../Database/Database.h"

using namespace std;

void CurrencyAccount::ShowAccountInfo()
{
    cout << "Account currency: " << currency->currencyName << " --- currency value: " << value << endl;
}

void CurrencyAccount::Initialize(Database** database)
{
    for (auto& curr : (*database)->currencies)
    {
        if(curr.id == currencyId)
            currency = &curr;
    }
}

void CurrencyAccount::AddMoney(int money)
{
    value += money;
}

void CurrencyAccount::RemoveMoney(int money)
{
    value -= money;
}


