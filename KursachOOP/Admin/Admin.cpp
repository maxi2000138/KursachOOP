#include <iostream>
#include "Admin.h"

#include "../Database/Database.h"
#include "../Services/RequestService/RequestService.h"
#include "../Services/StaticDataService/SaveLoadService.h"
#include "../Client/ClientFactory.h"


using namespace std;

void AddClient(Database* database, ClientFactory* clientFactory, SaveLoadService* saveLoadService)
{
    string login, password;
    cout << "Enter the username of a new client: ";
    cin >> login;
    cout << "Enter the password of a new client: ";
    cin >> password;

    Client* client = clientFactory->CreateUser(login, password);
    database->clients.push_back(*client);
    saveLoadService->SaveDatabase(database);
    cout << "Client succesfull added!" << endl;
}

void RemoveClient(Database* database, SaveLoadService* saveLoadService)
{
    while(true)
    {
        string login;
        cout << "Enter the username of a client: ";
        cin >> login;

        for(auto it = database->clients.begin();it != database->clients.end();++it)
        {
            if(it->getUserName() == login)
            {
                database->clients.erase(it);
                saveLoadService->SaveDatabase(database);
                cout << "Client succesfull removed!" << endl;
                return;
            }
        }

        cout << "User with this username not found!" << endl << "Try again" << endl;
    }
}

void ShowAllClients(Database* database)
{
    cout << "---------" << endl;
    for(auto it = database->clients.begin();it != database->clients.end();++it)
    {
        cout << it->getUserName() << endl;
    }
    cout << "---------" << endl;
}



void ShowAllCurrencies(Database* database)
{
    cout << "---------" << endl;
    for (auto currency : database->currencies)
    {
        cout << "Currency name: " << setw(10) << currency.currencyName << "  Currency icon: " << setw(4) << currency.currencySymbol << endl;
    }
    cout << "---------" << endl;
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
                cout << "Data successfully deleted!" << endl;
                return;
            }
        }

        cout << "Currency not found! Try again" << endl;
    }
}

void ConsiderRequest(RequestService* requestService, int num, CurrencyClientRequest& request)
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
                requestService->ApproveRequest(request);
                considered = true;
                break;
            case 2:
                requestService->DeclineRequest(request);
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

void ConsiderRequest(RequestService* requestService, int num, SendMoneyClientRequest& request)
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
                requestService->ApproveRequest(request);
                considered = true;
                break;
            case 2:
                requestService->DeclineRequest(request);
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

void CheckRequests(Database* database, RequestService* requestService)
{
    int num = 0;
    for (auto& request : database->currencyClientRequests)
        ConsiderRequest(requestService, num, request);

    for (auto& request : database->sendMoneyClientRequests)
        ConsiderRequest(requestService, num, request);
    
    cout << "Requests end up" << endl << endl;
}

void Exit()
{
    
}

bool Admin::showMenu()
{
    while (true)
    {
        cout << endl;
        cout << "1. Add client" << endl;
        cout << "2. Remove client" << endl;
        cout << "3. View All clients" << endl;
        cout << "4. Add currency" << endl;
        cout << "5. Remove currency" << endl;
        cout << "6. See all currencies" << endl;
        cout << "7. View Requests" << endl;
        cout << "8. Exit" << endl;
        
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            AddClient(*database,clientFactory, saveLoadService);
            break;
        case 2:
            RemoveClient(*database, saveLoadService);
            break;
        case 3:
            ShowAllClients(*database);
            break;
        case 4:
            AddCurrency(*database,saveLoadService);
            break;
        case 5:
            RemoveCurrency(*database,saveLoadService);
            break;
        case 6:
            ShowAllCurrencies(*database);
            break;
        case 7:
            CheckRequests(*database, requestService);
            break;
        case 8:
            system("cls");
            return false;
            
            
        default:
            cout << "Введите корректное число!" << endl << endl;
            break;
        }


        string str;
        cout << "Enter to clear..";
        cin.clear();
        getline(cin, str);
        getline(cin, str);
        system("cls");
    }
}
