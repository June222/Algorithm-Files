#include <iostream>

using namespace std;


long long DivideAndConquer(int A, int B, int C)
{
	if (B == 1)
		return A % C;

	else if (B > 2)
	{
		long long halfExp = DivideAndConquer(A, B / 2, C);

		if (B % 2 == 0)
			return (halfExp * halfExp) % C;

		else
			return (((halfExp * halfExp) % C) * A) % C;
	}
}

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	cout << DivideAndConquer(A, B, C);

	return 0;
}