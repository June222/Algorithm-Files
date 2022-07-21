#include <iostream>
#include <climits>

using namespace std;

int ScoreBoard[21][21];
bool Included[21];
int N;
int Min_score_diff = INT_MAX;

void seperate(int cnt, int member) {
	if (cnt == N / 2) {
		int score_t1 = 0, score_t2 = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (Included[i] && Included[j]) {
					score_t1 += ScoreBoard[i][j];
					score_t1 += ScoreBoard[j][i];
				}
				else if (!Included[i] && !Included[j]) {
					score_t2 += ScoreBoard[i][j];
					score_t2 += ScoreBoard[j][i];
				}
			}
		}
		int temp_diff = abs(score_t1 - score_t2);
		if (Min_score_diff > temp_diff)
			Min_score_diff = temp_diff;
		return;
	}
	else {
		for (int i = member + 1; i <= N; i++) {
			Included[i] = true;
			seperate(cnt + 1, i);
			Included[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> ScoreBoard[i][j];
		
	seperate(0, 0);
	cout << Min_score_diff;
}