#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> Pair; // cost, end

// 경로를 저장할 곳
vector<Pair> Graph[20001];

// 정답 -> INT_MAX로 초기화
int MinCost[20001] = { 0 };

int V, E, K;

// 출력
void printAns()
{
	for (int i = 1; i <= V; i++)
	{
		if (MinCost[i] == 2e9)
			cout << "INF\n";
		else
			cout << MinCost[i] << '\n';
	}
}

// MinCost 초기화
void init()
{
	for (int i = 0; i <= V; i++)
	{
		if (i == K)
			MinCost[0];

		else
			MinCost[i] = 2e9;
	}
}

void solution()
{
	// 우선순위 큐
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	// 주어진 출발지 부분을 큐에 삽입.
	for (Pair k : Graph[K])
	{
		pq.emplace(k);
	}

	while (!pq.empty())
	{
		Pair temp = pq.top();
		pq.pop();

		// 삽입시에 추가해서 넣기 때문에 합산이 됨.
		int total_cost_next_node = temp.first;
		// 다음 도착지
		int next_node = temp.second;

		// 간단해진 조건문.
		if (MinCost[next_node] > total_cost_next_node)
		{
			MinCost[next_node] = total_cost_next_node;

			// 조건에 해당될 경우에만 큐에 삽입 (메모리초과 방지)
			for (Pair a : Graph[next_node])
			{
				pq.emplace(a.first + total_cost_next_node, a.second);
			}
		}
	}

	printAns();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> K;
	init();
	while (E--)
	{
		int s, e, c;
		cin >> s >> e >> c;

		Graph[s].emplace_back(c, e);
	}

	solution();

	return 0;
}