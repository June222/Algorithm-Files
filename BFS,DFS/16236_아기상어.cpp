#include <iostream>
#include <queue>

using namespace std;

// queue에서 확인할 정보 : 위치, n번째 이동
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

// 아기상어의 정보 (위치, 몸집의 크기, 이동거리, 먹은 물고기의 수)
typedef struct SHARK {
	int row;
	int col;
	int size = 2;
	int moved = 0;
	int eaten = 0;
}SHARK;

// 우선순위 큐의 조건 : 1. 가까운 것 부터, 2. 위의 물고기 부터, 3. 왼쪽 물고기 부터
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

// 이 문제에서 이 순서는 상관이 없다.
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

// 물고기들의 위치와 크기 정보
int SEA[22][22] = { 0 };

// 중복 계산 방지, 대신 상어가 움직일 때마다 init 필요함
int Visited[22][22] = { 0 };

// init을 빠르게 하기 위하여 Visit을 체크한 위치들
vector<pair<int, int>> buff;

int N;
SHARK Shark;

// 아기상어가 움직일 수 있는 공간인가? (2가지): 1. 몸집의 크기, 2. 이미 체크하였는가? 
bool isValid_move(int row, int col) {
	return Shark.size >= SEA[row][col] && !Visited[row][col];
}

// 아기상어가 먹을 수 있는 물고기인가? (2가지): 1. 몸집의 크기, 2. 물고기가 있어야함.
bool isValid_eat(int row, int col) {
	return Shark.size > SEA[row][col] && SEA[row][col] != 0;
}

// 물고기를 먹은 뒤에 아기상어의 위치 재설정
void SetSharkPosition(int row, int col) {
	Shark.row = row;
	Shark.col = col;
}

// 물고기 먹음 (3가지): 1. 먹은 물고기 수 늘리기, 2. 몸집 키우기, 3. 아기상어 위치 재설정
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

// 아기상어가 움직인 뒤에 init Visited
void init_buff() {

	for (int i = 0; i < buff.size(); i++)
		Visited[buff[i].first][buff[i].second] = 0;

	buff.clear();
}

// BFS를 이용한 함수, priority_queue에는 조건에 맞는 물고기가 top에 있게 됨
void MoveSHARK() {

	priority_queue <info, vector<info>, compare> q; // 상어가 도달 가능한 위치, 움직인 횟수, 

	q.emplace(info(Shark.row, Shark.col, 0));

	// 처음 아기상어의 위치는 검색하지 않도록 함.
	Visited[Shark.row][Shark.col] = 1;
	buff.emplace_back(Shark.row, Shark.col);

	while (!q.empty())
	{
		// temp에는 아기상어가 갈 수 있는 공간의 정보가 있음
		info temp = q.top();
		q.pop();

		int row = temp.row; int col = temp.col; int cnt = temp.cnt;

		// 갈 수 있는 공간에 물고기가 있고 먹을 수 있는가?
		if (isValid_eat(row, col))
		{
			// 위치 재설정과 다시 BFS를 하기 위한 초기화 (queue 비우기, Visited 초기화)
			while (!q.empty())
				q.pop();

			init_buff();

			// 이 위치를 queue에 넣고 다시 BFS
			q.emplace(info(row, col, 0));

			// 물고기 먹기
			EatFish(row, col, cnt);
			// 추가적인 queue에 삽입 없이 BFS진행
			continue;
		}

		for (int i = 0; i < 4; i++) {

			// 아기상어가 갈 수 있는 곳이라면 queue 삽입
			if (isValid_move(row + dy[i], col + dx[i]))
				q.emplace(info(row + dy[i], col + dx[i], cnt + 1));

			// 확인한 곳은 체크
			Visited[row + dy[i]][col + dx[i]] = 1;
			// 빠른 초기화를 위한 확인한 곳 저장
			buff.emplace_back(row + dy[i], col + dx[i]);
		}
	}
}

// 아기상어는 30에 근접하게 몸집을 키울 수 있음.
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

			// 아기상어의 위치 확보
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
