#include <iostream>

#include "AuthorizationService.h"
#include "../../Database/Database.h"
#include "../RequestService/RequestService.h"

using namespace std;


void GetAuthorizationData(string* username, string* password)
{
    cout << "Enter the user name: ";
    cin >> *username; 
    cout << "Enter the password: ";
    cin >> *password; 
}

template <typename T>
bool TryAuthUser(vector<T>* usersVector, UserBase** authorizedUser)
{
    string username;
    string password;
    GetAuthorizationData(&username, &password);

    for (int i = 0; i < usersVector->size(); i++)
    {
        if (username == (*usersVector)[i].getUserName())
        {
            if((*usersVector)[i].equalPasswords(password))
            {
                *authorizedUser = &(*usersVector)[i];
                return true;    
            }

            cout << "Wrong password entered!" << endl << endl;
            return false;
        }
    }

    cout << "No user with this login was found!" << endl << endl;
    return false;
}


bool AuthorizationService::TryAuthorizeClient(UserBase** client)
{
    if(TryAuthUser(&(*database)->clients,  client))
    {
        reinterpret_cast<Client*>(*client)->Construct(database, saveLoadService, requestService);
        return true;
    }

    return false;
}

bool AuthorizationService::TryAuthorizeAdmin(UserBase** admin)
{
    if(TryAuthUser(&(*database)->admins, admin))
    {
        reinterpret_cast<Admin*>(*admin)->Construct(database, saveLoadService, requestService);
        return true;
    }

    return false;
}




