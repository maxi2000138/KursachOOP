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
    static nlohmann::json toJson(nlohmann::json& j,const ClientRequest& clientRequest);
    static void fromJson(const nlohmann::json& j, ClientRequest& clientRequest);
    Database* database;
    SaveLoadService* saveLoadService;
public:
    std::string clientUsername;    

    ClientRequest(std::string username, std::string text) : clientUsername(username), requestText(text) { }
    ClientRequest() {  }

    void Initialize(Database* Database, SaveLoadService* SaveLoadService)
    {
        database = Database;
        saveLoadService = SaveLoadService;
    }

    bool IsConsidered() { return isApplied; }
    void TryApply();
    void ShowRequestInfo();
    void Approve();
    void Decline();
};
