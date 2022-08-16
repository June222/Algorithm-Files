
#include <iostream>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int Board[500][500] = { 0 };
int Checked[500][500] = { 0 };

int N, M;

int sum = 0; // ���� Ǯ�̿��� ���ڷ� �Ѱ��־���.
int MM = 0; // �ִ밪

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
		// ���� ����� �� üũ
		if (isValid(row + dy[i], col + dx[i]))
		{
			// �̹� Ȯ���� ���� �ٽ� Ȯ������ �ʵ���
			if (!Checked[row + dy[i]][col + dx[i]])
			{
				// ������ �����ְ�, Ȯ���� ���� üũ
				sum += Board[row + dy[i]][col + dx[i]];
				Checked[row + dy[i]][col + dx[i]] = 1;

				// �� ����� ����� ���� �κ�
				if (cnt == 2)
					DFS(row, col, cnt + 1);

				// ��������� ���� �Űܰ��� Ȯ��
				DFS(row + dy[i], col + dx[i], cnt + 1);

				// �ʱ�ȭ
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