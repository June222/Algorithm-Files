#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool Visited[1001] = { 0 };
vector<int> buffer[1001];
int N, M, V;

void DFS(int start) {

	Visited[start] = 1;

	// 여기가 문제.
	cout << start << " ";

	for (int i = 0; i < buffer[start].size(); i++)
		if (!Visited[buffer[start][i]])
			DFS(buffer[start][i]);
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	Visited[start] = 1;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		cout << temp << " ";

		for (int i = 0; i < buffer[temp].size(); i++)
			if (!Visited[buffer[temp][i]]) {
				q.push(buffer[temp][i]);
				Visited[buffer[temp][i]] = 1;
			}
	}
}

void initVisited() {
	for (int i = 0; i < 1001; i++)
		Visited[i] = 0;
}

int main() {
	int n1, n2;
	cin >> N >> M >> V;

	while (M--) {
		cin >> n1 >> n2;
		buffer[n1].push_back(n2);
		buffer[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++)
		sort(buffer[i].begin(), buffer[i].end());

	DFS(V);

	cout << '\n';

	initVisited();

	BFS(V);

	return 0;
}