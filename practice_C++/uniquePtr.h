#pragma once
#include <iostream>
#include <memory>
#include <vector>

using namespace std;


void usingUniquePoitners()
{
	unique_ptr<int> num1 = make_unique<int>(5);
	unique_ptr<char> char1 = make_unique<char>('A');

	cout << *num1 << endl;
	cout << *char1 << endl;

	unique_ptr<vector<int>> vec = make_unique<vector<int>>(1, 3);

	cout << vec->at(0) << endl;
	
	// Compiler error
	// 원시 포인터(vector<int>*)의 소유권이 두 명 이상
	// unique_ptr<vector<int>> copyOfVector = vec;

	num1.reset();
	vec = nullptr;
	unique_ptr<char> char2(move(char1));

	cout << "Char2: " << *char2 << endl;

	const unique_ptr<float> float1 = make_unique<float>(2.0f);

	// Compile error
	//unique_ptr<float> float2(move(float1));
	// float1.reset(neq float(1.f));
}


