#include <iostream>
#include <map>

using namespace std;

int N, M;

// 14425
// map <key, value> 
// 배열처럼 저장가능하고,
// key로 접근하여, value를 가짐.
//

map <string, string> notepad;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string site, pwd;

	cin >> N >> M;
	while (N--) {
		cin >> site >> pwd;
		// map 자료구조의 입력은 이런 식으로 가능
		notepad[site] = pwd;
	}

	while (M--) {
		cin >> site;
		// 출력도 가능.
		cout << notepad[site] << '\n';
	}
	return 0;
}
