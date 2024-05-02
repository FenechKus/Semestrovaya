#pragma once
#include "UserData.h"

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

///TODO (CRITICAL!!) ПЕРЕПИСАТЬ С ОДНОСВЯЗНОГО НА ДВУХСВЯЗНЫЙ СПИСОК!!!
/// <summary>
/// Суммарная информация: LinkedList
/// Класс характеризующий связный список
///
/// Поля:
/// head - указатель на начало списка
///	TODO (High) Добавить tail - указатель на конец списка
///
/// Методы:
/// GetHead - Получение начала списка
/// PushBack - Добавление элемента в конец списка
///  printList - Вывод списка TODO (Low) удалить, если не будет использоваться в дальнейшем
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


	/*UserData GetUserData(String^ lName);

	void SetUserData(UserData^ user);*/
};
