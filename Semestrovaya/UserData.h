// UserData.h
#pragma once

#include <string> // Для использования строк в конструкторе

using namespace System;

public ref class UserData sealed
{
public:
	String^ l_name;
	int year_start_up;
	String^ phone;

	// Адрес
	String^ street;
	int house;
	int number_apart;

	// Конструкторы
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
