#pragma once
#include "UserData.h"

// ReSharper disable once CppNotAllPathsReturnValue
ref class Node
{
private:
	UserData^ user;
	Node^ next;

public:
	Node(UserData^ _user);

	// ������ ������� �� ����� ������� �������� null, ������� �� �������� ��������
	Node^ GetNext();
	void SetNext(Node^ _next);

	UserData^ GetUser();
	void SetUser(UserData^ _user);
};

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
