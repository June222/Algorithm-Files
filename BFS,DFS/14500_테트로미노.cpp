
#include <iostream>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int Board[500][500] = { 0 };
int Checked[500][500] = { 0 };

int N, M;

int sum = 0; // 이전 풀이에는 인자로 넘겨주었음.
int MM = 0; // 최대값

bool isValid(int row, int col)
{
	return 0 <= row && row < N && 0 <= col && col < M;
}

void DFS(int row, int col, int cnt)
{
	if (cnt == 4)
	{
		if (MM < sum)
			MM = sum;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// 맵을 벗어나는 지 체크
		if (isValid(row + dy[i], col + dx[i]))
		{
			// 이미 확인한 블럭은 다시 확인하지 않도록
			if (!Checked[row + dy[i]][col + dx[i]])
			{
				// 점수를 합쳐주고, 확인한 블럭에 체크
				sum += Board[row + dy[i]][col + dx[i]];
				Checked[row + dy[i]][col + dx[i]] = 1;

				// ㅗ 모양을 만들기 위한 부분
				if (cnt == 2)
					DFS(row, col, cnt + 1);

				// 재귀적으로 블럭을 옮겨가며 확인
				DFS(row + dy[i], col + dx[i], cnt + 1);

				// 초기화
				Checked[row + dy[i]][col + dx[i]] = 0;
				sum -= Board[row + dy[i]][col + dx[i]];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			sum += Board[i][j];
			Checked[i][j] = 1;

			DFS(i, j, 1);

			Checked[i][j] = 0;
			sum -= Board[i][j];
		}

	cout << MM;

	return 0;
}