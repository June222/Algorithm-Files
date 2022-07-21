#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, num;
	int answer[11] = { 0,1,2,4 };

	cin >> tc;
	while (tc--) {
		cin >> num;
		for (int i = 4; i <= num; i++) {
			answer[i] = 
				answer[i - 1] + 
				answer[i - 2] + 
				answer[i - 3];
		}
		cout << answer[num] << '\n';
	}

	return 0;
}