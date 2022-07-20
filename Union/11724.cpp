#include <iostream>
using namespace std;


int Root[1001];
int N, M;
int GroupNum = 0;
void init() {
	int i = 1000;
	while (i > -1) {
		Root[i--] = i;
	}
}

int Find(int x) {
	if (Root[x] == x)
		return x;
	return Root[x] = Find(Root[x]);
}

void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);

	if (Root[y] == Root[x])
		return;

	Root[y] = Root[x];
}

int main()
{
	init();
	int n1, n2;
	cin >> N >> M;
	int t = M;
	while (t--) {
		cin >> n1 >> n2;
		Union(n1, n2);
	}

	for (int i = 1; i <= N; i++)
		if (Root[i] == i)
			GroupNum++;

	cout << GroupNum;
	return 0;
}