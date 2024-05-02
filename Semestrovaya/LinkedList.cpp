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

                System::Diagnostics::Debug::WriteLine("prevNode �� " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail �� " + tail->GetUser()->lName);

                tail = current->GetPrev();

                if (tail != nullptr) {
                    tail->SetNext(nullptr);
                }

                System::Diagnostics::Debug::WriteLine("prevNode �� " + current->GetPrev()->GetUser()->lName);
                System::Diagnostics::Debug::WriteLine("tail �� " + tail->GetUser()->lName);
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

/// ������ �������
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

        System::Diagnostics::Debug::WriteLine("�������: ", user->lName);
        if(currentNode->GetPrev())
			System::Diagnostics::Debug::WriteLine("������� ����������� �� ������ ", currentNode->GetPrev()->GetUser()->lName);
        else
            System::Diagnostics::Debug::WriteLine("������� ����������� �� ������ NULL");
        if (currentNode->GetNext())
            System::Diagnostics::Debug::WriteLine("������� ���������� �� ������ ", currentNode->GetNext()->GetUser()->lName);
        else
            System::Diagnostics::Debug::WriteLine("������� ���������� �� ������ NULL");

    	System::Diagnostics::Debug::WriteLine("----------");


        currentNode = currentNode->GetNext();
    }
}

void LinkedList::DEBUG_PrintListToConsoleList()
{
    // �������� � ������ ������
    Node^ currentNode = head;

    // �������� �� ������� ���� � ������
    while (currentNode != nullptr)
    {
        // �������� ������ ������������ �� �������� ����
        UserData^ user = currentNode->GetUser();

        // ������� ������ ������������ � �������
        System::Diagnostics::Debug::WriteLine(""); // ������ ������ ��� ���������� �������
        System::Diagnostics::Debug::WriteLine("�������: {0}", user->lName);
        System::Diagnostics::Debug::WriteLine("��� ���������: {0}", user->year_start_up);
        System::Diagnostics::Debug::WriteLine("�������: {0}", user->phone);
        System::Diagnostics::Debug::WriteLine("�����: {0}", user->street);
        System::Diagnostics::Debug::WriteLine("���: {0}", user->house);
        System::Diagnostics::Debug::WriteLine("��������: {0}", user->number_apart);
        System::Diagnostics::Debug::WriteLine(""); // ������ ������ ��� ���������� �������

        

        // ��������� � ���������� ����
        currentNode = currentNode->GetNext();
    }
}

