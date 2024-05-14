#pragma once
#include <memory>

using namespace std;

class Node2
{
public:
	Node2() = default;
	Node2(int data);
	~Node2();

	int GetData() const { return mData; }

	shared_ptr<Node2> mNext;
	weak_ptr  <Node2> mPrev;

private:
	int mData;
	
};

