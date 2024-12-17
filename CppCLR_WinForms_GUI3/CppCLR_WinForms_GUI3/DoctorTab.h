//#pragma once
//
//using namespace System;
//using namespace System::IO;
//
//namespace CppCLRWinFormsProject {
//
//    public ref class DoctorFileManager
//    {
//    public:
//        // Method to save doctor details into a file
//        static void SaveDoctorDetails(String^ doctorName, String^ specialization, String^ availableHours)
//        {
//            // Specify the file path where the doctor details will be saved
//            String^ filePath = "doctor_details.txt";  // Adjust the path if needed
//
//            try {
//                // Open the file to append
//                StreamWriter^ sw = gcnew StreamWriter(filePath, true);
//
//                // Write the doctor details in the file
//                sw->WriteLine("Doctor Name: " + doctorName);
//                sw->WriteLine("Specialization: " + specialization);
//                sw->WriteLine("Available Hours: " + availableHours);
//                sw->WriteLine();  // Add a line break between different entries
//
//                // Close the file
//                sw->Close();
//            }
//            catch (Exception^ ex) {
//                MessageBox::Show("An error occurred: " + ex->Message);
//            }
//        }
//    };
//}
