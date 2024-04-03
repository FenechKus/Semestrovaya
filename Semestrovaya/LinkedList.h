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

ref class Node
{
private:
	UserData^ user;
	Node^ next;

public:
	Node(UserData^ _user);

	Node^ GetNext();
	void SetNext(Node^ _next);

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
ref class LinkedList
{
private:
	Node^ head;

public:
	LinkedList();

	Node^ GetHead();

	void PushBack(UserData^ user);

	void printList();
};
