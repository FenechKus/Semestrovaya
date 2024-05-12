#pragma once
#include "LinkedList.h"
#include "UserData.h"



Node::Node(UserData^ _user) : user(_user), next(nullptr), prev(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::PushBack(UserData^ user)
{
	Node^ newNode = gcnew Node(user);

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

void LinkedList::RemoveNode(String^ lastName)
{
    Node^ current = head;

    while (current != nullptr) {
        
        if (current->GetUser()->l_name == lastName) {

            if (current == head) {
				this->PopFront();
                return;
            }

            if (current == tail) {

                System::Diagnostics::Debug::WriteLine("prevNode До " + current->GetPrev()->GetUser()->l_name);
                System::Diagnostics::Debug::WriteLine("tail До " + tail->GetUser()->l_name);

                this->PopBack();

                System::Diagnostics::Debug::WriteLine("prevNode После " + current->GetPrev()->GetUser()->l_name);
                System::Diagnostics::Debug::WriteLine("tail После " + tail->GetUser()->l_name);
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


/// Методы доступа
Node^ Node::GetNext()
{
	return next;
}

void Node::SetNext(Node^ _next) { next = _next; }

Node^ Node::GetPrev()
{
	return prev;
}

void Node::SetPrev(Node^ _prev) { prev = _prev; }

UserData^ Node::GetUser()
{
	return user;
}

void Node::SetUser(UserData^ _user) { user = _user; }


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

void LinkedList::UpdateBindingGridView(LinkedList^ list, DataGridView^ dataGridView, String^ mode)
{
    int counterNotes = 0;
    // Очистить все строки в DataGridView
    dataGridView->Rows->Clear();
    
    // Начинаем с головы списка
    Node^ currentNode;
    if (mode == "front" or mode == nullptr)
        currentNode = list->GetHead();
    else
        currentNode = list->GetTail();


    // Проходим по каждому узлу в списке
    while (currentNode != nullptr) {
        // Создаем новую строку для DataGridView
        DataGridViewRow^ row = gcnew DataGridViewRow();

        // Создаем ячейки в строке
        row->CreateCells(dataGridView);

        // Устанавливаем значения для каждой ячейки из текущего узла
        row->Cells[0]->Value = currentNode->GetUser()->l_name;
        row->Cells[1]->Value = currentNode->GetUser()->year_start_up;
        row->Cells[2]->Value = currentNode->GetUser()->phone;
        row->Cells[3]->Value = currentNode->GetUser()->street;
        row->Cells[4]->Value = currentNode->GetUser()->house;
        row->Cells[5]->Value = currentNode->GetUser()->number_apart;

        // Добавляем строку в DataGridView
        dataGridView->Rows->Add(row);
        counterNotes++;

        // Переходим к следующему узлу
        if (mode == "front" or mode == nullptr)
            currentNode = currentNode->GetNext();
        else
            currentNode = currentNode->GetPrev();
    }
}

LinkedList^ LinkedList::FindNode(String^ param, String^ senderName)
{
    LinkedList^ findList = gcnew LinkedList();
    Node^ curentNode = head;

    while (curentNode != nullptr)
    {
	    if (curentNode->GetUser()->l_name == param && senderName == "RichBoxLastname")
	    {
            findList->PushBack(curentNode->GetUser());
	    }
        else if (curentNode->GetUser()->phone == param && senderName == "RichBoxPhone")
        {
            findList->PushBack(curentNode->GetUser());
        }
        curentNode = curentNode->GetNext();
    }
    return findList;
}

LinkedList^ LinkedList::FindNode(int yearStartup)
{
    LinkedList^ findList = gcnew LinkedList();
    Node^ curentNode = head;

    while (curentNode != nullptr)
    {
        if (curentNode->GetUser()->year_start_up == yearStartup)
        {
        	findList->PushBack(curentNode->GetUser());
        }
        curentNode = curentNode->GetNext();
    }
    return findList;
}

LinkedList^ LinkedList::FindNode(String^ street)
{
    LinkedList^ findlist = gcnew LinkedList();
    Node^ curentNode = head;

	while (curentNode != nullptr)
    {
	    if (curentNode->GetUser()->street == street)
	    {
			findlist->PushBack(curentNode->GetUser());
	    }
        curentNode = curentNode->GetNext();
    }
    return findlist;
}

void LinkedList::DEBUG_PrintListConsoleLinkedRelation()
{
    Node^ currentNode = head;

    while (currentNode != nullptr)
    {
        UserData^ user = currentNode->GetUser();

        System::Diagnostics::Debug::WriteLine("Фамилия: ", user->l_name);
        if(currentNode->GetPrev())
			System::Diagnostics::Debug::WriteLine("Фамилия предыдущего по списку ", currentNode->GetPrev()->GetUser()->l_name);
        else
            System::Diagnostics::Debug::WriteLine("Фамилия предыдущего по списку NULL");
        if (currentNode->GetNext())
            System::Diagnostics::Debug::WriteLine("Фамилия следующего по списку ", currentNode->GetNext()->GetUser()->l_name);
        else
            System::Diagnostics::Debug::WriteLine("Фамилия следующего по списку NULL");

    	System::Diagnostics::Debug::WriteLine("----------");


        currentNode = currentNode->GetNext();
    }
}

void LinkedList::DEBUG_PrintListToConsoleList()
{
    // Начинаем с головы списка
    Node^ currentNode = head;

    // Проходим по каждому узлу в списке
    while (currentNode != nullptr)
    {
        // Получаем данные пользователя из текущего узла
        UserData^ user = currentNode->GetUser();

        // Выводим данные пользователя в консоль
        System::Diagnostics::Debug::WriteLine(""); // Пустая строка для разделения записей
        System::Diagnostics::Debug::WriteLine("Фамилия: {0}", user->l_name);
        System::Diagnostics::Debug::WriteLine("Год установки: {0}", user->year_start_up);
        System::Diagnostics::Debug::WriteLine("Телефон: {0}", user->phone);
        System::Diagnostics::Debug::WriteLine("Улица: {0}", user->street);
        System::Diagnostics::Debug::WriteLine("Дом: {0}", user->house);
        System::Diagnostics::Debug::WriteLine("Квартира: {0}", user->number_apart);
        System::Diagnostics::Debug::WriteLine(""); // Пустая строка для разделения записей

        

        // Переходим к следующему узлу
        currentNode = currentNode->GetNext();
    }
}

