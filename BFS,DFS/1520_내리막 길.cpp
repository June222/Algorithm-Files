#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef pair<int, int> Pair; // row, col

vector<Pair> Trace; // 발자취

// 입력받은 값 저장
int map[502][502] = { 0 };

// DFS 왔던 길 계산 방지용
bool Visited[502][502] = { 0 };

// Dynamic Programming 에 이용되는 이미 도착한 적 있는 노드의 가능한 모든 경우의 수 저장
// Promising
int Possible[502][502] = { 0 };

// 모든 방향에서 도달할 수 없는 노드 저장
// Non-Promising
bool Never[502][502] = { 0 };

int M, N; // 가로 세로

// 갈 수 있는 길인지 확인하는 함수
bool isValid(int row, int col, int num)
{
	return map[row][col] != 0 && !Visited[row][col] && num > map[row][col];
}

void solution(int row, int col, int num)
{
	// Non-Promising node는 검색안함.
	if (Never[row][col])
		return;

	// Promising node는 Dynamic Programming 기법 이용하여 저장.
	if (Possible[row][col])
	{
		int poss_cases = Possible[row][col];

		// 왔던 길에 갈 수있는 모든 경우의 수 더해주기
		for (int i = 0; i < Trace.size() - 1; i++)
			Possible[Trace[i].first][Trace[i].second] += poss_cases;

		return;
	}

	// DFS
	for (int i = 0; i < 4; i++)
	{
		int new_row = row + dy[i]; int new_col = col + dx[i];

		if (isValid(new_row, new_col, num))
		{
			Visited[new_row][new_col] = 1;
			Trace.push_back({ new_row,new_col });

			solution(new_row, new_col, map[new_row][new_col]);

			Trace.pop_back();
			Visited[new_row][new_col] = 0;
		}

	}

	// 모든 방향 검색 후 도달하지 못한 노드면 대상에서 지우기. 
	if (!Possible[row][col])
		Never[row][col] = 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	Possible[M][N] = 1;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	Trace.push_back({ 1,1 });

	solution(1, 1, map[1][1]);

	// 시작 노드에 가능한 모든 경우의 수의 합이 저장됨.
	cout << Possible[1][1];

	return 0;
}