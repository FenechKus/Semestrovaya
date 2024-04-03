#pragma once
#include "LinkedList.h"
#include "UserData.h"



Node::Node(UserData^ _user) : user(_user), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::PushBack(UserData^ user)
{
	Node^ newNode = gcnew Node(user);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	Node^ current = head;
	while (current->GetNext() != nullptr)
	{
		current = current->GetNext();
	}
	current->SetNext(newNode);
}


Node^ LinkedList::GetHead()
{
	if (head != nullptr)
		return head;
}


Node^ Node::GetNext()
{
	if (next != nullptr)
		return next;
}

void Node::SetNext(Node^ _next) { next = _next; }

UserData^ Node::GetUser()
{
	return user;
}

void Node::SetUser(UserData^ _user) { user = _user; }


//TODO Удалить реализацию, если она не будет использоваться
void LinkedList::printList()
{
	Node^ current = head;
	while (current != nullptr)
	{
			Windows::Forms::MessageBox::Show(current->GetUser()->l_name->ToString());
			current = current->GetNext();
	}
}