#pragma once
#include "Parser.h"
#include <fstream>
#include <iostream>
#include <string>
#include "UserData.h"
#include "LinkedList.h"

void Parser::GetDataFromCSV(LinkedList^ list, String^ path)
{
	// Путь к файлу CSV
	const std::string filePath = ConvertSystemStringToStdString(path);

	// Открываем файл для чтения
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		Console::WriteLine("Не удалось открыть файл.");
		return;
	}

	// Читаем строки из файла CSV
	std::string line;
	while (std::getline(inFile, line))
	{
		// Считаем количество полей в строке (6)
		constexpr int fieldCount = 6;
		//Создаем массив строк с помощью cli::array
		std::string fields[fieldCount];

		// Разбиваем строку на поля, используя запятую и точку с запятой
		int fieldIndex = 0;
		std::string tempField;
		for (char c : line)
		{
			if (c == ',' || c == ';')
			{
				// Преобразуем временное поле в String^ и добавляем в массив полей
				fields[fieldIndex++] = tempField;
				tempField.clear();

				// Если достигли точки с запятой, прекращаем разбор строки
				if (c == ';')
				{
					break;
				}
			}
			else
			{
				tempField += c;
			}
		}

		// Если не удалось прочитать нужное количество полей, пропускаем строку
		if (fieldIndex < fieldCount)
		{
			Console::WriteLine("Ошибка: неполные данные в строке.");
			continue;
		}

		// Создаем объект UserData и добавляем его в список
		auto userData = gcnew UserData(
			ConvertStdStringToSystemString(fields[0]),
			Int32::Parse(ConvertStdStringToSystemString(fields[1])),
			ConvertStdStringToSystemString(fields[2]),
			ConvertStdStringToSystemString(fields[3]),
			Int32::Parse(ConvertStdStringToSystemString(fields[4])),
			Int32::Parse(ConvertStdStringToSystemString(fields[5]))
		);

		list->PushBack(userData);
	}

	// Закрываем файл
	inFile.close();
}

void Parser::SaveDataInCSV(LinkedList^ list, String^ path)
{
	std::string savePath = ConvertSystemStringToStdString(path);

	// Открытие файла для записи
	std::ofstream outFile(savePath);

	if (outFile.is_open()) {

		auto current = list->GetHead();
		while (current != nullptr) {

			// Форматирование данных для записи
			outFile << ConvertSystemStringToStdString(current->GetUser()->lName) << ","
				<< current->GetUser()->yearStartUp << ","
				<< ConvertSystemStringToStdString(current->GetUser()->phone) << ","
				<< ConvertSystemStringToStdString(current->GetUser()->street) << ","
				<< current->GetUser()->house << ","
				<< current->GetUser()->numberApart << ";\n";

			// Переход к следующему узлу
			current = current->GetNext();
		}
		outFile.close();
	}
}

String^ Parser::ConvertStdStringToSystemString(const std::string& str)
{
	return gcnew String(str.c_str());
}

std::string Parser::ConvertSystemStringToStdString(String^ str)
{
	auto chars = static_cast<const char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str).
		ToPointer());
	std::string result(chars);
	Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));
	return result;
}