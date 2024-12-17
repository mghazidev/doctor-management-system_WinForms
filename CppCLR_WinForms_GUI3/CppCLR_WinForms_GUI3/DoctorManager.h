#pragma once
#include "EntityManager.h";


ref class DoctorManager : public EntityManager {
public:
    DoctorManager() : EntityManager("DoctorDetails.txt") {}

    void SaveDoctor(String^ name, String^ specialization, String^ hours) {
        List<String^>^ details = gcnew List<String^>();
        details->Add("Doctor Name: " + name);
        details->Add("Specialization: " + specialization);
        details->Add("Available Hours: " + hours);

        SaveDetails(details);
    }

    List<String^>^ LoadDoctorNames() {
        return LoadNames("Doctor Name: ");
    }

    void DeleteDoctor(String^ name) {
        DeleteByName("Doctor Name: ", name);
    }
};

