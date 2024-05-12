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
	void SetNext(Node^ _next); 
	Node^ GetPrev(); 
	void SetPrev(Node^ _prev); 

	///������ ������� � ������ ������������:
	UserData^ GetUser();
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

	/// ������ ��� ������� ������:
	void DEBUG_PrintListConsoleLinkedRelation();
	void DEBUG_PrintListToConsoleList();

	/// ������ ��� ������ �� �������:
	void PushBack(UserData^ user);
	void PopBack();
	void PopFront();
	void RemoveNode(String^ lastName);

	//// ������ ��� ������ � DataGridView �� WinForms:
	static void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView, String^ mode);
	LinkedList^ FindNode(String^ lastName, String^ senderName);
	LinkedList^ FindNode(int yearStartup);
	LinkedList^ FindNode(String^ street);
	

};
