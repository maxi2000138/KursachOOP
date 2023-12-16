#include <iostream>
#include "Admin.h"

#include "../Database/Database.h"
#include "../Services/StaticDataService/SaveLoadService.h"

using namespace std;

void ShowAllCurrencies(Database* database)
{
    cout << endl;
    for (auto currency : database->currencies)
    {
        cout << "Currency name: " << setw(10) << currency.currencyName << "  Currency icon: " << setw(4) << currency.currencySymbol << endl;
    }
    
    cout << endl;
}

void AddCurrency(Database* database, SaveLoadService* saveLoadService)
{
    string currencyName;
    string currenySymbol;
    int id;
    
    cout << "Enter a currency name:";
    cin >> currencyName;
    cout << "Enter the currency icon:";
    cin >> currenySymbol;

    if(database->currencies.size() != 0)
        id = database->currencies.back().id+1;
    else
        id = 0;

    Currency* currency = new Currency(currencyName, currenySymbol, id);
    database->currencies.push_back(*currency);
    saveLoadService->SaveDatabase(database);
    cout << "Currency successfully added!" << endl << endl;
}

void RemoveCurrency(Database* database, SaveLoadService* saveLoadService)
{
    string currencyName;

    while(true)
    {
    
        cout << "Enter the name of the currency you want to delete:";
        cin >> currencyName;



        for (auto it = begin (database->currencies); it != end (database->currencies); ++it) {
            if(it->currencyName == currencyName)
            {
                database->currencies.erase(it);
                saveLoadService->SaveDatabase(database);
                cout << "Data successfully deleted!";
                return;
            }
        }
    }
}

void CheckRequests(Database* database)
{
    int num;
    for (auto& request : database->currencyClientRequests)
    {
        if(!request.IsConsidered())
        {
            request.ShowRequestInfo();
            cout << "1.Одобрить\n2.Отклонить\n3.Пропустить\n";
            cin >> num;
            bool isContinue = true;
            while(isContinue)
            {
                bool considered = false;
                
                switch (num)
                {
                case 1:
                    request.Approve();
                    considered = true;
                    break;
                case 2:
                    request.Decline();
                    considered = true;
                    break;
                case 3:
                    isContinue = false;
                    break;
                default:
                    cout << "Enter the correct number" << endl;
                }
                
                if(considered)
                    break;
            }

        }

    }
    
    cout << "Requests end up" << endl << endl;
}

void Exit()
{
    
}

bool Admin::showMenu()
{
    while (true)
    {
        system("cls");
        cout << endl;
        cout << "1. See all currencies" << endl;
        cout << "2. Add currency" << endl;
        cout << "3. Remove currency" << endl;
        cout << "4. View Requests" << endl;
        cout << "5. Exit" << endl;
        
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            ShowAllCurrencies(database);
            break;
            
        case 2:
            AddCurrency(database,saveLoadService);
            break;

        case 3:
            RemoveCurrency(database,saveLoadService);
            break;
        case 4:
            CheckRequests(database);
            break;
        case 5:
            system("cls");
            return false;
            
            
        default:
            cout << "Введите корректное число!" << endl << endl;
            break;
        }   
    }
}
