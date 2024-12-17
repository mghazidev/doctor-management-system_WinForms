#pragma once
#include "EntityManager.h"
using namespace System;
using namespace System::Collections::Generic;

ref class FeedbackManager : public EntityManager {
public:
    FeedbackManager(String^ filePath) : EntityManager(filePath) {}

    // Method to save feedback to the file
    void SaveFeedback(String^ doctorName, String^ feedbackRating) {
        List<String^>^ feedbackDetails = gcnew List<String^>();
        feedbackDetails->Add("Doctor: " + doctorName);
        feedbackDetails->Add("Feedback Rating: " + feedbackRating);
        feedbackDetails->Add("Date: " + DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss"));

        SaveDetails(feedbackDetails);
    }

};

