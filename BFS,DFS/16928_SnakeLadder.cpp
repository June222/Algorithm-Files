#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pair; // 현재 위치, 위치까지의 최소 횟수

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

		// 현재 위치, 위치까지의 횟수
		int curr_point = temp.first; int curr_cnt = temp.second;

		for (int i = 1; i <= 6; i++) {

			// 다음 위치 = 현재 위치 + 주사위 눈의 수
			int next_point = curr_point + i;

			if (next_point <= 100)
			{
				// while문 탈출
				if (next_point == 100)
				{
					Board[100] = curr_cnt + 1;
					return;
				}

				// 도착 지점에 들린 적 없고,
				if (!Visited[next_point])
				{
					if (ladders[next_point] != 0) // 도착 지점에 사다리가 있고
					{

						//
						// 아래는 순서대로
						// 1. 사다리 타는 곳에 들렀음을 체크
						// 2. 사다리에서 내려온 곳은 들렀음을 체크
						// 3. 점수판에 기록
						// 4. 사다리에서 내려온 곳과 횟수로 queue에 삽입
						//

						Visited[next_point] = 1;
						Visited[ladders[next_point]] = 1;
						Board[ladders[next_point]] = curr_cnt + 1;
						q.push({ ladders[next_point],curr_cnt + 1 });
						continue;
					}

					if (snakes[next_point] != 0)  // 도착 지점에 뱀이 있으며
					{

						//
						// 사다리를 탔을 때와 마찬가지로 진행.
						//

						Visited[next_point] = 1;
						Visited[snakes[next_point]] = 1;
						Board[snakes[next_point]] = curr_cnt + 1;
						q.push({ snakes[next_point],curr_cnt + 1 });
						continue;

					}

					// 사다리도, 뱀도 타지 않는 경우
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