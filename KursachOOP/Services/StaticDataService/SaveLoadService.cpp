#include "SaveLoadService.h"
#include "../../Database/Database.h"
#include <fstream>

Database* SaveLoadService::LoadDatabase()
{
    std::ifstream i(DATABASE_PATH);
    nlohmann::json j;
    i >> j;
    Database* db = new Database();
    db->from_json(j, *db);
    return db;
}

void SaveLoadService::SaveDatabase(Database* database)
{
    nlohmann::json j;
    database->to_json(j, *database);

    std::ofstream o(DATABASE_PATH);
    o << setw(4) << j << endl;
}

