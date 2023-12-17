#include "RequestService.h"

#include "../StaticDataService/SaveLoadService.h"

void RequestService::InitalizeRequests()
{
    for (auto& request : (*database )->currencyClientRequests)
    {
        request.Initialize(database);
    }
}

void RequestService::AddAccountRequest(Database** database, SaveLoadService* saveLoadService, string userName)
{
    string currencyName;

    while(true)
    {
        cout << "Enter the currency in which you want to open an account" << endl;
        cin >> currencyName;

        for (auto currency : (*database)->currencies)
        {
            if (currency.currencyName == currencyName)
            {
                CurrencyClientRequest request(&currency, userName, currencyName, currency.id);
                request.Initialize(database);
                
                (*database)->currencyClientRequests.push_back(request);
                saveLoadService->SaveDatabase(*database);
                
                cout << "Your account send for consideration!" << endl;
                return;
            }
        }

        cout << "Enter existing currency" << endl;
    }
}


void RequestService::ApproveRequest(ClientRequest& request)
{
    request.Approve();
    saveLoadService->SaveDatabase(*database);
}

void RequestService::DeclineRequest(ClientRequest& request)
{
    request.Decline();
    saveLoadService->SaveDatabase(*database);
}



void RequestService::TryApply(ClientRequest& request)
{
    cout << "Your request: " << request.RequestText() << " is in the status: ";
    
    if(!request.IsConsidered())
    {
        cout << "In process\n";
        return;
    }
    
    if(request.IsApplied())
        cout << "Approved\n";
    else
        cout << "Decline\n ";

    auto d = (*database)->currencyClientRequests.begin();
    for(auto it = (*database)->currencyClientRequests.begin();it != (*database)->currencyClientRequests.end();++it)
    {
        if(it->RequestText() == request.RequestText())
        {
            (*database)->currencyClientRequests.erase(it);
            saveLoadService->SaveDatabase(*database);
            return;
        }
    }
}