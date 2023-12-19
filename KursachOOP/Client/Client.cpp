#include <iostream>
#include "Client.h"

#include "../Services/CurrencyService/CurrencyService.h"
#include "../Services/RequestService/RequestService.h"
#include "Requests/CurrencyClientRequest.h"

using namespace std;

void ShowBalance(const vector<CurrencyAccount>& accounts)
{
    for (auto account : accounts)
        account.ShowAccountInfo();
}

CurrencyAccount* ChooseAccount(std::vector<CurrencyAccount>& balance)
{
    string currName;
    while(true)
    {
        cout << "Choose account currency: " << endl;
    
        for (auto account : balance)
            cout << account.CurrencyName() << endl;

        cin >> currName;

        for(auto& curr : balance)
            if(currName == curr.CurrencyName())
                return &curr;
    }
}

int ChooseMoneyValue()
{
    int moneyValue;
    cout << "Choose currency value: ";
    cin >> moneyValue;
    return moneyValue;
}



void DebugLogInfo()
{
    cout << "1. Show balance" << endl;
    cout << "2. Send an account application" << endl;
    cout << "3. Add money" << endl;
    cout << "4. Remove money" << endl;
    cout << "5. Exit" << endl;
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
        CurrencyAccount* curr;
        int money;
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
            curr = ChooseAccount(balance);
            money = ChooseMoneyValue();
            if(currencyService->TryAddMoney(curr, money))
                cout << "Operation was successful!" << endl;
            break;
        case 4:
            curr = ChooseAccount(balance);
            money = ChooseMoneyValue();
            if(currencyService->TryRemoveMoney(curr, money))
                cout << "Operation was successful!" << endl;
            break;
        case 5:
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
