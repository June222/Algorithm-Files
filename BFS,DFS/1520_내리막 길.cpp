#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

typedef pair<int, int> Pair; // row, col

vector<Pair> Trace; // ������

// �Է¹��� �� ����
int map[502][502] = { 0 };

// DFS �Դ� �� ��� ������
bool Visited[502][502] = { 0 };

// Dynamic Programming �� �̿�Ǵ� �̹� ������ �� �ִ� ����� ������ ��� ����� �� ����
// Promising
int Possible[502][502] = { 0 };

// ��� ���⿡�� ������ �� ���� ��� ����
// Non-Promising
bool Never[502][502] = { 0 };

int M, N; // ���� ����

// �� �� �ִ� ������ Ȯ���ϴ� �Լ�
bool isValid(int row, int col, int num)
{
	return map[row][col] != 0 && !Visited[row][col] && num > map[row][col];
}

void solution(int row, int col, int num)
{
	// Non-Promising node�� �˻�����.
	if (Never[row][col])
		return;

	// Promising node�� Dynamic Programming ��� �̿��Ͽ� ����.
	if (Possible[row][col])
	{
		int poss_cases = Possible[row][col];

		// �Դ� �濡 �� ���ִ� ��� ����� �� �����ֱ�
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

	// ��� ���� �˻� �� �������� ���� ���� ��󿡼� �����. 
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

	// ���� ��忡 ������ ��� ����� ���� ���� �����.
	cout << Possible[1][1];

	return 0;
}