
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int N;
int min_score_diff = INT_MAX;
int** Score = NULL;

bool included[50] = { 0, };

typedef struct Node {
    int cnt;
    int score;
    vector<int> team;
public:
    Node() {}
    Node(int cnt, int score, vector<int> team) {
        this->cnt = cnt;
        this->score = score;
        this->team = team;
    }
}Node;

bool isAlreadyIn(Node* node, int i) {
    for (int j = 0; j < node->team.size(); j++) {
        if (node->team[j] == i) {
            return true;
        }
    }
    return false;
}

int getScore(Node* node, int member) {
    int newScore = 0;

    for (int i = 0; i < node->team.size(); i++) {
        newScore += Score[node->team[i]][member];
        newScore += Score[member][node->team[i]];
    }
    return newScore;
}

bool isPromising(Node* node, int member) {
    return !isAlreadyIn(node, member);
}

void backtracking(Node* node, int cnt) {

    if (cnt == N / 2) {
        int score_t1 = node->score;
        int score_t2 = 0;
        vector<int> t2;

        for (int i = 1; i <= N; i++)
            if (!included[i])
                t2.push_back(i);

        for (int i = 0; i < t2.size(); i++)
            for (int j = 0; j < t2.size(); j++)
                score_t2 += Score[t2[i]][t2[j]];

        if (min_score_diff > abs(score_t1 - score_t2))
            min_score_diff = abs(score_t1 - score_t2);
        cout << "최소 점수 차이 : " << min_score_diff << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (isPromising(node, i)) {
            node->team.push_back(i);
            included[i] = true;
            int newScore = getScore(node, i);
            node->score += newScore;
            cout << "현재 점수 : " << node->score << '\n';
            backtracking(node, cnt + 1);
            node->team.pop_back();
            included[i] = false;
            node->score -= newScore;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    Score = new int* [N + 1];
    for (int i = 0; i <= N; i++) {
        Score[i] = new int[N + 1];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Score[i][j];
        }
    }

    vector<int> team;
    Node node(0, 0, team);
    backtracking(&node, 0);
    cout << min_score_diff;
}

