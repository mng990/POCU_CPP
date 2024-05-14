#include "Node2.h"
#include <iostream>

using namespace std;

Node2::Node2(int data)
	:mData(data), mNext(nullptr)
{
}

Node2::~Node2()
{
	cout << mData << " is destroyed!\n";
}
