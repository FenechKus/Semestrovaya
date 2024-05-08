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
			OpenSCVFile();


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
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->Filter = "Text files(*.csv)|*.csv|All files(*.*)|*.*";
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filename = openFileDialog1->FileName;
				Parser::GetDataFromCSV(list, filename);

			}
		}

#pragma region Windows Form Designer generated code
	private: System::Windows::Forms::Button^ CreateNewUser;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Apartament;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ House;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Street;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	private: System::Windows::Forms::DataGridView^ GridViewAbonents;

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
			this->Apartament = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->House = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Street = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GridViewAbonents = (gcnew System::Windows::Forms::DataGridView());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridViewAbonents))->BeginInit();
			this->SuspendLayout();
			// 
			// CreateNewUser
			// 
			this->CreateNewUser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateNewUser->Location = System::Drawing::Point(12, 365);
			this->CreateNewUser->Name = L"CreateNewUser";
			this->CreateNewUser->Size = System::Drawing::Size(169, 60);
			this->CreateNewUser->TabIndex = 0;
			this->CreateNewUser->Text = L"����� ������������";
			this->CreateNewUser->UseVisualStyleBackColor = true;
			this->CreateNewUser->Click += gcnew System::EventHandler(this, &MainWindow::OnClick_NewUserPhone);
			// 
			// Apartament
			// 
			this->Apartament->HeaderText = L"��������";
			this->Apartament->Name = L"Apartament";
			this->Apartament->ReadOnly = true;
			// 
			// House
			// 
			this->House->HeaderText = L"���";
			this->House->Name = L"House";
			this->House->ReadOnly = true;
			// 
			// Street
			// 
			this->Street->HeaderText = L"�����";
			this->Street->Name = L"Street";
			this->Street->ReadOnly = true;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"�������";
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			// 
			// Year
			// 
			this->Year->HeaderText = L"��� ��������� ��������";
			this->Year->Name = L"Year";
			this->Year->ReadOnly = true;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"�������";
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
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
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->Location = System::Drawing::Point(706, 365);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(79, 60);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"�����";
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
			this->EditButton->Text = L"��������";
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
			this->button1->Text = L"������� ����";
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
			this->SaveButton->Text = L"��������� ����";
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
			this->RemoveButton->Text = L"�������";
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
			this->FrontListRadioButton->Text = L"������ ������";
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
			this->ReverseListButton->Text = L"�������� ������";
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
			this->RichBoxLastname->TextChanged += gcnew System::EventHandler(this, &MainWindow::OnTextChangedFind);
			// 
			// RichBoxPhone
			// 
			this->RichBoxPhone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RichBoxPhone->Location = System::Drawing::Point(679, 313);
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
			this->label1->Location = System::Drawing::Point(680, 249);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"����� �������";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(680, 297);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"����� �������";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(680, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"����������";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(680, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"����������";
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
			this->Controls->Add(this->GridViewAbonents);
			this->Controls->Add(this->CreateNewUser);
			this->MinimumSize = System::Drawing::Size(817, 492);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridViewAbonents))->EndInit();
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
					if (currentNode->GetUser()->lName == GridViewAbonents->SelectedRows[i]->Cells[0]->Value->ToString()) {
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
	
private: System::Void Debug_Click(System::Object^ sender, System::EventArgs^ e) {
	list->DEBUG_PrintListConsoleLinkedRelation();
}
private: System::Void FrontListRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
}
private: System::Void ReverseListButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	LinkedList::UpdateBindingGridView(list, GridViewAbonents, "reverse");
}
	private: System::Void OnTextChangedFind(System::Object^ sender, System::EventArgs^ e) {
		RichTextBox^ richBox = dynamic_cast<RichTextBox^>(sender);
		if (RichBoxPhone->Text->Length != 0)
		{
			//��������� DataGridView �� ������ ������
			GridViewAbonents->Rows->Clear();
			UserData^ user = list->FindNode(richBox->Text, richBox->Name);
			
				if (user != nullptr)
				{
					// ������� ����� ������ ��� DataGridView
					DataGridViewRow^ row = gcnew DataGridViewRow();

					// ������� ������ � ������
					row->CreateCells(GridViewAbonents);

					// ������������� �������� ��� ������ ������ �� �������� ����
					row->Cells[0]->Value = user->lName;
					row->Cells[1]->Value = user->year_start_up;
					row->Cells[2]->Value = user->phone;
					row->Cells[3]->Value = user->street;
					row->Cells[4]->Value = user->house;
					row->Cells[5]->Value = user->number_apart;

					// ��������� ������ � DataGridView
					GridViewAbonents->Rows->Add(row);
				}
		}
		else
		{
			LinkedList::UpdateBindingGridView(list, GridViewAbonents, "front");
		}

	}
};
};
