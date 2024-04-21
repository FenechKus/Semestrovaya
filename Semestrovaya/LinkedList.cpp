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
	}
	else
	{
		tail->SetNext(newNode);
		newNode->SetPrev(tail);
		tail = newNode;
	}
	
}

/// Ìåòîäû äîñòóïà
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

///TODO (CRITICAL) ÏĞÎÂÅĞÈÒÜ ĞÅÀËÈÇÀÖÈŞ

//UserData LinkedList::GetUserData(String^ string)
//{
//	Node^ current = head;
//	while (current->GetUser()->lName != string)
//	{
//		current = current->GetNext();
//	}
//	return *current->GetUser();
//}
//
//void LinkedList::SetUserData(UserData^ user)
//{
//	Node^ current = head;
//	while (current->GetUser()->lName != user->lName)
//	{
//		current = current->GetNext();
//	}
//	current->SetUser(user);
//}
