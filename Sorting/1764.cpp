#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> v;
vector <string> answer;
int N, M;
int Count = 0;

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	string name;

	// �Է¹ޱ�
	cin >> N >> M;
	while (N--) {
		cin >> name;
		v.emplace_back(name);
	}
	while (M--) {
		cin >> name;
		v.emplace_back(name);
	}

	// ���ĺ� ������ ����
	sort(v.begin(), v.end(), cmp);

	// ���� ���� ������ üũ
	for (int i = 1; i < v.size(); i++)
		if (v[i] == v[i - 1])
		{
			Count++;
			answer.emplace_back(v[i]);
		}

	cout << Count << '\n';

	auto iter = answer.begin();
	while (iter != answer.end())
		cout << (*iter++) << '\n';

	return 0;
}
