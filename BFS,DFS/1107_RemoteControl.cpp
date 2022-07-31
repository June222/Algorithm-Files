#include <iostream>

using namespace std;

#define MIN(a,b) ((a>=b)?b:a)

bool Broken[10] = { 0 };
int N, M;
int digit_num = 1;
int Min_Times = 550000;

void DFS(int sum, int cnt) {

	if (cnt > digit_num + 1)
		return;

	if (cnt == digit_num - 1 || cnt == digit_num || cnt == digit_num + 1)
		Min_Times = MIN(Min_Times, abs(N - sum) + cnt);

	sum *= 10;

	for (int i = 0; i < 10; i++)
		if (!Broken[i])
			DFS(sum + i, cnt + 1);
	
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int broken;

	cin >> N >> M;
	while (M--)
	{
		cin >> broken;
		Broken[broken] = 1;
	}

	int temp = N;
	while (temp /= 10)
	{
		digit_num++;
	}

	for (int i = 0; i < 10; i++)
		if (!Broken[i])
			DFS(i, 1);

	Min_Times = MIN(Min_Times, abs(N - 100));

	cout << Min_Times;

	return 0;
}