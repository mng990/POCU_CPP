#include "linkedLIst.h"
#include <iostream>


linkedList::linkedList()
	:head(nullptr), tail(nullptr), mSize(0)
{
}

linkedList::~linkedList()
{
	cout << "LinkedList is destroyed!\n";
}

void linkedList::push_back(const shared_ptr<Node>& newNode)
{
	if (head == nullptr) 
	{
		head = newNode;
		tail = head;
	}
	else 
	{
		tail->SetNextNode(newNode);
		tail = tail->GetNextNode();
	}

	mSize++;
}
