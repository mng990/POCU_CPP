#pragma once

constexpr int Factorial(int n)
{
	return n <= 1 ? 1 : n * Factorial(n - 1);
}

void constexprTest() {

	int value = 3;
	int result1 = Factorial(value);

	// value ���� �������� �ʾ� 
	// ������ ���� �� �� �Ұ�
	constexpr int result2 = Factorial(value);

	constexpr int result3 = Factorial(3);

	// ��� ȣ���� ���� ���
	// �����Ϸ��� �̸� �ź��� �� ����
	constexpr int result4 = Factorial(30);

	return;
}