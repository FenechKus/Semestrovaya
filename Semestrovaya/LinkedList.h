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
	void SetNext(Node^ _next); 
	Node^ GetPrev(); 
	void SetPrev(Node^ _prev); 

	///Методы доступа к данным пользователя:
	UserData^ GetUser();
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

	/// Методы для отладки списка:
	void DEBUG_PrintListConsoleLinkedRelation();
	void DEBUG_PrintListToConsoleList();

	/// Методы для работы со списком:
	void PushBack(UserData^ user);
	void PopBack();
	void PopFront();
	void RemoveNode(String^ lastName);

	//// Методы для работы с DataGridView из WinForms:
	static void UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView, String^ mode);
	LinkedList^ FindNode(String^ lastName, String^ senderName);
	LinkedList^ FindNode(int yearStartup);
	LinkedList^ FindNode(String^ street);
	

};
