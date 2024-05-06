#pragma once
//#include "LinkedList.h"
#include "NewUserPhone.h"
#include "Parser.h"
//#include "Parser.h"

ref class Node;
ref class LinkedList;
//ref class NewUserPhone;
ref class UserData;
ref class Parser;

namespace Semestrovaya {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private:
		LinkedList^ list;

	public:
		MainWindow(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			OpenSCVFile();


		}

		void OpenSCVFile()
		{
			list = gcnew LinkedList();
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filename = openFileDialog1->FileName;
				Parser::GetDataFromCSV(list, filename);

			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CreateNewUser;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Apartament;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ House;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Street;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ CloseButton;
	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ SortBox1;
	private: System::Windows::Forms::ComboBox^ SortBox2;
	private: System::Windows::Forms::Button^ HelpButton;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::Button^ RemoveButton;


	private: System::Windows::Forms::RadioButton^ FrontListRadioButton;
	private: System::Windows::Forms::RadioButton^ ReverseListButton;
	private: System::Windows::Forms::RichTextBox^ RichBoxLastname;
	private: System::Windows::Forms::RichTextBox^ RichBoxPhone;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:




















	protected:




























	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CreateNewUser = (gcnew System::Windows::Forms::Button());
			this->Apartament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->House = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Street = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SortBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SortBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->HelpButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->RemoveButton = (gcnew System::Windows::Forms::Button());
			this->FrontListRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->ReverseListButton = (gcnew System::Windows::Forms::RadioButton());
			this->RichBoxLastname = (gcnew System::Windows::Forms::RichTextBox());
			this->RichBoxPhone = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// CreateNewUser
			// 
			this->CreateNewUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateNewUser->Location = System::Drawing::Point(12, 365);
			this->CreateNewUser->Name = L"CreateNewUser";
			this->CreateNewUser->Size = System::Drawing::Size(169, 60);
			this->CreateNewUser->TabIndex = 0;
			this->CreateNewUser->Text = L"Новый пользователь";
			this->CreateNewUser->UseVisualStyleBackColor = true;
			this->CreateNewUser->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_NewUserPhone);
			// 
			// Apartament
			// 
			this->Apartament->HeaderText = L"Квартира";
			this->Apartament->Name = L"Apartament";
			this->Apartament->ReadOnly = true;
			// 
			// House
			// 
			this->House->HeaderText = L"Дом";
			this->House->Name = L"House";
			this->House->ReadOnly = true;
			// 
			// Street
			// 
			this->Street->HeaderText = L"Улица";
			this->Street->Name = L"Street";
			this->Street->ReadOnly = true;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Телефон";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			// 
			// Year
			// 
			this->Year->HeaderText = L"Год установки телефона";
			this->Year->Name = L"Year";
			this->Year->ReadOnly = true;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"Фамилия";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->LastName,
					this->Year, this->Phone, this->Street, this->House, this->Apartament
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(661, 321);
			this->dataGridView1->TabIndex = 1;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->Location = System::Drawing::Point(706, 365);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(79, 60);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"Выход";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MainWindow::CloseButton_Click);
			// 
			// EditButton
			// 
			this->EditButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->EditButton->Location = System::Drawing::Point(187, 365);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(169, 60);
			this->EditButton->TabIndex = 3;
			this->EditButton->Text = L"Изменить";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &MainWindow::EditButton_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(683, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 26);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Открыть файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_OpenFile);
			// 
			// SortBox1
			// 
			this->SortBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SortBox1->FormattingEnabled = true;
			this->SortBox1->Location = System::Drawing::Point(683, 121);
			this->SortBox1->Name = L"SortBox1";
			this->SortBox1->Size = System::Drawing::Size(102, 21);
			this->SortBox1->TabIndex = 6;
			// 
			// SortBox2
			// 
			this->SortBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SortBox2->FormattingEnabled = true;
			this->SortBox2->Location = System::Drawing::Point(683, 162);
			this->SortBox2->Name = L"SortBox2";
			this->SortBox2->Size = System::Drawing::Size(102, 21);
			this->SortBox2->TabIndex = 7;
			// 
			// HelpButton
			// 
			this->HelpButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->HelpButton->Location = System::Drawing::Point(683, 10);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(102, 23);
			this->HelpButton->TabIndex = 8;
			this->HelpButton->Text = L"Help";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &MainWindow::Debug_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SaveButton->Location = System::Drawing::Point(683, 71);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(102, 26);
			this->SaveButton->TabIndex = 9;
			this->SaveButton->Text = L"Сохранить файл";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_SaveFile);
			// 
			// RemoveButton
			// 
			this->RemoveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->RemoveButton->Location = System::Drawing::Point(362, 365);
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size(169, 60);
			this->RemoveButton->TabIndex = 10;
			this->RemoveButton->Text = L"Удалить";
			this->RemoveButton->UseVisualStyleBackColor = true;
			this->RemoveButton->Click += gcnew System::EventHandler(this, &MainWindow::RemoveButton_Click);
			// 
			// FrontListRadioButton
			// 
			this->FrontListRadioButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->FrontListRadioButton->AutoSize = true;
			this->FrontListRadioButton->Checked = true;
			this->FrontListRadioButton->Location = System::Drawing::Point(679, 202);
			this->FrontListRadioButton->Name = L"FrontListRadioButton";
			this->FrontListRadioButton->Size = System::Drawing::Size(104, 17);
			this->FrontListRadioButton->TabIndex = 13;
			this->FrontListRadioButton->TabStop = true;
			this->FrontListRadioButton->Text = L"Прямой список";
			this->FrontListRadioButton->UseVisualStyleBackColor = true;
			this->FrontListRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::FrontListRadioButton_CheckedChanged);
			// 
			// ReverseListButton
			// 
			this->ReverseListButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ReverseListButton->AutoSize = true;
			this->ReverseListButton->Location = System::Drawing::Point(679, 225);
			this->ReverseListButton->Name = L"ReverseListButton";
			this->ReverseListButton->Size = System::Drawing::Size(116, 17);
			this->ReverseListButton->TabIndex = 14;
			this->ReverseListButton->TabStop = true;
			this->ReverseListButton->Text = L"Обратный Список";
			this->ReverseListButton->UseVisualStyleBackColor = true;
			this->ReverseListButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::ReverseListButton_CheckedChanged);
			// 
			// RichBoxLastname
			// 
			this->RichBoxLastname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxLastname->Location = System::Drawing::Point(679, 265);
			this->RichBoxLastname->Name = L"RichBoxLastname";
			this->RichBoxLastname->Size = System::Drawing::Size(106, 33);
			this->RichBoxLastname->TabIndex = 15;
			this->RichBoxLastname->Text = L"";
			this->RichBoxLastname->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFindLastname);
			// 
			// RichBoxPhone
			// 
			this->RichBoxPhone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxPhone->Location = System::Drawing::Point(679, 313);
			this->RichBoxPhone->Name = L"RichBoxPhone";
			this->RichBoxPhone->Size = System::Drawing::Size(106, 33);
			this->RichBoxPhone->TabIndex = 16;
			this->RichBoxPhone->Text = L"";
			this->RichBoxPhone->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFindPhone);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(680, 249);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Поиск Фамилия";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(680, 297);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Поиск Телефон";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(680, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Сортировка";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(680, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Сортировка";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(801, 453);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->RichBoxPhone);
			this->Controls->Add(this->RichBoxLastname);
			this->Controls->Add(this->ReverseListButton);
			this->Controls->Add(this->FrontListRadioButton);
			this->Controls->Add(this->RemoveButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->HelpButton);
			this->Controls->Add(this->SortBox2);
			this->Controls->Add(this->SortBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->EditButton);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->CreateNewUser);
			this->MinimumSize = System::Drawing::Size(817, 492);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		/// <summary>
		///	Метод, который обновляет привязку данных к DataGridView, отчистив перед этим все строки
		///</summary>
		static void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView, String^ mode) {
			// Очистить все строки в DataGridView
			dataGridView->Rows->Clear();

			// Начинаем с головы списка
			Node^ currentNode;
			if(mode == "front" or mode == nullptr)
			currentNode = list->GetHead();
			else
			currentNode = list->GetTail();


			// Проходим по каждому узлу в списке
			while (currentNode != nullptr) {
				// Создаем новую строку для DataGridView
				DataGridViewRow^ row = gcnew DataGridViewRow();

				// Создаем ячейки в строке
				row->CreateCells(dataGridView);

				// Устанавливаем значения для каждой ячейки из текущего узла
				row->Cells[0]->Value = currentNode->GetUser()->lName;
				row->Cells[1]->Value = currentNode->GetUser()->year_start_up;
				row->Cells[2]->Value = currentNode->GetUser()->phone;
				row->Cells[3]->Value = currentNode->GetUser()->street;
				row->Cells[4]->Value = currentNode->GetUser()->house;
				row->Cells[5]->Value = currentNode->GetUser()->number_apart;

				// Добавляем строку в DataGridView
				dataGridView->Rows->Add(row);

				// Переходим к следующему узлу
				if(mode == "front" or mode == nullptr)
					currentNode = currentNode->GetNext();
				else
					currentNode = currentNode->GetPrev();
			}
		}


	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		UpdateBindingGridView(list, dataGridView1, "front");
	}

		   //TODO (Low) Изменить название кнопки
		   /// <summary>
		   /// Метод, который вызывает окно добавления нового пользователя, после чего обновляет привязку данных к DataGridView
		   /// </summary>
	private: System::Void OnClick_NewUserPhone(System::Object^ sender, System::EventArgs^ e) {
		NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, nullptr);
		newUserWindow->ShowDialog();
		UpdateBindingGridView(list, dataGridView1, "front");
	}

		   /// <summary>
		   /// Метод, закрывающий приложение
		   /// </summary>
	private: System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		auto messResult = MessageBox::Show("Вы уверены, что хотите выйти из приложения?", "Подтверждение",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (messResult == System::Windows::Forms::DialogResult::Yes)
			Application::Exit();

	}

	private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) { // Проверяем, есть ли выбранные строки
			// Начинаем с головы списка
			Node^ currentNode = list->GetHead();
			while (currentNode != nullptr) { // Используем цикл для обхода узлов
				for (int i = 0; i < dataGridView1->SelectedRows->Count; i++) {
					// Сравниваем имя текущего узла с выбранным именем в dataGridView1
					if (currentNode->GetUser()->lName == dataGridView1->SelectedRows[i]->Cells[0]->Value->ToString()) {
						// Создаем окно для редактирования пользователя
						NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, currentNode->GetUser());
						newUserWindow->ShowDialog(); // Показываем окно как диалог
						UpdateBindingGridView(list, dataGridView1, "front"); // Обновляем dataGridView после редактирования
						return; // Выходим из метода после редактирования
					}
				}
				currentNode = currentNode->GetNext(); // Переходим к следующему узлу
			}
		}
	}

	private: System::Void RemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0)
		{
			
			for (int i = 0; i < dataGridView1->SelectedRows->Count; i++)
			{
				if (dataGridView1->SelectedRows[i]->Cells[0]->Value != nullptr)
				{
					list->RemoveNode(dataGridView1->SelectedRows[i]->Cells[0]->Value->ToString());
				}
			}
			UpdateBindingGridView(list, dataGridView1, "front");
		}
		
	}

	private: System::Void OnClick_OpenFile(System::Object^ sender, System::EventArgs^ e) {
		OpenSCVFile();
		UpdateBindingGridView(list, dataGridView1, "front");
	}
	private:

	private: System::Void OnClick_SaveFile(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filename = saveFileDialog1->FileName;
			Parser::SaveDataInCSV(list, filename);
		}
	}
	
private: System::Void Debug_Click(System::Object^ sender, System::EventArgs^ e) {
	list->DEBUG_PrintListConsoleLinkedRelation();
}
private: System::Void FrontListRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	UpdateBindingGridView(list, dataGridView1, "front");
}
private: System::Void ReverseListButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	UpdateBindingGridView(list, dataGridView1, "reverse");
}

	   private: System::Void OnTextChangedFindLastname(System::Object^ sender, System::EventArgs^ e)
	   {
		   if (RichBoxLastname->Text->Length != 0)
		   {
			   //отсчистка DataGridView от старых данных
			   dataGridView1->Rows->Clear();

			   dataGridView1->Columns[1]->Visible = false;

			   Node^ currentNode = list->GetHead();
			   while (currentNode != nullptr)
			   {
				   if (currentNode->GetUser()->lName == RichBoxLastname->Text)
				   {

					   // Создаем новую строку для DataGridView
					   DataGridViewRow^ row = gcnew DataGridViewRow();

					   // Создаем ячейки в строке
					   row->CreateCells(dataGridView1);

					   // Устанавливаем значения для каждой ячейки из текущего узла
					   row->Cells[0]->Value = currentNode->GetUser()->lName;
					   row->Cells[1]->Value = currentNode->GetUser()->year_start_up;
					   row->Cells[2]->Value = currentNode->GetUser()->phone;
					   row->Cells[3]->Value = currentNode->GetUser()->street;
					   row->Cells[4]->Value = currentNode->GetUser()->house;
					   row->Cells[5]->Value = currentNode->GetUser()->number_apart;

					   // Добавляем строку в DataGridView
					   dataGridView1->Rows->Add(row);
				   }
				   currentNode = currentNode->GetNext();
			   }
		   }
		   else
		   {
			   UpdateBindingGridView(list, dataGridView1, "front");
		   }
	   }
	private: System::Void OnTextChangedFindPhone(System::Object^ sender, System::EventArgs^ e) {
		if (RichBoxPhone->Text->Length != 0)
		{
			//отсчистка DataGridView от старых данных
			dataGridView1->Rows->Clear();

			Node^ currentNode = list->GetHead();
			while (currentNode != nullptr)
			{
				if (currentNode->GetUser()->phone == RichBoxPhone->Text)
				{
					// Создаем новую строку для DataGridView
					DataGridViewRow^ row = gcnew DataGridViewRow();

					// Создаем ячейки в строке
					row->CreateCells(dataGridView1);

					// Устанавливаем значения для каждой ячейки из текущего узла
					row->Cells[0]->Value = currentNode->GetUser()->lName;
					row->Cells[1]->Value = currentNode->GetUser()->year_start_up;
					row->Cells[2]->Value = currentNode->GetUser()->phone;
					row->Cells[3]->Value = currentNode->GetUser()->street;
					row->Cells[4]->Value = currentNode->GetUser()->house;
					row->Cells[5]->Value = currentNode->GetUser()->number_apart;

					// Добавляем строку в DataGridView
					dataGridView1->Rows->Add(row);
				}
				currentNode = currentNode->GetNext();
			}
		}
		else
		{
			UpdateBindingGridView(list, dataGridView1, "front");
		}

	}
};
};
