#pragma once
#include <fstream>

#include "LinkedList.h"
using namespace System;
using namespace std;


/// \brief �����, ��������������� ���������� ��� ������, ������, �������������� � UserData � ������� � CSV-�����
/// \param path - ���� � �����
///	
ref class CSVParser
{
protected:
	const int MAX_COLS = 6;
	LinkedList^ userList;

public:
	void GetUserFromCSV(String^, LinkedList^);

};

