#pragma once
using namespace System;

ref class UserCredentials
{
public:
    String^ email;
    String^ password;
    String^ role;

    UserCredentials(String^ email, String^ password, String^ role)
    {
        this->email = email;
        this->password = password;
        this->role = role;
    }
};
