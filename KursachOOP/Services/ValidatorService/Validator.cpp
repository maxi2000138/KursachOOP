#include "Validator.h"

#include <iostream>
#include <Windows.h>

void InputText(string result)
{
    cout << result;
}

string InputMessageAndReadValue(std::string inputText)
{
    InputText(inputText);
    string inputValue;
    cin >> inputValue;
    return inputText;
}

bool Validator::ValidateInteger(std::string inputText, int& result)
{
    InputMessageAndReadValue(inputText);
    return true;
}

bool Validator::ValidateString(std::string inputText, string& result)
{
    InputMessageAndReadValue(inputText);
    return true;
}
