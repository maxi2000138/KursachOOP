#pragma once
#include <string>
#include <iostream>
#include "../external/json/single_include/nlohmann/json.hpp"


class UserBase
{
public:
    UserBase(std::string username,std::string password)
        : _username(username),
          _password(password)
    {
        
    }

    virtual bool showMenu() { return false; }

    std::string getUserName() const
    {
        return _username;
    }
    
    bool equalPasswords(std::string password) const
    {
        return password == _password;
    }
    
    
    static void to_json(nlohmann::json& j, const UserBase& userBase) {
        j = nlohmann::json
        {
            {"username", userBase._username}
            ,{"password", userBase._password}
        };
        
    }

    static void from_json(const nlohmann::json& j, UserBase& userBase) {
        j.at("username").get_to(userBase._username);
        j.at("password").get_to(userBase._password);
    }
    
private:
    std::string _username;
    std::string _password;
    
};
