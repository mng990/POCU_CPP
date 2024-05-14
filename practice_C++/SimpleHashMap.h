#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class SimpleHashMap
{
public:
	SimpleHashMap() = default;
	~SimpleHashMap() = default;

	void Add(const char* key, unsigned long hash, int value);
	int Get(const char* key, unsigned long hash) const;
	void Print() const;

private:
	static constexpr int MAX_SIZE = 10;
	// 해쉬 충돌 시, 리스트로 저장
	shared_ptr<Node> mArray[MAX_SIZE];
};

