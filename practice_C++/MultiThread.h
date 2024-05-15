#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

void PrintMessage(const std::string& message)
{
	std::cout << message << std::endl;
}

void PrintMessageLoop(const std::string& message, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << i + 1 << ": " << message << std::endl;
	}
}

void PrintMessageYield(const std::string& message, std::chrono::seconds delay)
{
	auto end = std::chrono::high_resolution_clock::now() + delay;

	while (std::chrono::high_resolution_clock::now() < end)
	{
		std::this_thread::yield();
	}

	std::cout << message << std::endl;
}

void PrintMessageMutex(const std::string& message)
{
	static std::mutex sMutex; // 공유 자원

	// lock이 풀리기 전까지
	// 현 쓰레드를 제외한 나머지 쓰레드는 해당 로직에 접근 불가
	sMutex.lock(); 
	std::cout << message << std::endl;
	sMutex.unlock();
}
void PrintMessageScopedLock(const std::string& message)
{
	static std::mutex sMutex;

	// scoped_lock 개체가 존재하는 동안 lock을 걺
	// 해당 개체가 사라지는 순간 unlock 
	// (shared_ptr의 메모리 할당/해제와 유사)
	std::scoped_lock<std::mutex> lock(sMutex);
	std::cout << message << std::endl;
}

void PrintMessageMultiScopedLock(const std::string& message)
{
	static std::mutex sMutex;

	{
		// 해당 스코프를 벗어나면 scoped_lock 개체가 소멸
		// 자연스레 lock, unlock 기능이 동작
		std::scoped_lock<std::mutex> lock(sMutex);
		std::cout << "Message from thread ID " << std::this_thread::get_id() << std::endl;
	}

	// 여러 스레드가 공유하는 로직

	{
		std::scoped_lock<std::mutex> lock(sMutex);
		std::cout << message << std::endl;
	}
}




void MakeChildThread() {
	std::thread thread1(PrintMessage, "Message from a child thread.");
	PrintMessage("Message from a main thread.");

	// child thread가 실행을 마치고 복귀할 때까지
	// main thread가 대기
	thread1.join();

	return;
}

void GetThreadID()
{
	std::thread thread(PrintMessage, "Message from a child thread.");

	std::thread::id childThreadID = thread.get_id();
	std::thread::id mainThreadID = std::this_thread::get_id();

	PrintMessage("Message from a main thread.");

	std::stringstream ss;
	ss << childThreadID;
	std::string childThreadIDStr = ss.str();

	ss.clear();
	

	ss << mainThreadID;

	std::string mainThreadIDStr = ss.str();

	// OS마다 Thread ID의 자료형이 다름
	PrintMessage("Waiting the child thread (ID: "+ childThreadIDStr + ")");
	thread.join();
	PrintMessage("Waiting the main thread (ID: " + mainThreadIDStr + ")");
	return;
}

void DetachChildThread() 
{

	std::thread thread(PrintMessageLoop, "Message from a child thread.", 10);

	PrintMessageLoop("Waiting the child thread...", 1);

	// child thread를 main thread에서 분리
	// 그러나 main thread가 끝날 때, 
	// 로컬 변수였던 child thread도 함께 종료
	thread.detach();

	std::this_thread::sleep_for(std::chrono::seconds(3));
	return ;
}

void CheckJoinable()
{
	std::thread thread(PrintMessageLoop, "Message from a child thread.", 10);

	PrintMessageLoop("Waiting the child thread...", 1);

	thread.detach();

	// main에서 detach된 child thread는 
	// 다시 join 불가
	std::this_thread::sleep_for(std::chrono::seconds(1));

	if (thread.joinable())
	{
		cout << "Join (ID: " << thread.get_id() << ")" << endl;
		thread.join();
	}

	return;
}

void usingLambda()
{
	auto printMessage = [](const std::string& message)
		{
			std::cout << message << std::endl;
		};

	std::thread thread(printMessage, "Messgae from a child thread.");
	printMessage("Waiting the child thread...");
	thread.join();

	return ;
}

void passTheReference()
{
	std::vector<int> list(100,1);
	int result = 0;

	std::thread thread([](const std::vector<int>& v, int& result)
		{
			for (auto item : v)
			{
				result += item;
			}
		}, list, std::ref(result));

	thread.join();
	//thread.detach();
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "Result: " << result << std::endl;

	return;
}

void usingYield()
{
	// 3초 대기
	std::thread thread(PrintMessageYield, "Message from a child thread.", std::chrono::seconds(3));

	// 2초 대기
	PrintMessageYield("Message from a main thread.", std::chrono::seconds(2));

	thread.join();

	return;
}

void usingMutex() 
{
	std::thread thread(PrintMessageMutex, "Message from a child thread.");

	PrintMessageMutex("Message from a main thread.");

	thread.join();

	return;
}

void usingScopedLock()
{
	std::thread thread(PrintMessageMultiScopedLock, "Message from a child thread.");
	PrintMessageMultiScopedLock("Message from a main thread.");

	thread.join();

	return;
}



void multiThreadingExample()
{
	static mutex sMutex;
	static int sNumber = 10;

	auto Multiply = [](int rhs) {
		scoped_lock<mutex> lock(sMutex);
		cout << "Executing Multiply" << endl;
		sNumber *= rhs;
	};

	auto SlowAdd = [&](int rhs) 
	{
		{
			scoped_lock<mutex> lock(sMutex);
			cout << "Executing SlowAdd" << endl;
		}
		this_thread::sleep_for(chrono::seconds(1)); 
		{
			scoped_lock<mutex> lock(sMutex);
			cout << "SlowAdd Adding.." << endl;
			sNumber += rhs;
		}
	};

	auto MultiThreadingExample = [&]()
	{
		thread childThread1(SlowAdd, 10);
		Multiply(10);

		if (childThread1.joinable())
		{
			{
				scoped_lock<mutex> lock(sMutex);
				cout << "childThread1 is joinable!" << endl;
			}
			childThread1.join();
		}

		cout << sNumber << endl;
		sNumber = 10;

		thread childThread2(SlowAdd, 10);

		if (childThread2.joinable())
		{
			{
				scoped_lock<mutex> lock(sMutex);
				cout << "childThread2 is joinable" << endl;
			}
			childThread2.join();
		}

		Multiply(10);

		cout << sNumber << endl;
		sNumber = 10;
	};

	MultiThreadingExample();
}