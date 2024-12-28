#pragma once
#include "EntityManager.h"
using namespace System;
using namespace System::Collections::Generic;

ref class MessageManager : public EntityManager {
public:
    MessageManager(String^ filePath) : EntityManager(filePath) {}

    // Method to save Message to the file
    void SaveMessage(String^ doctorName, String^ message) {
        List<String^>^ messageDetails = gcnew List<String^>();
        messageDetails->Add("Doctor: " + doctorName);
        messageDetails->Add("Message: " + message);
        messageDetails->Add("Status: " + "Unread");

        SaveDetails(messageDetails);
    }

};

