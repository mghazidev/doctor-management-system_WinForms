#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace System;
using namespace System::Collections::Generic;

public ref class FileFetcher
{
public:
    // Static method to fetch data from a file
    static List<String^>^ FetchFileData(String^ fileName)
    {
        List<String^>^ data = gcnew List<String^>();

        // Open the file
        std::ifstream file((const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(fileName).ToPointer());
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                data->Add(gcnew String(line.c_str()));
            }
            file.close();
        }
        else
        {
            Console::WriteLine("Error opening file: " + fileName);
        }

        return data;
    }
};
