#pragma once


#include "DoctorManager.h"
#include "PatientManager.h"
#include "LoginHandler.h"
#include "BillingManager.h"
#include "FeedbackManager.h"
#include "DataHandler.h"


namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  
  public ref class Form1 : public System::Windows::Forms::Form
  {

  private:
      DoctorManager^ doctorManager;
  private: System::Windows::Forms::TabPage^ LoginTab;
  private: System::Windows::Forms::Label^ Loginhead;
  private: System::Windows::Forms::Button^ loginbutton;

  private: System::Windows::Forms::GroupBox^ selectionbox;
  private: System::Windows::Forms::RadioButton^ useradio;


  private: System::Windows::Forms::RadioButton^ doctorradio;

  private: System::Windows::Forms::TextBox^ passwordtextbox;

  private: System::Windows::Forms::Label^ Passwordlabel;
  private: System::Windows::Forms::TextBox^ emailtextbox;



  private: System::Windows::Forms::Label^ emaillabel;
  private: System::Windows::Forms::TabPage^ UserDashboardTab;
  private: System::Windows::Forms::TabPage^ doctordashboardtab;
  private: System::Windows::Forms::Label^ userdashboardhead;
  private: System::Windows::Forms::Label^ doctordashboardhead;
  private: System::Windows::Forms::TabPage^ billingtab;
  private: System::Windows::Forms::Label^ BillingHead;
  private: System::Windows::Forms::Button^ addbill;

  private: System::Windows::Forms::TextBox^ paidamounttextbox;

  private: System::Windows::Forms::Label^ paidamountlabel;

  private: System::Windows::Forms::TextBox^ totalamounttextbox;

  private: System::Windows::Forms::Label^ totalamount;

  private: System::Windows::Forms::ComboBox^ billpatientnamedropdown;


  private: System::Windows::Forms::Label^ patientbilllabel;




         PatientManager^ patientManager;
  private: System::Windows::Forms::TabPage^ feedbacktab;
  private: System::Windows::Forms::Label^ feedbackhead;
  private: System::Windows::Forms::Label^ feedbackdoctorlabel;
  private: System::Windows::Forms::ComboBox^ feedbackdoctordropdown;
  private: System::Windows::Forms::GroupBox^ feedbackselectionbox;
  private: System::Windows::Forms::RadioButton^ badradio;

  private: System::Windows::Forms::RadioButton^ goodradio;

  private: System::Windows::Forms::RadioButton^ excellentradio;


  private: System::Windows::Forms::RadioButton^ remarkableradio;
  private: System::Windows::Forms::Button^ addfeedbackbutton;




         BillingManager^ billingManager;
          FeedbackManager^ feedbackManager;

 


  private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
  private: System::Windows::Forms::Label^ feedbackdetailssubhead;
  private: System::Windows::Forms::Label^ billingdetailsubhead;
  private: System::Windows::Forms::Label^ doctordetailsubhead;
  private: System::Windows::Forms::GroupBox^ patientdetailgroupbox;
  private: System::Windows::Forms::GroupBox^ doctordetailsgroupbox;
  private: System::Windows::Forms::GroupBox^ billingdetailsgroupbox;
  private: System::Windows::Forms::GroupBox^ feedbackdetailsgroupbox;
  private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
  private: System::Windows::Forms::Label^ patientdetailssubheaddoctortab;

  private: System::Windows::Forms::Label^ doctordetailssubheaddoctortab;
  private: System::Windows::Forms::Label^ billingdetailssubheaddoctortab;
  private: System::Windows::Forms::GroupBox^ doctordashboardpatientdetailsgroupbox;
  private: System::Windows::Forms::GroupBox^ doctordashboarddoctordetailsgroupbox;
  private: System::Windows::Forms::GroupBox^ doctordashboardbillingdetailsgroupbox;




  private: System::Windows::Forms::Label^ patientdetailsubhead;


        

  

  public:
    Form1(void)
    {
      InitializeComponent();
      //tabControl1->TabPages->Remove(doctor);
      //tabControl1->TabPages->Remove(Patient);
      //tabControl1->TabPages->Remove(UserDashboardTab);
      //tabControl1->TabPages->Remove(doctordashboardtab);
      //tabControl1->TabPages->Remove(billingtab);
      //tabControl1->TabPages->Remove(feedbacktab);

      //idhar constructor banaya of loaddoctor becayse jaise form run ho to ye class ka object ban jai foran take doctor names
      // field me show hojain

      doctorManager = gcnew DoctorManager();

      patientManager = gcnew PatientManager();

      billingManager = gcnew BillingManager();


      LoadDoctorNames();
      LoadPatientNames();
      LoadPatientNamesIntoComboBox();
      LoadDoctorNamesIntoFeedbackComboBox();

     
      LoadData();
    }

  protected:
   //Cleanig the Resources 
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  

  private: System::Windows::Forms::TextBox^ out_textBox;
  private: System::Windows::Forms::TextBox^ in_textBox;
  private: System::Windows::Forms::Button^ button_plus_1;
  private: System::Windows::Forms::Button^ button_plus_2;
  private: System::Windows::Forms::TabControl^ tabControl1;
  private: System::Windows::Forms::TabPage^ doctor;
  private: System::Windows::Forms::TabPage^ Patient;


  private: System::Windows::Forms::Label^ doctorinfo;
  private: System::Windows::Forms::Button^ deletedoctor;

  private: System::Windows::Forms::Button^ adddoctor;

  private: System::Windows::Forms::TextBox^ availablehourstextfield;

  private: System::Windows::Forms::Label^ availablehours;
  private: System::Windows::Forms::TextBox^ specializationtextfield;

  private: System::Windows::Forms::Label^ specialization;
  private: System::Windows::Forms::TextBox^ doctornametextfield;

  private: System::Windows::Forms::Label^ doctornamelabel;
  private: System::Windows::Forms::ComboBox^ deletedoctorcombobox;
  private: System::Windows::Forms::Label^ patientinfohead;
  private: System::Windows::Forms::ComboBox^ deletepatientcombobox;

  private: System::Windows::Forms::Button^ deletepatient;

  private: System::Windows::Forms::Button^ addpatientbutton;

  private: System::Windows::Forms::TextBox^ contactnumbertextbox;

  private: System::Windows::Forms::Label^ contactnumber;

  private: System::Windows::Forms::TextBox^ diseasetextbox;

  private: System::Windows::Forms::Label^ diseaselabel;

  private: System::Windows::Forms::TextBox^ patientnametextbox;

  private: System::Windows::Forms::Label^ patientnamelabel;


  protected:

  private:
  
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
 
    void InitializeComponent(void)
    {
        this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
        this->doctor = (gcnew System::Windows::Forms::TabPage());
        this->deletedoctorcombobox = (gcnew System::Windows::Forms::ComboBox());
        this->deletedoctor = (gcnew System::Windows::Forms::Button());
        this->adddoctor = (gcnew System::Windows::Forms::Button());
        this->availablehourstextfield = (gcnew System::Windows::Forms::TextBox());
        this->availablehours = (gcnew System::Windows::Forms::Label());
        this->specializationtextfield = (gcnew System::Windows::Forms::TextBox());
        this->specialization = (gcnew System::Windows::Forms::Label());
        this->doctornametextfield = (gcnew System::Windows::Forms::TextBox());
        this->doctornamelabel = (gcnew System::Windows::Forms::Label());
        this->doctorinfo = (gcnew System::Windows::Forms::Label());
        this->Patient = (gcnew System::Windows::Forms::TabPage());
        this->deletepatientcombobox = (gcnew System::Windows::Forms::ComboBox());
        this->deletepatient = (gcnew System::Windows::Forms::Button());
        this->addpatientbutton = (gcnew System::Windows::Forms::Button());
        this->contactnumbertextbox = (gcnew System::Windows::Forms::TextBox());
        this->contactnumber = (gcnew System::Windows::Forms::Label());
        this->diseasetextbox = (gcnew System::Windows::Forms::TextBox());
        this->diseaselabel = (gcnew System::Windows::Forms::Label());
        this->patientnametextbox = (gcnew System::Windows::Forms::TextBox());
        this->patientnamelabel = (gcnew System::Windows::Forms::Label());
        this->patientinfohead = (gcnew System::Windows::Forms::Label());
        this->LoginTab = (gcnew System::Windows::Forms::TabPage());
        this->loginbutton = (gcnew System::Windows::Forms::Button());
        this->selectionbox = (gcnew System::Windows::Forms::GroupBox());
        this->useradio = (gcnew System::Windows::Forms::RadioButton());
        this->doctorradio = (gcnew System::Windows::Forms::RadioButton());
        this->passwordtextbox = (gcnew System::Windows::Forms::TextBox());
        this->Passwordlabel = (gcnew System::Windows::Forms::Label());
        this->emailtextbox = (gcnew System::Windows::Forms::TextBox());
        this->emaillabel = (gcnew System::Windows::Forms::Label());
        this->Loginhead = (gcnew System::Windows::Forms::Label());
        this->UserDashboardTab = (gcnew System::Windows::Forms::TabPage());
        this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->billingdetailsubhead = (gcnew System::Windows::Forms::Label());
        this->doctordetailsubhead = (gcnew System::Windows::Forms::Label());
        this->patientdetailsubhead = (gcnew System::Windows::Forms::Label());
        this->feedbackdetailssubhead = (gcnew System::Windows::Forms::Label());
        this->patientdetailgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->doctordetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->billingdetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->feedbackdetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->userdashboardhead = (gcnew System::Windows::Forms::Label());
        this->doctordashboardtab = (gcnew System::Windows::Forms::TabPage());
        this->doctordashboardhead = (gcnew System::Windows::Forms::Label());
        this->billingtab = (gcnew System::Windows::Forms::TabPage());
        this->addbill = (gcnew System::Windows::Forms::Button());
        this->paidamounttextbox = (gcnew System::Windows::Forms::TextBox());
        this->paidamountlabel = (gcnew System::Windows::Forms::Label());
        this->totalamounttextbox = (gcnew System::Windows::Forms::TextBox());
        this->totalamount = (gcnew System::Windows::Forms::Label());
        this->billpatientnamedropdown = (gcnew System::Windows::Forms::ComboBox());
        this->patientbilllabel = (gcnew System::Windows::Forms::Label());
        this->BillingHead = (gcnew System::Windows::Forms::Label());
        this->feedbacktab = (gcnew System::Windows::Forms::TabPage());
        this->addfeedbackbutton = (gcnew System::Windows::Forms::Button());
        this->feedbackselectionbox = (gcnew System::Windows::Forms::GroupBox());
        this->badradio = (gcnew System::Windows::Forms::RadioButton());
        this->goodradio = (gcnew System::Windows::Forms::RadioButton());
        this->excellentradio = (gcnew System::Windows::Forms::RadioButton());
        this->remarkableradio = (gcnew System::Windows::Forms::RadioButton());
        this->feedbackdoctordropdown = (gcnew System::Windows::Forms::ComboBox());
        this->feedbackdoctorlabel = (gcnew System::Windows::Forms::Label());
        this->feedbackhead = (gcnew System::Windows::Forms::Label());
        this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->patientdetailssubheaddoctortab = (gcnew System::Windows::Forms::Label());
        this->doctordetailssubheaddoctortab = (gcnew System::Windows::Forms::Label());
        this->billingdetailssubheaddoctortab = (gcnew System::Windows::Forms::Label());
        this->doctordashboardpatientdetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->doctordashboarddoctordetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->doctordashboardbillingdetailsgroupbox = (gcnew System::Windows::Forms::GroupBox());
        this->tabControl1->SuspendLayout();
        this->doctor->SuspendLayout();
        this->Patient->SuspendLayout();
        this->LoginTab->SuspendLayout();
        this->selectionbox->SuspendLayout();
        this->UserDashboardTab->SuspendLayout();
        this->tableLayoutPanel1->SuspendLayout();
        this->doctordashboardtab->SuspendLayout();
        this->billingtab->SuspendLayout();
        this->feedbacktab->SuspendLayout();
        this->feedbackselectionbox->SuspendLayout();
        this->tableLayoutPanel2->SuspendLayout();
        this->SuspendLayout();
        // 
        // tabControl1
        // 
        this->tabControl1->Controls->Add(this->doctor);
        this->tabControl1->Controls->Add(this->Patient);
        this->tabControl1->Controls->Add(this->LoginTab);
        this->tabControl1->Controls->Add(this->UserDashboardTab);
        this->tabControl1->Controls->Add(this->doctordashboardtab);
        this->tabControl1->Controls->Add(this->billingtab);
        this->tabControl1->Controls->Add(this->feedbacktab);
        this->tabControl1->Location = System::Drawing::Point(12, 13);
        this->tabControl1->Name = L"tabControl1";
        this->tabControl1->SelectedIndex = 0;
        this->tabControl1->Size = System::Drawing::Size(1501, 756);
        this->tabControl1->TabIndex = 0;
        // 
        // doctor
        // 
        this->doctor->Controls->Add(this->deletedoctorcombobox);
        this->doctor->Controls->Add(this->deletedoctor);
        this->doctor->Controls->Add(this->adddoctor);
        this->doctor->Controls->Add(this->availablehourstextfield);
        this->doctor->Controls->Add(this->availablehours);
        this->doctor->Controls->Add(this->specializationtextfield);
        this->doctor->Controls->Add(this->specialization);
        this->doctor->Controls->Add(this->doctornametextfield);
        this->doctor->Controls->Add(this->doctornamelabel);
        this->doctor->Controls->Add(this->doctorinfo);
        this->doctor->Location = System::Drawing::Point(4, 22);
        this->doctor->Name = L"doctor";
        this->doctor->Padding = System::Windows::Forms::Padding(3);
        this->doctor->Size = System::Drawing::Size(1493, 583);
        this->doctor->TabIndex = 0;
        this->doctor->Text = L"Doctor";
        this->doctor->UseVisualStyleBackColor = true;
        // 
        // deletedoctorcombobox
        // 
        this->deletedoctorcombobox->FormattingEnabled = true;
        this->deletedoctorcombobox->Location = System::Drawing::Point(408, 256);
        this->deletedoctorcombobox->Name = L"deletedoctorcombobox";
        this->deletedoctorcombobox->Size = System::Drawing::Size(121, 21);
        this->deletedoctorcombobox->TabIndex = 9;
        // 
        // deletedoctor
        // 
        this->deletedoctor->Location = System::Drawing::Point(259, 254);
        this->deletedoctor->Name = L"deletedoctor";
        this->deletedoctor->Size = System::Drawing::Size(126, 23);
        this->deletedoctor->TabIndex = 8;
        this->deletedoctor->Text = L"Delete Doctor";
        this->deletedoctor->UseVisualStyleBackColor = true;
        this->deletedoctor->Click += gcnew System::EventHandler(this, &Form1::deleteDoctor_Click);
        // 
        // adddoctor
        // 
        this->adddoctor->Location = System::Drawing::Point(451, 156);
        this->adddoctor->Name = L"adddoctor";
        this->adddoctor->Size = System::Drawing::Size(75, 23);
        this->adddoctor->TabIndex = 7;
        this->adddoctor->Text = L"Add Doctor";
        this->adddoctor->UseVisualStyleBackColor = true;
        this->adddoctor->Click += gcnew System::EventHandler(this, &Form1::adddoctor_Click);
        // 
        // availablehourstextfield
        // 
        this->availablehourstextfield->Location = System::Drawing::Point(234, 154);
        this->availablehourstextfield->Name = L"availablehourstextfield";
        this->availablehourstextfield->Size = System::Drawing::Size(100, 20);
        this->availablehourstextfield->TabIndex = 6;
        // 
        // availablehours
        // 
        this->availablehours->AutoSize = true;
        this->availablehours->Location = System::Drawing::Point(110, 161);
        this->availablehours->Name = L"availablehours";
        this->availablehours->Size = System::Drawing::Size(81, 13);
        this->availablehours->TabIndex = 5;
        this->availablehours->Text = L"Available Hours";
        // 
        // specializationtextfield
        // 
        this->specializationtextfield->Location = System::Drawing::Point(507, 77);
        this->specializationtextfield->Name = L"specializationtextfield";
        this->specializationtextfield->Size = System::Drawing::Size(100, 20);
        this->specializationtextfield->TabIndex = 4;
        // 
        // specialization
        // 
        this->specialization->AutoSize = true;
        this->specialization->Location = System::Drawing::Point(422, 77);
        this->specialization->Name = L"specialization";
        this->specialization->Size = System::Drawing::Size(72, 13);
        this->specialization->TabIndex = 3;
        this->specialization->Text = L"Specialization";
        // 
        // doctornametextfield
        // 
        this->doctornametextfield->Location = System::Drawing::Point(234, 71);
        this->doctornametextfield->Name = L"doctornametextfield";
        this->doctornametextfield->Size = System::Drawing::Size(100, 20);
        this->doctornametextfield->TabIndex = 2;
        // 
        // doctornamelabel
        // 
        this->doctornamelabel->AutoSize = true;
        this->doctornamelabel->Location = System::Drawing::Point(110, 74);
        this->doctornamelabel->Name = L"doctornamelabel";
        this->doctornamelabel->Size = System::Drawing::Size(70, 13);
        this->doctornamelabel->TabIndex = 1;
        this->doctornamelabel->Text = L"Doctor Name";
        // 
        // doctorinfo
        // 
        this->doctorinfo->AutoSize = true;
        this->doctorinfo->Location = System::Drawing::Point(405, 22);
        this->doctorinfo->Name = L"doctorinfo";
        this->doctorinfo->Size = System::Drawing::Size(60, 13);
        this->doctorinfo->TabIndex = 0;
        this->doctorinfo->Text = L"Doctor Info";
        // 
        // Patient
        // 
        this->Patient->Controls->Add(this->deletepatientcombobox);
        this->Patient->Controls->Add(this->deletepatient);
        this->Patient->Controls->Add(this->addpatientbutton);
        this->Patient->Controls->Add(this->contactnumbertextbox);
        this->Patient->Controls->Add(this->contactnumber);
        this->Patient->Controls->Add(this->diseasetextbox);
        this->Patient->Controls->Add(this->diseaselabel);
        this->Patient->Controls->Add(this->patientnametextbox);
        this->Patient->Controls->Add(this->patientnamelabel);
        this->Patient->Controls->Add(this->patientinfohead);
        this->Patient->Location = System::Drawing::Point(4, 22);
        this->Patient->Name = L"Patient";
        this->Patient->Padding = System::Windows::Forms::Padding(3);
        this->Patient->Size = System::Drawing::Size(1493, 583);
        this->Patient->TabIndex = 1;
        this->Patient->Text = L"Patient";
        this->Patient->UseVisualStyleBackColor = true;
        // 
        // deletepatientcombobox
        // 
        this->deletepatientcombobox->FormattingEnabled = true;
        this->deletepatientcombobox->Location = System::Drawing::Point(521, 282);
        this->deletepatientcombobox->Name = L"deletepatientcombobox";
        this->deletepatientcombobox->Size = System::Drawing::Size(121, 21);
        this->deletepatientcombobox->TabIndex = 9;
        // 
        // deletepatient
        // 
        this->deletepatient->Location = System::Drawing::Point(353, 280);
        this->deletepatient->Name = L"deletepatient";
        this->deletepatient->Size = System::Drawing::Size(124, 23);
        this->deletepatient->TabIndex = 8;
        this->deletepatient->Text = L"Delete Patient";
        this->deletepatient->UseVisualStyleBackColor = true;
        this->deletepatient->Click += gcnew System::EventHandler(this, &Form1::deletePatientButton_Click);
        // 
        // addpatientbutton
        // 
        this->addpatientbutton->Location = System::Drawing::Point(521, 183);
        this->addpatientbutton->Name = L"addpatientbutton";
        this->addpatientbutton->Size = System::Drawing::Size(75, 23);
        this->addpatientbutton->TabIndex = 7;
        this->addpatientbutton->Text = L"Add Patient";
        this->addpatientbutton->UseVisualStyleBackColor = true;
        this->addpatientbutton->Click += gcnew System::EventHandler(this, &Form1::addPatientButton_Click);
        // 
        // contactnumbertextbox
        // 
        this->contactnumbertextbox->Location = System::Drawing::Point(271, 183);
        this->contactnumbertextbox->Name = L"contactnumbertextbox";
        this->contactnumbertextbox->Size = System::Drawing::Size(100, 20);
        this->contactnumbertextbox->TabIndex = 6;
        // 
        // contactnumber
        // 
        this->contactnumber->AutoSize = true;
        this->contactnumber->Location = System::Drawing::Point(138, 190);
        this->contactnumber->Name = L"contactnumber";
        this->contactnumber->Size = System::Drawing::Size(87, 13);
        this->contactnumber->TabIndex = 5;
        this->contactnumber->Text = L"Contact  Number";
        // 
        // diseasetextbox
        // 
        this->diseasetextbox->Location = System::Drawing::Point(624, 92);
        this->diseasetextbox->Name = L"diseasetextbox";
        this->diseasetextbox->Size = System::Drawing::Size(100, 20);
        this->diseasetextbox->TabIndex = 4;
        // 
        // diseaselabel
        // 
        this->diseaselabel->AutoSize = true;
        this->diseaselabel->Location = System::Drawing::Point(561, 99);
        this->diseaselabel->Name = L"diseaselabel";
        this->diseaselabel->Size = System::Drawing::Size(48, 13);
        this->diseaselabel->TabIndex = 3;
        this->diseaselabel->Text = L"Disease ";
        // 
        // patientnametextbox
        // 
        this->patientnametextbox->Location = System::Drawing::Point(249, 96);
        this->patientnametextbox->Name = L"patientnametextbox";
        this->patientnametextbox->Size = System::Drawing::Size(100, 20);
        this->patientnametextbox->TabIndex = 2;
        // 
        // patientnamelabel
        // 
        this->patientnamelabel->AutoSize = true;
        this->patientnamelabel->Location = System::Drawing::Point(155, 99);
        this->patientnamelabel->Name = L"patientnamelabel";
        this->patientnamelabel->Size = System::Drawing::Size(71, 13);
        this->patientnamelabel->TabIndex = 1;
        this->patientnamelabel->Text = L"Patient Name";
        // 
        // patientinfohead
        // 
        this->patientinfohead->AutoSize = true;
        this->patientinfohead->Location = System::Drawing::Point(471, 39);
        this->patientinfohead->Name = L"patientinfohead";
        this->patientinfohead->Size = System::Drawing::Size(61, 13);
        this->patientinfohead->TabIndex = 0;
        this->patientinfohead->Text = L"Patient Info";
        // 
        // LoginTab
        // 
        this->LoginTab->Controls->Add(this->loginbutton);
        this->LoginTab->Controls->Add(this->selectionbox);
        this->LoginTab->Controls->Add(this->passwordtextbox);
        this->LoginTab->Controls->Add(this->Passwordlabel);
        this->LoginTab->Controls->Add(this->emailtextbox);
        this->LoginTab->Controls->Add(this->emaillabel);
        this->LoginTab->Controls->Add(this->Loginhead);
        this->LoginTab->Location = System::Drawing::Point(4, 22);
        this->LoginTab->Name = L"LoginTab";
        this->LoginTab->Padding = System::Windows::Forms::Padding(3);
        this->LoginTab->Size = System::Drawing::Size(1493, 583);
        this->LoginTab->TabIndex = 2;
        this->LoginTab->Text = L"Login ";
        this->LoginTab->UseVisualStyleBackColor = true;
        // 
        // loginbutton
        // 
        this->loginbutton->Location = System::Drawing::Point(476, 316);
        this->loginbutton->Name = L"loginbutton";
        this->loginbutton->Size = System::Drawing::Size(279, 23);
        this->loginbutton->TabIndex = 7;
        this->loginbutton->Text = L"Login";
        this->loginbutton->UseVisualStyleBackColor = true;
        this->loginbutton->Click += gcnew System::EventHandler(this, &Form1::loginButton_Click);
        // 
        // selectionbox
        // 
        this->selectionbox->Controls->Add(this->useradio);
        this->selectionbox->Controls->Add(this->doctorradio);
        this->selectionbox->Location = System::Drawing::Point(151, 217);
        this->selectionbox->Name = L"selectionbox";
        this->selectionbox->Size = System::Drawing::Size(200, 100);
        this->selectionbox->TabIndex = 6;
        this->selectionbox->TabStop = false;
        this->selectionbox->Text = L"Login As";
        // 
        // useradio
        // 
        this->useradio->AutoSize = true;
        this->useradio->Location = System::Drawing::Point(65, 73);
        this->useradio->Name = L"useradio";
        this->useradio->Size = System::Drawing::Size(47, 17);
        this->useradio->TabIndex = 1;
        this->useradio->TabStop = true;
        this->useradio->Text = L"User";
        this->useradio->UseVisualStyleBackColor = true;
        // 
        // doctorradio
        // 
        this->doctorradio->AutoSize = true;
        this->doctorradio->Location = System::Drawing::Point(22, 19);
        this->doctorradio->Name = L"doctorradio";
        this->doctorradio->Size = System::Drawing::Size(57, 17);
        this->doctorradio->TabIndex = 0;
        this->doctorradio->TabStop = true;
        this->doctorradio->Text = L"Doctor";
        this->doctorradio->UseVisualStyleBackColor = true;
        // 
        // passwordtextbox
        // 
        this->passwordtextbox->Location = System::Drawing::Point(567, 152);
        this->passwordtextbox->Name = L"passwordtextbox";
        this->passwordtextbox->PasswordChar = '*';
        this->passwordtextbox->Size = System::Drawing::Size(100, 20);
        this->passwordtextbox->TabIndex = 5;
        // 
        // Passwordlabel
        // 
        this->Passwordlabel->AutoSize = true;
        this->Passwordlabel->Location = System::Drawing::Point(457, 160);
        this->Passwordlabel->Name = L"Passwordlabel";
        this->Passwordlabel->Size = System::Drawing::Size(53, 13);
        this->Passwordlabel->TabIndex = 4;
        this->Passwordlabel->Text = L"Password";
        // 
        // emailtextbox
        // 
        this->emailtextbox->Location = System::Drawing::Point(281, 160);
        this->emailtextbox->Name = L"emailtextbox";
        this->emailtextbox->Size = System::Drawing::Size(100, 20);
        this->emailtextbox->TabIndex = 3;
        // 
        // emaillabel
        // 
        this->emaillabel->AutoSize = true;
        this->emaillabel->Location = System::Drawing::Point(201, 160);
        this->emaillabel->Name = L"emaillabel";
        this->emaillabel->Size = System::Drawing::Size(32, 13);
        this->emaillabel->TabIndex = 2;
        this->emaillabel->Text = L"Email";
        // 
        // Loginhead
        // 
        this->Loginhead->AutoSize = true;
        this->Loginhead->Location = System::Drawing::Point(450, 70);
        this->Loginhead->Name = L"Loginhead";
        this->Loginhead->Size = System::Drawing::Size(33, 13);
        this->Loginhead->TabIndex = 0;
        this->Loginhead->Text = L"Login";
        // 
        // UserDashboardTab
        // 
        this->UserDashboardTab->Controls->Add(this->tableLayoutPanel1);
        this->UserDashboardTab->Controls->Add(this->userdashboardhead);
        this->UserDashboardTab->Location = System::Drawing::Point(4, 22);
        this->UserDashboardTab->Name = L"UserDashboardTab";
        this->UserDashboardTab->Padding = System::Windows::Forms::Padding(3);
        this->UserDashboardTab->Size = System::Drawing::Size(1493, 730);
        this->UserDashboardTab->TabIndex = 3;
        this->UserDashboardTab->Text = L"User Dashboard";
        this->UserDashboardTab->UseVisualStyleBackColor = true;
        // 
        // tableLayoutPanel1
        // 
        this->tableLayoutPanel1->ColumnCount = 4;
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            31.69203F)));
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            35.16988F)));
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            33.14968F)));
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
            365)));
        this->tableLayoutPanel1->Controls->Add(this->billingdetailsubhead, 2, 0);
        this->tableLayoutPanel1->Controls->Add(this->doctordetailsubhead, 1, 0);
        this->tableLayoutPanel1->Controls->Add(this->patientdetailsubhead, 0, 0);
        this->tableLayoutPanel1->Controls->Add(this->feedbackdetailssubhead, 3, 0);
        this->tableLayoutPanel1->Controls->Add(this->patientdetailgroupbox, 0, 1);
        this->tableLayoutPanel1->Controls->Add(this->doctordetailsgroupbox, 1, 1);
        this->tableLayoutPanel1->Controls->Add(this->billingdetailsgroupbox, 2, 1);
        this->tableLayoutPanel1->Controls->Add(this->feedbackdetailsgroupbox, 3, 1);
        this->tableLayoutPanel1->Location = System::Drawing::Point(18, 56);
        this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
        this->tableLayoutPanel1->RowCount = 2;
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 631)));
        this->tableLayoutPanel1->Size = System::Drawing::Size(1456, 654);
        this->tableLayoutPanel1->TabIndex = 1;
        // 
        // billingdetailsubhead
        // 
        this->billingdetailsubhead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->billingdetailsubhead->AutoSize = true;
        this->billingdetailsubhead->Location = System::Drawing::Point(731, 0);
        this->billingdetailsubhead->Name = L"billingdetailsubhead";
        this->billingdetailsubhead->Size = System::Drawing::Size(355, 23);
        this->billingdetailsubhead->TabIndex = 3;
        this->billingdetailsubhead->Text = L"Billing Detail";
        this->billingdetailsubhead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // doctordetailsubhead
        // 
        this->doctordetailsubhead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordetailsubhead->AutoSize = true;
        this->doctordetailsubhead->Location = System::Drawing::Point(348, 0);
        this->doctordetailsubhead->Name = L"doctordetailsubhead";
        this->doctordetailsubhead->Size = System::Drawing::Size(377, 23);
        this->doctordetailsubhead->TabIndex = 2;
        this->doctordetailsubhead->Text = L"Doctor Details";
        this->doctordetailsubhead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // patientdetailsubhead
        // 
        this->patientdetailsubhead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->patientdetailsubhead->AutoSize = true;
        this->patientdetailsubhead->Location = System::Drawing::Point(3, 0);
        this->patientdetailsubhead->Name = L"patientdetailsubhead";
        this->patientdetailsubhead->Size = System::Drawing::Size(339, 23);
        this->patientdetailsubhead->TabIndex = 1;
        this->patientdetailsubhead->Text = L"Patient Details";
        this->patientdetailsubhead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // feedbackdetailssubhead
        // 
        this->feedbackdetailssubhead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->feedbackdetailssubhead->AutoSize = true;
        this->feedbackdetailssubhead->Location = System::Drawing::Point(1092, 0);
        this->feedbackdetailssubhead->Name = L"feedbackdetailssubhead";
        this->feedbackdetailssubhead->Size = System::Drawing::Size(361, 23);
        this->feedbackdetailssubhead->TabIndex = 0;
        this->feedbackdetailssubhead->Text = L"Feedback Detail";
        this->feedbackdetailssubhead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // patientdetailgroupbox
        // 
        this->patientdetailgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->patientdetailgroupbox->AutoSize = true;
        this->patientdetailgroupbox->Location = System::Drawing::Point(3, 26);
        this->patientdetailgroupbox->Name = L"patientdetailgroupbox";
        this->patientdetailgroupbox->Size = System::Drawing::Size(339, 625);
        this->patientdetailgroupbox->TabIndex = 4;
        this->patientdetailgroupbox->TabStop = false;
        // 
        // doctordetailsgroupbox
        // 
        this->doctordetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordetailsgroupbox->AutoSize = true;
        this->doctordetailsgroupbox->Location = System::Drawing::Point(348, 26);
        this->doctordetailsgroupbox->Name = L"doctordetailsgroupbox";
        this->doctordetailsgroupbox->Size = System::Drawing::Size(377, 625);
        this->doctordetailsgroupbox->TabIndex = 5;
        this->doctordetailsgroupbox->TabStop = false;
        // 
        // billingdetailsgroupbox
        // 
        this->billingdetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->billingdetailsgroupbox->AutoSize = true;
        this->billingdetailsgroupbox->Location = System::Drawing::Point(731, 26);
        this->billingdetailsgroupbox->Name = L"billingdetailsgroupbox";
        this->billingdetailsgroupbox->Size = System::Drawing::Size(355, 625);
        this->billingdetailsgroupbox->TabIndex = 6;
        this->billingdetailsgroupbox->TabStop = false;
        // 
        // feedbackdetailsgroupbox
        // 
        this->feedbackdetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->feedbackdetailsgroupbox->AutoSize = true;
        this->feedbackdetailsgroupbox->Location = System::Drawing::Point(1092, 26);
        this->feedbackdetailsgroupbox->Name = L"feedbackdetailsgroupbox";
        this->feedbackdetailsgroupbox->Size = System::Drawing::Size(361, 625);
        this->feedbackdetailsgroupbox->TabIndex = 7;
        this->feedbackdetailsgroupbox->TabStop = false;
        // 
        // userdashboardhead
        // 
        this->userdashboardhead->AutoSize = true;
        this->userdashboardhead->Location = System::Drawing::Point(702, 20);
        this->userdashboardhead->Name = L"userdashboardhead";
        this->userdashboardhead->Size = System::Drawing::Size(84, 13);
        this->userdashboardhead->TabIndex = 0;
        this->userdashboardhead->Text = L"User Dashboard";
        // 
        // doctordashboardtab
        // 
        this->doctordashboardtab->Controls->Add(this->tableLayoutPanel2);
        this->doctordashboardtab->Controls->Add(this->doctordashboardhead);
        this->doctordashboardtab->Location = System::Drawing::Point(4, 22);
        this->doctordashboardtab->Name = L"doctordashboardtab";
        this->doctordashboardtab->Padding = System::Windows::Forms::Padding(3);
        this->doctordashboardtab->Size = System::Drawing::Size(1493, 730);
        this->doctordashboardtab->TabIndex = 4;
        this->doctordashboardtab->Text = L"Doctor Dashboard";
        this->doctordashboardtab->UseVisualStyleBackColor = true;
        // 
        // doctordashboardhead
        // 
        this->doctordashboardhead->AutoSize = true;
        this->doctordashboardhead->Location = System::Drawing::Point(705, 14);
        this->doctordashboardhead->Name = L"doctordashboardhead";
        this->doctordashboardhead->Size = System::Drawing::Size(94, 13);
        this->doctordashboardhead->TabIndex = 0;
        this->doctordashboardhead->Text = L"Doctor Dashboard";
        // 
        // billingtab
        // 
        this->billingtab->Controls->Add(this->addbill);
        this->billingtab->Controls->Add(this->paidamounttextbox);
        this->billingtab->Controls->Add(this->paidamountlabel);
        this->billingtab->Controls->Add(this->totalamounttextbox);
        this->billingtab->Controls->Add(this->totalamount);
        this->billingtab->Controls->Add(this->billpatientnamedropdown);
        this->billingtab->Controls->Add(this->patientbilllabel);
        this->billingtab->Controls->Add(this->BillingHead);
        this->billingtab->Location = System::Drawing::Point(4, 22);
        this->billingtab->Name = L"billingtab";
        this->billingtab->Padding = System::Windows::Forms::Padding(3);
        this->billingtab->Size = System::Drawing::Size(1493, 583);
        this->billingtab->TabIndex = 5;
        this->billingtab->Text = L"Billing ";
        this->billingtab->UseVisualStyleBackColor = true;
        // 
        // addbill
        // 
        this->addbill->Location = System::Drawing::Point(335, 293);
        this->addbill->Name = L"addbill";
        this->addbill->Size = System::Drawing::Size(75, 23);
        this->addbill->TabIndex = 7;
        this->addbill->Text = L"Add Bill";
        this->addbill->UseVisualStyleBackColor = true;
        this->addbill->Click += gcnew System::EventHandler(this, &Form1::addbill_Click);
        // 
        // paidamounttextbox
        // 
        this->paidamounttextbox->Location = System::Drawing::Point(245, 237);
        this->paidamounttextbox->Name = L"paidamounttextbox";
        this->paidamounttextbox->Size = System::Drawing::Size(100, 20);
        this->paidamounttextbox->TabIndex = 6;
        // 
        // paidamountlabel
        // 
        this->paidamountlabel->AutoSize = true;
        this->paidamountlabel->Location = System::Drawing::Point(150, 237);
        this->paidamountlabel->Name = L"paidamountlabel";
        this->paidamountlabel->Size = System::Drawing::Size(67, 13);
        this->paidamountlabel->TabIndex = 5;
        this->paidamountlabel->Text = L"Paid Amount";
        // 
        // totalamounttextbox
        // 
        this->totalamounttextbox->Location = System::Drawing::Point(236, 190);
        this->totalamounttextbox->Name = L"totalamounttextbox";
        this->totalamounttextbox->Size = System::Drawing::Size(100, 20);
        this->totalamounttextbox->TabIndex = 4;
        // 
        // totalamount
        // 
        this->totalamount->AutoSize = true;
        this->totalamount->Location = System::Drawing::Point(147, 190);
        this->totalamount->Name = L"totalamount";
        this->totalamount->Size = System::Drawing::Size(70, 13);
        this->totalamount->TabIndex = 3;
        this->totalamount->Text = L"Total Amount";
        // 
        // billpatientnamedropdown
        // 
        this->billpatientnamedropdown->FormattingEnabled = true;
        this->billpatientnamedropdown->Location = System::Drawing::Point(236, 136);
        this->billpatientnamedropdown->Name = L"billpatientnamedropdown";
        this->billpatientnamedropdown->Size = System::Drawing::Size(121, 21);
        this->billpatientnamedropdown->TabIndex = 2;
        // 
        // patientbilllabel
        // 
        this->patientbilllabel->AutoSize = true;
        this->patientbilllabel->Location = System::Drawing::Point(148, 145);
        this->patientbilllabel->Name = L"patientbilllabel";
        this->patientbilllabel->Size = System::Drawing::Size(71, 13);
        this->patientbilllabel->TabIndex = 1;
        this->patientbilllabel->Text = L"Patient Name";
        // 
        // BillingHead
        // 
        this->BillingHead->AutoSize = true;
        this->BillingHead->Location = System::Drawing::Point(366, 56);
        this->BillingHead->Name = L"BillingHead";
        this->BillingHead->Size = System::Drawing::Size(34, 13);
        this->BillingHead->TabIndex = 0;
        this->BillingHead->Text = L"Billing";
        // 
        // feedbacktab
        // 
        this->feedbacktab->Controls->Add(this->addfeedbackbutton);
        this->feedbacktab->Controls->Add(this->feedbackselectionbox);
        this->feedbacktab->Controls->Add(this->feedbackdoctordropdown);
        this->feedbacktab->Controls->Add(this->feedbackdoctorlabel);
        this->feedbacktab->Controls->Add(this->feedbackhead);
        this->feedbacktab->Location = System::Drawing::Point(4, 22);
        this->feedbacktab->Name = L"feedbacktab";
        this->feedbacktab->Padding = System::Windows::Forms::Padding(3);
        this->feedbacktab->Size = System::Drawing::Size(1493, 583);
        this->feedbacktab->TabIndex = 6;
        this->feedbacktab->Text = L"Feedback";
        this->feedbacktab->UseVisualStyleBackColor = true;
        // 
        // addfeedbackbutton
        // 
        this->addfeedbackbutton->Location = System::Drawing::Point(378, 328);
        this->addfeedbackbutton->Name = L"addfeedbackbutton";
        this->addfeedbackbutton->Size = System::Drawing::Size(181, 23);
        this->addfeedbackbutton->TabIndex = 4;
        this->addfeedbackbutton->Text = L"Give Feedback";
        this->addfeedbackbutton->UseVisualStyleBackColor = true;
        this->addfeedbackbutton->Click += gcnew System::EventHandler(this, &Form1::addfeedbackbutton_Click);
        // 
        // feedbackselectionbox
        // 
        this->feedbackselectionbox->Controls->Add(this->badradio);
        this->feedbackselectionbox->Controls->Add(this->goodradio);
        this->feedbackselectionbox->Controls->Add(this->excellentradio);
        this->feedbackselectionbox->Controls->Add(this->remarkableradio);
        this->feedbackselectionbox->Location = System::Drawing::Point(197, 209);
        this->feedbackselectionbox->Name = L"feedbackselectionbox";
        this->feedbackselectionbox->Size = System::Drawing::Size(484, 100);
        this->feedbackselectionbox->TabIndex = 3;
        this->feedbackselectionbox->TabStop = false;
        this->feedbackselectionbox->Text = L"Choose one";
        // 
        // badradio
        // 
        this->badradio->AutoSize = true;
        this->badradio->Location = System::Drawing::Point(195, 57);
        this->badradio->Name = L"badradio";
        this->badradio->Size = System::Drawing::Size(44, 17);
        this->badradio->TabIndex = 3;
        this->badradio->TabStop = true;
        this->badradio->Text = L"Bad";
        this->badradio->UseVisualStyleBackColor = true;
        // 
        // goodradio
        // 
        this->goodradio->AutoSize = true;
        this->goodradio->Location = System::Drawing::Point(342, 19);
        this->goodradio->Name = L"goodradio";
        this->goodradio->Size = System::Drawing::Size(51, 17);
        this->goodradio->TabIndex = 2;
        this->goodradio->TabStop = true;
        this->goodradio->Text = L"Good";
        this->goodradio->UseVisualStyleBackColor = true;
        // 
        // excellentradio
        // 
        this->excellentradio->AutoSize = true;
        this->excellentradio->Location = System::Drawing::Point(181, 20);
        this->excellentradio->Name = L"excellentradio";
        this->excellentradio->Size = System::Drawing::Size(68, 17);
        this->excellentradio->TabIndex = 1;
        this->excellentradio->TabStop = true;
        this->excellentradio->Text = L"Excellent";
        this->excellentradio->UseVisualStyleBackColor = true;
        // 
        // remarkableradio
        // 
        this->remarkableradio->AutoSize = true;
        this->remarkableradio->Location = System::Drawing::Point(32, 20);
        this->remarkableradio->Name = L"remarkableradio";
        this->remarkableradio->Size = System::Drawing::Size(82, 17);
        this->remarkableradio->TabIndex = 0;
        this->remarkableradio->TabStop = true;
        this->remarkableradio->Text = L"Remarkable";
        this->remarkableradio->UseVisualStyleBackColor = true;
        // 
        // feedbackdoctordropdown
        // 
        this->feedbackdoctordropdown->FormattingEnabled = true;
        this->feedbackdoctordropdown->Location = System::Drawing::Point(229, 132);
        this->feedbackdoctordropdown->Name = L"feedbackdoctordropdown";
        this->feedbackdoctordropdown->Size = System::Drawing::Size(300, 21);
        this->feedbackdoctordropdown->TabIndex = 2;
        // 
        // feedbackdoctorlabel
        // 
        this->feedbackdoctorlabel->AutoSize = true;
        this->feedbackdoctorlabel->Location = System::Drawing::Point(112, 135);
        this->feedbackdoctorlabel->Name = L"feedbackdoctorlabel";
        this->feedbackdoctorlabel->Size = System::Drawing::Size(70, 13);
        this->feedbackdoctorlabel->TabIndex = 1;
        this->feedbackdoctorlabel->Text = L"Doctor Name";
        // 
        // feedbackhead
        // 
        this->feedbackhead->AutoSize = true;
        this->feedbackhead->Location = System::Drawing::Point(325, 73);
        this->feedbackhead->Name = L"feedbackhead";
        this->feedbackhead->Size = System::Drawing::Size(55, 13);
        this->feedbackhead->TabIndex = 0;
        this->feedbackhead->Text = L"Feedback";
        // 
        // tableLayoutPanel2
        // 
        this->tableLayoutPanel2->ColumnCount = 3;
        this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            50)));
        this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            50)));
        this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
            487)));
        this->tableLayoutPanel2->Controls->Add(this->patientdetailssubheaddoctortab, 0, 0);
        this->tableLayoutPanel2->Controls->Add(this->doctordetailssubheaddoctortab, 1, 0);
        this->tableLayoutPanel2->Controls->Add(this->billingdetailssubheaddoctortab, 2, 0);
        this->tableLayoutPanel2->Controls->Add(this->doctordashboardpatientdetailsgroupbox, 0, 1);
        this->tableLayoutPanel2->Controls->Add(this->doctordashboarddoctordetailsgroupbox, 1, 1);
        this->tableLayoutPanel2->Controls->Add(this->doctordashboardbillingdetailsgroupbox, 2, 1);
        this->tableLayoutPanel2->Location = System::Drawing::Point(6, 68);
        this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
        this->tableLayoutPanel2->RowCount = 2;
        this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 6.25F)));
        this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 93.75F)));
        this->tableLayoutPanel2->Size = System::Drawing::Size(1481, 656);
        this->tableLayoutPanel2->TabIndex = 1;
        // 
        // patientdetailssubheaddoctortab
        // 
        this->patientdetailssubheaddoctortab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->patientdetailssubheaddoctortab->AutoSize = true;
        this->patientdetailssubheaddoctortab->Location = System::Drawing::Point(3, 0);
        this->patientdetailssubheaddoctortab->Name = L"patientdetailssubheaddoctortab";
        this->patientdetailssubheaddoctortab->Size = System::Drawing::Size(491, 41);
        this->patientdetailssubheaddoctortab->TabIndex = 0;
        this->patientdetailssubheaddoctortab->Text = L"Patient Details";
        this->patientdetailssubheaddoctortab->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // doctordetailssubheaddoctortab
        // 
        this->doctordetailssubheaddoctortab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordetailssubheaddoctortab->AutoSize = true;
        this->doctordetailssubheaddoctortab->Location = System::Drawing::Point(500, 0);
        this->doctordetailssubheaddoctortab->Name = L"doctordetailssubheaddoctortab";
        this->doctordetailssubheaddoctortab->Size = System::Drawing::Size(491, 41);
        this->doctordetailssubheaddoctortab->TabIndex = 1;
        this->doctordetailssubheaddoctortab->Text = L"Doctor Details";
        this->doctordetailssubheaddoctortab->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // billingdetailssubheaddoctortab
        // 
        this->billingdetailssubheaddoctortab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->billingdetailssubheaddoctortab->AutoSize = true;
        this->billingdetailssubheaddoctortab->Location = System::Drawing::Point(997, 0);
        this->billingdetailssubheaddoctortab->Name = L"billingdetailssubheaddoctortab";
        this->billingdetailssubheaddoctortab->Size = System::Drawing::Size(481, 41);
        this->billingdetailssubheaddoctortab->TabIndex = 2;
        this->billingdetailssubheaddoctortab->Text = L"Billing Details";
        this->billingdetailssubheaddoctortab->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // doctordashboardpatientdetailsgroupbox
        // 
        this->doctordashboardpatientdetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordashboardpatientdetailsgroupbox->AutoSize = true;
        this->doctordashboardpatientdetailsgroupbox->Location = System::Drawing::Point(3, 44);
        this->doctordashboardpatientdetailsgroupbox->Name = L"doctordashboardpatientdetailsgroupbox";
        this->doctordashboardpatientdetailsgroupbox->Size = System::Drawing::Size(491, 609);
        this->doctordashboardpatientdetailsgroupbox->TabIndex = 3;
        this->doctordashboardpatientdetailsgroupbox->TabStop = false;
        // 
        // doctordashboarddoctordetailsgroupbox
        // 
        this->doctordashboarddoctordetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordashboarddoctordetailsgroupbox->AutoSize = true;
        this->doctordashboarddoctordetailsgroupbox->Location = System::Drawing::Point(500, 44);
        this->doctordashboarddoctordetailsgroupbox->Name = L"doctordashboarddoctordetailsgroupbox";
        this->doctordashboarddoctordetailsgroupbox->Size = System::Drawing::Size(491, 609);
        this->doctordashboarddoctordetailsgroupbox->TabIndex = 4;
        this->doctordashboarddoctordetailsgroupbox->TabStop = false;
        // 
        // doctordashboardbillingdetailsgroupbox
        // 
        this->doctordashboardbillingdetailsgroupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->doctordashboardbillingdetailsgroupbox->AutoSize = true;
        this->doctordashboardbillingdetailsgroupbox->Location = System::Drawing::Point(997, 44);
        this->doctordashboardbillingdetailsgroupbox->Name = L"doctordashboardbillingdetailsgroupbox";
        this->doctordashboardbillingdetailsgroupbox->Size = System::Drawing::Size(481, 609);
        this->doctordashboardbillingdetailsgroupbox->TabIndex = 5;
        this->doctordashboardbillingdetailsgroupbox->TabStop = false;
        // 
        // Form1
        // 
        this->ClientSize = System::Drawing::Size(1525, 876);
        this->Controls->Add(this->tabControl1);
        this->Name = L"Form1";
        this->tabControl1->ResumeLayout(false);
        this->doctor->ResumeLayout(false);
        this->doctor->PerformLayout();
        this->Patient->ResumeLayout(false);
        this->Patient->PerformLayout();
        this->LoginTab->ResumeLayout(false);
        this->LoginTab->PerformLayout();
        this->selectionbox->ResumeLayout(false);
        this->selectionbox->PerformLayout();
        this->UserDashboardTab->ResumeLayout(false);
        this->UserDashboardTab->PerformLayout();
        this->tableLayoutPanel1->ResumeLayout(false);
        this->tableLayoutPanel1->PerformLayout();
        this->doctordashboardtab->ResumeLayout(false);
        this->doctordashboardtab->PerformLayout();
        this->billingtab->ResumeLayout(false);
        this->billingtab->PerformLayout();
        this->feedbacktab->ResumeLayout(false);
        this->feedbacktab->PerformLayout();
        this->feedbackselectionbox->ResumeLayout(false);
        this->feedbackselectionbox->PerformLayout();
        this->tableLayoutPanel2->ResumeLayout(false);
        this->tableLayoutPanel2->PerformLayout();
        this->ResumeLayout(false);

    }



#pragma endregion

    /// <Doctor summary>
    /// Doctor Tab Functions Logic we are separating the logic of these functions into separate DoctorManage.h file
    /// so that we can achieve abstraction and also readabillity
    /// 
     private: void LoadDoctorNames() {
         try {
             //this is for Removing existing something in the comobo box
             deletedoctorcombobox->Items->Clear();

             //Load karne ke liye names doctor ke tab me like yahan call kiya hai humber apna method ko
             List<String^>^ doctorNames = doctorManager->LoadDoctorNames();

             // get krne ke badd jo upr kiya uske baad hukein list arahi doctor names ku unko for each loop laga kar combo
             //box me one render kardiya hai 
             for each (String ^ doctorName in doctorNames) {
                 deletedoctorcombobox->Items->Add(doctorName);
             }
         }
         catch (Exception^ ex) {
             MessageBox::Show("Error loading doctor names: " + ex->Message);
         }
     }


    private: System::Void adddoctor_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ doctorName = doctornametextfield->Text;
        String^ specialization = specializationtextfield->Text;
        String^ availableHours = availablehourstextfield->Text;

        try {
            doctorManager->SaveDoctor(doctorName, specialization, availableHours);
            MessageBox::Show("Doctor details saved successfully!");
            doctornametextfield->Text = "";
            specializationtextfield->Text = "";
            availablehourstextfield->Text = "";

            LoadDoctorNames();
            LoadDoctorNamesIntoFeedbackComboBox();
        }
        catch (ArgumentException^ argEx) {
            MessageBox::Show(argEx->Message);
        }
        catch (InvalidOperationException^ ioEx) {
            MessageBox::Show(ioEx->Message);
        }
    }


    private: System::Void deleteDoctor_Click(System::Object^ sender, System::EventArgs^ e) {
        // Yhan pr jab user doctor name select kare ga woh doctor name get kar rahe hain
        String^ doctorName = deletedoctorcombobox->SelectedItem == nullptr
            ? nullptr
            : deletedoctorcombobox->SelectedItem->ToString();

        if (String::IsNullOrWhiteSpace(doctorName)) {
            MessageBox::Show("Please select a doctor to delete.");
           
            return;
        }

        try {
            // idhar humne deletedoctordetails ka method call kiya aur usko argument pass kardiya doctorName to delete the doctor 
            doctorManager->DeleteDoctor(doctorName);
            MessageBox::Show("Doctor details deleted successfully!");
            deletedoctorcombobox->SelectedIndex = -1;
            LoadDoctorNames(); // Yahan pr Referesh kar rahe 
        }
        /*catch (ArgumentException^ argEx) {
            MessageBox::Show(argEx->Message);
        }*/
        catch (InvalidOperationException^ ioEx) {
            MessageBox::Show(ioEx->Message);
        }
    }

   /// </Doctor summary>


   ////<PatientSummary>
           private: System::Void addPatientButton_Click(System::Object^ sender, System::EventArgs^ e) {
               String^ name = patientnametextbox->Text;
               String^ disease = diseasetextbox->Text;
               String^ contact = contactnumbertextbox->Text;

               try {
                   patientManager->SavePatient(name, disease, contact);
                   MessageBox::Show("Patient added successfully!");

                   patientnametextbox->Text = "";
                   diseasetextbox->Text = "";
                   contactnumbertextbox->Text = "";
                 
                   LoadPatientNames();

                   LoadPatientNamesIntoComboBox();
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message);
               }
           }


                  private: System::Void deletePatientButton_Click(System::Object^ sender, System::EventArgs^ e) {
                      String^ name = deletepatientcombobox->SelectedItem == nullptr
                          ? nullptr
                          : deletepatientcombobox->SelectedItem->ToString();

                      try {
                          patientManager->DeletePatient(name);
                          MessageBox::Show("Patient deleted successfully!");
                          deletepatientcombobox->SelectedIndex = -1;
                          LoadPatientNames();
                      }
                      catch (Exception^ ex) {
                          MessageBox::Show(ex->Message);
                      }
                  }

                         private: void LoadPatientNames() {
                             try {
                                 deletepatientcombobox->Items->Clear();
                                 List<String^>^ names = patientManager->LoadPatientNames();
                                 for each (String ^ name in names) {
                                     deletepatientcombobox->Items->Add(name);
                                 }
                             }
                             catch (Exception^ ex) {
                                 MessageBox::Show(ex->Message);
                             }
                         }

   ////<PatientSummary>

/// <Loginummary>
private:void loginButton_Click(Object^ sender, EventArgs^ e) {
    String^ email = emailtextbox->Text;
    String^ password = passwordtextbox->Text;

    String^ role = doctorradio->Checked ? "doctor" : "user";

    // Create LoginHandler instance with file path for credentials
    LoginHandler^ loginHandler = gcnew LoginHandler("Credentials.txt");

    // Verify login credentials
    bool loginSuccess = loginHandler->VerifyLogin(email, password, role);

    if (loginSuccess)
    {
        tabControl1->TabPages->Remove(LoginTab);

        if (role == "doctor")
        {
            tabControl1->TabPages->Add(doctor);
            tabControl1->TabPages->Add(Patient);
            tabControl1->TabPages->Add(billingtab);
            tabControl1->TabPages->Add(doctordashboardtab);
            
        }
        else if (role == "user")
        {
            tabControl1->TabPages->Add(feedbacktab);
            tabControl1->TabPages->Add(UserDashboardTab);
            

        }
        MessageBox::Show("Login successful!");
    }
    else
    {
        MessageBox::Show("Invalid credentials. Please try again.");
    }
}

       private: System::Void logoutbutton_Click(System::Object^ sender, System::EventArgs^ e)
       {
           // Hide all tabs except the login tab
           tabControl1->TabPages->Clear();
           tabControl1->TabPages->Add(LoginTab);
       }

/// </Loginummary>

              ///<BIlling Summary>
                        private: void LoadPatientNamesIntoComboBox() {
                            try {
                                billpatientnamedropdown->Items->Clear();
                                List<String^>^ names = patientManager->LoadPatientNames();
                                for each (String ^ name in names) {
                                    billpatientnamedropdown->Items->Add(name);
                                }
                            }
                            catch (Exception^ ex) {
                                MessageBox::Show("Error loading patient names: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                            }
                        }

                             private: System::Void addbill_Click(System::Object^ sender, System::EventArgs^ e) {
                                 String^ selectedPatient = billpatientnamedropdown->Text;
                                 String^ totalAmount = totalamounttextbox->Text;
                                 String^ paidAmount = paidamounttextbox->Text;

                                 if (String::IsNullOrWhiteSpace(selectedPatient) ||
                                     String::IsNullOrWhiteSpace(totalAmount) ||
                                     String::IsNullOrWhiteSpace(paidAmount)) {
                                     MessageBox::Show("Please fill in all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                     return;
                                 }

                                 BillingManager^ billingManager = gcnew BillingManager();

                                 try {
                                     billingManager->SaveBilling(selectedPatient, totalAmount, paidAmount);
                                     MessageBox::Show("Billing details saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                                     totalamounttextbox->Text = "";
                                     paidamounttextbox->Text = "";
                                     billpatientnamedropdown->SelectedIndex = -1;
                                 }
                                 catch (InvalidOperationException^ ex) {
                                     MessageBox::Show("Error: " + ex->Message, "Duplicate Entry", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                 }
                                 catch (Exception^ ex) {
                                     MessageBox::Show("Error saving billing details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                                 }
                             }

              ///<BIlling Summary>

                                    ////<Feedback Summary>
                                        private: void LoadDoctorNamesIntoFeedbackComboBox() {
                                            try {
                                                feedbackdoctordropdown->Items->Clear();
                                                List<String^>^ names = doctorManager->LoadDoctorNames();
                                                for each (String ^ name in names) {
                                                    feedbackdoctordropdown->Items->Add(name);
                                                }
                                            }
                                            catch (Exception^ ex) {
                                                MessageBox::Show("Error loading doctor names: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                                            }
                                        }

                                               private: System::Void addfeedbackbutton_Click(System::Object^ sender, System::EventArgs^ e) {
                                                   // Get the selected doctor and feedback rating
                                                   String^ selectedDoctor = this->feedbackdoctordropdown->SelectedItem->ToString();
                                                   String^ feedbackRating = "";

                                                   if (this->remarkableradio->Checked) {
                                                       feedbackRating = "Remarkable";
                                                   }
                                                   else if (this->excellentradio->Checked) {
                                                       feedbackRating = "Excellent";
                                                   }
                                                   else if (this->goodradio->Checked) {
                                                       feedbackRating = "Good";
                                                   }
                                                   else if (this->badradio->Checked) {
                                                       feedbackRating = "Bad";
                                                   }

                                                   // Ensure both doctor and feedback are selected
                                                   if (selectedDoctor == nullptr || feedbackRating == "") {
                                                       MessageBox::Show("Please select both a doctor and a feedback rating.");
                                                       return;
                                                   }

                                                   // Create an instance of FeedbackManager and save feedback
                                                   FeedbackManager^ feedbackManager = gcnew FeedbackManager("feedback.txt");
                                                   try {
                                                       feedbackManager->SaveFeedback(selectedDoctor, feedbackRating);
                                                       MessageBox::Show("Feedback saved successfully!");
                                                       this->feedbackdoctordropdown->SelectedIndex = -1;  // Clears the selection

                                                       // Uncheck all the RadioButtons
                                                       this->remarkableradio->Checked = false;
                                                       this->excellentradio->Checked = false;
                                                       this->goodradio->Checked = false;
                                                       this->badradio->Checked = false;
                                                   }
                                                   catch (Exception^ ex) {
                                                       MessageBox::Show("Error: " + ex->Message);
                                                   }
                                               }

                                    ////<Feedback Summary>


                                                      /// <summary>
                                                      /// Dashboard data loading function
                                                      ///                                              
                                                      ///        /// </summary>
                                                      void LoadData()
                                                      {
                                                          try {
                                                              // Initialize DataHandler for each category of data
                                                              DataHandler^ patientDataHandler = gcnew DataHandler("PatientDetails.txt");
                                                              DataHandler^ doctorDataHandler = gcnew DataHandler("DoctorDetails.txt");
                                                              DataHandler^ billingDataHandler = gcnew DataHandler("BillingDetails.txt");
                                                              DataHandler^ feedbackDataHandler = gcnew DataHandler("feedback.txt");

                                                              // Load data from the files
                                                              List<String^>^ patientData = patientDataHandler->LoadDetails();
                                                              List<String^>^ doctorData = doctorDataHandler->LoadDetails();
                                                              List<String^>^ billingData = billingDataHandler->LoadDetails();
                                                              List<String^>^ feedbackData = feedbackDataHandler->LoadDetails();

                                                              // Populate GroupBoxes with the loaded data
                                                              PopulateGroupBox(this->patientdetailgroupbox, patientData);
                                                              PopulateGroupBox(this->doctordetailsgroupbox, doctorData);
                                                              PopulateGroupBox(this->billingdetailsgroupbox, billingData);
                                                              PopulateGroupBox(this->feedbackdetailsgroupbox, feedbackData);
                                                              PopulateGroupBox(this->doctordashboardpatientdetailsgroupbox, patientData);
                                                              PopulateGroupBox(this->doctordashboarddoctordetailsgroupbox, doctorData);
                                                              PopulateGroupBox(this->doctordashboardbillingdetailsgroupbox, billingData);
                                                          }
                                                          catch (Exception^ ex) {
                                                              MessageBox::Show("Error: " + ex->Message, "Data Loading Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                                                          }
                                                      }

                                                      void PopulateGroupBox(GroupBox^ groupBox, List<String^>^ data)
                                                      {
                                                          int yPosition = 20;

                                                          for each (String ^ line in data) {
                                                              Label^ label = gcnew Label();
                                                              label->Text = line;
                                                              label->Location = Point(10, yPosition);
                                                              label->AutoSize = true;

                                                              groupBox->Controls->Add(label);
                                                              yPosition += 25;  // Adjust label spacing
                                                          }
                                                      }



                                                      /// Dashboard data loading function
                                                      ///                                                      /// </summary>

};
} 
