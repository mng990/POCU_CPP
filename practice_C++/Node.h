#pragma once
#include <string>
#include <memory>

using namespace std;

class Node final
{
public:
	Node() = delete;
	Node(const char* key, int data);
	~Node();

	int GetData() const { return mData; }

	const string& GetKey() const { return mKey; }
	
	shared_ptr<Node> GetNextNode() const;
	void SetNextNode(const shared_ptr<Node>& next);

private:
	int mData;
	string mKey;
	shared_ptr<Node> mNext;
};

