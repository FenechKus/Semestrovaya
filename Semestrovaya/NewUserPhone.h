#pragma once
#include <functional>

#include "LinkedList.h"
#include "UserData.h"


namespace Semestrovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Класс формы для добавления нового пользователя
	/// </summary>
	public ref class NewUserPhone : public System::Windows::Forms::Form
	{
		//Создание ссылки на список, чтобы добавить в него нового пользователя
		LinkedList^ list;
		UserData^ user;
	public:
		NewUserPhone(LinkedList^ _list, UserData^ _user) : list(_list), user(_user)
		{
			InitializeComponent();
			isEditMode();
			if (isEditMode())
			{
				this->Text = "Редактирование данных абонента " + user->lName;
				InsertValueUserData();
			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewUserPhone()
		{
			if (components)
			{
				delete components;
			}

			if (list)
			{
				delete list;
			}
			if (user)
			{
				delete user;
			}
		}
#pragma region Код, автоматически созданный конструктором форм Windows
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ LastNameBox;
	private: System::Windows::Forms::TextBox^ YearBox;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ PhoneBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ NumApartamentBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ HouseBox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ StreetBox;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ ApplyButton;
	private: System::Windows::Forms::Button^ CancelButton;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LastNameBox = (gcnew System::Windows::Forms::TextBox());
			this->YearBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->PhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NumApartamentBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->HouseBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->StreetBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Фамилия";
			// 
			// LastNameBox
			// 
			this->LastNameBox->Location = System::Drawing::Point(66, 62);
			this->LastNameBox->Name = L"LastNameBox";
			this->LastNameBox->Size = System::Drawing::Size(178, 20);
			this->LastNameBox->TabIndex = 1;
			// 
			// YearBox
			// 
			this->YearBox->Location = System::Drawing::Point(66, 104);
			this->YearBox->Name = L"YearBox";
			this->YearBox->Size = System::Drawing::Size(178, 20);
			this->YearBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Год установки";
			// 
			// PhoneBox
			// 
			this->PhoneBox->Location = System::Drawing::Point(66, 152);
			this->PhoneBox->Name = L"PhoneBox";
			this->PhoneBox->Size = System::Drawing::Size(178, 20);
			this->PhoneBox->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(63, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Номер телефона(+7)";
			// 
			// NumApartamentBox
			// 
			this->NumApartamentBox->Location = System::Drawing::Point(376, 152);
			this->NumApartamentBox->Name = L"NumApartamentBox";
			this->NumApartamentBox->Size = System::Drawing::Size(178, 20);
			this->NumApartamentBox->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(373, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Квартира";
			// 
			// HouseBox
			// 
			this->HouseBox->Location = System::Drawing::Point(376, 104);
			this->HouseBox->Name = L"HouseBox";
			this->HouseBox->Size = System::Drawing::Size(178, 20);
			this->HouseBox->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(373, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Дом";
			// 
			// StreetBox
			// 
			this->StreetBox->Location = System::Drawing::Point(376, 62);
			this->StreetBox->Name = L"StreetBox";
			this->StreetBox->Size = System::Drawing::Size(178, 20);
			this->StreetBox->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(373, 45);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Улица";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(445, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Адрес";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(97, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Контактные данные";
			// 
			// ApplyButton
			// 
			this->ApplyButton->Location = System::Drawing::Point(90, 214);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(154, 46);
			this->ApplyButton->TabIndex = 14;
			this->ApplyButton->Text = L"Применить";
			this->ApplyButton->UseVisualStyleBackColor = true;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &NewUserPhone::ApplyButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(376, 214);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(154, 46);
			this->CancelButton->TabIndex = 15;
			this->CancelButton->Text = L"Отмена";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &NewUserPhone::CancelButton_Click);
			// 
			// NewUserPhone
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 314);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->ApplyButton);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->NumApartamentBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->HouseBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->StreetBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->PhoneBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->YearBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->LastNameBox);
			this->Controls->Add(this->label1);
			this->Name = L"NewUserPhone";
			this->Text = L"Новый пользователь";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		///<summary>
		///Метод для вставки данных пользователя в поля формы
		///</summary>
		System::Void InsertValueUserData()
		{
			if (user != nullptr)
			{
				LastNameBox->Text = user->lName;
				YearBox->Text = Convert::ToString(user->yearStartUp);
				PhoneBox->Text = user->phone;
				StreetBox->Text = user->street;
				HouseBox->Text = Convert::ToString(user->house);
				NumApartamentBox->Text = Convert::ToString(user->numberApart);
			}
		}

		bool isEditMode()
		{
			if (user != nullptr)
			{
				return true;
			}
			return false;
		}

		/// <summary>
		/// Метод обработчика события, применяющий изменение пользователя или создающий нового пользователя
		/// </summary>
		System::Void ApplyButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try
			{
				// Определение режима работы формы
				if (isEditMode())
				{
						Node^ currentNode = list->GetHead();
						while (currentNode != nullptr)
						{

							if (user->phone == currentNode->GetUser()->phone)
							{
								UserData^ user = gcnew UserData();
								user->lName = LastNameBox->Text;
								user->yearStartUp = Convert::ToInt32(YearBox->Text);
								user->phone = PhoneBox->Text;
								user->street = StreetBox->Text;
								user->house = Convert::ToInt32(HouseBox->Text);
								if(NumApartamentBox->Text != "")
								user->numberApart = Convert::ToInt32(NumApartamentBox->Text);
								else
									user->numberApart = 0;

									currentNode->SetUser(user);
									break;
								
							}
							currentNode = currentNode->GetNext();
						}

					this->Close();
				}
				else
				{
					UserData^ user = gcnew UserData();
					user->lName = LastNameBox->Text;
					user->yearStartUp = Convert::ToInt32(YearBox->Text);
					user->phone = PhoneBox->Text;
					user->street = StreetBox->Text;
					user->house = Convert::ToInt32(HouseBox->Text);
					if (NumApartamentBox->Text != "")
						user->numberApart = Convert::ToInt32(NumApartamentBox->Text);
					else
						user->numberApart = 0;

					if (list->IsExistAbonent(user))
					{
						list->PushBack(user);
						this->Close();
					}
					
				}
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

		/// <summary>
		/// Метод обработчика события, который закрывает данное окно
		/// </summary>
		System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
			auto messResult = MessageBox::Show("Вы уверены, что хотите закрыть окно?", "Подтверждение",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (messResult == System::Windows::Forms::DialogResult::Yes)
				this->Close();
		}
	};
}