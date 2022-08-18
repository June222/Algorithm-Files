#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair> G[100001];

bool Visited[100001] = { 0 };

int V;
int FarthestNode = 0, MM = 0;

void FindFarthestNode(int node, int sum)
{
	// 위치 중요
	if (MM < sum)
	{
		MM = sum;
		FarthestNode = node;
	}

	for (int i = 0; i < G[node].size(); i++)
	{
		// 무한 루프 방지
		if (!Visited[G[node][i].first])
		{
			// DFS로 구현.
			Visited[G[node][i].first] = 1;
			FindFarthestNode(G[node][i].first, sum + G[node][i].second);
			Visited[G[node][i].first] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V;

	int temp = V;
	while (temp--)
	{
		int v_s, v_e, cost;
		cin >> v_s >> v_e;
		while (v_e != -1)
		{
			cin >> cost;
			G[v_s].emplace_back(v_e, cost);
			cin >> v_e;
		}
	}

	Visited[1] = 1;
	FindFarthestNode(1, 0);
	Visited[1] = 0;

	// 가장 먼 노드로부터 재검색.
	MM = 0;
	Visited[FarthestNode] = 1;
	FindFarthestNode(FarthestNode, 0);

	cout << MM;

	return 0;
}