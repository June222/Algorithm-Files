#include <iostream>

using namespace std;

int map[21][21] = { 0 };
int IncludedTeam1[21] = { 0 };

int N;
int MinDiff = 10000000;

void BackTracking(int index, int cnt)
{
	if (cnt == N / 2)
	{
		int team1Power = 0, team2Power = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = i; j <= N; j++)
			{
				if (IncludedTeam1[i] && IncludedTeam1[j])
				{
					team1Power += map[i][j];
					team1Power += map[j][i];
				}

				else if (!IncludedTeam1[i] && !IncludedTeam1[j])
				{
					team2Power += map[i][j];
					team2Power += map[j][i];
				}
			}
		}

		int diff = abs(team1Power - team2Power);

		if (MinDiff > diff)
			MinDiff = diff;

		return;
	}

	for (int i = index; i <= N; i++)
	{
		IncludedTeam1[i] = 1;
		BackTracking(i + 1, cnt + 1);
		IncludedTeam1[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	BackTracking(1, 0);

	cout << MinDiff;

	return 0;
}