#pragma once
#include <mutex>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

static mutex sMutex;
static condition_variable sEvent;
static int seconds;
constexpr int MAX_SECONDS = 10;

void Timer()
{
	while (true)
	{
		{
			scoped_lock<mutex> lock(sMutex);
			cout << seconds << endl;
		}

		this_thread::sleep_for(chrono::seconds(1));
		{
			unique_lock<mutex> lock(sMutex);
			seconds++;

			// 1초마다 이벤트 발생
			sEvent.notify_one();
		}
	}
}

void Resetter()
{
	while (true)
	{
		unique_lock<mutex> lock(sMutex);
		sEvent.wait(lock, [] {return seconds >= MAX_SECONDS; });

		seconds = 0;
		cout << "Reset: " << seconds << endl;
	}
}

void AutoResetTimerExample()
{
	thread timer(Timer);
	thread resetter(Resetter);
	resetter.join();
	timer.join();
}