#include <iostream>
using namespace std;

int Buffer[1001] = { 0 };
int DP[1001] = { 0 };

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Buffer[i];

	//DP[1] = 1;

	// 이렇게 초기화해야 답이 됨.
	for (int i = 1; i <= N; i++)
		DP[i] = 1;

	// 찾는 함수.
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (Buffer[j] < Buffer[i])
				if (DP[j] >= DP[i])
					DP[i] = DP[j] + 1;

	// 찾은 수 중에서 가장 긴 것.
	int MM = 0;
	for (int i = 1; i <= N; i++)
		if (MM < DP[i])
			MM = DP[i];

	cout << MM;

	return 0;
}