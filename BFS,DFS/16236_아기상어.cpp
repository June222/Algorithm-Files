#include <iostream>
#include <queue>

using namespace std;

// queue���� Ȯ���� ���� : ��ġ, n��° �̵�
typedef struct info {
	int row;
	int col;
	int cnt;
public:
	info() {}
	info(int row, int col, int cnt) {
		this->row = row;
		this->col = col;
		this->cnt = cnt;
	}
}info;

// �Ʊ����� ���� (��ġ, ������ ũ��, �̵��Ÿ�, ���� ������� ��)
typedef struct SHARK {
	int row;
	int col;
	int size = 2;
	int moved = 0;
	int eaten = 0;
}SHARK;

// �켱���� ť�� ���� : 1. ����� �� ����, 2. ���� ����� ����, 3. ���� ����� ����
struct compare {
	bool operator()(info info1, info info2) {
		if (info1.cnt == info2.cnt)
		{
			if (info1.row == info2.row)
			{
				return info1.col > info2.col;
			}
			return info1.row > info2.row;
		}
		return info1.cnt > info2.cnt;
	}
};

// �� �������� �� ������ ����� ����.
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

// �������� ��ġ�� ũ�� ����
int SEA[22][22] = { 0 };

// �ߺ� ��� ����, ��� �� ������ ������ init �ʿ���
int Visited[22][22] = { 0 };

// init�� ������ �ϱ� ���Ͽ� Visit�� üũ�� ��ġ��
vector<pair<int, int>> buff;

int N;
SHARK Shark;

// �Ʊ�� ������ �� �ִ� �����ΰ�? (2����): 1. ������ ũ��, 2. �̹� üũ�Ͽ��°�? 
bool isValid_move(int row, int col) {
	return Shark.size >= SEA[row][col] && !Visited[row][col];
}

// �Ʊ�� ���� �� �ִ� ������ΰ�? (2����): 1. ������ ũ��, 2. ����Ⱑ �־����.
bool isValid_eat(int row, int col) {
	return Shark.size > SEA[row][col] && SEA[row][col] != 0;
}

// ����⸦ ���� �ڿ� �Ʊ����� ��ġ �缳��
void SetSharkPosition(int row, int col) {
	Shark.row = row;
	Shark.col = col;
}

// ����� ���� (3����): 1. ���� ����� �� �ø���, 2. ���� Ű���, 3. �Ʊ��� ��ġ �缳��
void EatFish(int row, int col, int cnt) {

	Shark.eaten++;

	if (Shark.eaten == Shark.size)
	{
		Shark.eaten = 0;
		Shark.size++;
	}
	Shark.moved += cnt;
	SEA[row][col] = 0;
	SetSharkPosition(row, col);
}

// �Ʊ�� ������ �ڿ� init Visited
void init_buff() {

	for (int i = 0; i < buff.size(); i++)
		Visited[buff[i].first][buff[i].second] = 0;

	buff.clear();
}

// BFS�� �̿��� �Լ�, priority_queue���� ���ǿ� �´� ����Ⱑ top�� �ְ� ��
void MoveSHARK() {

	priority_queue <info, vector<info>, compare> q; // �� ���� ������ ��ġ, ������ Ƚ��, 

	q.emplace(info(Shark.row, Shark.col, 0));

	// ó�� �Ʊ����� ��ġ�� �˻����� �ʵ��� ��.
	Visited[Shark.row][Shark.col] = 1;
	buff.emplace_back(Shark.row, Shark.col);

	while (!q.empty())
	{
		// temp���� �Ʊ�� �� �� �ִ� ������ ������ ����
		info temp = q.top();
		q.pop();

		int row = temp.row; int col = temp.col; int cnt = temp.cnt;

		// �� �� �ִ� ������ ����Ⱑ �ְ� ���� �� �ִ°�?
		if (isValid_eat(row, col))
		{
			// ��ġ �缳���� �ٽ� BFS�� �ϱ� ���� �ʱ�ȭ (queue ����, Visited �ʱ�ȭ)
			while (!q.empty())
				q.pop();

			init_buff();

			// �� ��ġ�� queue�� �ְ� �ٽ� BFS
			q.emplace(info(row, col, 0));

			// ����� �Ա�
			EatFish(row, col, cnt);
			// �߰����� queue�� ���� ���� BFS����
			continue;
		}

		for (int i = 0; i < 4; i++) {

			// �Ʊ�� �� �� �ִ� ���̶�� queue ����
			if (isValid_move(row + dy[i], col + dx[i]))
				q.emplace(info(row + dy[i], col + dx[i], cnt + 1));

			// Ȯ���� ���� üũ
			Visited[row + dy[i]][col + dx[i]] = 1;
			// ���� �ʱ�ȭ�� ���� Ȯ���� �� ����
			buff.emplace_back(row + dy[i], col + dx[i]);
		}
	}
}

// �Ʊ���� 30�� �����ϰ� ������ Ű�� �� ����.
void init_SEA() { 
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 22; j++)
			SEA[i][j] = 10000;
}

int main()
{
	init_SEA();

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> SEA[i][j];

			// �Ʊ����� ��ġ Ȯ��
			if (SEA[i][j] == 9)
			{
				SetSharkPosition(i, j);
				SEA[i][j] = 0;
			}
		}
	}

	MoveSHARK();
	cout << Shark.moved;
	return 0;
}
