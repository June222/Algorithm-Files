#include <iostream>
#include <map>
using namespace std;

int answer;
map <string, int> closet;

int main()
{
	int tc, n;
	string costume, type;
	cin >> tc;
	while (tc--)
	{
		closet.clear();
		answer = 1;
		cin >> n;
		while (n--)
		{
			cin >> costume >> type;
			auto iter = closet.find(type);
			if (iter != closet.end())
				closet[type]++;
			else
				closet[type] = 1;
		}

		//auto iter = closet.begin();
		//while (iter != closet.end()) 
		//	answer *= (*iter).second + 1;

		for (auto iter : closet)
			answer *= iter.second + 1;

		cout << --answer << '\n';
	}



	return 0;
}