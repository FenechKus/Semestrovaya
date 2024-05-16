#pragma once

using namespace System;

/// <summary>
/// ����� ��������������� ������ ��������
/// </summary>
public ref class UserData sealed
{
public:
	//���� ��������
	String^ lName;
	int yearStartUp;
	String^ phone;

	//���� ������
	String^ street;
	int house;
	int numberApart;

	//������������
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
