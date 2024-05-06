#pragma once
#include <fstream>

#include "LinkedList.h"
using namespace System;
using namespace std;


/// \brief  ласс, предоставл€ющий функционал дл€ чтени€, записи, преобразовани€ к UserData и обратно к CSV-файлу
/// \param path - путь к файлу
///	
ref class CSVParser
{
protected:
	const int MAX_COLS = 6;
	LinkedList^ userList;

public:
	void GetUserFromCSV(String^, LinkedList^);

};

