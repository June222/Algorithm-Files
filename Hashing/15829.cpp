#include <iostream>

using namespace std;

#define M 1544

int main() {
	int L;
	string str;
	int result = 0;
	cin >> L >> str;
	for (int i = 0; i < L; i++) {
		long long hash = 1;
		for (int j = i; j <= i) {
			hash *= 31;
			hash %= M;
		}
		result += (str[i] - 97) * hash;
		result %= M;
	}
	cout << result;
}