#pragma once
#include "UserData.h"

using namespace System::Windows::Forms;

/// <summary>
/// ����� ��������������� ���� ������
/// </summary
public ref class Node
{
private:
	///����:
	UserData^ user; // - ������ ������������
	Node^ next; // - ��������� �� ��������� ����
	Node^ prev; // - ��������� �� ���������� ����

public:
	//����������� ������
	
	Node(UserData^ _user);

	//������ ������� � �����:

	Node^ GetNext();
	Node^ GetPrev();

	void SetNext(Node^ _next); 
	void SetPrev(Node^ _prev); 

	//������ ������� � ������ ������������:

	UserData^ GetUser();
	void SetUser(UserData^ _user);
};

/// <summary>
/// ����� ��������������� ������� ������
/// </summary>
public ref class LinkedList
{
private:
	/// ����:
	int countNodes = 0;// - ���������� ����� � ������
	Node^ head; // - ��������� �� ������ ������
	Node^ tail; // - ��������� �� ����� ������

public:
	// ����������� ������
	LinkedList();

	// ������ ������� � ������:

	Node^ GetHead();
	Node^ GetTail();

	// ������ ��� ������ �� �������:

	void PushBack(UserData^ _user);
	void RemoveNode(String^ _lastName);
	bool IsExistAbonent(UserData^ _user);

	//��������� ��� ������ � ����������� ������

	typedef int (*CompareFunc)(UserData^, UserData^);

	//������ ���������� ������ � ��� ��������� ������

	LinkedList^ SortBy(int (*compareFunc)(UserData^, UserData^));
	LinkedList^ SortByLastName();
	LinkedList^ SortByPhone();
	LinkedList^ SortByYear();
	LinkedList^ SortByStreet();

	//������ ��� ������ � DataGridView �� WinForms:

	static void UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode);
	LinkedList^ FindNode(String^ _lastName, String^ _senderName);
	int FindNode(int _yearStartup);
	LinkedList^ FindNode(String^ _street, int _house);
	
};
