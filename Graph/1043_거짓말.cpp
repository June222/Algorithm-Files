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
	// üũ ���� ����̸�: ���� ���� ����
	if (!Checked[person])
	{
		// üũ������ ����
		Checked[person] = 1;

		// �� ����� �ִ� ��� ��Ƽ�� ���Ͽ�
		for (auto partyNum : Party_Particepate[person])
		{
			// ������ ���ؾ��ϴ� ��Ƽ�̰�
			Must_Truth[partyNum] = 1;

			// �ش� ��Ƽ�� ���� �ִ� ��� ����鿡 ���Ͽ� 
			for (auto man_in_party : People_In_Party[partyNum])

				// ��������� üũ
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
