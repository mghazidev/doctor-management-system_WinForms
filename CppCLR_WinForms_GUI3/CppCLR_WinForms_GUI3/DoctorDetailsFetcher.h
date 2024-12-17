#pragma once
#include "FileFetcher.h"

public ref class DoctorDetailsFetcher
{
public:
    static List<String^>^ FetchDoctorData()
    {
        return FileFetcher::FetchFileData("DoctorDetails.txt");
    }
};
