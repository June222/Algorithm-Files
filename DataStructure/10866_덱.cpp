#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* front;
	Node* back;
}Node;

typedef struct Deque {
	int cnt;
	Node* first;
	Node* last;
public:
	Deque() {}
	void command(string str);
	bool empty();
}Deque;

bool Deque::empty()
{
	return cnt == 0;
}

void Deque::command(string str)
{
	if (str == "push_front")
	{
		int x; cin >> x;
		Node* newNode = new Node{ x,NULL,NULL };

		if (empty())
		{
			first = newNode;
			last = newNode;
		}

		else
		{
			first->front = newNode;
			newNode->back = first;
			first = newNode;
		}

		cnt++;
	}

	else if (str == "push_back")
	{
		int x; cin >> x;
		Node* newNode = new Node{ x,NULL,NULL };

		if (empty())
		{
			first = newNode;
			last = newNode;
		}

		else
		{
			last->back = newNode;
			newNode->front = last;
			last = newNode;
		}

		cnt++;
	}

	else if (str == "pop_front")
	{
		if (empty())
			cout << -1 << '\n';

		else
		{
			cout << first->data << '\n';

			Node* temp = first;
			first = first->back;
			free(temp);
			cnt--;
		}
	}

	else if (str == "pop_back")
	{
		if (empty())
			cout << -1 << '\n';

		else
		{
			cout << last->data << '\n';

			Node* temp = last;
			last = last->front;
			free(temp);
			cnt--;
		}
	}

	else if (str == "size")
		cout << cnt << '\n';

	else if (str == "empty")
	{
		if (empty())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	else if (str == "front")
	{
		if (empty())
			cout << -1 << '\n';

		else
			cout << first->data << '\n';
	}

	else if (str == "back")
	{
		if (empty())
			cout << -1 << '\n';

		else
			cout << last->data << '\n';
	}
}

Deque dq;

int N;

void initdq()
{
	dq.cnt = 0;
	dq.first = NULL;
	dq.last = NULL;
}

int main()
{
	string inst;

	initdq();

	cin >> N;

	while (N--)
	{
		cin >> inst;
		dq.command(inst);
	}

	return 0;
}