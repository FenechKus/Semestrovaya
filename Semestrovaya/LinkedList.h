#pragma once
#include "UserData.h"

using namespace System::Windows::Forms;

/// <summary>
/// Класс характеризующий узел списка
/// </summary
public ref class Node
{
private:
	///Поля:
	UserData^ user; // - данные пользователя
	Node^ next; // - указатель на следующий узел
	Node^ prev; // - указатель на предыдущий узел

public:
	//Конструктор класса
	
	Node(UserData^ _user);

	//Методы доступа к узлам:

	Node^ GetNext();
	Node^ GetPrev();

	void SetNext(Node^ _next); 
	void SetPrev(Node^ _prev); 

	//Методы доступа к данным пользователя:

	UserData^ GetUser();
	void SetUser(UserData^ _user);
};

/// <summary>
/// Класс характеризующий связный список
/// </summary>
public ref class LinkedList
{
private:
	/// Поля:
	int countNodes = 0;// - количество узлов в списке
	Node^ head; // - указатель на начало списка
	Node^ tail; // - указатель на конец списка

public:
	// Конструктор класса
	LinkedList();

	// Методы доступа к списку:

	Node^ GetHead();
	Node^ GetTail();

	// Методы для работы со списком:

	void PushBack(UserData^ _user);
	void RemoveNode(String^ _lastName);
	bool IsExistAbonent(UserData^ _user);

	//Псевдоним для работы с сортировкой списка

	typedef int (*CompareFunc)(UserData^, UserData^);

	//Методы сортировки списка и его косвенные вызовы

	LinkedList^ SortBy(int (*compareFunc)(UserData^, UserData^));
	LinkedList^ SortByLastName();
	LinkedList^ SortByPhone();
	LinkedList^ SortByYear();
	LinkedList^ SortByStreet();

	//Методы для работы с DataGridView из WinForms:

	static void UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode);
	LinkedList^ FindNode(String^ _lastName, String^ _senderName);
	int FindNode(int _yearStartup);
	LinkedList^ FindNode(String^ _street, int _house);
	
};
