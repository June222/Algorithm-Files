#include <iostream>
#include <math.h>

using namespace std;

#define MIN(a,b) ((a>=b)?b:a)

int Answer[50001] = { 0 };

int main() {
	int N;
	cin >> N;

	Answer[1] = 1;
	Answer[2] = 2;
	Answer[3] = 3;

	for (int i = 4; i <= N; i++) {

		int sqrt_i = sqrt(i);
		int min_num_sum = 4;

		for (int j = sqrt_i; j >= 1; j--) {
			min_num_sum = MIN(min_num_sum, Answer[i - j * j] + 1);
		}

		Answer[i] = min_num_sum;
	}

	cout << Answer[N];

	return 0;
}