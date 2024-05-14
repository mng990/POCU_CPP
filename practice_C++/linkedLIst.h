#pragma once
#include "Node.h"


class linkedList
{
public:
	linkedList();
	~linkedList();

	shared_ptr<Node> GetHead() { return head; }
	shared_ptr<Node> GetTail() { return tail; }

	void push_back(const shared_ptr<Node>& newNode);

private:
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
	int mSize;
};

