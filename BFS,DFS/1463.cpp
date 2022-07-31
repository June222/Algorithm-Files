#include <iostream>
#include <queue>
using namespace std;

typedef struct Node {
	int num;
	int cnt;

public:
	Node(int num, int cnt) {
		this->num = num;
		this->cnt = cnt;
	}
}Node;

int N;

void BFS(int n) {

	queue<Node> q;
	q.push(Node(n, 0));

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		if (temp.num == 1) {
			cout << temp.cnt;
			return;
		}

		if (temp.num % 2 == 0)
			q.push(Node(temp.num / 2, temp.cnt + 1));

		if (temp.num % 3 == 0)
			q.push(Node(temp.num / 3, temp.cnt + 1));

		q.push(Node(temp.num - 1, temp.cnt + 1));
	}
}

int main() {
	cin >> N;

	BFS(N);


	return 0;
}