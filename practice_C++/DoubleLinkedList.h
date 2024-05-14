#pragma once
#include "Node2.h"
#include <memory>

using namespace std;

class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	bool Delete(int idx);


	shared_ptr<Node2> GetHead() const { return head; }
	void push_back(const shared_ptr<Node2>& node);
	int GetSize() const { return mSize; }
private:
	shared_ptr<Node2> head;
	shared_ptr<Node2> tail;
	int mSize;
};

