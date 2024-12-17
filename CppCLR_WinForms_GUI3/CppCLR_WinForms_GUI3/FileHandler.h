#pragma once
#include "UserCredentials.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class FileHandler
{
private:
    String^ filePath;

public:
    FileHandler(String^ path) // Constructor to set the file path
    {
        this->filePath = path;
    }

    // Method to load credentials from the file
    List<UserCredentials^>^ LoadCredentials()
    {
        List<UserCredentials^>^ credentialsList = gcnew List<UserCredentials^>();

        if (File::Exists(filePath))
        {
            StreamReader^ reader = gcnew StreamReader(filePath);
            while (!reader->EndOfStream)
            {
                String^ line = reader->ReadLine();
                array<String^>^ parts = line->Split(',');

                if (parts->Length == 3)
                {
                    String^ email = parts[0]->Trim();
                    String^ password = parts[1]->Trim();
                    String^ role = parts[2]->Trim();
                    credentialsList->Add(gcnew UserCredentials(email, password, role));
                }
            }
            reader->Close();
        }
        return credentialsList;
    }
};
