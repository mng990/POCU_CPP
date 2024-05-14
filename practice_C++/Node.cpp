#include "Node.h"
#include <iostream>


Node::Node(const char* key, int data)
	: mKey(key), mData(data), mNext(nullptr)
{
}

Node::~Node()
{
	cout << "Node is destoryed!\n";
}

shared_ptr<Node> Node::GetNextNode() const
{
	return mNext;
}

void Node::SetNextNode(const shared_ptr<Node>& next)
{
	mNext = next;

	return ;
}

