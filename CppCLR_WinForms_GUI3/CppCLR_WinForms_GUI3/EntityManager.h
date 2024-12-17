#pragma once
using namespace System;
using namespace System::Collections::Generic;

ref class EntityManager {
protected:
    String^ filePath;

    EntityManager(String^ filePath) {
        this->filePath = filePath;
    }

    void SaveDetails(List<String^>^ details) {
        if (details == nullptr || details->Count == 0) {
            throw gcnew ArgumentException("Details cannot be empty.");
        }

        try {
            System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter(filePath, true);
            for each (String ^ detail in details) {
                file->WriteLine(detail);
            }
            file->WriteLine("----------------------------------");
            file->Close();
        }
        catch (Exception^ ex) {
            throw gcnew InvalidOperationException("Error saving details: " + ex->Message);
        }
    }

    List<String^>^ LoadNames(String^ namePrefix) {
        List<String^>^ names = gcnew List<String^>();
        try {
            if (!System::IO::File::Exists(filePath)) {
                return names; // Return empty list if the file doesn't exist
            }

            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
            String^ line;

            while ((line = reader->ReadLine()) != nullptr) {
                if (line->StartsWith(namePrefix)) {
                    String^ name = line->Substring(namePrefix->Length);
                    names->Add(name);
                }
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            throw gcnew InvalidOperationException("Error loading names: " + ex->Message);
        }

        return names;
    }

   


    void DeleteByName(String^ namePrefix, String^ nameToDelete) {
        if (String::IsNullOrWhiteSpace(nameToDelete)) {
            throw gcnew ArgumentException("Name cannot be empty.");
        }

        String^ tempFilePath = filePath + ".tmp";

        try {
            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
            System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(tempFilePath);

            bool found = false;
            String^ line;

            while ((line = reader->ReadLine()) != nullptr) {
                if (line->StartsWith(namePrefix + nameToDelete)) {
                    found = true;
                    for (int i = 0; i < 3; i++) reader->ReadLine(); // Skip next 3 lines
                }
                else {
                    writer->WriteLine(line);
                }
            }

            reader->Close();
            writer->Close();

            if (found) {
                System::IO::File::Delete(filePath);
                System::IO::File::Move(tempFilePath, filePath);
            }
            else {
                System::IO::File::Delete(tempFilePath);
                throw gcnew InvalidOperationException("Name not found.");
            }
        }
        catch (Exception^ ex) {
            throw gcnew InvalidOperationException("Error deleting details: " + ex->Message);
        }
    }
};
