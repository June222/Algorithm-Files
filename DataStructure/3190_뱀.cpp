#include <iostream>
#include <vector>
using namespace std;

pair<int, int> type_dir[4] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상우하좌(시계방향)

typedef struct Body {
	int row, col;
	Body* front;
	Body* back;
}Body;

struct Snake {
	int dir;
	Body* head;
	Body* tail;
};

// 함수에서 쓰기 위하여 전역변수 설정
Snake snake;

// 방향을 바꿀 시간에 어디로 바꿀건지 저장
char Time_to_change_dir[10001] = { 0 };

// 사과가 있는 곳
bool Apple[101][101] = { 0 };

int N, K, L;

bool hitting_wall(int row, int col)
{
	return row <= 0 || row > N || col <= 0 || col > N;
}

bool hitting_own_body(int row, int col)
{
	Body* body = snake.head;

	while (body != NULL)
	{
		if (row == body->row && col == body->col)
			return true;

		body = body->back;
	}

	return false;
}

// 뱀이 죽는지 체크할 함수
bool isSnakeDie(int row, int col)
{
	return hitting_wall(row, col) || hitting_own_body(row, col);
}

// 뱀의 머리 만들기
void MakeHead(int row, int col)
{
	Body* new_head = new Body{ row,col,NULL,NULL };

	snake.head->front = new_head;
	new_head->back = snake.head;
	snake.head = new_head;
}

bool isThereApple(int row, int col)
{
	return Apple[row][col];
}

// 사과가 없을 때 꼬리 한 칸 당기는 함수
void MoveTail()
{
	Body* temp = snake.tail;

	snake.tail = snake.tail->front;
	snake.tail->back = NULL;
	free(temp);
}

// 방향 바꾸기 D -> 시계 방향, L -> 반시계 방향
void ChangeDirection(int time)
{
	if (Time_to_change_dir[time] == 'D')
	{
		snake.dir++;

		if (snake.dir == 4)
			snake.dir = 0;
	}

	else if (Time_to_change_dir[time] == 'L')
	{
		snake.dir--;

		if (snake.dir < 0)
			snake.dir = 3;
	}
}

int WhenSnakeDie()
{
	int time_survived = 0;

	while (1)
	{
		time_survived++;

		// 다음 머리의 위치 = 머리의 위치 + 머리의 방향
		int next_row = snake.head->row + type_dir[snake.dir].first;
		int next_col = snake.head->col + type_dir[snake.dir].second;

		if (isSnakeDie(next_row, next_col))
			return time_survived;

		MakeHead(next_row, next_col);

		if (isThereApple(next_row, next_col))
			Apple[next_row][next_col] = 0;

		else
			MoveTail();

		if (Time_to_change_dir[time_survived])
			ChangeDirection(time_survived);
	}
}

int main()
{
	cin >> N >> K;
	while (K--)
	{
		int row, col; cin >> row >> col;
		Apple[row][col] = 1;
	}

	cin >> L;
	while (L--)
	{
		int time; char C; cin >> time >> C;
		Time_to_change_dir[time] = C;
	}

	Body* new_body = new Body{ 1,1,NULL,NULL };
	snake.dir = 1; snake.head = new_body; snake.tail = new_body;

	cout << WhenSnakeDie();

	return 0;
}