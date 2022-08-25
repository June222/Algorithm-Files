#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> buff;
vector<int> stk;
vector<int> answer;

int N;

int main()
{
	cin >> N;
	while (N--)
	{
		int num; cin >> num;
		buff.push_back(num);
	}

	// ����� �������� ��.
	reverse(buff.begin(), buff.end());

	for (int a : buff)
	{
		bool exist = false;

		// ������ ��������� �� ū ���� ���ٴ� ��.
		while (!stk.empty())
		{
			// ���� ���� �����ε� ���� �� ����.
			if (stk.back() <= a)
				stk.pop_back();

			// ��ū���� �߰��� ���.
			else
			{
				exist = true;
				break;
			}
		}

		if (exist)
			answer.push_back(stk.back());

		else
			answer.push_back(-1);

		stk.push_back(a);
	}

	reverse(answer.begin(), answer.end());

	for (int ans : answer)
		cout << ans << " ";

	return 0;
}