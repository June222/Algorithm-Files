#include <iostream>
using namespace std;

int Parent[1000001] = { 0 };

int N, M;

void init()
{
	// 모든 노드를 각 그룹으로 초기화
	for (int i = 1; i <= N; i++)
		Parent[i] = i;
}

int Find(int x)
{
	if (x == Parent[x])
		return x;

	// 루트 노드를 찾음과 동시에 부모 노드의 번호로 저장
	return Parent[x] = Find(Parent[x]);
}

void Union(int a, int b)
{
	// 각 그룹의 루트 노드 s1, s2
	int s1 = Find(a); int s2 = Find(b);

	// 그룹이 같으면 무시
	if (s1 == s2)
		return;

	// 그룹이 다르면 병합
	Parent[s2] = s1;
	return;
}

void solution(int inst, int set1, int set2)
{
	if (inst)
	{
		// 이 부분에서 문제가 발생했음.
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