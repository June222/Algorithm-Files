#include <iostream>

using namespace std;

#define MAX(a,b) ((a<=b)?b:a)

int DP_EVEN[1002] = { 0 };
int DP_ODD[1002] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;

	int i = -1, j = -1;
	int MM = 0;

	while (++i < s1.size())
	{
		j = -1;
		MM = 0;
		while (++j < s2.size())
		{
			if (i % 2 == 0)
			{
				if (s1[i] == s2[j])
				{
					MM = MAX(DP_ODD[j] + 1, DP_ODD[j + 1]);
				}
				MM = DP_EVEN[j + 1] = MAX(DP_EVEN[j + 1], MAX(DP_ODD[j + 1], MM));
			}

			else
			{
				if (s1[i] == s2[j])
				{
					MM = MAX(DP_EVEN[j] + 1, DP_EVEN[j + 1]);
				}
				MM = DP_ODD[j + 1] = MAX(DP_ODD[j + 1], MAX(DP_EVEN[j + 1], MM));
			}
		}
	}

	cout << MAX(DP_ODD[s2.size()], DP_EVEN[s2.size()]);

	return 0;
}