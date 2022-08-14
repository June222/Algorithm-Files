#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MM 2e9

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef pair<int, int> Pair;

typedef struct info {
	int row;
	int col;
	int cnt;
	bool chance = true;
public:
	info() {}
	info(int row, int col, int cnt, bool chance)
	{
		this->row = row;
		this->col = col;
		this->cnt = cnt;
		this->chance = chance;
	}
}info;

vector<Pair> chk;

int map[1002][1002] = { 0 };
bool Checked[1002][1002][2] = { 0 };

int N, M;
int minCnt = MM;

bool isWall(int row, int col)
{
	return map[row][col] == 1;
}

bool isValid(int row, int col)
{
	return map[row][col] == 0;
}

bool isDest(int row, int col)
{
	return row == N && col == M;
}

// 벽을 부술 가치가 있나?
// -> 그 주변에 확인하지 않은 갈 곳이 있나?
bool isWorth(int row, int col, int chance)
{
	return (map[row - 1][col] == 0 && !Checked[row - 1][col][chance]) || (map[row + 1][col] == 0 && !Checked[row + 1][col][chance]) ||
		(map[row][col - 1] == 0 && !Checked[row][col - 1][chance]) || (map[row][col + 1] == 0 && !Checked[row][col + 1][chance]);
}

void init()
{
	for (int i = 0; i < N + 2; i++)
		for (int j = 0; j < M + 2; j++)
			map[i][j] = -1;
}

void BFS(int row, int col, int cnt)
{
	queue<info> q;

	q.emplace(info(row, col, cnt, 1));

	while (!q.empty())
	{
		info temp = q.front();
		q.pop();

		if (isDest(temp.row, temp.col))
		{
			if (minCnt > temp.cnt)
				minCnt = temp.cnt;

			return;
		}

		else
		{
			for (int i = 0; i < 4; i++)
			{
				int new_row = temp.row + dy[i]; int new_col = temp.col + dx[i];

				if (!Checked[new_row][new_col][temp.chance])
				{
					Checked[new_row][new_col][temp.chance] = 1;

					if (isValid(new_row, new_col))
						q.emplace(info(new_row, new_col, temp.cnt + 1, temp.chance));

					else if (isWall(new_row, new_col) && temp.chance)
						if (isWorth(new_row, new_col, temp.chance))
							q.emplace(info(new_row, new_col, temp.cnt + 1, 0));

				}
			}
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &M);

	init();

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf_s("%1d", &map[i][j]);

	Checked[1][1][1] = 1; Checked[1][1][0] = 1;

	BFS(1, 1, 1);

	printf("%d", ((minCnt == MM) ? -1 : minCnt));

	return 0;
}