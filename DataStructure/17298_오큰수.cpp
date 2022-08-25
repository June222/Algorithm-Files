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

	// 뒤집어서 왼쪽으로 함.
	reverse(buff.begin(), buff.end());

	for (int a : buff)
	{
		bool exist = false;

		// 스택이 비어있으면 더 큰 수가 없다는 것.
		while (!stk.empty())
		{
			// 작은 수는 앞으로도 쓰일 일 없음.
			if (stk.back() <= a)
				stk.pop_back();

			// 오큰수를 발견한 경우.
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