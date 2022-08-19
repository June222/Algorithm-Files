#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> Pair; // cost, end

// ��θ� ������ ��
vector<Pair> Graph[20001];

// ���� -> INT_MAX�� �ʱ�ȭ
int MinCost[20001] = { 0 };

int V, E, K;

// ���
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

// MinCost �ʱ�ȭ
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
	// �켱���� ť
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	// �־��� ����� �κ��� ť�� ����.
	for (Pair k : Graph[K])
	{
		pq.emplace(k);
	}

	while (!pq.empty())
	{
		Pair temp = pq.top();
		pq.pop();

		// ���Խÿ� �߰��ؼ� �ֱ� ������ �ջ��� ��.
		int total_cost_next_node = temp.first;
		// ���� ������
		int next_node = temp.second;

		// �������� ���ǹ�.
		if (MinCost[next_node] > total_cost_next_node)
		{
			MinCost[next_node] = total_cost_next_node;

			// ���ǿ� �ش�� ��쿡�� ť�� ���� (�޸��ʰ� ����)
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