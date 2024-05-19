#pragma once
#include "LinkedList.h"
#include "UserData.h"



Node::Node(UserData^ _user) : next(nullptr), prev(nullptr)
{
	this->SetUser(_user);
}

// ������ �������

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
		throw gcnew System::Exception("������������ ������");
    }
    else
    {
		user = _user;
    }
}


void Node::SetNext(Node^ _next) { next = _next; }

void Node::SetPrev(Node^ _prev) { prev = _prev; }

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//------------------------------------Linked List---------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

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
    countNodes++;
}

void LinkedList::PopBack()
{

}

void LinkedList::PopFront()
{

}

void LinkedList::RemoveNode(String^ _lastName)
{
    Node^ current = head;

    while (current != nullptr) {

        if (current->GetUser()->lName == _lastName) {

            if (current == head) {
                Node^ newHead = head->GetNext();

                if (newHead != nullptr) {
                    newHead->SetPrev(nullptr);
                }
                else {
                    tail = newHead;
                }
                delete head;
                head = newHead;
                return;
            }

            if (current == tail) {
                Node^ newTail = tail->GetPrev();

                if (newTail != nullptr) {
                    newTail->SetNext(nullptr);
                }
                else {
                    head = newTail;
                }
                delete tail;
                tail = newTail;
                return;
            }

            Node^ prevNode = current->GetPrev();
            Node^ nextNode = current->GetNext();

            prevNode->SetNext(nextNode);
            nextNode->SetPrev(prevNode);

            delete current;
            countNodes--;
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
        if (curentNode->GetUser()->phone == _user->phone /*&& curentNode->GetUser()->lName != _user->lName*/)
        {
            throw gcnew System::Exception("����� ��� ������������");
        }
        curentNode = curentNode->GetNext();
    }
    return true;
}


void LinkedList::UpdateBindingGridView(LinkedList^ _list, DataGridView^ _dataGridView, String^ _mode)
{
    int counterNotes = 0;
    // �������� ��� ������ � DataGridView
    _dataGridView->Rows->Clear();
    
    // �������� � ������ ������
    Node^ currentNode;
    if (_mode == "front" or _mode == nullptr)
        currentNode = _list->GetHead();
    else
        currentNode = _list->GetTail();


    // �������� �� ������� ���� � ������
    while (currentNode != nullptr) {
        // ������� ����� ������ ��� DataGridView
        DataGridViewRow^ row = gcnew DataGridViewRow();

        // ������� ������ � ������
        row->CreateCells(_dataGridView);

        // ������������� �������� ��� ������ ������ �� �������� ����
        row->Cells[0]->Value = currentNode->GetUser()->lName;
        row->Cells[1]->Value = currentNode->GetUser()->yearStartUp;
        row->Cells[2]->Value = currentNode->GetUser()->phone;
        row->Cells[3]->Value = currentNode->GetUser()->street;
        row->Cells[4]->Value = currentNode->GetUser()->house;
        if (currentNode->GetUser()->numberApart == 0)
        {
            row->Cells[5]->Value = "������� ���";
        }
        else
        row->Cells[5]->Value = currentNode->GetUser()->numberApart;

        // ��������� ������ � DataGridView
        _dataGridView->Rows->Add(row);
        counterNotes++;

        // ��������� � ���������� ����
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

int LinkedList::FindNode(int _yearStartup)
{
	int counterNodes = 0;
    Node^ curentNode = head;
    while (curentNode != nullptr)
    {
        if (curentNode->GetUser()->yearStartUp == _yearStartup)
        {
            counterNodes++;
        }
        curentNode = curentNode->GetNext();
    }
    return counterNodes;
}

LinkedList^ LinkedList::FindNode(String^ _street, int _house)
{
    LinkedList^ findlist = gcnew LinkedList();
    Node^ curentNode = head;

	while (curentNode != nullptr)
    {
        auto user = curentNode->GetUser();
	    if (user->street == _street && user->house == _house)
	    {
			findlist->PushBack(curentNode->GetUser());
	    }
        curentNode = curentNode->GetNext();
    }
    return findlist;
}

typedef int (*CompareFunc)(UserData^, UserData^);
LinkedList^ LinkedList::SortBy(CompareFunc compareFunc)
{
    if (head == nullptr) return this;

    int length = countNodes;

    // ���������� �����
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            // ����� i-� �������
            Node^ tempNode = head;
            for (int k = 0; k < i; k++) {
                tempNode = tempNode->GetNext();
            }
            UserData^ tempData = tempNode->GetUser();

            // ����������� �������� tempNode � ��������������� ����� ������
            Node^ jNode = tempNode;
            while (jNode != nullptr) {
                Node^ gapNode = jNode;
                for (int k = 0; k < gap; k++) {
                    if (gapNode->GetPrev() != nullptr) {
                        gapNode = gapNode->GetPrev();
                    }
                    else {
                        gapNode = nullptr;
                        break;
                    }
                }

                if (gapNode == nullptr || compareFunc(gapNode->GetUser(), tempData) <= 0) {
                    break;
                }

                jNode->SetUser(gapNode->GetUser());
                jNode = gapNode;
            }
            jNode->SetUser(tempData);
        }
    }

    return this;
}

int CompareByLastName(UserData^ a, UserData^ b) {
    return String::Compare(a->lName, b->lName);
}

int CompareByPhone(UserData^ a, UserData^ b) {
    return String::Compare(a->phone, b->phone);
}

int CompareByStreet(UserData^ a, UserData^ b) {
	return String::Compare(a->street, b->street);
}

int CompareByYear(UserData^ a, UserData^ b) {
    if (a->yearStartUp > b->yearStartUp) {
        return 1;
    }
    else if (a->yearStartUp < b->yearStartUp) {
        return -1;
    }
    else {
        return 0;
    }
}



LinkedList^ LinkedList::SortByLastName()
{
    return SortBy(CompareByLastName);
}

LinkedList^ LinkedList::SortByPhone()
{
    return SortBy(CompareByPhone);
}

LinkedList^ LinkedList::SortByYear()
{
    return SortBy(CompareByYear);
}

LinkedList^ LinkedList::SortByStreet()
{
    return SortBy(CompareByStreet);
}