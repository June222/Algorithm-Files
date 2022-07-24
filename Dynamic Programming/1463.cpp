#include <iostream>

using namespace std;

#define Min(a,b) ((a>b)?b:a)

int buffer[100001] = { 0 };
int N;

int main() {
	cin >> N;
	buffer[1] = 0;

	for (int i = 2; i <= N; i++) {
		buffer[i] = buffer[i - 1] + 1;
		if (i % 2 == 0)
			buffer[i] = Min(buffer[i], buffer[i / 2] + 1);
		if (i % 3 == 0)
			buffer[i] = Min(buffer[i], buffer[i / 3] + 1);
	}
	cout << buffer[N];

	return 0;
}