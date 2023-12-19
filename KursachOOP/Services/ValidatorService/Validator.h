#pragma once
#include <string>

using namespace std;

class Validator
{
public:
    bool ValidateInteger(std::string inputText, int& result);
    bool ValidateString(std::string inputText, string& result);
};
