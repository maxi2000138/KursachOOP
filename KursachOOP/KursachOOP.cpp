#include <iostream>
#include <Windows.h>

#include "Database/Database.h"
#include "external/json/single_include/nlohmann/json.hpp"
#include "Services/AuthorizationService/AuthorizationService.h"
#include "Services/RequestService/RequestService.h"
#include "Services/StaticDataService/SaveLoadService.h"

using json = nlohmann::json;
using namespace std;


bool AuthorizeUser(AuthorizationService* authorizationService, UserBase** user)
{
    while (true)
    {
        cout << "1. Login as an admin" << endl;
        cout << "2. Login as a client" << endl;
        cout << "3. End program" << endl;

        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            if(authorizationService->TryAuthorizeAdmin(user))
            {
                system("cls");
                return true;
            }
            continue;
            
        case 2:
            if(authorizationService->TryAuthorizeClient(user))
            {
                system("cls");
                return true;
            }
            continue;
        case 3:
            return false;

        default:
            cout << "Enter the correct number!" << endl << endl;
            break;
        }   
    }
}

int main()
{
    auto* saveLoadService = new SaveLoadService;
    auto* database = saveLoadService->LoadDatabase();

    RequestService* requestService = new RequestService(database, saveLoadService);
    auto* authorizationService = new  AuthorizationService(database, saveLoadService);

    requestService->InitalizeRequests();
    
    
    UserBase* user;

    while (AuthorizeUser(authorizationService, &user))
    {
        while(user->showMenu())
        { }
    }
    
    delete saveLoadService;
    delete database;
    delete authorizationService;
    
    return 0;
}

