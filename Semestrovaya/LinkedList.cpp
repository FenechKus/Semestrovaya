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

/// Ìåòîäû äîñòóïà
Node^ LinkedList::GetHead()
{
	if (head != nullptr)
		return head;
	else
		return nullptr;
}

Node^ Node::GetNext()
{
	if (next != nullptr)
		return next;
	else
		return nullptr;
}

void Node::SetNext(Node^ _next) { next = _next; }

UserData^ Node::GetUser()
{
	return user;
}

void Node::SetUser(UserData^ _user) { user = _user; }


//TODO Óäàëèòü ğåàëèçàöèş, åñëè îíà íå áóäåò èñïîëüçîâàòüñÿ
void LinkedList::printList()
{
	Node^ current = head;
	while (current != nullptr)
	{
		Windows::Forms::MessageBox::Show(current->GetUser()->lName->ToString());
		current = current->GetNext();
	}
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
