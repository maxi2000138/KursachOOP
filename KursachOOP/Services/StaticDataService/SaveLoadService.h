#pragma once
#include "../../Database/Database.h"

class SaveLoadService
{
public:
    Database* LoadDatabase();
    void SaveDatabase(Database* database);
private:
    const std::string DATABASE_PATH = "E:\\LabyOOP\\KursachOOP\\Database.json";
};
