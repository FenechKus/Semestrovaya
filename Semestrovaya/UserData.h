#pragma once

using namespace System;

/// <summary>
/// Класс характеризующий данные пользователя телефона
/// 
/// Поля:
/// l_name - фамилия
/// year_start_up - год подключения
/// phone - номер телефона
/// street - улица
/// house - дом
/// number_apart - номер квартиры
/// 
/// Методы:
///
/// </summary>
public ref class UserData sealed
{
public:
	String^ lName;
	int year_start_up;
	String^ phone;

	
	String^ street;
	int house;
	int number_apart;

	
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
