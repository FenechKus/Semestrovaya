#pragma once
#include "UserData.h"

using namespace System::Windows::Forms;

/// <summary>
/// Класс характеризующий узел списка
/// </summary>
public ref class Node
{
private:
	///Поля:
	UserData^ user; // - данные пользователя
	Node^ next; // - указатель на следующий узел
	Node^ prev; // - указатель на предыдущий узел

public:
	///Конструктор класса
	Node(UserData^ _user);

	///Методы доступа к узлам:
	Node^ GetNext();
	Node^ GetPrev();
	UserData^ GetUser();

	void SetNext(Node^ _next); 
	void SetPrev(Node^ _prev); 

	///Методы доступа к данным пользователя:
	void SetUser(UserData^ _user);
};

///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------
///-----------------------------------Linked-List----------------------------------------------
///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------

/// <summary>
/// Класс характеризующий связный список
/// </summary>
public ref class LinkedList
{
private:
	/// Поля:
	Node^ head; // - указатель на начало списка
	Node^ tail; // - указатель на конец списка

public:
	/// Конструктор класса
	LinkedList();

	/// Методы доступа к списку:
	Node^ GetHead();
	Node^ GetTail();

	/// Методы для работы со списком:
	void PushBack(UserData^ _user);
	void PopBack();
	void PopFront();
	void RemoveNode(String^ _lastName);
	bool IsExistAbonent(UserData^ _user);

	//// Методы для работы с DataGridView из WinForms:
	static void UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode);
	LinkedList^ FindNode(String^ _lastName, String^ _senderName);
	LinkedList^ FindNode(int _yearStartup);
	LinkedList^ FindNode(String^ _street);

};
