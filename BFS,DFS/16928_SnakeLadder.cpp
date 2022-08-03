#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pair; // ���� ��ġ, ��ġ������ �ּ� Ƚ��

int Board[101] = { 0 };
bool Visited[101] = { 1,1,0 };
int ladders[101] = { 0 };
int snakes[101] = { 0 };

int N, M;
int x, y, u, v;

void Solution(int start, int cnt) {

	queue <Pair> q;
	q.push({ start,cnt });

	while (!q.empty())
	{
		Pair temp = q.front();
		q.pop();

		// ���� ��ġ, ��ġ������ Ƚ��
		int curr_point = temp.first; int curr_cnt = temp.second;

		for (int i = 1; i <= 6; i++) {

			// ���� ��ġ = ���� ��ġ + �ֻ��� ���� ��
			int next_point = curr_point + i;

			if (next_point <= 100)
			{
				// while�� Ż��
				if (next_point == 100)
				{
					Board[100] = curr_cnt + 1;
					return;
				}

				// ���� ������ �鸰 �� ����,
				if (!Visited[next_point])
				{
					if (ladders[next_point] != 0) // ���� ������ ��ٸ��� �ְ�
					{

						//
						// �Ʒ��� �������
						// 1. ��ٸ� Ÿ�� ���� �鷶���� üũ
						// 2. ��ٸ����� ������ ���� �鷶���� üũ
						// 3. �����ǿ� ���
						// 4. ��ٸ����� ������ ���� Ƚ���� queue�� ����
						//

						Visited[next_point] = 1;
						Visited[ladders[next_point]] = 1;
						Board[ladders[next_point]] = curr_cnt + 1;
						q.push({ ladders[next_point],curr_cnt + 1 });
						continue;
					}

					if (snakes[next_point] != 0)  // ���� ������ ���� ������
					{

						//
						// ��ٸ��� ���� ���� ���������� ����.
						//

						Visited[next_point] = 1;
						Visited[snakes[next_point]] = 1;
						Board[snakes[next_point]] = curr_cnt + 1;
						q.push({ snakes[next_point],curr_cnt + 1 });
						continue;

					}

					// ��ٸ���, �쵵 Ÿ�� �ʴ� ���
					Visited[next_point] = 1;
					Board[next_point] = curr_cnt + 1;
					q.push({ next_point,curr_cnt + 1 });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	while (N--)
	{
		cin >> x >> y;
		ladders[x] = y;
	}

	while (M--) {
		cin >> u >> v;
		snakes[u] = v;
	}

	Solution(1, 0);

	cout << Board[100];

	return 0;
}