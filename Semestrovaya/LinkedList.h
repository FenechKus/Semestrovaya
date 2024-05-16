#pragma once
#include "UserData.h"

using namespace System::Windows::Forms;

/// <summary>
/// ����� ��������������� ���� ������
/// </summary>
public ref class Node
{
private:
	///����:
	UserData^ user; // - ������ ������������
	Node^ next; // - ��������� �� ��������� ����
	Node^ prev; // - ��������� �� ���������� ����

public:
	///����������� ������
	Node(UserData^ _user);

	///������ ������� � �����:
	Node^ GetNext();
	Node^ GetPrev();
	UserData^ GetUser();

	void SetNext(Node^ _next); 
	void SetPrev(Node^ _prev); 

	///������ ������� � ������ ������������:
	void SetUser(UserData^ _user);
};

///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------
///-----------------------------------Linked-List----------------------------------------------
///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------

/// <summary>
/// ����� ��������������� ������� ������
/// </summary>
public ref class LinkedList
{
private:
	/// ����:
	Node^ head; // - ��������� �� ������ ������
	Node^ tail; // - ��������� �� ����� ������

public:
	/// ����������� ������
	LinkedList();

	/// ������ ������� � ������:
	Node^ GetHead();
	Node^ GetTail();

	/// ������ ��� ������ �� �������:
	void PushBack(UserData^ _user);
	void PopBack();
	void PopFront();
	void RemoveNode(String^ _lastName);
	bool IsExistAbonent(UserData^ _user);

	//// ������ ��� ������ � DataGridView �� WinForms:
	static void UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode);
	LinkedList^ FindNode(String^ _lastName, String^ _senderName);
	LinkedList^ FindNode(int _yearStartup);
	LinkedList^ FindNode(String^ _street);

};
