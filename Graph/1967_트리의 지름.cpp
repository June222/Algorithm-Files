#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair; // ����� ���, ���

// �׷���
vector<Pair> buff[10001];

// ���� ���� ����
int Visited[10001] = { 0 };

int N;
// ��Ʈ�κ����� �ִ�Ÿ��� �� ����ȣ.
int MM = 0, MaxNode = 1;

void DFS(int node, int sum)
{
	// �� �� ����� �缳��
	if (MM < sum)
	{
		MM = sum;
		MaxNode = node;
	}

	// ���� ���� ����
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
	
	int s, e, w; // �θ�, �ڽ�, ���

	// �׷��� �����.
	while (!(cin >> s >> e >> w).eof())
	{
		buff[s].emplace_back(e, w);
		buff[e].emplace_back(s, w);
	}

	// ��Ʈ ��忡�� ���� �ָ� �������ִ� ��带 �˻�
	DFS(1, 0);

	// �ʱ�ȭ.
	MM = 0;
	for (int i = 0; i <= N; i++)
		Visited[i] = 0;

	// ��Ʈ�κ��� ���� �ָ� �������ִ� ��忡�� �ٽ� �˻� -> ������ ����.
	DFS(MaxNode, 0);

	cout << MM;

	return 0;
}
