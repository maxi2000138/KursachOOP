#include <iostream>
#include "Client.h"

#include "../Services/StaticDataService/SaveLoadService.h"
#include "Requests/CurrencyClientRequest.h"

using namespace std;

void ShowBalance(const vector<CurrencyAccount>& accounts)
{
    for (auto account : accounts)
        account.ShowAccountInfo();
}

void AddAccountRequest(Database* database, SaveLoadService* saveLoadService, string userName)
{
    string currencyName;

    while(true)
    {
        cout << "Enter the currency in which you want to open an account" << endl;
        cin >> currencyName;

        for (auto currency : database->currencies)
        {
            if (currency.currencyName == currencyName)
            {
                CurrencyClientRequest request(&currency, userName, currencyName);
                request.Initialize(database, saveLoadService);
                database->currencyClientRequests.push_back(request);
                saveLoadService->SaveDatabase(database);
                
                cout << "Your account send for consideration!" << endl;
                return;
            }
        }

        cout << "Enter existing currency" << endl;
    }
}

void DebugLogInfo()
{
    cout << "1. Show balance" << endl;
    cout << "2. Send an account application" << endl;
    cout << "3. Exit" << endl;
}

bool Client::showMenu()
{
    for (auto request : database->currencyClientRequests)
    {
        if(request.clientUsername == getUserName())
            request.TryApply();
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
            AddAccountRequest(database, saveLoadService, getUserName());
            break;
        case 3:
            system("cls");
            return false;
        }   
    }
}

void Client::AddAccount(Currency* currency)
{
    CurrencyAccount currencyAccount(currency);
    balance.push_back(currencyAccount);
}
