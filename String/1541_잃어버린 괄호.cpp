#include <iostream>
#include <sstream>

using namespace std;

string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string temp;
	int answer = 0;
	bool minus = false;

	cin >> str;
	for (int i = 0; i <= str.size(); i++) {

		if (str[i] == '-' || str[i] == '+' || i == str.size())
		{
			int num;
			stringstream strToint(temp);
			strToint >> num;

			if (minus)
				answer -= num;

			else
				answer += num;

			if (str[i] == '-')
				minus = true;

			temp = "";
		}

		else
			temp += str[i];
	}

	cout << answer;

	return 0;
}