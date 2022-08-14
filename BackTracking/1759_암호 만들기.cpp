#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> buff;
vector<string> Answers;

// �־��� �信 ���Ե� ������ ���� ���� ����.
vector<char> IncludedVowel;
vector<char> IncludedConsonant;

// ã�� ��й�ȣ.
string answer = "";

int L, C;

bool isVowel(char a)
{
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void BackTracking(int index, int cnt)
{
	if (cnt == L)
	{
		// ��������: ������ �ּ� 1��, ������ �ּ� 2��
		if (IncludedVowel.size() && IncludedConsonant.size() >= 2)
			Answers.emplace_back(answer);

		return;
	}

	for (int i = index; i < buff.size(); i++)
	{
		if (isVowel(buff[i]))
		{
			IncludedVowel.push_back(buff[i]);
			answer += buff[i];

			BackTracking(i + 1, cnt + 1);

			answer = answer.substr(0, answer.size() - 1);
			IncludedVowel.pop_back();
		}

		else
		{
			IncludedConsonant.push_back(buff[i]);
			answer += buff[i];

			BackTracking(i + 1, cnt + 1);

			IncludedConsonant.pop_back();
			answer = answer.substr(0, answer.size() - 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;

	while (C--)
	{
		char apb;
		cin >> apb;
		buff.emplace_back(apb);
	}

	// ���������� �̸� �����
	sort(buff.begin(), buff.end());

	BackTracking(0, 0);

	for (string a : Answers)
		cout << a << '\n';

	return 0;
}