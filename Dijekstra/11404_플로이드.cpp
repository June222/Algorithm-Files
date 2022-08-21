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

		// 버스 출발지, 들렀던 마지막 도시, 도착지, 비용
		int home = temp.home,
			start = temp.start,
			end = temp.end,
			cost = temp.cost;

		// 가장 cost가 작은 것 부터 실행하여 중복 방지(최대 1 만번)
		if (!Visited[home][end])
		{
			Visited[home][end] = 1;

			// 버스의 도착지에서 갈 수 있는 모든 도시를 체크(최대 100 번)
			for (int i = 1; i <= N; i++)
			{
				// 문제의 답에서 출발==도착은 없다고 했음
				if (home != i)
				{
					// 도착지에서 갈 수 있는 도시의 경우에만 
					if (Cost[end][i])
					{
						// 더 비용이 적은 경우에는 채택 or
						// 출발지에서 경유하지 않고 갈 수 없었던 경우 
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