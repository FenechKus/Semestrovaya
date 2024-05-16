#pragma once
#include "LinkedList.h"
#include "UserData.h"



Node::Node(UserData^ _user) : next(nullptr), prev(nullptr)
{
	this->SetUser(_user);
}

/// Методы доступа
Node^ Node::GetNext()
{
	return next;
}

Node^ Node::GetPrev()
{
	return prev;
}

UserData^ Node::GetUser()
{
	return user;
}

void Node::SetUser(UserData^ _user)
{
    if (_user->lName == "" || _user->yearStartUp == 0 || _user->phone == "" || _user->street == "" || _user->house == 0)
    {
		throw gcnew System::Exception("Неккоректные данные");
    }
    else
    {
		user = _user;
    }
}


void Node::SetNext(Node^ _next) { next = _next; }

void Node::SetPrev(Node^ _prev) { prev = _prev; }

///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------
///------------------------------------Linked List---------------------------------------------
///--------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------

Node^ LinkedList::GetHead()
{
	return head;
}

Node^ LinkedList::GetTail()
{
	return tail;
}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::PushBack(UserData^ _user)
{
    Node^ newNode = gcnew Node(_user);

    newNode->SetPrev(this->tail);
    if (tail != nullptr)
    {
        tail->SetNext(newNode);
    }
    if (head == nullptr)
    {
        head = newNode;
    }
    tail = newNode;
}

void LinkedList::PopBack()
{
    Node^ newTail = tail->GetPrev();

    if (newTail != nullptr) {
        newTail->SetNext(nullptr);
    }
    else {
        head = newTail;
    }
    delete tail;
    tail = newTail;
}

void LinkedList::PopFront()
{
    Node^ newHead = head->GetNext();

    if (newHead != nullptr) {
        newHead->SetPrev(nullptr);
    }
    else {
        tail = newHead;
    }
    delete head;
    head = newHead;
}

void LinkedList::RemoveNode(String^ _lastName)
{
    Node^ current = head;

    while (current != nullptr) {

        if (current->GetUser()->lName == _lastName) {

            if (current == head) {
                this->PopFront();
                return;
            }

            if (current == tail) {
                this->PopBack();
                return;
            }

            Node^ prevNode = current->GetPrev();
            Node^ nextNode = current->GetNext();

            prevNode->SetNext(nextNode);
            nextNode->SetPrev(prevNode);

            delete current;
            return;
        }

        current = current->GetNext();
    }
}

bool LinkedList::IsExistAbonent(UserData^ _user)
{
    Node^ curentNode = GetHead();

    while (curentNode != nullptr)
    {
        if (curentNode->GetUser()->phone == _user->phone && curentNode->GetUser()->lName != _user->lName)
        {
            throw gcnew System::Exception("Номер уже используется");
        }
        curentNode = curentNode->GetNext();
    }
    return true;
}

void LinkedList::UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode)
{
    int counterNotes = 0;
    // Очистить все строки в DataGridView
    _dataGridView->Rows->Clear();
    
    // Начинаем с головы списка
    Node^ currentNode;
    if (_mode == "front" or _mode == nullptr)
        currentNode = _list->GetHead();
    else
        currentNode = _list->GetTail();


    // Проходим по каждому узлу в списке
    while (currentNode != nullptr) {
        // Создаем новую строку для DataGridView
        DataGridViewRow^ row = gcnew DataGridViewRow();

        // Создаем ячейки в строке
        row->CreateCells(_dataGridView);

        // Устанавливаем значения для каждой ячейки из текущего узла
        row->Cells[0]->Value = currentNode->GetUser()->lName;
        row->Cells[1]->Value = currentNode->GetUser()->yearStartUp;
        row->Cells[2]->Value = currentNode->GetUser()->phone;
        row->Cells[3]->Value = currentNode->GetUser()->street;
        row->Cells[4]->Value = currentNode->GetUser()->house;
        if (currentNode->GetUser()->numberApart == 0)
        {
            row->Cells[5]->Value = "Частный дом";
        }
        else
        row->Cells[5]->Value = currentNode->GetUser()->numberApart;

        // Добавляем строку в DataGridView
        _dataGridView->Rows->Add(row);
        counterNotes++;

        // Переходим к следующему узлу
        if (_mode == "front" or _mode == nullptr)
            currentNode = currentNode->GetNext();
        else
            currentNode = currentNode->GetPrev();
    }
}

LinkedList^ LinkedList::FindNode(String^ param, String^ _senderName)
{
    LinkedList^ findList = gcnew LinkedList();
    Node^ curentNode = head;

    while (curentNode != nullptr)
    {
	    if (curentNode->GetUser()->lName == param && _senderName == "RichBoxLastname")
	    {
            findList->PushBack(curentNode->GetUser());
	    }
        else if (curentNode->GetUser()->phone == param && _senderName == "RichBoxPhone")
        {
            findList->PushBack(curentNode->GetUser());
        }
        curentNode = curentNode->GetNext();
    }
    return findList;
}

LinkedList^ LinkedList::FindNode(int _yearStartup)
{
    LinkedList^ findList = gcnew LinkedList();
    Node^ curentNode = head;

    while (curentNode != nullptr)
    {
        if (curentNode->GetUser()->yearStartUp == _yearStartup)
        {
        	findList->PushBack(curentNode->GetUser());
        }
        curentNode = curentNode->GetNext();
    }
    return findList;
}

LinkedList^ LinkedList::FindNode(String^ _street)
{
    LinkedList^ findlist = gcnew LinkedList();
    Node^ curentNode = head;

	while (curentNode != nullptr)
    {
	    if (curentNode->GetUser()->street == _street)
	    {
			findlist->PushBack(curentNode->GetUser());
	    }
        curentNode = curentNode->GetNext();
    }
    return findlist;
}

/*
 LinkedList* LinkedList::FindNode(string _street)
{
    LinkedList* findlist = gcnew LinkedList(); Это создание списка с результатами 
    Node^ curentNode = head; Это начало списка, его голова

	while (curentNode != nullptr) Это цикл обхода списка по каждому элементу
    {
	    if (curentNode->GetUser()->street == _street) Это проверка на совпадение параметра поиска с параметром в текущем узле
	    {
			findlist->PushBack(curentNode->GetUser()); Это добавление узла в список с результатами
	    }
        curentNode = curentNode->GetNext(); Это переход к следующему узлу
    }
    return findlist; Это возврат списка с результатами
}
 */