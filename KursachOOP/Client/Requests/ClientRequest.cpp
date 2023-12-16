#include <iostream>
#include "ClientRequest.h"


#include "../../Services/StaticDataService/SaveLoadService.h"

using namespace std;


void ClientRequest::Approve()
{
    isConsidered = true;
    isApplied = true;
    OnApply();
    saveLoadService->SaveDatabase(database);
}

void ClientRequest::Decline()
{
    isConsidered = true;
    isApplied = false;
    saveLoadService->SaveDatabase(database);
}

void ClientRequest::TryApply()
{
    cout << "Your request: " << requestText << " is in the status: ";
    
    if(!isConsidered)
    {
        cout << "In process\n";
        return;
    }
    
    if(isApplied)
    {
        cout << "Approved\n";
    }
    else
    {
        cout << "Decline\n ";
    }
    
    auto it = std::find_if(database->currencyClientRequests.begin(), database->currencyClientRequests.end(), [this](const ClientRequest& request) {
    return request.requestText == this->requestText;});

    if (it != database->currencyClientRequests.end())
    {
        database->currencyClientRequests.erase(it);
        saveLoadService->SaveDatabase(database);
    }
}

void ClientRequest::ShowRequestInfo()
{
    cout << "Client with nickname: " << clientUsername << " applied request: " << requestText << endl;
}

void ClientRequest::OnApply()
{
    

}

nlohmann::json ClientRequest::toJson(nlohmann::json& j, const ClientRequest& cl)
{
    j = nlohmann::json
        {
                {"isConsidered", cl.isConsidered },
                {"isApplied", cl.isApplied },
                {"clientUsername", cl.clientUsername },
                {"requestText", cl.requestText }
        };

    return j;
}

void ClientRequest::fromJson(const nlohmann::json& j, ClientRequest& cl)
{
    j.at("isConsidered").get_to(cl.isConsidered);
    j.at("isApplied").get_to(cl.isApplied);
    j.at("clientUsername").get_to(cl.clientUsername);
    j.at("requestText").get_to(cl.requestText);    
}



