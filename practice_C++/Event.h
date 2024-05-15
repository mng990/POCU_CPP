#pragma once
#include <iostream>
#include <mutex>
#include <queue>

static std::mutex sQueueLock;
static std::condition_variable sEvent;
static std::queue<int> sQueue;

void BadConsume()
{
	while (true)
	{
		int val;

		{
			std::unique_lock<std::mutex> lock(sQueueLock);
			
			sEvent.wait(lock); // 5 -> �̺�Ʈ�� �����ϴ� ����(3)�� �̹� ����� ��Ȳ
			// event �ֱⰡ ���̸� ���� X

			val = sQueue.front();
			sQueue.pop();
		}

		std::cout << val << std::endl;
	}
}

void Consume()
{
	while (true)
	{
		int val;
		{
			std::unique_lock<std::mutex> lock(sQueueLock);
			// if sQueue.empty() => wait ����
			sEvent.wait(lock, [] {return !sQueue.empty(); });
			val = sQueue.front();
			sQueue.pop();
		}

		if (val == -1) break;

		std::cout << "Consumer::Buying." << std::endl;
		std::cout << val << std::endl;
	}
}

void Produce(int num)
{
	std::unique_lock<std::mutex> lock(sQueueLock);
	sQueue.push(num); // 2

	sEvent.notify_one(); // 3
}



void BadMarket()
{
	// ���������� wait�� �ɸ��� ���

	std::thread producer(Produce, 1); // 1
	std::thread consumer(BadConsume); // 4 

	consumer.join();
	producer.join();

	return ;
}

void BestMarket()
{
	std::thread consumer(Consume);
	std::thread producer1(Produce, 1);
	std::thread producer2(Produce, 2);
	std::thread producer3(Produce, 3);
	std::thread end(Produce, -1);


	consumer.join();
	producer1.join();
	producer2.join();
	producer3.join();	
	end.join();

	return;
}