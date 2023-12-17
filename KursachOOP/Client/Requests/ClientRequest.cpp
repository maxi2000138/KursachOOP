#include <iostream>
#include "ClientRequest.h"


#include "../../Services/StaticDataService/SaveLoadService.h"

using namespace std;


void ClientRequest::Approve()
{
    isConsidered = true;
    isApplied = true;
    OnApply();
}

void ClientRequest::Decline()
{
    isConsidered = true;
    isApplied = false;
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



