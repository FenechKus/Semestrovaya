#pragma once

#include "LinkedList.h"
#include "NewUserPhone.h"
#include "UserData.h"


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
			list = gcnew LinkedList();
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

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Street;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ House;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Apartament;
	private: System::Windows::Forms::Button^ CloseButton;







	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CreateNewUser = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Street = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->House = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Apartament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// CreateNewUser
			// 
			this->CreateNewUser->Location = System::Drawing::Point(109, 317);
			this->CreateNewUser->Name = L"CreateNewUser";
			this->CreateNewUser->Size = System::Drawing::Size(169, 69);
			this->CreateNewUser->TabIndex = 0;
			this->CreateNewUser->Text = L"Новый пользователь";
			this->CreateNewUser->UseVisualStyleBackColor = true;
			this->CreateNewUser->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->LastName,
					this->Year, this->Phone, this->Street, this->House, this->Apartament
			});
			this->dataGridView1->Location = System::Drawing::Point(37, 90);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(643, 150);
			this->dataGridView1->TabIndex = 1;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"Фамилия";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			// 
			// Year
			// 
			this->Year->HeaderText = L"Год установки телефона";
			this->Year->Name = L"Year";
			this->Year->ReadOnly = true;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Телефон";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			// 
			// Street
			// 
			this->Street->HeaderText = L"Улица";
			this->Street->Name = L"Street";
			this->Street->ReadOnly = true;
			// 
			// House
			// 
			this->House->HeaderText = L"Дом";
			this->House->Name = L"House";
			this->House->ReadOnly = true;
			// 
			// Apartament
			// 
			this->Apartament->HeaderText = L"Квартира";
			this->Apartament->Name = L"Apartament";
			this->Apartament->ReadOnly = true;
			// 
			// CloseButton
			// 
			this->CloseButton->Location = System::Drawing::Point(481, 317);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(169, 69);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"Выход";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MainWindow::CloseButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 435);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->CreateNewUser);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


		/// <summary>
		///	Метод, который обновляет привязку данных к DataGridView, отчистив перед этим все строки
		///</summary>
		void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView) {
			dataGridView->Rows->Clear();

			Node^ currentNode = list->GetHead();
			while (currentNode != nullptr) {
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(dataGridView);
				row->Cells[0]->Value = currentNode->GetUser()->l_name;
				row->Cells[1]->Value = currentNode->GetUser()->year_start_up;
				row->Cells[2]->Value = currentNode->GetUser()->phone;
				row->Cells[3]->Value = currentNode->GetUser()->street;
				row->Cells[4]->Value = currentNode->GetUser()->house;
				row->Cells[5]->Value = currentNode->GetUser()->number_apart;

				dataGridView->Rows->Add(row);
				currentNode = currentNode->GetNext();
			}
		}

	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		//TODO (High) Удалить тестовые данные и вызовы методов
		UserData^ user1 = gcnew UserData("Smith", 2000, "123-456-789", "Main St", 123, 1);
		UserData^ user2 = gcnew UserData("Johnson", 2010, "456-789-012", "First St", 456, 2);
		UserData^ user3 = gcnew UserData("Williams", 2015, "789-012-345", "Second St", 789, 3);
		
		
		list->PushBack(user1);
		list->PushBack(user2);
		list->PushBack(user3);

		
		UpdateBindingGridView(list, dataGridView1);
	}

		//TODO (Low) Изменить название кнопки
		/// <summary>
		/// Метод, который вызывает окно добавления нового пользователя, после чего обновляет привязку данных к DataGridView
		/// </summary>
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		NewUserPhone^ newUserWindow = gcnew NewUserPhone(list);
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
};
}
