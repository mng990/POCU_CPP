#pragma once
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


void NoCaptureFunc() 
{
	auto noCapture = []() {cout << "No capturing example 1" << endl; };

	// 실행 예시 1
	noCapture();

	// 실행 예시 2
	[] {cout << "No capturing example 2" << endl; }();
	
	return;
}

void CaptureByValue() 
{
	float score1 = 80.f;
	float score2 = 20.f;

	// 값에 의한 캡쳐 ([=])
	// 모든 로컬 변수 사용 가능
	// 값 수정은 불가능
	auto max = [=]() {return score1 > score2 ? score1 : score2; };

	cout << "Max value is " << max() << endl;

	return;
}

void CaptureByReference()
{
	float score1 = 80.f;
	float score2 = 20.f;

	auto changeValue = [&]()
	{
		score1 = 60.f;
		score2 = 55.f;
	};

	changeValue();
}

void CaptureByValue2()
{
	float score1 = 80.f;
	float score2 = 20.f;
	float score3 = 40.f;

	auto specificCapture = [score1, score3]()->bool
	{
		return score1 > score3;
	};

	cout << specificCapture() << endl;
}

void CaptureByReference2()
{
	float score1 = 80.f;
	float score2 = 20.f;
	float score3 = 40.f;

	auto specificCapture = [&score1, &score3]()->void
		{
			float temp = score1;
			score1 = score3;
			score3 = temp;
			cout << "score1: " << score1 << " / " << "score3: " << temp << endl;
		};
	
	specificCapture();
}

void CaptureMixed() 
{
	float score1 = 80.f;
	float score2 = 40.f;
	float score3 = 20.f;


	auto changeValue = [=, &score1]()
		{
			score1 = score2;

			cout << "score1 = score2" << endl;
			cout << "score1: " << score1 << ", score2: " << score2 << endl;
		};

	auto changeValue2 = [&, score1]()
		{
			score2 = score1;
			
			cout << "score2 = score1" << endl;
			cout << "score2: " << score2 << ", score1: " << score1 << endl;
		};

	changeValue();
	changeValue2();

	return;
}

void SortByLambda() 
{
	vector<float> scores;

	scores.push_back(40.f);
	scores.push_back(50.f);
	scores.push_back(30.f);

	sort(scores.begin(), scores.end(), [](float a, float b) { return a < b; });

	for (auto num : scores) 
	{
		cout << num << endl;
	}
	
	return;
}

void SpecifiersInLambda() 
{
	int value = 10;
	
	// mutable 
	// 값에 의한 캡처로 가져온 로컬 변수도 수정 가능
	auto lambda = [value]() mutable 
	{
		for(;value<=15;value++) 
			cout << value << endl;
	};
	
	lambda();
}