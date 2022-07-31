#include <iostream>
//2579
using namespace std;

int stairs[301][2];
int N;

int MAX(int* s1) {
	return ((s1[0] <= s1[1]) ? s1[1] : s1[0]);
}

int main() {
	int number;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> number;

		if (i == 1)
		{
			stairs[1][0] = number;
			stairs[1][1] = number;
		}
		else if (i == 2)
		{
			stairs[2][0] = number;
			stairs[2][1] = stairs[1][0] + number;
		}
		else
		{
			stairs[i][0] = MAX(stairs[i - 2]) + number;
			stairs[i][1] = stairs[i - 1][0] + number;
		}
	}

	cout << MAX(stairs[N]);

	return 0;
}


