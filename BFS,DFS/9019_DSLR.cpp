#include <iostream>
#include <queue>
using namespace std;

typedef struct Node {

public:
	int a;
	string inst;

	Node(int a, string inst) {
		this->a = a;
		this->inst = inst;
	}
	void print_inst() {
		cout << inst << '\n';
	}
}Node;

int Regsiter;
int A, B;
bool Visited[10001] = { 0 };

void initVisited() {
	for (int i = 0; i < 10001; i++)
		Visited[i] = 0;
}

Node DSLR(int func_mode,Node node) {
	int a = node.a;
	switch (func_mode)
	{
	case 0:
		a*= 2;
		if (a > 9999)
			a %= 10000;
		node.inst += "D";
		break;
	case 1:
		a -= 1;
		if (a < 0)
			a = 9999;
		node.inst += "S";
		break;
	case 2: 
		a = (a % 1000) * 10 + a / 1000;
		node.inst += "L";
		break;
	case 3:
		a = (a % 10) * 1000 + a / 10 ;
		node.inst += "R";
		break;
	}
	node.a = a;

	return node;
}


void BFS(Node node) {
	queue<Node> q;
	q.push(node);

	while (!q.empty()) {
		Node temp = q.front();
		Visited[temp.a] = 1;
		q.pop();

		if (temp.a == B) {
			temp.print_inst();
			return;
		}

		for (int i = 0; i < 4; i++) {
			Node result = DSLR(i, temp);
			if (result.a == B) {
				result.print_inst();
				return;
			}
			if (!Visited[result.a]) {
				Visited[result.a] = 1;
				q.push(result);
			}
		}

	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> A >> B;
		BFS(Node(A, ""));
		initVisited();
	}

	return 0;
}
