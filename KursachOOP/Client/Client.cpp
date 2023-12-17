#include <iostream>
#include "Client.h"

#include "../Services/RequestService/RequestService.h"
#include "../Services/StaticDataService/SaveLoadService.h"
#include "Requests/CurrencyClientRequest.h"

using namespace std;

void ShowBalance(const vector<CurrencyAccount>& accounts)
{
    for (auto account : accounts)
        account.ShowAccountInfo();
}


void DebugLogInfo()
{
    cout << "1. Show balance" << endl;
    cout << "2. Send an account application" << endl;
    cout << "3. Exit" << endl;
}

bool Client::showMenu()
{
    for (auto request : (*database)->currencyClientRequests)
    {
        if(request.clientUsername == getUserName())
            requestService->TryApply(request);
    }

    while (true)
    {
        cout << endl;
        DebugLogInfo();
    
        int result;
        cin >> result;
        switch (result)
        {
        case 1:
            ShowBalance(balance);
            break;
        case 2:
            requestService->AddAccountRequest(database, saveLoadService, getUserName());
            break;
        case 3:
            system("cls");
            return false;
        }   
    }
}

void Client::AddAccount(Currency* currency)
{
    const CurrencyAccount* currencyAccount = new CurrencyAccount(currency);
    balance.push_back(*currencyAccount);
}
