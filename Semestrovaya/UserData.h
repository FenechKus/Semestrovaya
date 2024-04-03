#pragma once

using namespace System;

/// <summary>
/// ����� ��������������� ������ ������������ ��������
/// 
/// ����:
/// l_name - �������
/// year_start_up - ��� �����������
/// phone - ����� ��������
/// street - �����
/// house - ���
/// number_apart - ����� ��������
/// 
/// ������:
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
