#pragma once
#include "UserData.h"

/// <summary>
/// ��������� ����������: Node
/// ����� ��������������� ���� ������
///
/// ����:
/// user - ������ ������������
///	next - ��������� �� ��������� ����
///
///	������:
///	GetNext - ��������� ���������� ����
///	SetNext - ��������� ���������� ����
/// GetUser - ��������� ������ ������������
///	SetUser - ��������� ������ ������������
/// </summary>
public ref class Node
{
private:
	UserData^ user;
	Node^ next, ^ prev;

public:
	Node(UserData^ _user);

	Node^ GetNext();
	void SetNext(Node^ _next);

	Node^ GetPrev();
	void SetPrev(Node^ _prev);

	UserData^ GetUser();
	void SetUser(UserData^ _user);
};

///TODO (CRITICAL!!) ���������� � ������������ �� ����������� ������!!!
/// <summary>
/// ��������� ����������: LinkedList
/// ����� ��������������� ������� ������
///
/// ����:
/// head - ��������� �� ������ ������
///	TODO (High) �������� tail - ��������� �� ����� ������
///
/// ������:
/// GetHead - ��������� ������ ������
/// PushBack - ���������� �������� � ����� ������
///  printList - ����� ������ TODO (Low) �������, ���� �� ����� �������������� � ����������
/// </summary>
public ref class LinkedList
{
private:
	Node^ head;
	Node^ tail;

public:
	LinkedList();

	Node^ GetHead();

	void PushBack(UserData^ user);

	/*UserData GetUserData(String^ lName);

	void SetUserData(UserData^ user);*/
};
