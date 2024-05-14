#pragma once

constexpr int Factorial(int n)
{
	return n <= 1 ? 1 : n * Factorial(n - 1);
}

void constexprTest() {

	int value = 3;
	int result1 = Factorial(value);

	// value 값이 결정되지 않아 
	// 컴파일 도중 값 평가 불가
	constexpr int result2 = Factorial(value);

	constexpr int result3 = Factorial(3);

	// 재귀 호출이 과한 경우
	// 컴파일러가 이를 거부할 수 있음
	constexpr int result4 = Factorial(30);

	return;
}