#pragma once
#include "SimpleHashMap.h"

constexpr unsigned long HashFunction(const char* s)
{
	int i = 0;
	unsigned long sum = 0;
	while (s[i] != '\0')
	{
		sum += s[i++];
	}

	return sum;
}

void SimpleHashMapExample()
{
	SimpleHashMap map;

	constexpr unsigned long test1 = HashFunction("test1");

	map.Add("test1", test1, 1);
	map.Add("test2", HashFunction("test2"), 2);
	map.Add("test3", HashFunction("test3"), 3);
	map.Add("test4", HashFunction("test4"), 4);
	map.Add("test5", HashFunction("test5"), 5);
	map.Add("test15", HashFunction("test15"), 11);


	map.Print();

	map.Add("test1", HashFunction("test1"), 10);
	map.Add("test5", HashFunction("test5"), 100);

	cout << map.Get("test2", HashFunction("test2")) << endl;
	cout << map.Get("nokey", HashFunction("nokey")) << endl;
}

