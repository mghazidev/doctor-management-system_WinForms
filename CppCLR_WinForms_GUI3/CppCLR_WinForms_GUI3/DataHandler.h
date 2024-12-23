#pragma once
using namespace System;
using namespace System::Collections::Generic;

ref class DataHandler {
private:
    String^ filePath;

public:
    DataHandler(String^ filePath) {
        this->filePath = filePath;
    }

    List<String^>^ LoadDetails() {
        List<String^>^ details = gcnew List<String^>();

        try {
            if (!System::IO::File::Exists(filePath)) {
                throw gcnew FileNotFoundException("File not found: " + filePath);
            }

            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
            String^ line;

            while ((line = reader->ReadLine()) != nullptr) {
                details->Add(line);
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            throw gcnew InvalidOperationException("Error loading details: " + ex->Message);
        }

        return details;
    }
};
