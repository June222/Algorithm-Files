#include <iostream>

using namespace std;

typedef struct node
{
public:
	char data;
	node* left;
	node* right;
}node;

pair<char, char> Childs[26];

node* buff[26];

int N;

// 부모 -> 왼쪽 자식 -> 오른쪽 자식 순
void print_pre_order(node* n)
{
	cout << n->data;
	if (n->left != NULL) print_pre_order(n->left);
	if (n->right != NULL) print_pre_order(n->right);

}
// 왼쪽 자식 -> 부모 -> 오른쪽 자식 순
void print_in_order(node* n)
{
	if (n->left != NULL) print_in_order(n->left);
	cout << n->data;
	if (n->right != NULL) print_in_order(n->right);
}

// 왼쪽 자식 -> 오른쪽 자식 -> 부모 순
void print_post_order(node* n)
{
	if (n->left != NULL) print_post_order(n->left);
	if (n->right != NULL) print_post_order(n->right);
	cout << n->data;
}

// 자식 설정은 모든 노드를 생성한 이후에 
void setChilds(node* n)
{
	char data_left = Childs[n->data - 65].first; char data_right = Childs[n->data - 65].second;

	if (data_left != '.')
		n->left = buff[data_left - 65];

	if (data_right != '.')
		n->right = buff[data_right - 65];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int temp = N;
	while (temp--)
	{
		char p, l, r;
		cin >> p >> l >> r;

		// 생성자의 방식과 다르면 사용하지 못함.
		buff[p - 65] = new node{ p,NULL,NULL };

		Childs[p - 65].first = l;
		Childs[p - 65].second = r;
	}

	for (int i = 0; i < N; i++)
		setChilds(buff[i]);

	print_pre_order(buff[0]);
	cout << '\n';
	print_in_order(buff[0]);
	cout << '\n';
	print_post_order(buff[0]);

	return 0;
}
