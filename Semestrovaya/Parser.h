#pragma once
#include <string>
#include "LinkedList.h"

using namespace System;

ref class Parser
{
public:
	Parser()
	{
	}

	// Метод для считывания данных из файла CSV
	static void GetDataFromCSV(LinkedList^ list, String^ path);

	static void SaveDataInCSV(LinkedList^ list, String^ path);

private:
	// Функция для преобразования std::string в System::String^
	static String^ ConvertStdStringToSystemString(const std::string& str);

	// Функция для преобразования System::String^ в std::string
	static std::string ConvertSystemStringToStdString(String^ str);
};
