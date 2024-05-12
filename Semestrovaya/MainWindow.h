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
	/// ������ ��� MainWindow
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
			InitilizeSortBox();
			OpenSCVFile();

			
			GridViewAbonents->RowsAdded += gcnew DataGridViewRowsAddedEventHandler(this, &MainWindow::dataGridView_RowsAdded);
			GridViewAbonents->RowsRemoved += gcnew DataGridViewRowsRemovedEventHandler(this, &MainWindow::dataGridView_RowsRemoved);
		}


		
		void dataGridView_RowsAdded(Object^ sender, DataGridViewRowsAddedEventArgs^ e)
		{
			CounterLabel->Text = "�����: " + GridViewAbonents->Rows->Count;
		}

		
		void dataGridView_RowsRemoved(Object^ sender, DataGridViewRowsRemovedEventArgs^ e)
		{
			CounterLabel->Text = "�����: " + GridViewAbonents->Rows->Count;
		}

	protected:

		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

		void OpenSCVFile()
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

#pragma region Windows Form Designer generated code
	private: System::Windows::Forms::Button^ CreateNewUser;
	protected:






	private: System::Windows::Forms::DataGridView^ GridViewAbonents;

	private: System::Windows::Forms::Button^ CloseButton;
	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ SortDataGrid;



	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::Button^ RemoveButton;
	private: System::Windows::Forms::RadioButton^ FrontListButton;



	private: System::Windows::Forms::RadioButton^ ReverseListButton;
	private: System::Windows::Forms::RichTextBox^ RichBoxLastname;
	private: System::Windows::Forms::RichTextBox^ RichBoxPhone;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Street;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ House;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Apartament;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ CounterLabel;



	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->CreateNewUser->Text = L"����� ������������";
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
			this->GridViewAbonents->Location = System::Drawing::Point(12, 12);
			this->GridViewAbonents->Name = L"GridViewAbonents";
			this->GridViewAbonents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->GridViewAbonents->Size = System::Drawing::Size(661, 321);
			this->GridViewAbonents->TabIndex = 1;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"�������";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			this->LastName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Year
			// 
			this->Year->HeaderText = L"��� ��������� ��������";
			this->Year->Name = L"Year";
			this->Year->ReadOnly = true;
			this->Year->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"�������";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			this->Phone->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Street
			// 
			this->Street->HeaderText = L"�����";
			this->Street->Name = L"Street";
			this->Street->ReadOnly = true;
			this->Street->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// House
			// 
			this->House->HeaderText = L"���";
			this->House->Name = L"House";
			this->House->ReadOnly = true;
			this->House->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Apartament
			// 
			this->Apartament->HeaderText = L"��������";
			this->Apartament->Name = L"Apartament";
			this->Apartament->ReadOnly = true;
			this->Apartament->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->CloseButton->Location = System::Drawing::Point(714, 375);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(79, 60);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"�����";
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
			this->EditButton->Text = L"��������";
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
			this->button1->Text = L"������� ����";
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
			this->SaveButton->Text = L"��������� ����";
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
			this->RemoveButton->Text = L"�������";
			this->RemoveButton->UseVisualStyleBackColor = false;
			this->RemoveButton->Click += gcnew System::EventHandler(this, &MainWindow::RemoveButton_Click);
			// 
			// FrontListButton
			// 
			this->FrontListButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->FrontListButton->AutoSize = true;
			this->FrontListButton->Checked = true;
			this->FrontListButton->Location = System::Drawing::Point(12, 146);
			this->FrontListButton->Name = L"FrontListButton";
			this->FrontListButton->Size = System::Drawing::Size(104, 17);
			this->FrontListButton->TabIndex = 13;
			this->FrontListButton->TabStop = true;
			this->FrontListButton->Text = L"������ ������";
			this->FrontListButton->UseVisualStyleBackColor = true;
			this->FrontListButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::WayListRadioButton_CheckedChanged);
			// 
			// ReverseListButton
			// 
			this->ReverseListButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ReverseListButton->AutoSize = true;
			this->ReverseListButton->Location = System::Drawing::Point(12, 169);
			this->ReverseListButton->Name = L"ReverseListButton";
			this->ReverseListButton->Size = System::Drawing::Size(116, 17);
			this->ReverseListButton->TabIndex = 14;
			this->ReverseListButton->TabStop = true;
			this->ReverseListButton->Text = L"�������� ������";
			this->ReverseListButton->UseVisualStyleBackColor = true;
			this->ReverseListButton->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::WayListRadioButton_CheckedChanged);
			// 
			// RichBoxLastname
			// 
			this->RichBoxLastname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxLastname->Location = System::Drawing::Point(12, 209);
			this->RichBoxLastname->Name = L"RichBoxLastname";
			this->RichBoxLastname->Size = System::Drawing::Size(106, 33);
			this->RichBoxLastname->TabIndex = 15;
			this->RichBoxLastname->Text = L"";
			this->RichBoxLastname->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFind);
			// 
			// RichBoxPhone
			// 
			this->RichBoxPhone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxPhone->Location = System::Drawing::Point(12, 257);
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
			this->label1->Location = System::Drawing::Point(13, 193);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"����� �������";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 241);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"����� �������";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"����������";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->ReverseListButton);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->SortDataGrid);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->SaveButton);
			this->panel1->Controls->Add(this->RichBoxPhone);
			this->panel1->Controls->Add(this->FrontListButton);
			this->panel1->Controls->Add(this->RichBoxLastname);
			this->panel1->Location = System::Drawing::Point(675, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(124, 328);
			this->panel1->TabIndex = 21;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"������ � �������";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel2->BackColor = System::Drawing::Color::LightGray;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->CreateNewUser);
			this->panel2->Controls->Add(this->EditButton);
			this->panel2->Controls->Add(this->RemoveButton);
			this->panel2->Location = System::Drawing::Point(12, 350);
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
			this->label6->Text = L"������ � �������";
			// 
			// CounterLabel
			// 
			this->CounterLabel->AutoSize = true;
			this->CounterLabel->Location = System::Drawing::Point(23, 334);
			this->CounterLabel->Name = L"CounterLabel";
			this->CounterLabel->Size = System::Drawing::Size(49, 13);
			this->CounterLabel->TabIndex = 24;
			this->CounterLabel->Text = L"�����: 0";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(801, 453);
			this->Controls->Add(this->CounterLabel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->GridViewAbonents);
			this->MinimumSize = System::Drawing::Size(817, 492);
			this->Name = L"MainWindow";
			this->Text = L"����������� ������ ������ ���-108";
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

		

		   /// <summary>	
		   /// ���������� �����, ������� ��������� ���� � ��������� ������ � ������ ��� ������� ����������
		   /// </summary>
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}

		   /// <summary>
		   /// ���������� �����, ������� �������� ���� ���������� ������ ������������, ����� ���� ��������� �������� ������ � DataGridView
		   /// </summary>
	private: System::Void OnClick_NewUserPhone(System::Object^ sender, System::EventArgs^ e) {
		NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, nullptr);
		newUserWindow->ShowDialog();
		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}

		   /// <summary>
		   /// ���������� �����, ����������� ����������
		   /// </summary>
	private: System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		auto messResult = MessageBox::Show("�� �������, ��� ������ ����� �� ����������?", "�������������",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (messResult == System::Windows::Forms::DialogResult::Yes)
			Application::Exit();

	}

		//TODO: (HIGH) ��������� ���������� ������ � ������� � LinkedList

	private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GridViewAbonents->SelectedRows->Count > 0) { // ���������, ���� �� ��������� ������
			// �������� � ������ ������
			Node^ currentNode = list->GetHead();
			while (currentNode != nullptr) { // ���������� ���� ��� ������ �����
				for (int i = 0; i < GridViewAbonents->SelectedRows->Count; i++) {
					// ���������� ��� �������� ���� � ��������� ������ � GridViewAbonents
					if (currentNode->GetUser()->l_name == GridViewAbonents->SelectedRows[i]->Cells[0]->Value->ToString()) {
						// ������� ���� ��� �������������� ������������
						NewUserPhone^ newUserWindow = gcnew NewUserPhone(list, currentNode->GetUser());
						newUserWindow->ShowDialog(); // ���������� ���� ��� ������
						LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front"); // ��������� dataGridView ����� ��������������
						return; // ������� �� ������ ����� ��������������
					}
				}
				currentNode = currentNode->GetNext(); // ��������� � ���������� ����
			}
		}
	}

	private: System::Void RemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GridViewAbonents->SelectedRows->Count > 0)
		{
			
			for (int i = 0; i < GridViewAbonents->SelectedRows->Count; i++)
			{
				if (GridViewAbonents->SelectedRows[i]->Cells[0]->Value != nullptr)
				{
					list->RemoveNode(GridViewAbonents->SelectedRows[i]->Cells[0]->Value->ToString());
				}
			}
			LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
		}
		
	}

	private: System::Void OnClick_OpenFile(System::Object^ sender, System::EventArgs^ e) {
		OpenSCVFile();
		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}

	private: System::Void OnClick_SaveFile(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filename = saveFileDialog1->FileName;
			Parser::SaveDataInCSV(list, filename);
		}
	}

private: System::Void WayListRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
	RadioButton^ rb = dynamic_cast<RadioButton^>(sender);
	if(rb->Name == "FrontListButton")
	{
		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
	}
	else if(rb->Name == "ReverseListButton")
	{
		LinkedList::UpdateBindingGridView(list, GridViewAbonents, "reverse");
	}
}
private: System::Void ReverseListButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
	private: System::Void OnTextChangedFind(System::Object^ sender, System::EventArgs^ e) {
		RichTextBox^ richBox = dynamic_cast<RichTextBox^>(sender);
		if (richBox->Text->Length != 0)
		{
			LinkedList^ findUser = list->FindNode(richBox->Text, richBox->Name);
			Node^ current = findUser->GetHead();

			if (findUser != nullptr)
			{
				//��������� DataGridView �� ������ ������
				GridViewAbonents->Rows->Clear();
			}
				
					while (current !=nullptr)
					{
						// ������� ����� ������ ��� DataGridView
						DataGridViewRow^ row = gcnew DataGridViewRow();

						// ������� ������ � ������
						row->CreateCells(GridViewAbonents);

						// ������������� �������� ��� ������ ������ �� �������� ����
						row->Cells[0]->Value = current->GetUser()->l_name;
						row->Cells[1]->Value = current->GetUser()->year_start_up;
						row->Cells[2]->Value = current->GetUser()->phone;
						row->Cells[3]->Value = current->GetUser()->street;
						row->Cells[4]->Value = current->GetUser()->house;
						row->Cells[5]->Value = current->GetUser()->number_apart;

						// ��������� ������ � DataGridView
						GridViewAbonents->Rows->Add(row);
						current = current->GetNext();
					}
					
		}
		else
		{
			LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
		}

	}

			void InitilizeSortBox()
		   {
				SortDataGrid->DropDownStyle = ComboBoxStyle::DropDownList;
				auto tmp = GridViewAbonents->Columns;
				SortDataGrid->Items->Add("���");
			   for (int i = 0; i < GridViewAbonents->Columns->Count; i++)
			   {
				   SortDataGrid->Items->Add(tmp[i]->HeaderText);
			   }
				
				if (SortDataGrid->Items->Count != 0)
				{
					SortDataGrid->SelectedIndex = 0;
				}
		   }

private: System::Void SelectedValueChangedSortBox(System::Object^ sender, System::EventArgs^ e) {
	
	switch (SortDataGrid->SelectedIndex)
	{
	case 0:

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
