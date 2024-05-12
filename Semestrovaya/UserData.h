#pragma once

using namespace System;

/// <summary>
/// Класс характеризующий данные абонента
/// </summary>
public ref class UserData sealed
{
public:
	//Поля Абонента
	String^ l_name;
	int year_start_up;
	String^ phone;

	//Поля Адреса
	String^ street;
	int house;
	int number_apart;

	//Конструкторы
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
