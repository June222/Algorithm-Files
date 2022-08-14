#include <iostream>

using namespace std;

#define MIN(a,b) ((a>=b)?b:a)

int House[1001][3] = { 0 };

int N;

int main()
{
	int R, G, B;

	cin >> N;

	cin >> R >> G >> B;
	House[1][0] = R; House[1][1] = G; House[1][2] = B;

	for (int i = 2; i <= N; i++)
	{
		cin >> R >> G >> B;

		House[i][0] = MIN(House[i - 1][1], House[i - 1][2]) + R;
		House[i][1] = MIN(House[i - 1][0], House[i - 1][2]) + G;
		House[i][2] = MIN(House[i - 1][0], House[i - 1][1]) + B;
	}

	cout << MIN(House[N][0], MIN(House[N][1], House[N][2]));

	return 0;
}