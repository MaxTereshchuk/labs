#pragma once
#include "trains.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>

namespace laba77 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	int trainNumber;
	std::string destination;
	std::string departureTime;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ text_write1;
	private: System::Windows::Forms::TextBox^ text_write2;
	private: System::Windows::Forms::TextBox^ text_write3;
	protected:


	private: System::Windows::Forms::Label^ label_write1;
	private: System::Windows::Forms::Label^ label_name_file;
	private: System::Windows::Forms::TextBox^ text_name_file;
	private: System::Windows::Forms::Label^ label_file1;
	private: System::Windows::Forms::Label^ label_write2;
	private: System::Windows::Forms::Label^ label_write3;
	private: System::Windows::Forms::Label^ label_out;
	private: System::Windows::Forms::TextBox^ text_out1;
	private: System::Windows::Forms::Button^ button_write;
	private: System::Windows::Forms::Button^ button_open;
	private: System::Windows::Forms::Label^ City;
	private: System::Windows::Forms::TextBox^ text_city;
	private: System::Windows::Forms::Label^ label_race;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button_search;
	private: System::Windows::Forms::Button^ button_clear;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->text_write1 = (gcnew System::Windows::Forms::TextBox());
			this->text_write2 = (gcnew System::Windows::Forms::TextBox());
			this->text_write3 = (gcnew System::Windows::Forms::TextBox());
			this->label_write1 = (gcnew System::Windows::Forms::Label());
			this->label_name_file = (gcnew System::Windows::Forms::Label());
			this->text_name_file = (gcnew System::Windows::Forms::TextBox());
			this->label_file1 = (gcnew System::Windows::Forms::Label());
			this->label_write2 = (gcnew System::Windows::Forms::Label());
			this->label_write3 = (gcnew System::Windows::Forms::Label());
			this->label_out = (gcnew System::Windows::Forms::Label());
			this->text_out1 = (gcnew System::Windows::Forms::TextBox());
			this->button_write = (gcnew System::Windows::Forms::Button());
			this->button_open = (gcnew System::Windows::Forms::Button());
			this->City = (gcnew System::Windows::Forms::Label());
			this->text_city = (gcnew System::Windows::Forms::TextBox());
			this->label_race = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// text_write1
			// 
			this->text_write1->Location = System::Drawing::Point(17, 122);
			this->text_write1->Name = L"text_write1";
			this->text_write1->Size = System::Drawing::Size(100, 20);
			this->text_write1->TabIndex = 0;
			this->text_write1->TextChanged += gcnew System::EventHandler(this, &MyForm::text_write1_TextChanged);
			// 
			// text_write2
			// 
			this->text_write2->Location = System::Drawing::Point(17, 181);
			this->text_write2->Name = L"text_write2";
			this->text_write2->Size = System::Drawing::Size(100, 20);
			this->text_write2->TabIndex = 1;
			this->text_write2->TextChanged += gcnew System::EventHandler(this, &MyForm::text_write2_TextChanged);
			// 
			// text_write3
			// 
			this->text_write3->Location = System::Drawing::Point(17, 242);
			this->text_write3->Name = L"text_write3";
			this->text_write3->Size = System::Drawing::Size(100, 20);
			this->text_write3->TabIndex = 2;
			this->text_write3->TextChanged += gcnew System::EventHandler(this, &MyForm::text_write3_TextChanged);
			// 
			// label_write1
			// 
			this->label_write1->AutoSize = true;
			this->label_write1->Location = System::Drawing::Point(28, 95);
			this->label_write1->Name = L"label_write1";
			this->label_write1->Size = System::Drawing::Size(79, 13);
			this->label_write1->TabIndex = 3;
			this->label_write1->Text = L"Номер поїзду:";
			this->label_write1->Click += gcnew System::EventHandler(this, &MyForm::label_write1_Click);
			// 
			// label_name_file
			// 
			this->label_name_file->AutoSize = true;
			this->label_name_file->Location = System::Drawing::Point(217, 9);
			this->label_name_file->Name = L"label_name_file";
			this->label_name_file->Size = System::Drawing::Size(103, 13);
			this->label_name_file->TabIndex = 4;
			this->label_name_file->Text = L"Введіть ім\'я файлу:";
			// 
			// text_name_file
			// 
			this->text_name_file->Location = System::Drawing::Point(220, 41);
			this->text_name_file->Name = L"text_name_file";
			this->text_name_file->Size = System::Drawing::Size(100, 20);
			this->text_name_file->TabIndex = 5;
			this->text_name_file->TextChanged += gcnew System::EventHandler(this, &MyForm::text_name_file_TextChanged);
			// 
			// label_file1
			// 
			this->label_file1->AutoSize = true;
			this->label_file1->Location = System::Drawing::Point(11, 58);
			this->label_file1->Name = L"label_file1";
			this->label_file1->Size = System::Drawing::Size(106, 13);
			this->label_file1->TabIndex = 6;
			this->label_file1->Text = L"Введіть дані в файл";
			// 
			// label_write2
			// 
			this->label_write2->AutoSize = true;
			this->label_write2->Location = System::Drawing::Point(9, 154);
			this->label_write2->Name = L"label_write2";
			this->label_write2->Size = System::Drawing::Size(108, 13);
			this->label_write2->TabIndex = 7;
			this->label_write2->Text = L"Пункт призначення:";
			// 
			// label_write3
			// 
			this->label_write3->AutoSize = true;
			this->label_write3->Location = System::Drawing::Point(16, 215);
			this->label_write3->Name = L"label_write3";
			this->label_write3->Size = System::Drawing::Size(101, 13);
			this->label_write3->TabIndex = 8;
			this->label_write3->Text = L"Час відправлення:";
			// 
			// label_out
			// 
			this->label_out->AutoSize = true;
			this->label_out->Location = System::Drawing::Point(400, 58);
			this->label_out->Name = L"label_out";
			this->label_out->Size = System::Drawing::Size(76, 13);
			this->label_out->TabIndex = 9;
			this->label_out->Text = L"Дані з файлу:";
			// 
			// text_out1
			// 
			this->text_out1->Location = System::Drawing::Point(351, 122);
			this->text_out1->Multiline = true;
			this->text_out1->Name = L"text_out1";
			this->text_out1->Size = System::Drawing::Size(170, 167);
			this->text_out1->TabIndex = 10;
			this->text_out1->TextChanged += gcnew System::EventHandler(this, &MyForm::text_out1_TextChanged);
			// 
			// button_write
			// 
			this->button_write->Location = System::Drawing::Point(26, 278);
			this->button_write->Name = L"button_write";
			this->button_write->Size = System::Drawing::Size(75, 23);
			this->button_write->TabIndex = 11;
			this->button_write->Text = L"Записати";
			this->button_write->UseVisualStyleBackColor = true;
			this->button_write->Click += gcnew System::EventHandler(this, &MyForm::button_write_Click);
			// 
			// button_open
			// 
			this->button_open->Location = System::Drawing::Point(231, 76);
			this->button_open->Name = L"button_open";
			this->button_open->Size = System::Drawing::Size(75, 23);
			this->button_open->TabIndex = 12;
			this->button_open->Text = L"Відкрити";
			this->button_open->UseVisualStyleBackColor = true;
			this->button_open->Click += gcnew System::EventHandler(this, &MyForm::button_open_Click);
			// 
			// City
			// 
			this->City->AutoSize = true;
			this->City->Location = System::Drawing::Point(9, 350);
			this->City->Name = L"City";
			this->City->Size = System::Drawing::Size(108, 13);
			this->City->TabIndex = 13;
			this->City->Text = L"Пункт призначення:";
			// 
			// text_city
			// 
			this->text_city->Location = System::Drawing::Point(123, 347);
			this->text_city->Name = L"text_city";
			this->text_city->Size = System::Drawing::Size(100, 20);
			this->text_city->TabIndex = 14;
			this->text_city->TextChanged += gcnew System::EventHandler(this, &MyForm::text_city_TextChanged);
			// 
			// label_race
			// 
			this->label_race->AutoSize = true;
			this->label_race->Location = System::Drawing::Point(11, 386);
			this->label_race->Name = L"label_race";
			this->label_race->Size = System::Drawing::Size(144, 13);
			this->label_race->TabIndex = 15;
			this->label_race->Text = L"Номер найпізнішого рейсу:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(161, 383);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(174, 20);
			this->textBox1->TabIndex = 16;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(245, 344);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(75, 23);
			this->button_search->TabIndex = 17;
			this->button_search->Text = L"Знайти";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_search_Click);
			// 
			// button_clear
			// 
			this->button_clear->Location = System::Drawing::Point(26, 12);
			this->button_clear->Name = L"button_clear";
			this->button_clear->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button_clear->Size = System::Drawing::Size(75, 23);
			this->button_clear->TabIndex = 18;
			this->button_clear->Text = L"Очистити";
			this->button_clear->UseVisualStyleBackColor = true;
			this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(522, 426);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label_race);
			this->Controls->Add(this->text_city);
			this->Controls->Add(this->City);
			this->Controls->Add(this->button_open);
			this->Controls->Add(this->button_write);
			this->Controls->Add(this->text_out1);
			this->Controls->Add(this->label_out);
			this->Controls->Add(this->label_write3);
			this->Controls->Add(this->label_write2);
			this->Controls->Add(this->label_file1);
			this->Controls->Add(this->text_name_file);
			this->Controls->Add(this->label_name_file);
			this->Controls->Add(this->label_write1);
			this->Controls->Add(this->text_write3);
			this->Controls->Add(this->text_write2);
			this->Controls->Add(this->text_write1);
			this->Name = L"MyForm";
			this->Text = L"Trains";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label_write1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button_open_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = text_name_file->Text;

	try {
		String^ fileContent = System::IO::File::ReadAllText(filePath);

		text_out1->Text = fileContent;

		MessageBox::Show("Файл відкрито.");
	}
	catch (Exception^ ex) {
		MessageBox::Show("Помилка при відкритті файлу: " + ex->Message);
	}
}
private: System::Void button_write_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ trainNumberText = text_write1->Text;
	std::string destination = msclr::interop::marshal_as<std::string>(text_write2->Text);
	std::string departureTime = msclr::interop::marshal_as<std::string>(text_write3->Text);

	int trainNumber;
	if (!Int32::TryParse(trainNumberText, trainNumber) || trainNumber <= 0) {
		MessageBox::Show("Некоректний номер рейсу. Будь ласка, введіть натуральне число.");
		return;
	}

	if (destination.empty()) {
		throw gcnew System::ArgumentException("Пункт призначення не може бути порожнім.");
	}

	try {
		System::DateTime::ParseExact(text_write3->Text, "HH:mm", nullptr);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Некоректний формат часу: " + ex->Message);
		return;
	}

	Train train(trainNumber, destination, departureTime);

	String^ filePath = text_name_file->Text;
	std::ofstream outputFile(msclr::interop::marshal_as<std::string>(filePath), std::ios::app);

	if (outputFile.is_open()) {
		outputFile << train.trainNumber << " " << train.destination << " " << train.departureTime << std::endl;

		outputFile.close();

		UpdateTextOut1();

		MessageBox::Show("Інформацію про поїзд було успішно записано у файл.");
	}
	else {
		MessageBox::Show("Помилка при відкритті файлу для запису.");
	}
}
private: System::Void text_out1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void text_write1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void text_write2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void text_write3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void text_name_file_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void text_city_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string destination = msclr::interop::marshal_as<std::string>(text_city->Text);

	int latestTrainNumber = FindLatestTrainNumber(destination);

	if (latestTrainNumber != -1) {
		textBox1->Text = latestTrainNumber.ToString();
	}
	else {
		textBox1->Text = "Помилка при пошуку рейсу";
	}
}
private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = text_name_file->Text;

	try {
		System::IO::File::WriteAllText(filePath, "");

		UpdateTextOut1();

		MessageBox::Show("Файл було успішно очищено.");
	}
	catch (Exception^ ex) {
		MessageBox::Show("Помилка при очищенні файлу: " + ex->Message);
	}
}
void UpdateTextOut1() {
	String^ filePath = text_name_file->Text;

	try {
		String^ fileContent = System::IO::File::ReadAllText(filePath);

		text_out1->Text = fileContent;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Помилка при відкритті файлу: " + ex->Message);
	}
	catch (FormatException^ ex) {
		MessageBox::Show("Некоректний формат часу в файлі: " + ex->Message);
	}
}
int FindLatestTrainNumber(const std::string& destination) {
	String^ filePath = text_name_file->Text;

	try {
		String^ fileContent = System::IO::File::ReadAllText(filePath);

		array<String^>^ lines = fileContent->Split('\n');

		int latestTrainNumber = -1;  
		std::string latestDepartureTime;  

		for each (String ^ line in lines) {
			std::string trainInfo = msclr::interop::marshal_as<std::string>(line);
			std::istringstream iss(trainInfo);

			int trainNumber;
			std::string trainDestination;
			std::string departureTime;

			if (iss >> trainNumber >> trainDestination >> departureTime) {
				if (trainDestination == destination) {
					if (departureTime > latestDepartureTime) {
						latestTrainNumber = trainNumber;
						latestDepartureTime = departureTime;
					}
				}
			}
		}

		return latestTrainNumber;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Помилка при відкритті файлу: " + ex->Message);
		return -1;
	}
}
};
}
