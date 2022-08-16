#include <iostream>

using namespace std;

int chk[10001] = { 0 };

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	while (N--)
	{
		int num;
		cin >> num;
		chk[num]++;
	}

	for (int i = 1; i <= 10000; i++)
		while (chk[i]--)
			cout << i << '\n';

	return 0;
}