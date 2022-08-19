#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair; // 연결된 노드, 비용

// 그래프
vector<Pair> buff[10001];

// 무한 루프 방지
int Visited[10001] = { 0 };

int N;
// 루트로부터의 최대거리와 그 노드번호.
int MM = 0, MaxNode = 1;

void DFS(int node, int sum)
{
	// 더 먼 노드라면 재설정
	if (MM < sum)
	{
		MM = sum;
		MaxNode = node;
	}

	// 무한 루프 방지
	if (!Visited[node])
	{
		Visited[node] = 1;

		for (int i = 0; i < buff[node].size(); i++)
		{
			int nextNode = buff[node][i].first;
			int nextCost = buff[node][i].second;

			if (!Visited[nextNode])
				DFS(nextNode, sum + nextCost);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	int s, e, w; // 부모, 자식, 비용

	// 그래프 만들기.
	while (!(cin >> s >> e >> w).eof())
	{
		buff[s].emplace_back(e, w);
		buff[e].emplace_back(s, w);
	}

	// 루트 노드에서 가장 멀리 떨어져있는 노드를 검색
	DFS(1, 0);

	// 초기화.
	MM = 0;
	for (int i = 0; i <= N; i++)
		Visited[i] = 0;

	// 루트로부터 가장 멀리 떨어져있는 노드에서 다시 검색 -> 지름이 나옴.
	DFS(MaxNode, 0);

	cout << MM;

	return 0;
}
