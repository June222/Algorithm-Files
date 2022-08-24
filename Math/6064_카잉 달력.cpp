#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	// b가 크게끔 설정
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	if (b % a == 1)
		return 1;

	if (b % a == 0)
		return a;

	return GCD(a, b % a);
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		if (M > N)
		{
			int temp = M;
			M = N;
			N = temp;
			temp = x;
			x = y;
			y = temp;
		}

		if (x == y)
		{
			cout << x << '\n';
			continue;
		}

		bool found = false;
		int idx_num = x - 1;
		int _y = x;

		int lcm = LCM(M, N);

		while (idx_num < lcm)
		{
			idx_num += M;
			_y = idx_num % N + 1;

			if (_y == y)
			{
				found = true;
				break;
			}
		}
		if (found)
			cout << idx_num + 1 << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}