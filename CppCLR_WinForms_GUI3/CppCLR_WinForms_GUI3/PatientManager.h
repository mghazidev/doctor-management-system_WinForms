#pragma once
#include "EntityManager.h"

ref class PatientManager : public EntityManager {
public:
    PatientManager() : EntityManager("PatientDetails.txt") {}

    void SavePatient(String^ name, String^ disease, String^ contact) {
        List<String^>^ details = gcnew List<String^>();
        details->Add("Patient Name: " + name);
        details->Add("Disease: " + disease);
        details->Add("Contact: " + contact);

        SaveDetails(details);
    }

    List<String^>^ LoadPatientNames() {
        return LoadNames("Patient Name: ");
    }

    void DeletePatient(String^ name) {
        DeleteByName("Patient Name: ", name);
    }
};
