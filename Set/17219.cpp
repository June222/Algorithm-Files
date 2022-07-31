#include <iostream>
#include <map>

using namespace std;

int N, M;

// 14425
// map <key, value> 
// �迭ó�� ���尡���ϰ�,
// key�� �����Ͽ�, value�� ����.
//

map <string, string> notepad;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string site, pwd;

	cin >> N >> M;
	while (N--) {
		cin >> site >> pwd;
		// map �ڷᱸ���� �Է��� �̷� ������ ����
		notepad[site] = pwd;
	}

	while (M--) {
		cin >> site;
		// ��µ� ����.
		cout << notepad[site] << '\n';
	}
	return 0;
}
