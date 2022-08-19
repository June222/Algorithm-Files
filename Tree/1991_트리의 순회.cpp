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

// �θ� -> ���� �ڽ� -> ������ �ڽ� ��
void print_pre_order(node* n)
{
	cout << n->data;
	if (n->left != NULL) print_pre_order(n->left);
	if (n->right != NULL) print_pre_order(n->right);

}
// ���� �ڽ� -> �θ� -> ������ �ڽ� ��
void print_in_order(node* n)
{
	if (n->left != NULL) print_in_order(n->left);
	cout << n->data;
	if (n->right != NULL) print_in_order(n->right);
}

// ���� �ڽ� -> ������ �ڽ� -> �θ� ��
void print_post_order(node* n)
{
	if (n->left != NULL) print_post_order(n->left);
	if (n->right != NULL) print_post_order(n->right);
	cout << n->data;
}

// �ڽ� ������ ��� ��带 ������ ���Ŀ� 
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

		// �������� ��İ� �ٸ��� ������� ����.
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
