#pragma once

using namespace System;

/// <summary>
/// Класс характеризующий данные абонента
/// </summary>
public ref class UserData sealed
{
public:
	//Поля Абонента
	String^ lName;
	int yearStartUp;
	String^ phone;

	//Поля Адреса
	String^ street;
	int house;
	int numberApart;

	//Конструкторы
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
