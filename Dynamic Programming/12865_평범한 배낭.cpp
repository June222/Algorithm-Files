#include <iostream>
using namespace std;

#define MAX(a,b) ((a<=b)?b:a)

int Knapsack[100001] = { 0 };

int N, K;

void solution(int weight, int value)
{
	// �迭�� �߸��� ������ �������� ������ ����Ѵ�.
	for (int i = K; i >= weight; i--)
		Knapsack[i] = MAX(Knapsack[i - weight] + value, Knapsack[i]);
}

int main()
{
	cin >> N >> K;

	int temp = N;
	while (temp--)
	{
		int weight, value;
		cin >> weight >> value;

		solution(weight, value);
	}

	cout << Knapsack[K];

	return 0;
}