#pragma once

using namespace System;

/// <summary>
/// ����� ��������������� ������ ��������
/// </summary>
public ref class UserData sealed
{
public:
	//���� ��������
	String^ l_name;
	int year_start_up;
	String^ phone;

	//���� ������
	String^ street;
	int house;
	int number_apart;

	//������������
	UserData();
	UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart);
};
