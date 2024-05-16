#pragma once

#include "NewUserPhone.h"
#include "Parser.h"


// Объявление управляемых CLI классов для решения циклических зависимостей

ref class Node;
ref class LinkedList;
ref class Parser;
ref class UserData;

namespace Semestrovaya {

	/// <summary>
	///	Подключение пространства имен для работы с формами и средой CLI
	/// </summary>
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	///<summary>
	///Класс, характеризующий главное окно приложения
	///</summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private:
		LinkedList^ list;

	public:
		///<summary>
		///Конструктор инициализации компонентов формы,
		///открытия файла и инициализации поля сортировки
		///</summary>
		MainWindow(void) : GridViewAbonents()
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			OpenSCVFile();
			InitilizeSortBox();

			// События для обновления счетчика строк
			GridViewAbonents->RowsAdded += gcnew DataGridViewRowsAddedEventHandler(
				this, &MainWindow::dataGridView_RowsAdded);
			GridViewAbonents->RowsRemoved += gcnew DataGridViewRowsRemovedEventHandler(
				this, &MainWindow::dataGridView_RowsRemoved);

		}

		///<summary>
		/// Методы обработчика события, который обновляет счетчик строк в списке
		///</summary>
#pragma region Обработчики событий подсчета строк в списке
		void dataGridView_RowsAdded(Object^ sender, DataGridViewRowsAddedEventArgs^ e)
		{
			CounterLabel->Text = "Строк: " + GridViewAbonents->Rows->Count;
		}

		void dataGridView_RowsRemoved(Object^ sender, DataGridViewRowsRemovedEventArgs^ e)
		{
			CounterLabel->Text = "Строк: " + GridViewAbonents->Rows->Count;
		}
#pragma endregion

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

#pragma region Windows Form Designer generated code

	private:

	System::Windows::Forms::Button^ CreateNewUser;

	System::Windows::Forms::DataGridView^ GridViewAbonents;

	System::Windows::Forms::Button^ CloseButton;
	System::Windows::Forms::Button^ EditButton;
	System::Windows::Forms::Button^ button1;
	System::Windows::Forms::ComboBox^ SortDataGrid;

	System::Windows::Forms::Button^ SaveButton;
	System::Windows::Forms::Button^ RemoveButton;
	System::Windows::Forms::RadioButton^ FrontListButton;

	System::Windows::Forms::RadioButton^ ReverseListButton;
	System::Windows::Forms::RichTextBox^ RichBoxLastname;
	System::Windows::Forms::RichTextBox^ RichBoxPhone;
	System::Windows::Forms::Label^ label1;
	System::Windows::Forms::Label^ label2;
	System::Windows::Forms::Label^ label3;

	System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	System::Windows::Forms::DataGridViewTextBoxColumn^ Street;
	System::Windows::Forms::DataGridViewTextBoxColumn^ House;
	System::Windows::Forms::DataGridViewTextBoxColumn^ Apartament;
	System::Windows::Forms::Panel^ panel1;
	System::Windows::Forms::Label^ label5;
	System::Windows::Forms::Panel^ panel2;
	System::Windows::Forms::Label^ label6;

	System::Windows::Forms::Label^ CounterLabel;
	System::Windows::Forms::Label^ label7;
	System::Windows::Forms::Label^ label4;

	System::Windows::Forms::RichTextBox^ RichBoxYearFind;

	System::Windows::Forms::RichTextBox^ RichBoxStreetFind;



	private:

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CreateNewUser = (gcnew System::Windows::Forms::Button());
			this->GridViewAbonents = (gcnew System::Windows::Forms::DataGridView());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Street = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->House = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Apartament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SortDataGrid = (gcnew System::Windows::Forms::ComboBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->RemoveButton = (gcnew System::Windows::Forms::Button());
			this->FrontListButton = (gcnew System::Windows::Forms::RadioButton());
			this->ReverseListButton = (gcnew System::Windows::Forms::RadioButton());
			this->RichBoxLastname = (gcnew System::Windows::Forms::RichTextBox());
			this->RichBoxPhone = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RichBoxYearFind = (gcnew System::Windows::Forms::RichTextBox());
			this->RichBoxStreetFind = (gcnew System::Windows::Forms::RichTextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CounterLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridViewAbonents))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// CreateNewUser
			// 
			this->CreateNewUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateNewUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->CreateNewUser->Location = System::Drawing::Point(11, 25);
			this->CreateNewUser->Name = L"CreateNewUser";
			this->CreateNewUser->Size = System::Drawing::Size(169, 60);
			this->CreateNewUser->TabIndex = 0;
			this->CreateNewUser->Text = L"Новый пользователь";
			this->CreateNewUser->UseVisualStyleBackColor = false;
			this->CreateNewUser->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_NewUserPhone);
			// 
			// GridViewAbonents
			// 
			this->GridViewAbonents->AllowUserToAddRows = false;
			this->GridViewAbonents->AllowUserToDeleteRows = false;
			this->GridViewAbonents->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GridViewAbonents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->GridViewAbonents->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->GridViewAbonents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridViewAbonents->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->LastName,
					this->Year, this->Phone, this->Street, this->House, this->Apartament
			});
			this->GridViewAbonents->Location = System::Drawing::Point(12, 5);
			this->GridViewAbonents->Name = L"GridViewAbonents";
			this->GridViewAbonents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->GridViewAbonents->Size = System::Drawing::Size(661, 386);
			this->GridViewAbonents->TabIndex = 1;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"Фамилия";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			this->LastName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Year
			// 
			this->Year->HeaderText = L"Год установки телефона";
			this->Year->Name = L"Year";
			this->Year->ReadOnly = true;
			this->Year->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Телефон";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			this->Phone->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Street
			// 
			this->Street->HeaderText = L"Улица";
			this->Street->Name = L"Street";
			this->Street->ReadOnly = true;
			this->Street->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// House
			// 
			this->House->HeaderText = L"Дом";
			this->House->Name = L"House";
			this->House->ReadOnly = true;
			this->House->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Apartament
			// 
			this->Apartament->HeaderText = L"Квартира";
			this->Apartament->Name = L"Apartament";
			this->Apartament->ReadOnly = true;
			this->Apartament->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->CloseButton->Location = System::Drawing::Point(714, 433);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(79, 60);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"Выход";
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MainWindow::CloseButton_Click);
			// 
			// EditButton
			// 
			this->EditButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->EditButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->EditButton->Location = System::Drawing::Point(186, 25);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(169, 60);
			this->EditButton->TabIndex = 3;
			this->EditButton->Text = L"Изменить";
			this->EditButton->UseVisualStyleBackColor = false;
			this->EditButton->Click += gcnew System::EventHandler(this, &MainWindow::EditButton_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(12, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 26);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Открыть файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_OpenFile);
			// 
			// SortDataGrid
			// 
			this->SortDataGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SortDataGrid->FormattingEnabled = true;
			this->SortDataGrid->Location = System::Drawing::Point(12, 110);
			this->SortDataGrid->Name = L"SortDataGrid";
			this->SortDataGrid->Size = System::Drawing::Size(102, 21);
			this->SortDataGrid->TabIndex = 6;
			this->SortDataGrid->SelectedValueChanged += gcnew System::EventHandler(this, &MainWindow::SelectedValueChangedSortBox);
			// 
			// SaveButton
			// 
			this->SaveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SaveButton->Location = System::Drawing::Point(12, 60);
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
			this->RemoveButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->RemoveButton->Location = System::Drawing::Point(361, 25);
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size(169, 60);
			this->RemoveButton->TabIndex = 10;
			this->RemoveButton->Text = L"Удалить";
			this->RemoveButton->UseVisualStyleBackColor = false;
			this->RemoveButton->Click += gcnew System::EventHandler(this, &MainWindow::RemoveButton_Click);
			// 
			// FrontListButton
			// 
			this->FrontListButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->FrontListButton->AutoSize = true;
			this->FrontListButton->Checked = true;
			this->FrontListButton->Location = System::Drawing::Point(12, 137);
			this->FrontListButton->Name = L"FrontListButton";
			this->FrontListButton->Size = System::Drawing::Size(104, 17);
			this->FrontListButton->TabIndex = 13;
			this->FrontListButton->TabStop = true;
			this->FrontListButton->Text = L"Прямой список";
			this->FrontListButton->UseVisualStyleBackColor = true;
			this->FrontListButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::WayListRadioButton_CheckedChanged);
			// 
			// ReverseListButton
			// 
			this->ReverseListButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ReverseListButton->AutoSize = true;
			this->ReverseListButton->Location = System::Drawing::Point(12, 160);
			this->ReverseListButton->Name = L"ReverseListButton";
			this->ReverseListButton->Size = System::Drawing::Size(116, 17);
			this->ReverseListButton->TabIndex = 14;
			this->ReverseListButton->TabStop = true;
			this->ReverseListButton->Text = L"Обратный Список";
			this->ReverseListButton->UseVisualStyleBackColor = true;
			this->ReverseListButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::WayListRadioButton_CheckedChanged);
			// 
			// RichBoxLastname
			// 
			this->RichBoxLastname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxLastname->Location = System::Drawing::Point(8, 196);
			this->RichBoxLastname->Name = L"RichBoxLastname";
			this->RichBoxLastname->Size = System::Drawing::Size(106, 33);
			this->RichBoxLastname->TabIndex = 15;
			this->RichBoxLastname->Text = L"";
			this->RichBoxLastname->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFind);
			// 
			// RichBoxPhone
			// 
			this->RichBoxPhone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxPhone->Location = System::Drawing::Point(8, 244);
			this->RichBoxPhone->Name = L"RichBoxPhone";
			this->RichBoxPhone->Size = System::Drawing::Size(106, 33);
			this->RichBoxPhone->TabIndex = 16;
			this->RichBoxPhone->Text = L"";
			this->RichBoxPhone->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFind);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Поиск Фамилия";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 228);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Поиск Телефон";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Сортировка";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->ReverseListButton);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->SortDataGrid);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->SaveButton);
			this->panel1->Controls->Add(this->RichBoxYearFind);
			this->panel1->Controls->Add(this->RichBoxPhone);
			this->panel1->Controls->Add(this->RichBoxStreetFind);
			this->panel1->Controls->Add(this->FrontListButton);
			this->panel1->Controls->Add(this->RichBoxLastname);
			this->panel1->Location = System::Drawing::Point(675, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(124, 386);
			this->panel1->TabIndex = 21;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Работа с данными";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 325);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Поиск по году";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 277);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Поиск по улице";
			// 
			// RichBoxYearFind
			// 
			this->RichBoxYearFind->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxYearFind->Location = System::Drawing::Point(10, 341);
			this->RichBoxYearFind->Name = L"RichBoxYearFind";
			this->RichBoxYearFind->Size = System::Drawing::Size(106, 33);
			this->RichBoxYearFind->TabIndex = 16;
			this->RichBoxYearFind->Text = L"";
			this->RichBoxYearFind->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFindYear);
			// 
			// RichBoxStreetFind
			// 
			this->RichBoxStreetFind->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxStreetFind->Location = System::Drawing::Point(10, 293);
			this->RichBoxStreetFind->Name = L"RichBoxStreetFind";
			this->RichBoxStreetFind->Size = System::Drawing::Size(106, 33);
			this->RichBoxStreetFind->TabIndex = 15;
			this->RichBoxStreetFind->Text = L"";
			this->RichBoxStreetFind->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFindToStreet);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel2->BackColor = System::Drawing::Color::LightGray;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->CreateNewUser);
			this->panel2->Controls->Add(this->EditButton);
			this->panel2->Controls->Add(this->RemoveButton);
			this->panel2->Location = System::Drawing::Point(12, 408);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(541, 91);
			this->panel2->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(223, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Работа с списком";
			// 
			// CounterLabel
			// 
			this->CounterLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CounterLabel->AutoSize = true;
			this->CounterLabel->Location = System::Drawing::Point(12, 392);
			this->CounterLabel->Name = L"CounterLabel";
			this->CounterLabel->Size = System::Drawing::Size(49, 13);
			this->CounterLabel->TabIndex = 24;
			this->CounterLabel->Text = L"Строк: 0";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(801, 511);
			this->Controls->Add(this->CounterLabel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->GridViewAbonents);
			this->MinimumSize = System::Drawing::Size(817, 492);
			this->Name = L"MainWindow";
			this->Text = L"Семестровая Влизко Максим ВИП-108";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridViewAbonents))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private:

		///<summary>
		/// Метод, который открывает диалоговое окно выбора файла и загружает данные из файла в список
		///</summary>
		System::Void OpenSCVFile()
		{
			list = gcnew LinkedList();
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filename = openFileDialog->FileName;
				Parser::GetDataFromCSV(list, filename);

			}
		}

		/// <summary>
		/// Метод обработчика события кнопки, который загружает в GridViewAbonents данные из спска абонентов
		/// </summary>
		System::Void OnClick_OpenFile(System::Object^ sender, System::EventArgs^ e) {
			OpenSCVFile();
			FrontListButton->Checked = true;
			LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
		}

		/// <summary>
		/// Метод обработчика события кнопки, который сохраняет данные из списка в файл
		/// </summary>
		System::Void OnClick_SaveFile(System::Object^ sender, System::EventArgs^ e) {
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filename = saveFileDialog1->FileName;
				Parser::SaveDataInCSV(list, filename);
			}
		}

		/// <summary>
		/// Метод добавления строки в DataGridView
		/// </summary>
		System::Void AddRowToDataGridView(LinkedList^ findUser)
		{
			Node^ current = findUser->GetHead();
			
			//отсчистка DataGridView от старых данных
			GridViewAbonents->Rows->Clear();
			

			while (current != nullptr)
			{
				// Создаем новую строку для DataGridView
				DataGridViewRow^ row = gcnew DataGridViewRow();

				// Создаем ячейки в строке
				row->CreateCells(GridViewAbonents);

				// Привязывание к ячейкам данных из списка
				row->Cells[0]->Value = current->GetUser()->l_name;
				row->Cells[1]->Value = current->GetUser()->year_start_up;
				row->Cells[2]->Value = current->GetUser()->phone;
				row->Cells[3]->Value = current->GetUser()->street;
				row->Cells[4]->Value = current->GetUser()->house;
				row->Cells[5]->Value = current->GetUser()->number_apart;

				GridViewAbonents->Rows->Add(row);
				current = current->GetNext();
			}
		}

		////<summary>
		///Метод инициализации списка сортировки
		///</summary>
		System::Void InitilizeSortBox()
		{
			SortDataGrid->DropDownStyle = ComboBoxStyle::DropDownList;
			auto tmp = GridViewAbonents->Columns;
			SortDataGrid->Items->Add("Все");
			for (int i = 0; i < GridViewAbonents->Columns->Count; i++)
			{
				SortDataGrid->Items->Add(tmp[i]->HeaderText);
			}

			if (SortDataGrid->Items->Count != 0)
			{
				SortDataGrid->SelectedIndex = 0;
			}
		}

		///<summary>	
		///Метод обработчика события, который выполняет привязку данных при первом запуске приложения
		///</summary>
		System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}

		   /// <summary>
		   /// Метод обработчика события кнопки, который вызывает окно добавления нового пользователя, после чего обновляет привязку данных к DataGridView
		   /// </summary>
		System::Void OnClick_NewUserPhone(System::Object^ sender, System::EventArgs^ e) {

		NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, nullptr);
		newUserWindow->ShowDialog();
		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}

		   /// <summary>
		   /// Метод обработчика события кнопки, закрывающий приложение
		   /// </summary>
		System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) {

			auto messResult = MessageBox::Show("Вы уверены, что хотите выйти из приложения?", "Подтверждение",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (messResult == System::Windows::Forms::DialogResult::Yes)
				Application::Exit();

		}

		//TODO: (HIGH) Перенести реализацию работы с списком в LinkedList

		///<summary>
		///Метод обработчика события кнопки, который вызывает окно редактирования нового пользователя
		///</summary>
		System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e) {

			if (GridViewAbonents->SelectedRows->Count > 0) { // Проверяем, есть ли выбранные строки

				Node^ currentNode = list->GetHead();
				while (currentNode != nullptr) {

					for (int i = 0; i < GridViewAbonents->SelectedRows->Count; i++) {
						// Сравниваем имя текущего узла с выбранным именем в GridViewAbonents
						if (currentNode->GetUser()->phone == GridViewAbonents->SelectedRows[i]->Cells[2]->Value->ToString()) {
							
							NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, currentNode->GetUser());
							newUserWindow->ShowDialog(); // Показываем окно как диалог
							LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front"); // Обновляем dataGridView после редактирования
							return; // Выходим из метода после редактирования
						}
					}
					currentNode = currentNode->GetNext(); // Переходим к следующему узлу
				}
			}
		}

		System::Void RemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (GridViewAbonents->SelectedRows->Count > 0)
			{

				for (int i = 0; i < GridViewAbonents->SelectedRows->Count; i++)
				{
					if (GridViewAbonents->SelectedRows[i]->Cells[0]->Value != nullptr)
					{
						list->RemoveNode(GridViewAbonents->SelectedRows[i]->Cells[0]->Value->ToString());
					}
				}
				FrontListButton->Checked = true;
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
			}

		}

		/// <summary>
		/// Метод обработчика событи RadioButton, который обновляет привязку данных к DataGridView в зависимости от выбранного RadioButton
		/// </summary>
		System::Void WayListRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

			RadioButton^ rb = dynamic_cast<RadioButton^>(sender);
			if (rb->Name == "FrontListButton")
			{
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
			}
			else if (rb->Name == "ReverseListButton")
			{
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "reverse");
			}
		}

		/// <summary>
		/// Методы обработчика события, которые производят поиск по списку
		/// OnTextChangedFind - поиск по фамилии и телефону
		/// OnTextChangedFindToStreet - поиск по улице
		/// OnTextChangedFindYear - поиск по году
		/// </summary>

		System::Void OnTextChangedFind(System::Object^ sender, System::EventArgs^ e) {
			RichTextBox^ richBox = dynamic_cast<RichTextBox^>(sender);
			if (richBox->Text->Length != 0)
			{
				LinkedList^ findUser = list->FindNode(richBox->Text, richBox->Name);
					AddRowToDataGridView(findUser);
			}
			else
			{
				FrontListButton->Checked = true;
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
			}

		}

		System::Void OnTextChangedFindToStreet(System::Object^ sender, System::EventArgs^ e) {

			if (RichBoxStreetFind->Text->Length != 0)
			{
				LinkedList^ findUser = list->FindNode(RichBoxStreetFind->Text);
				AddRowToDataGridView(findUser);

			}
			else
			{
				FrontListButton->Checked = true;
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
			}

		}

		System::Void OnTextChangedFindYear(System::Object^ sender, System::EventArgs^ e) {

			if (RichBoxYearFind->Text->Length != 0)
			{
				LinkedList^ findUser = list->FindNode(Convert::ToInt32(RichBoxYearFind->Text));
				AddRowToDataGridView(findUser);

			}
			else
			{
				FrontListButton->Checked = true;
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
			}
		}

		/// <summary>
		/// Метод обработчика события, который обновляет привязку данных к DataGridView в зависимости от выбранного элемента в SortDataGrid
		///	выполняя тем самым сортироввку данных
		/// </summary>
		System::Void SelectedValueChangedSortBox(System::Object^ sender, System::EventArgs^ e) {

			switch (SortDataGrid->SelectedIndex)
			{
			case 0:
				FrontListButton->Checked = true;
				LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
				break;

			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			}

		}

};
};
