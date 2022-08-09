#include <iostream>
#include <vector>

using namespace std;

vector<int> People_In_Party[51];
vector<int> Party_Particepate[51];
vector<int> People_Know_Truth;

bool Checked[51] = { 0 };
bool Must_Truth[51] = { 0 };

int N, M;
int Count = 0;

void Solution(int person)
{
	// 체크 안한 사람이면: 무한 루프 방지
	if (!Checked[person])
	{
		// 체크했음을 저장
		Checked[person] = 1;

		// 그 사람이 있는 모든 파티에 대하여
		for (auto partyNum : Party_Particepate[person])
		{
			// 진실을 말해야하는 파티이고
			Must_Truth[partyNum] = 1;

			// 해당 파티에 속해 있는 모든 사람들에 대하여 
			for (auto man_in_party : People_In_Party[partyNum])

				// 재귀적으로 체크
				Solution(man_in_party);
		}
	}
}

int main() {

	cin >> N >> M;

	int num_know_truth;
	cin >> num_know_truth;

	while (num_know_truth--)
	{
		int person_know_truth;
		cin >> person_know_truth;

		People_Know_Truth.push_back(person_know_truth);
	}

	for (int i = 1; i <= M; i++)
	{
		int num_in_party;
		cin >> num_in_party;

		while (num_in_party--)
		{
			int person;
			cin >> person;
			People_In_Party[i].push_back(person);
			Party_Particepate[person].push_back(i);
		}
	}

	for (auto person : People_Know_Truth)
		Solution(person);

	for (int i = 1; i <= M; i++)
		if (!Must_Truth[i])
			Count++;

	cout << Count;

	return 0;
