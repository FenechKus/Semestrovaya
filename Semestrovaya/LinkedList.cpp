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
        
        if (current->GetUser()->lName == lastName) {

            if (current == head) {
				this->PopFront();
                return;
            }

            if (current == tail) {

                System::Diagnostics::Debug::WriteLine("prevNode До " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail До " + tail->GetUser()->lName);

                this->PopBack();

                System::Diagnostics::Debug::WriteLine("prevNode После " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail После " + tail->GetUser()->lName);
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


Node^ LinkedList::GetHead()
{
	return head;
}

Node^ LinkedList::GetTail()
{
	return tail;
}

void LinkedList::DEBUG_PrintListConsoleLinkedRelation()
{
    Node^ currentNode = head;

    while (currentNode != nullptr)
    {
        UserData^ user = currentNode->GetUser();

        System::Diagnostics::Debug::WriteLine("Фамилия: ", user->lName);
        if(currentNode->GetPrev())
			System::Diagnostics::Debug::WriteLine("Фамилия предыдущего по списку ", currentNode->GetPrev()->GetUser()->lName);
        else
            System::Diagnostics::Debug::WriteLine("Фамилия предыдущего по списку NULL");
        if (currentNode->GetNext())
            System::Diagnostics::Debug::WriteLine("Фамилия следующего по списку ", currentNode->GetNext()->GetUser()->lName);
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
        System::Diagnostics::Debug::WriteLine("Фамилия: {0}", user->lName);
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

