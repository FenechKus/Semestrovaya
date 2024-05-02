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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// CreateNewUser
			// 
			this->CreateNewUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateNewUser->Location = System::Drawing::Point(94, 399);
			this->CreateNewUser->Name = L"CreateNewUser";
			this->CreateNewUser->Size = System::Drawing::Size(169, 41);
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
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->LastName,
					this->Year, this->Phone, this->Street, this->House, this->Apartament
			});
			this->dataGridView1->Location = System::Drawing::Point(41, 70);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(643, 276);
			this->dataGridView1->TabIndex = 1;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->Location = System::Drawing::Point(444, 399);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(169, 41);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"Выход";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MainWindow::CloseButton_Click);
			// 
			// EditButton
			// 
			this->EditButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->EditButton->Location = System::Drawing::Point(94, 352);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(169, 41);
			this->EditButton->TabIndex = 3;
			this->EditButton->Text = L"Изменить";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &MainWindow::EditButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 26);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Открыть файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_OpenFile);
			// 
			// SortBox1
			// 
			this->SortBox1->FormattingEnabled = true;
			this->SortBox1->Location = System::Drawing::Point(335, 12);
			this->SortBox1->Name = L"SortBox1";
			this->SortBox1->Size = System::Drawing::Size(121, 21);
			this->SortBox1->TabIndex = 6;
			// 
			// SortBox2
			// 
			this->SortBox2->FormattingEnabled = true;
			this->SortBox2->Location = System::Drawing::Point(474, 12);
			this->SortBox2->Name = L"SortBox2";
			this->SortBox2->Size = System::Drawing::Size(121, 21);
			this->SortBox2->TabIndex = 7;
			// 
			// HelpButton
			// 
			this->HelpButton->Location = System::Drawing::Point(669, 10);
			this->HelpButton->Name = L"HelpButton";
			this->HelpButton->Size = System::Drawing::Size(57, 23);
			this->HelpButton->TabIndex = 8;
			this->HelpButton->Text = L"Help";
			this->HelpButton->UseVisualStyleBackColor = true;
			this->HelpButton->Click += gcnew System::EventHandler(this, &MainWindow::Debug_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(165, 12);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(137, 26);
			this->SaveButton->TabIndex = 9;
			this->SaveButton->Text = L"Сохранить файл";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_SaveFile);
			// 
			// RemoveButton
			// 
			this->RemoveButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->RemoveButton->Location = System::Drawing::Point(269, 399);
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size(169, 41);
			this->RemoveButton->TabIndex = 10;
			this->RemoveButton->Text = L"Удалить";
			this->RemoveButton->UseVisualStyleBackColor = true;
			this->RemoveButton->Click += gcnew System::EventHandler(this, &MainWindow::RemoveButton_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->AutoSize = true;
			this->button2->Location = System::Drawing::Point(269, 351);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 41);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Поиск по Фамилии";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(444, 352);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 41);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Поиск по Номеру";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 453);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
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
			this->MinimumSize = System::Drawing::Size(754, 492);
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
		static void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView) {

			// Очистить все строки в DataGridView
			dataGridView->Rows->Clear();

			// Начинаем с головы списка
			Node^ currentNode = list->GetHead();

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
				currentNode = currentNode->GetNext();
			}
		}


	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		UpdateBindingGridView(list, dataGridView1);
	}

		   //TODO (Low) Изменить название кнопки
		   /// <summary>
		   /// Метод, который вызывает окно добавления нового пользователя, после чего обновляет привязку данных к DataGridView
		   /// </summary>
	private: System::Void OnClick_NewUserPhone(System::Object^ sender, System::EventArgs^ e) {
		NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, nullptr);
		newUserWindow->ShowDialog();
		UpdateBindingGridView(list, dataGridView1);
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
						UpdateBindingGridView(list, dataGridView1); // Обновляем dataGridView после редактирования
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
			UpdateBindingGridView(list, dataGridView1);
		}
		
	}

	private: System::Void OnClick_OpenFile(System::Object^ sender, System::EventArgs^ e) {
		OpenSCVFile();
		UpdateBindingGridView(list, dataGridView1);
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
};
};
