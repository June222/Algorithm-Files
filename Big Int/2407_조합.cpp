#include <iostream>

using namespace std;

string answer[101][101];

int N, M;

string Sum(string s1, string s2)
{
	// ū ���� ���ʿ� ��
	if (s1.size() < s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	string result = "";

	// �����ͷ� ���� ����
	int index1 = s1.size() - 1, index2 = s2.size() - 1;

	// �ø� �� ����
	int r = 0;

	// �����Ͱ� ū ���� �� ���ڸ� ���ڸ� �Ѿ ������
	while (index1 >= 0)
	{
		// char -> int
		int a = s1[index1] - '0';

		// �ø����� ���ڸ��� ���ϱ�
		int c = a + r;

		// �ø��� �ʱ�ȭ
		r = 0;
		
		// �ι�° ���� �ȴٸ� �Ȱ��� ����
		if (index2 >= 0)
		{
			int b = s2[index2] - '0';
			c += b;
		}

		// ���ڸ� ���� ���� ���� 10�� �Ѿ�� �ø�
		if (c >= 10)
		{
			c -= 10;
			r = 1;
		}

		// ����� char���·� �߰��ϰ�
		result = (c + '0') + result;

		// ���� �ڸ� �� ���
		index1--; index2--;
	}

	// while ���� Ż�������� �ø����� ���� �� ����. ex) 2�ڸ� �� + 2�ڸ� �� = 3�ڸ� ��
	if (r) 
		result = (r + '0') + result;

	return result;
}

int main()
{
	// �ʱ�ȭ
	answer[1][0] = "1"; answer[1][1] = "1";

	cin >> N >> M;
	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= M; j++)
			// �Ľ�Į�� �ﰢ�� �̿� (Dynamic Programming)
		{
			if (j == 0 && j == i)
				answer[i][j] = "1";

			else
				answer[i][j] = Sum(answer[i - 1][j - 1], answer[i - 1][j]);
		}


	return 0;
}