#include "SimpleHashMap.h"
#include "Node.h"
#include <iostream>

using namespace std;

void SimpleHashMap::Add(const char* key, unsigned long hash, int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(key, value);
	int index = hash % MAX_SIZE;
	
	if (mArray[index] == nullptr)
	{
		mArray[index] = newNode;
		return;
	}

	shared_ptr<Node> current = mArray[index];
	if (current->GetKey() == key)
	{
		newNode->SetNextNode(current->GetNextNode());
		mArray[index] = newNode;
		return;
	}
	
	while (current->GetNextNode() != nullptr)
	{
		if (current->GetNextNode()->GetKey() == key)
		{
			newNode->SetNextNode(current->GetNextNode()->GetNextNode());
			current->SetNextNode(newNode);

			return;
		}

		current = current->GetNextNode();
	}

	current->SetNextNode(newNode);

	return ;
}

int SimpleHashMap::Get(const char* key, unsigned long hash) const
{
	int index = hash % MAX_SIZE;

	if (mArray[index] == nullptr)
	{
		return -1;
	}

	shared_ptr<Node> current = mArray[index];

	while (current != nullptr)
	{
		if (current->GetKey() == key)
		{
			return current->GetData();
		}

		current = current->GetNextNode();
	}
	
	return -1;
}



void SimpleHashMap::Print() const
{
	for (int i = 0; i < MAX_SIZE; i++) 
	{
		cout << "Bucket #" << i << ": ";
		if (mArray[i] != nullptr)
		{
			shared_ptr<Node> current = mArray[i];

			while (current != nullptr)
			{
				cout << "Key: " << current->GetKey() << ", Value: " << current->GetData() << " ";
				current = current->GetNextNode();
			}
		}
		cout << endl;
	}
}
