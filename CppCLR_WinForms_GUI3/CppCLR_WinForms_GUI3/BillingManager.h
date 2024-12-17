#pragma once
#include "EntityManager.h"

ref class BillingManager : public EntityManager {
public:
    BillingManager() : EntityManager("BillingDetails.txt") {}

    void SaveBilling(String^ patientName, String^ totalAmount, String^ paidAmount) {
        if (IsBillExists(patientName)) {
            throw gcnew InvalidOperationException("Bill for this patient already exists.");
        }

        List<String^>^ details = gcnew List<String^>();
        details->Add("Patient Name: " + patientName);
        details->Add("Total Amount: " + totalAmount);
        details->Add("Paid Amount: " + paidAmount);
        SaveDetails(details);
    }
private:
    bool IsBillExists(String^ patientName) {
        try {
            if (!System::IO::File::Exists(filePath)) {
                return false; 
            }

            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
            String^ line;

            while ((line = reader->ReadLine()) != nullptr) {
                if (line->StartsWith("Patient Name: ") && line->Contains(patientName)) {
                    reader->Close();
                    return true; // Bill for this patient already exists
                }
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            throw gcnew InvalidOperationException("Error checking bill existence: " + ex->Message);
        }

        return false; 
    }
};
