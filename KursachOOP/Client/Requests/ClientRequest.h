#pragma once
#include <string>

#include "../../external/json/single_include/nlohmann/json.hpp"
class Database;
class SaveLoadService;


class ClientRequest
{
    bool isConsidered = false;
    bool isApplied = false;
    std::string requestText;
    virtual void OnApply();
protected:
    Database** database;
    static nlohmann::json toJson(nlohmann::json& j,const ClientRequest& clientRequest);
    static void fromJson(const nlohmann::json& j, ClientRequest& clientRequest);
public:
    std::string clientUsername;
    
    ClientRequest(std::string username, std::string text) : clientUsername(username), requestText(text) { }
    ClientRequest() {  }

    bool IsConsidered() { return isApplied; }
    bool IsApplied() { return isApplied; }
    std::string RequestText() {return requestText; }

    void Initialize(Database** Database)
    {
        database = Database;
    }
    
    void Approve();
    void Decline();
    
    void ShowRequestInfo();
};
