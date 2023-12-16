#include "RequestService.h"

#include "../StaticDataService/SaveLoadService.h"

void RequestService::InitalizeRequests()
{
    for (auto& request : database->currencyClientRequests)
    {
        request.Initialize(database, saveLoadService);
    }
}
