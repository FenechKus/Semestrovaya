#include "CSVParser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


void CSVParser::GetUserFromCSV(String^ filename, LinkedList^ list)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		Windows::Forms::MessageBox::Show("Ошибка открытия файла");
		return;
	}

	string line;
	while (getline(file, line))
	{
		istringstream ss(line);
		string field;

		int col = 0;
		String^ lName;
		String^ phone;
		String^ street;
		int yearStartUp;
		int house;
		int numApartament;
		while (getline(ss, field, ',') && col < MAX_COLS)
		{
			if (field.front() == '"' && field.back() == '"')
			{
				field = field.substr(1, field.length() - 2);
			}

			switch (col)
			{
			case 0: lName = gcnew String(field.c_str());
				break;
			case 1: yearStartUp = std::stoi(field);
				break;
			case 2: phone = gcnew String(field.c_str());
				break;
			case 3: street = gcnew String(field.c_str());
				break;
			case 4: house = std::stoi(field);
				break;
			case 5: numApartament = std::stoi(field);
				break;
			default: break;
			}
			col++;
		}

		UserData^ user = gcnew UserData(lName, yearStartUp, phone, street, house, numApartament);

		list->PushBack(user);
	}
}
