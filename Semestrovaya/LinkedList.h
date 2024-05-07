#pragma once
#include "UserData.h"

using namespace System::Windows::Forms;

/// <summary>
/// Суммарная информация: Node
/// Класс характеризующий узел списка
///
/// Поля:
/// user - данные пользователя
///	next - указатель на следующий узел
///
///	Методы:
///	GetNext - Получение следующего узла
///	SetNext - Установка следующего узла
/// GetUser - Получение данных пользователя
///	SetUser - Установка данных пользователя
/// </summary>
public ref class Node
{
private:
	UserData^ user;
	Node^ next;
	Node^ prev;

public:
	Node(UserData^ _user);

	Node^ GetNext();
	void SetNext(Node^ _next);
	Node^ GetPrev();
	void SetPrev(Node^ _prev);

	UserData^ GetUser();
	void SetUser(UserData^ _user);
};

/// <summary>
/// Суммарная информация: LinkedList
/// Класс характеризующий связный список
///
/// Поля:
/// head - указатель на начало списка
///
/// Методы:
/// GetHead - Получение начала списка
/// PushBack - Добавление элемента в конец списка
/// </summary>
public ref class LinkedList
{
private:
	Node^ head;
	Node^ tail;

public:
	LinkedList();

	Node^ GetHead();

	Node^ GetTail();
	void DEBUG_PrintListConsoleLinkedRelation();
	void DEBUG_PrintListToConsoleList();

	void PushBack(UserData^ user);
	void PopBack();

	void PopFront();
	void RemoveNode(String^ lastName);

	static void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView, String^ mode);
	UserData^ FindNode(String^ lastName, String^ senderName);

};
