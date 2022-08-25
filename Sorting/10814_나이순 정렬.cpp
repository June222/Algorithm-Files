#include <iostream>
#include <algorithm>
using namespace std;

pair<int, string> buff[100001];

int N;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; string name;
		cin >> num >> name;
		buff[i] = { num,name };
	}

	stable_sort(buff, buff + N, cmp);

	for (int i = 0; i < N; i++)
		cout << buff[i].first << " " << buff[i].second << '\n';

	return 0;
}