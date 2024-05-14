#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList()
	:head(nullptr), tail(nullptr), mSize(0)
{
}

DoubleLinkedList::~DoubleLinkedList()
{
	cout << "LinkedList is destroyed!!\n";
}

bool DoubleLinkedList::Delete(int data)
{
	shared_ptr<Node2> iter = head;
	
	while (iter->GetData() != data) 
	{
		iter = iter->mNext;
	}

	if (iter == nullptr) return false;

	weak_ptr<Node2> iterNext = iter->mNext;
	weak_ptr<Node2> iterPrev = iter->mPrev;

	if (iterNext.lock() != nullptr && iterPrev.lock() != nullptr) 
	{
		iterPrev.lock()->mNext = iterNext.lock();
		iterNext.lock()->mPrev = iterPrev.lock();
	}

	if (iter == head)
	{
		head = head->mNext;
	}
	
	if (iter == tail) 
	{
		tail = iterPrev.lock();
		tail->mNext = nullptr;
	}

	iter = nullptr;
	
	mSize--;

	return true;
}

void DoubleLinkedList::push_back(const shared_ptr<Node2>& node)
{
	shared_ptr<Node2> newNode = node;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->mNext = newNode;
		newNode->mPrev = tail;
		tail = newNode;
	}

	mSize++;

	return ;
}
