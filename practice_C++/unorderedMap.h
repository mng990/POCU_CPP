#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <chrono>

using namespace std;

void bucketList()
{
	unordered_map<string, int> testBucket;

	testBucket["Coco"] = 1;
	testBucket["Astro"] = 2;
	testBucket["Bear"] = 3;
	testBucket["Coke"] = 4;
	testBucket["RealForce"] = 5;
	testBucket["Tophre"] = 6;

	for (int i = 0; i < testBucket.bucket_count(); i++)
	{
		cout << "Bucket #" << i << endl;

		for (auto it = testBucket.begin(i); it != testBucket.end(i); it++)
		{
			cout << it->first << "/" << it->second << " ";
		}
		cout << endl;
	}
}

void speedTest() 
{
	set<int> orderedSet;
	unordered_set<int> unorderedSet;

	const int NUMBER_TO_INSERT_LATER = 1023;
	const int MAX_NUMBER_IN_SET = 100000;

	unorderedSet.reserve(MAX_NUMBER_IN_SET);

	static_assert(MAX_NUMBER_IN_SET > NUMBER_TO_INSERT_LATER, "MAX_NUMBER_IN_SET should be greater than NUMBER_TO_INSERT");

	for (int i = 0; i < MAX_NUMBER_IN_SET; i++)
	{
		if (i == NUMBER_TO_INSERT_LATER) continue;

		orderedSet.insert(i);
		unorderedSet.insert(i);
	}

	auto start = chrono::high_resolution_clock::now();
	orderedSet.insert(NUMBER_TO_INSERT_LATER);

	auto end = chrono::high_resolution_clock::now();
	auto elapsedNanoSeconds = end - start;

	cout << "Inserting into orderedSet: " << elapsedNanoSeconds.count() << " ns" << endl;

	start = chrono::high_resolution_clock::now();
	unorderedSet.insert(NUMBER_TO_INSERT_LATER);
	end = chrono::high_resolution_clock::now();
	elapsedNanoSeconds = end - start;

	cout << "Inserting into unorderedSet: " << elapsedNanoSeconds.count() << " ns" << endl;

	return ;
}