#pragma once
#include "LinkedList.h"
#include "UserData.h"



Node::Node(UserData^ _user) : user(_user), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::PushBack(UserData^ user)
{
	Node^ newNode = gcnew Node(user);

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;

        newNode->SetNext(nullptr);
        newNode->SetPrev(nullptr);
	}
	else
	{
		tail->SetNext(newNode);
		newNode->SetPrev(tail);
		tail = newNode;
	}

}

void LinkedList::RemoveNode(String^ lastName)
{
    Node^ current = head;

    while (current != nullptr) {
        
        if (current->GetUser()->lName == lastName) {

            if (current == head) {
        
                head = current->GetNext();

                if (head != nullptr) {
                    head->SetPrev(nullptr);
                }
            }
            else if (current == tail) {

                System::Diagnostics::Debug::WriteLine("prevNode До " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail До " + tail->GetUser()->lName);

                tail = current->GetPrev();

                if (tail != nullptr) {
                    tail->SetNext(nullptr);
                }

                System::Diagnostics::Debug::WriteLine("prevNode До " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail До " + tail->GetUser()->lName);
            }
            else {
                Node^ prevNode = current->GetPrev();
                Node^ nextNode = current->GetNext();

                if (prevNode != nullptr) {
                    prevNode->SetNext(nextNode);
                }

                if (nextNode != nullptr) {
                    nextNode->SetPrev(prevNode);
                }

            }

            
            delete current;

            
            return;
        }

        current = current->GetNext();
    }
}

/// Методы доступа
Node^ Node::GetNext()
{
	if (next != nullptr)
		return next;
	else
		return nullptr;
}

void Node::SetNext(Node^ _next) { next = _next; }

Node^ Node::GetPrev()
{
	if (next != nullptr)
		return prev;
	else
		return nullptr;
}

void Node::SetPrev(Node^ _prev) { prev = _prev; }

UserData^ Node::GetUser()
{
	return user;
}

void Node::SetUser(UserData^ _user) { user = _user; }


Node^ LinkedList::GetHead()
{
	if (head != nullptr)
		return head;
	else
		return nullptr;
}

Node^ LinkedList::GetTail()
{
	if (tail != nullptr)
		return tail;
	else
		return nullptr;
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

