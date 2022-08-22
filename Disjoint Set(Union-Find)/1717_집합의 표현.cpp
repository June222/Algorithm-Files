#include <iostream>
using namespace std;

int Parent[1000001] = { 0 };

int N, M;

void init()
{
	// ��� ��带 �� �׷����� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		Parent[i] = i;
}

int Find(int x)
{
	if (x == Parent[x])
		return x;

	// ��Ʈ ��带 ã���� ���ÿ� �θ� ����� ��ȣ�� ����
	return Parent[x] = Find(Parent[x]);
}

void Union(int a, int b)
{
	// �� �׷��� ��Ʈ ��� s1, s2
	int s1 = Find(a); int s2 = Find(b);

	// �׷��� ������ ����
	if (s1 == s2)
		return;

	// �׷��� �ٸ��� ����
	Parent[s2] = s1;
	return;
}

void solution(int inst, int set1, int set2)
{
	if (inst)
	{
		// �� �κп��� ������ �߻�����.
		if (Find(set1) == Find(set2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	else
		Union(set1, set2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	init();

	while (M--)
	{
		int inst, s1, s2;
		cin >> inst >> s1 >> s2;

		solution(inst, s1, s2);
	}
	return 0;
}