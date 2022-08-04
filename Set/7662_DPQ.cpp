#include <iostream>
#include <set>

using namespace std;

multiset<int> ms;

int T, K;

int main() {
	char command; int data;
	cin >> T;
	while (T--)
	{
		ms.erase();
		cin >> K;
		while (K--)
		{
			cin >> command >> data;
			if (command == 'I')
				ms.insert(data);

			else if (command == 'D')
			{
				if (!ms.empty())
				{
					if (data == -1)
						ms.erase(ms.begin());

					if (data == 1)
					{
						auto iter = ms.end();
						ms.erase(--iter);
					}
				}
				
			}
		}
		auto iter = ms.end();
		cout << *(iter - 1) << " " << *ms.begin() << '\n';
	}

	return 0;
}