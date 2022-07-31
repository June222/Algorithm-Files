
#include <iostream>
#include <set>

using namespace std;

int N, M;
int Count = 0;
set <string> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;

	cin >> N >> M;
	while (N--) {
		cin >> str;
		s.insert(str);
	}

	while (M--) {
		cin >> str;
		auto iter = s.find(str);
		if (iter != s.end())
			Count++;
	}

	cout << Count;

	return 0;
}