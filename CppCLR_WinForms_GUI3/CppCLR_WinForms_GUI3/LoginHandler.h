#pragma once
#include "FileHandler.h"
using namespace System;

ref class LoginHandler
{
private:
    FileHandler^ fileHandler;

public:
    LoginHandler(String^ filePath) // Constructor to initialize file handler
    {
        this->fileHandler = gcnew FileHandler(filePath);
    }

    // Method to verify if the email, password, and role match any saved credentials
    bool VerifyLogin(String^ email, String^ password, String^ role)
    {
        List<UserCredentials^>^ credentialsList = fileHandler->LoadCredentials();

        for each (UserCredentials ^ user in credentialsList)
        {
            // Check if email, password, and role match
            if (user->email == email && user->password == password && user->role == role)
            {
                return true; // Valid credentials
            }
        }
        return false; // Invalid credentials
    }
};
