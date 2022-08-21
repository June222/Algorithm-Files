using namespace std;

#define MIN(a,b) ((a>=b)?b:a)

struct bus {
	int home, start, end, cost;
	bus(int _h, int _s, int _e, int _c) :home(_h), start(_s), end(_e), cost(_c) {}
};

struct compare {
	bool operator()(bus a, bus b) {
		return a.cost > b.cost;
	}
};

priority_queue<bus, vector<bus>, compare> pq;

int Cost[101][101] = { 0 };
bool Visited[101][101] = { 0 };

int N, M;

void solution()
{
	while (!pq.empty())
	{
		bus temp = pq.top();
		pq.pop();

		// ���� �����, �鷶�� ������ ����, ������, ���
		int home = temp.home,
			start = temp.start,
			end = temp.end,
			cost = temp.cost;

		// ���� cost�� ���� �� ���� �����Ͽ� �ߺ� ����(�ִ� 1 ����)
		if (!Visited[home][end])
		{
			Visited[home][end] = 1;

			// ������ ���������� �� �� �ִ� ��� ���ø� üũ(�ִ� 100 ��)
			for (int i = 1; i <= N; i++)
			{
				// ������ �信�� ���==������ ���ٰ� ����
				if (home != i)
				{
					// ���������� �� �� �ִ� ������ ��쿡�� 
					if (Cost[end][i])
					{
						// �� ����� ���� ��쿡�� ä�� or
						// ��������� �������� �ʰ� �� �� ������ ��� 
						if (Cost[home][i] == 0 || Cost[home][i] > cost + Cost[end][i])
						{
							Cost[home][i] = cost + Cost[end][i];
							pq.emplace(bus(home, end, i, Cost[home][i]));
						}
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int temp;
	cin >> N >> M >> temp;

	while (M--)
	{
		int s, e, c;
		cin >> s >> e >> c;
		if (Cost[s][e] == 0)
			Cost[s][e] = c;

		else
			Cost[s][e] = MIN(Cost[s][e], c);

		pq.emplace(bus(s, s, e, c));
	}

	solution();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << Cost[i][j] << " ";

		cout << '\n';
	}

	return 0;
}